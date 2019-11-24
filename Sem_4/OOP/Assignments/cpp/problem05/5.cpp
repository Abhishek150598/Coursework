#include<iostream>
using namespace std;

class ARRAY
{
	private:
		int *arr;
		int size;
	
	public:
		ARRAY()
		{
			size=0;
			arr=NULL;	
		}
		
		ARRAY(int n,int val)
		{
			arr=new int[n];
			size=n;
			for(int i=0;i<n;i++)
			{
				arr[i]=val;
			}
		}
		
		ARRAY(ARRAY &a)
		{
			size=a.size;
			arr=new int[size];
			for(int i=0;i<size;i++)
			{
				arr[i]=a.arr[i];
			}
		}
		
		ARRAY(int a[], int n)
		{
			size=n;
			arr=new int[size];
			for(int i=0;i<size;i++)
			{
				arr[i]=a[i];
			}
		}
			
		ARRAY operator+(ARRAY a1)
		{
			ARRAY a2(size,0);
			for(int i=0;i<size;i++)
			{	
				a2.arr[i]=arr[i]+a1.arr[i];
			}
			return a2;
				
		}
	
		
		int operator[](int i)
		{
			return arr[i];
				
		}
		
		ARRAY operator*(int k)
		{
			ARRAY a2(size,0);
			for(int i=0;i<size;i++)
			{	
				a2.arr[i]=arr[i]*k;
			}
			return a2;
				
		}
		
		ARRAY printArray()
		{
			cout<<"The Array is: "<<endl;
			for(int i=0;i<size;i++)
			{	
				cout<<arr[i]<<" ";
			}	
		}
		friend ARRAY operator*(int, ARRAY);
};

ARRAY operator*(int k,ARRAY a)
{
	ARRAY a2(a.size,0);
	for(int i=0;i<a.size;i++)
	{	
		a2.arr[i]=a.arr[i]*k;
	}
	return a2;
}



void menu()
{	
	int ch,n,val,k;
	char s;
	int ar[1000];
	cout<<"Enter size of array: ";
	cin>>n;
	
	cout<<"Enter the elements of array A: ";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	ARRAY a(ar,n);

	cout<<"Enter the elements of array B: ";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	ARRAY b(ar,n);

	ARRAY c;
	
	cout<<"Enter choice:\n1. Add 2 arrays \n2. ith index of the array \n3. Multiply array with a constant\n";
	cin>>ch;
	switch(ch)
	{
		case 1:	c=a+b;
				c.printArray();
				break;
		case 2:	cout<<"Enter array name(A/B)?";
				cin>>s;
				cout<<"Enter the index :";
				int i;
				cin>>i;
				if(s=='A')
				{
					cout<<"The value at index"<<i<<" is "<<a[i];
				}
				else if(s=='B')
				{
					cout<<"The value at index"<<i<<" is "<<b[i];
				}
				break;	
		case 3:	cout<<"Enter array name(A/B)?";
				cin>>s;
				cout<<"Enter the constant :";
				cin>>k;
				if(s=='A')
				{
					c=a*k;
					c.printArray();
				}
				else if(s=='B')
				{
					c=k*b;
					c.printArray();
				}
				
				break;
	}
}



int main()
{
 	int ch;
	do
	{
		menu();
		cout<<"\n1.Enter more\n2.exit\n";
		cin>>ch;
	}
	while(ch==1);
}

