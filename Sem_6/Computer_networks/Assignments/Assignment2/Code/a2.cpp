#include<bits/stdc++.h>
#include<time.h>
#include<thread>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<cmath>
using namespace std;

vector<time_t> Sendingtimes;
vector<time_t> Receivingtimes;
time_t firstpacketreceived;
time_t lastpacketreceived;

string time2str(time_t seconds){
    std::stringstream ss;
    ss << seconds;
    std::string ts = ss.str();
    return ts;
}

void ImposeProbableError(string &data){
    int x = rand()%4;
    //printf("random is = %d\n",x);
    if(x==2){
        int pos = rand()%data.size();
        data[pos]=='0'?data[pos]='1':data[pos]='0';
    }
}

string getAddableBits(string s){
	string str;
	int p=s.size(); p--;
	while(p--){
		str.push_back('0');
	}
	return str;
}

string Divide(string& dividend, string divisor){
	string result="";
	string temp=dividend;
	int sz=divisor.size()-1;
	//cout<<"temp_ = "<<temp<<endl;
	while(sz--){
		temp.pop_back();
	}
	//cout<<"temp__ = "<<temp<<endl;
	while(1){
		
		if(dividend[0]=='0')
			result.push_back('0');
		else if(dividend[0]=='1'){
			result.push_back('1');
		for(int i=0;i<divisor.size();i++){
			dividend[i]= (char)(((divisor[i]-'0')^(dividend[i]-'0'))+'0');
		}
		}
		if(dividend.size()==divisor.size())
			{
				break;
			}
		dividend.erase(dividend.begin()+0);
	}
	
	dividend.erase(dividend.begin());
	//cout<<"dividend = "<<dividend<<endl;
	string ret = temp+ dividend;
	return ret;
}

class Channel{
public:
    bool sendable;
    bool busy;
    bool receivable;
    string data;
    int acked;
    vector<string> datagrp;
    vector<pair<int,string>> ordered_datagrp;
    vector<int> acknos;
    int failed_bit;
    vector<int> failed_bits;
    int total_number_of_transmission;

    void freeChannel(){
        sendable=true;
        busy=false;
        receivable = false;
        data="";
    }
    void Initiate(){
        freeChannel();
        acked=-1;
    }

    void makeSendable(){
        sendable=true;
        busy=false;
        receivable = false;
        data="";
    }

    void makeReceiveable(){
        sendable=false;
        busy=false;
        receivable = true;
    }

    void makeBusy(){
        sendable=false;
        busy=true;
        receivable = false;
    }
    bool isSendable(){
        if(sendable==true && busy==false && receivable == false){
            return true;
        }
        return false;
    }
    bool isReceiveable(){
        if(sendable==false && busy==false && receivable == true && (data!=""|| datagrp.size() || ordered_datagrp.size())){
            return true;
        }
        return false;
    }
    bool isBusy(){
        if(sendable==false && busy==true && receivable == true){
            return true;
        }
        return false;
    }
};
time_t gettime(){
    time_t t;
    time(&t);
    return t;    
}

class Sender{
public:
    int framesize;
    vector<string> senderFrames;
    bool TimeOut(int i, Channel& channel, int time_out){
        sleep(time_out);
        if(channel.acked==i)
        return true;
        else
        return false;
    }
    bool Send(int i, Channel& channel){
        
        time_t then;
        time(&then);
        time_t now;
        while(1){
        bool timedout = false;
        //try{
        
        if(channel.isSendable()){

            
            string divident = senderFrames[i]+"0000";
            string divisor = "10001";
            string data_with_redundancy = Divide(divident,divisor);
            channel.total_number_of_transmission+=1;
            printf("Sending %d's frame\n",i);
            channel.data = data_with_redundancy;
            Sendingtimes[i]=gettime();
            ImposeProbableError(channel.data);
            //cout<<"Sending started\n";
            channel.makeBusy();
            sleep(rand()%3+1);
            channel.makeReceiveable();
            //cout<<"Sending finished\n";
            while(1){
              bool timeout = TimeOut(i,channel,1);
              return timeout;
            }
        }
    }
    }

