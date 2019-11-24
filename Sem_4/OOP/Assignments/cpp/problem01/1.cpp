#include<bits/stdc++.h>
using namespace std;

class TIME
{
	int h;
	int m;
	int s;
	
	public:
		
		void convert_to_12()
		{
			string str;
			cout<<"Enter time in 24 hour(HH:MM:SS) format"<<endl;
			cin>>str;
			
			h=atoi(str.substr(0,2).c_str());
			m=atoi(str.substr(3,2).c_str());
			s=atoi(str.substr(6,2).c_str());
			
			if((h>23)||(h<0)||(m>59)||(m<0)||(s>59)||(s<0))
			{
				cout<<"Invalid time"<<endl;
				return;
			}
				
			
			cout<<"Time in 12 hour format is:"<<endl;
			if(h==0)
			{
				printf("12:%02d:%02d AM\n",m,s);
			}
			if(h>=1&&h<=11)
			{
				printf("%02d:%02d:%02d AM\n",h,m,s);
			}
			if(h==12)
			{
				printf("12:%02d:%02d PM\n",m,s);
			}
			else if(h>=13&&h<=23)
			{
				printf("%02d:%02d:%02d PM\n",h-12,m,s);
			}
		}
		
		void convert_to_24()
		{
			string str;
			cout<<"Enter time in 12 hour(HH:MM:SSAM/PM) format"<<endl;
			cin>>str;
			h=atoi(str.substr(0,2).c_str());
			m=atoi(str.substr(3,2).c_str());
			s=atoi(str.substr(6,2).c_str());
			if(str.substr(8,2)=="AM"&&h==12)
				h=0;
			if(str.substr(8,2)=="PM"&&h!=12)
				h+=12;
			if((h>23)||(h<0)||(m>59)||(m<0)||(s>59)||(s<0))
			{
				cout<<"Invalid time"<<endl;
				return;
			}
			cout<<"Time in 24 hour format is:"<<endl;
			printf("%02d:%02d:%02d\n",h,m,s);
		}
		
		void add_minutes()
		{
			int min;
			cout<<"Enter minutes to be added: ";
			cin>>min;
			h=(h+min/60)%24;
			min=min%60;
			if(m+min>=60)
			{
				h=(h+1)%24;
				m=(m+min)-60;
			}
			
			cout<<"Time in 24 hour format is:"<<endl;
			printf("%02d:%02d:%02d\n",h,m,s);
		}
};

int main()
{
	TIME t;
	char ch='y';
	while(ch=='y')
	{
		int choice;
		cout<<"Enter choice:\n1.Convert from 12 to 24 hour\n2.Convert from 24 to 12 hour\n3.Add minutes\n";
		cin>>choice;
		switch(choice)
		{
			case 1: t.convert_to_24();
					break;
			case 2: t.convert_to_12();
					break;
			case 3: t.add_minutes();
					break;
		}
		cout<<"Want choices again?(y/n)"<<endl;
		cin>>ch;
	}
}
