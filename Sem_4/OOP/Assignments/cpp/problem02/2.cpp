#include<bits/stdc++.h>
#include<string>
using namespace std;

class COMPLEX
{
	int real;
	int img;
	
	public:
		void getdata()
		{
			string s;
			cin>>s;
			int l=s.length();
			int pos=s.find("i");
			//CASE 1: Complex number is of type i
			if(s=="i")
			{
				real=0;
				img=1;
				return;
			}
			//CASE 2: Complex number is of type -i
			if(s=="-i")
			{
				real=0;
				img=-1;
				return;
			}
			//CASE 3: Complex number is of type ib
			if(pos==0)
			{
				int f=0;
				for(int i=1;i<l;i++)
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					real=0;
					img=atoi(s.substr(1,l-1).c_str());
					return;
				}
			}
			//CASE 4: Complex number is of type -ib
			if(pos==1&&s[0]=='-')
			{
				int f=0;
				for(int i=2;i<l;i++)
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					real=0;
					img=-atoi(s.substr(2,l-2).c_str());
					return;
				}
			}
			//CASE 5: Complex number is of type -bi
			if(pos==l-1&&s[0]=='-')
			{
				int f=0;
				for(int i=1;i<l-1;i++)
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					real=0;
					img=-atoi(s.substr(1,l-2).c_str());
					return;
				}
			}
			//CASE 6: Complex number is of type bi
			if(pos==l-1&&s[0]!='-')
			{
				int f=0;
				for(int i=0;i<l-1;i++)
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					real=0;
					img=atoi(s.substr(0,l-1).c_str());
					return;
				}
			}
			//CASE 7: Complex number is of type a
			if(pos==string::npos)
			{
				int f=0;
				for(int i=0;i<l;i++)
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					img=0;
					real=atoi(s.c_str());
					return;
				}
			}
			//CASE 8: Complex number is of type -a
			if(pos==string::npos&&s[0]=='-')
			{
				int f=0;
				for(int i=1;i<l;i++)
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					img=0;
					real=atoi(s.c_str());
					return;
				}
			}
			//CASE 9: Complex number is of type a+bi,a-bi,a+i,a-i
			if(pos==l-1&&s[0]!='-')
			{
				int f=0,i=0;
				while(s[i]!='+'&&s[i]!='-')
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
						i++;
				}
				int p=i,k=0;
				for(i=p+1;i<l-1;i++)
				{
					if(s[i]<'0' || s[i]>'9')
					{
						k=1;
						break;
					}
				}
				if(f==0&&k==0)
				{
					real=atoi(s.substr(0,p).c_str());
					if(p+1==l-1)
					{
						if(s[p]=='-')
							img=-1;
						else
							img=1;
					}
					else
						img=atoi(s.substr(p,l-p).c_str());
					return;
				}
			}
			//CASE 9: Complex number is of type -a+bi,-a-bi,-a+i,-a-i
			if(pos==l-1&&s[0]=='-')
			{
				int f=0,i=1;
				while(s[i]!='+'&&s[i]!='-')
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
						i++;
				}
				int p=i,k=0;
				for(i=p+1;i<l-1;i++)
				{
					if(s[i]<'0' || s[i]>'9')
					{
						k=1;
						break;
					}
				}
				if(f==0&&k==0)
				{
					real=atoi(s.substr(0,p).c_str());
					if(p+1==l-1)
					{
						if(s[p]=='-')
							img=-1;
						else
							img=1;
					}
					else
						img=atoi(s.substr(p,l-p).c_str());
					return;
				}
			}
			//CASE 10: Complex number is of type a+ib,a-ib
			if(pos>0&&pos<l-1&&s[0]!='-')
			{
				int f=0,i=0;
				while(s[i]!='+'&&s[i]!='-')
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
						i++;
				}
				int p=i;
				if(s[p+1]!='i')
					f=1;
				for(i=p+2;i<l;i++)
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
				}
				
				if(f==0)
				{
					real=atoi(s.substr(0,p).c_str());
					if(s[p]=='-')
						img=-atoi(s.substr(p+2,l-p-2).c_str());
					else
						img=atoi(s.substr(p+2,l-p-2).c_str());
					return;
				}
			}
			//CASE 11: Complex number is of type -a+ib,-a-ib
			if(pos>0&&pos<l-1&&s[0]!='-')
			{
				int f=0,i=1;
				while(s[i]!='+'&&s[i]!='-')
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
						i++;
				}
				int p=i;
				if(s[p+1]!='i')
					f=1;
				for(i=p+2;i<l;i++)
				{
					if(s[i]<'0' || s[i]>'9')
					{
						f=1;
						break;
					}
				}
				
				if(f==0)
				{
					real=atoi(s.substr(0,p).c_str());
					if(s[p]=='-')
						img=-atoi(s.substr(p+2,l-p-2).c_str());
					else
						img=atoi(s.substr(p+2,l-p-2).c_str());
					return;
				}
			}
			real=0;
			img=0;
			cout<<"Invalid input"<<endl;
		}
		
		COMPLEX operator+(COMPLEX b)
		{
			COMPLEX c;
			c.real=real+b.real;
			c.img=img+b.img;
			return c;
		}
		
		COMPLEX operator-(COMPLEX b)
		{
			COMPLEX c;
			c.real=real-b.real;
			c.img=img-b.img;
			return c; 
		}
		
		friend ostream& operator<<(ostream&, COMPLEX);
		friend istream& operator>>(istream&, COMPLEX&);
};

ostream& operator<<(ostream &cout, COMPLEX c)
{
	cout<<c.real;
	if(c.img>=0)
		cout<<"+";
	cout<<c.img<<"i";
	return cout;
}

istream& operator>>(istream &cin, COMPLEX &c)
{
	c.getdata();
	return cin;
}
int main()
{
	COMPLEX c1,c2;
	cout<<"Enter Complex number C1: "<<endl;
	cin>>c1;
	int choice;
	char ch='y';
	while(ch=='y')
	{
		cout<<"Enter Complex number C2: "<<endl;
		cin>>c2;
		cout<<"Enter choice:\n 1. Addition\n 2. Subtraction\n";
		cin>>choice;
		switch(choice)
		{
			case 1: c1=c1+c2;
					cout<<"Sum is "<<c1<<endl;
					break;
			case 2: c1=c1-c2;
					cout<<"Difference is "<<c1<<endl;
					break;
		}
		
		cout<<"Want to enter more?(y/n)"<<endl;
		cin>>ch;
	}
	
}