    int SendGoBackN(int i, Channel &channel, int windowsize){
        while(1){
        channel.datagrp.clear();
        if(channel.isSendable()){
        channel.acknos.clear();
        for(int x=i ; x< min(i+windowsize, (int)senderFrames.size()); x++){
            string divident = senderFrames[x]+"0000";
            string divisor = "10001";
            string data_with_redundancy = Divide(divident,divisor);
            printf("Sending %d's frame\n",x);
            channel.total_number_of_transmission+=1;
            channel.datagrp.insert(channel.datagrp.begin(),data_with_redundancy);
            Sendingtimes[x]=gettime();
            ImposeProbableError(channel.datagrp[0]);
        }
            channel.makeBusy();
            sleep(rand()%3+1);
            channel.makeReceiveable();
            while(1){
                sleep(1);
                if(channel.failed_bit!=-1){
                    int fb=channel.failed_bit;
                    channel.failed_bit=-1;
                    return fb;
                }
                else{

                    return -1;
                }
            }
        }
        }
    }


    int SendSelectiveRepeat(int i, Channel &channel, int windowsize){
        while(1){
        channel.datagrp.clear();
        if(channel.isSendable()){
        channel.acknos.clear();
        for(int x=0;x<channel.failed_bits.size();x++){
            int idx= channel.failed_bits[x];
            string divident = senderFrames[idx]+"0000";
            string divisor = "10001";
            string data_with_redundancy = Divide(divident,divisor);
            printf("Sending %d's frame\n",idx);
            channel.total_number_of_transmission+=1;
            channel.ordered_datagrp.insert(channel.ordered_datagrp.begin(),make_pair(idx,data_with_redundancy));
            Sendingtimes[idx]=gettime();
            ImposeProbableError(channel.ordered_datagrp[0].second);
        }
        channel.failed_bits.clear();

        for(int x=i ; x< min(i+windowsize, (int)senderFrames.size()); x++){
            string divident = senderFrames[x]+"0000";
            string divisor = "10001";
            string data_with_redundancy = Divide(divident,divisor);
            printf("Sending %d's frame\n",x);
            channel.total_number_of_transmission+=1;
            channel.ordered_datagrp.insert(channel.ordered_datagrp.begin(),make_pair(x,data_with_redundancy));
            Sendingtimes[x]=gettime();
            ImposeProbableError(channel.ordered_datagrp[0].second);
        }
            channel.makeBusy();
            sleep(rand()%3+1);
            channel.makeReceiveable();
            while(1){
                sleep(1);
                if(channel.failed_bit!=-1){
                    int fb=channel.failed_bit;
                    channel.failed_bit=-1;
                    return -1;
                }
                else{
                    return -1;
                }
            }
        }
        }
    }
    
};
int countzeros(string divident){
    int c=0;
    for(int i=0;i<divident.size();i++){
        if(divident[i]=='0')
        c++;
    }
    return c;
}

class Receiver{
public:
    int framesize;
    int received;
    vector<string> receiverFrames;
    int Receive(int i, Channel& channel){
            while(1){
            if(channel.isReceiveable()){
                bool allzeros=false;
                string divident =channel.data;
                Divide(divident,"10001");
                if(countzeros(divident)==divident.length()){
                    allzeros = true;
                }
                receiverFrames[i]=channel.data.substr(0,channel.data.size()-4);
                printf("Receiver gets = %s\n",receiverFrames[i].c_str());
                return SendAck(i,channel,allzeros);
            }
        }
      
    }

    bool ReceiveGoBackN(int i, Channel& channel, int windowsize){
          while(1){
        if(channel.isReceiveable()){
            while(channel.datagrp.size()){
                bool allzeros=false;
                string divident =channel.datagrp[channel.datagrp.size()-1];
                Divide(divident,"10001");
                if(countzeros(divident)==divident.length()){
                    allzeros = true;
                }
                receiverFrames[received]=channel.datagrp[channel.datagrp.size()-1].substr(0,channel.datagrp[channel.datagrp.size()-1].size()-4);
                channel.datagrp.pop_back();
                printf("Receiver gets = %s\n",receiverFrames[received].c_str());
                int ack= SendAck(received,channel,allzeros,0);
                if(ack!=-1){
                    channel.failed_bit=ack;
                    return false;
                }
                else{
                    received++;
                }
            }
            return true;
            
        }
    }
    }

