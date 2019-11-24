#include<bits/stdc++.h>
using namespace std;

class String
{
	private:
		char *arr;
		int size;
		int ref;
	public:
		
		String()
		{
			ref=1;
			size=0;
			arr=NULL;	
		}
		
		String(int n,char val)
		{
			ref=1;
			arr=new char[n];
			size=n;
			for(int i=0;i<n;i++)
			{
				arr[i]=val;
			}
		}
		
		String(String &a)
		{
			a.ref++;
			size=a.size;
			arr=new char[size];
			
			for(int i=0;i<size;i++)
			{
				arr[i]=a.arr[i];
			}
		}
		
		void show_ref()
		{
			cout<<"String reference="<<ref<<endl;
		}
		
		String(char a[], int n)
		{
			ref=1;
			size=n;
			arr=new char[size];
			for(int i=0;i<size;i++)
			{
				arr[i]=a[i];
			}
			
		}
			
		String operator+(String a1)
		{
			String a2(size+a1.size,'\0');
			for(int i=0;i<size;i++)
			{	
				a2.arr[i]=arr[i];
			}
			
			for(int i=size;i<a2.size;i++)
			{	
				a2.arr[i]=a1.arr[i-size];
			}
			return a2;
				
		}
		
		bool operator==(String a1)
		{
			if(strcmp(a1.arr,arr)==0)
				return true;
			else
				return false;
		}
	
		void printString()
		{
			cout<<"The String is: "<<endl;
			for(int i=0;i<size;i++)
			{	
				cout<<arr[i];
			}
			cout<<endl;	
		}
};


void menu()
{
	char str[100];
	int ch=1;
	gets(str);
	cout<<"Enter a string: ";
	gets(str);
	String s1(str,strlen(str));
	s1.show_ref();
	cout<<"Enter another string: ";
	gets(str);
	String s2(str,strlen(str));
	s2.show_ref();
	
	while(ch>=1&&ch<=3)
	{

	cout<<"Enter choice: \n1.Concatenate the strings \n2.Compare the strings\n3.Copy string\n";
	cin>>ch;
	String s3;

	switch(ch)
	{
		case 1:	s3=s1+s2;
				s3.printString();
				break;
		case 2: if(s1==s2)
					cout<<"The 2 strings are same"<<endl;
				else
					cout<<"The 2 strings are different"<<endl;
				break;	
		case 3: int p;
				cout<<"Enter the string to be copied: (1/2)";
				cin>>p;
				if(p==1)
				{
					String s4(s1);
					s1.show_ref();
				}
					
				else
				{
					String s4(s2);
					s2.show_ref();
				}	
				break;	
	}
	}
	return;
}
int main()
{
 	char ch='y';
 	while(ch=='y'||ch=='Y')
 	{
	 	menu();
	 	cout<<"Enter more?(Y/N)"<<endl;
	 	cin>>ch;
	}
 	
}