        bool ReceiveSelectiveRepeat(int i, Channel& channel, int windowsize){
          while(1){
        if(channel.isReceiveable()){
            while(channel.ordered_datagrp.size()){
                bool allzeros=false;
                string divident =channel.ordered_datagrp[channel.ordered_datagrp.size()-1].second;
                Divide(divident,"10001");
                if(countzeros(divident)==divident.length()){
                    allzeros = true;
                }
                int index=channel.ordered_datagrp[channel.ordered_datagrp.size()-1].first;
                string data2rcv=channel.ordered_datagrp[channel.ordered_datagrp.size()-1].second;
                receiverFrames[index]=data2rcv.substr(0,data2rcv.size()-4);
                channel.ordered_datagrp.pop_back();
                printf("Receiver gets = %s\n",receiverFrames[index].c_str());
                int ack= SendAck(index,channel,allzeros,0);
                if(ack!=-1){
                    channel.failed_bits.push_back(ack);
                    return true;
                }
                else{
                    received++;
                }
            }
            return true;
            
        }
    }
    }

   int SendAck(int i , Channel &channel, bool allzeros, int goback){
        if(!allzeros){
            printf("%d's ERROR detected\n\n",i);
            channel.freeChannel();
            return i;

        }
        int p = rand()%4;
       // cout<<"Random generated = "<<p<<endl;
        if(p==0){
            
            printf("%d's ACK SENDING FAILED\n\n",i);
            channel.freeChannel();
            return i;
        }
        else{
            channel.acknos.push_back(i);
            channel.freeChannel();
            printf("%d's ACK RECEIVED\n\n",i);
            Receivingtimes[i]=gettime();
            if(i==0)
                firstpacketreceived=Receivingtimes[i];
            else if(i==receiverFrames.size()-1)
                lastpacketreceived=Receivingtimes[i];
            return -1;
        }
    }

    bool SendAck(int i , Channel &channel, bool allzeros){
        if(!allzeros){

            printf("%d's ERROR detected\n\n",i);
            channel.freeChannel();
            return false;

        }
        int p = rand()%4;
        //cout<<"Random generated = "<<p<<endl;
        if(p==0){
            
            printf("%d's ACK SENDING FAILED\n\n",i);
            channel.freeChannel();
            return false;
        }
        else{
            channel.acked=i;
            channel.freeChannel();
             printf("%d's ACK RECEIVED\n\n",i);
             Receivingtimes[i]=gettime();
            if(i==0)
                firstpacketreceived=Receivingtimes[i];
            else if(i==receiverFrames.size()-1)
                lastpacketreceived=Receivingtimes[i];
            return true;
        }
    }
};

Sender s;
Receiver r;
Channel c;

void Sending(){
    time_t t;
    time(&t);

    for(int i=0;i<s.senderFrames.size();i++){
        if(s.Send(i,c)){
            time_t now;
            time(&now);
            t=now;
        }
        else{
            c.freeChannel();
            i--;
        }
    }
}

void Receiving (){
    r.received=0;
    for(int i=0;i<r.receiverFrames.size();i++){
        if(r.Receive(i,c)){

        }
        else{
            i--;
        }
        //r.received++;
    }
}

void SendingGoBackN(int windowsize){
    //int no_of_windows = s.senderFrames.size()/windowsize;
    int i=0;
    while(i<s.senderFrames.size()){
        int dect=s.SendGoBackN(i,c,windowsize);
        if(dect==-1){
            i+=windowsize;
        }
        else{
            i=dect;
        }
    }
}

void ReceivingGoBackN(int windowsize){
    r.received=0;
    int i=0;
    while(r.received<r.receiverFrames.size()){
        if(r.ReceiveGoBackN(i,c,windowsize)){

        }
        else{
           
        }
    }
}

void SendingSelectiveRepeat(int windowsize){
    //int no_of_windows = s.senderFrames.size()/windowsize;
    int i=0;
    while(i<s.senderFrames.size() || c.failed_bits.size()){
        int dect=s.SendSelectiveRepeat(i,c,windowsize);
        if(dect==-1){
            i+=windowsize;
        }
        else{
            i=dect;
        }
    }
}

void ReceivingSelectiveRepeat(int windowsize){
    r.received=0;
    int i=0;
    while(r.received<r.receiverFrames.size()){
        if(r.ReceiveSelectiveRepeat(i,c,windowsize)){

        }
        else{
           
        }
    }
}

int main(int argc, char const *argv[])
{
    cout<<endl<<endl<<"STOP AND WAIT"<<endl<<endl;
    srand(time(0));
    cout<<"Enter no of frames:";
    int f;
    cin>>f;

    s.framesize=f;
    r.framesize=f;
    r.receiverFrames.resize(f,"");
    c.Initiate();
    c.failed_bit=-1;
c.total_number_of_transmission=0;
Sendingtimes.resize(f,0);
Receivingtimes.resize(f,0);

    fstream fr;
    fr.open("in.txt");

    for(int i=0;i<f;i++){
        string str ;
        //cout<<"Enter the "<<i<<"th frame = ";
        fr>>str;
        s.senderFrames.push_back(str);
    }
    cout<<endl<<"Reading of frames from file is completed  "<<endl<<endl;
    
     time_t start=gettime();
     thread th1(Sending);
     thread th2(Receiving);
     th1.join();
     th2.join();
     time_t end = gettime();
     double avgrtt=0;
    cout<<endl<<endl;
    for(int i=0;i<f;i++){
        avgrtt+=(Receivingtimes[i]-Sendingtimes[i]);
//        cout<<"Sent at = "<<Sendingtimes[i]<<"\tACK Received at = "<<Receivingtimes[i]<<"\tRTT= "<<(Receivingtimes[i]-Sendingtimes[i])<<endl;
          cout<<"Frame no "<<i<<" "<<"\tRound Trip= "<<(Receivingtimes[i]-Sendingtimes[i])<<endl;
    }
    

/*    for(int i=0;i<f;i++){
        string str ;
        cout<<"Value in the "<<i<<"th frame = "<<r.receiverFrames[i]<<endl;
    }*/
    cout<<"Receiver Throughput = "<<f/(1.0*(lastpacketreceived-firstpacketreceived))<<endl;
    cout<<"Utilization percentage = "<<f/(1.0*c.total_number_of_transmission)<<endl;
    cout<<"Bandwidth delay prod = "<<(avgrtt/11)*(f*11.0/(end-start))<<endl;


c.total_number_of_transmission=0;
Sendingtimes.resize(f,0);
Receivingtimes.resize(f,0);
    
    cout<<endl<<endl<<"GO BACK AND N"<<endl<<endl;
    int windowsize;
    cout<<"Enter the window size  :";
    cin>>windowsize;
    start = gettime();
    thread th3(SendingGoBackN,windowsize);
    thread th4(ReceivingGoBackN,windowsize);
    th3.join();
     th4.join();
    end = gettime();
/*     for(int i=0;i<f;i++){
        string str ;
        cout<<"Value in the "<<i<<"th frame = "<<r.receiverFrames[i]<<endl;
    }*/
    avgrtt=0;
    cout<<endl<<endl;
    for(int i=0;i<f;i++){
        avgrtt+=(Receivingtimes[i]-Sendingtimes[i]);
    //    cout<<"Sent at = "<<Sendingtimes[i]<<"\tACK Received at = "<<Receivingtimes[i]<<"\tRTT= "<<(Receivingtimes[i]-Sendingtimes[i])<<endl;
          cout<<"Frame no "<<i<<" "<<"\tRound Trip= "<<(Receivingtimes[i]-Sendingtimes[i])<<endl;
    }
    cout<<"Bandwidth delay prod = "<<(avgrtt/11)*(f*11.0/(end-start))<<endl;
    cout<<"Receiver Throughput = "<<f/(1.0*(lastpacketreceived-firstpacketreceived))<<endl;
    cout<<"Utilization percentage = "<<f/(1.0*c.total_number_of_transmission)<<endl;

c.total_number_of_transmission=0;
Sendingtimes.resize(f,0);
Receivingtimes.resize(f,0);
     
     cout<<endl<<endl<<"SELECTIVE REPEAT ARQ"<<endl<<endl;
    //int windowsize;
    cout<<"Enter the window size  :";
    cin>>windowsize;
    start=gettime();
    thread th5(SendingSelectiveRepeat,windowsize);
    thread th6(ReceivingSelectiveRepeat,windowsize);
    th5.join();
    th6.join();
    end=gettime();
    

    cout<<endl<<endl;
    avgrtt=0;
    for(int i=0;i<f;i++){
        avgrtt+=(Receivingtimes[i]-Sendingtimes[i]);
    
        cout<<"Frame no "<<i<<" "<<"\tRound Trip= "<<(Receivingtimes[i]-Sendingtimes[i])<<endl;
    }
        cout<<"Bandwidth delay prod = "<<(avgrtt/11)*(f*11.0/(end-start))<<endl;
    cout<<"Receiver Throughput = "<<f/(1.0*(*max_element(Receivingtimes.begin(),Receivingtimes.end())-*min_element(Receivingtimes.begin(),Receivingtimes.end())))<<endl;
        cout<<"Utilization percentage = "<<f/(1.0*c.total_number_of_transmission)<<endl;


    return 0;
}