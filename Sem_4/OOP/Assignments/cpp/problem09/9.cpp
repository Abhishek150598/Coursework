#include<bits/stdc++.h>
using namespace std;


class date
{
	private:
		int day,month,year;
	public:
		void set_current_date()
		{
			time_t now=time(0);
			tm *ltm=localtime(&now);
			day=ltm->tm_mday;
			month=1+ltm->tm_mon;
			year=1900+ltm->tm_year;
		}
		void show_date()
		{
			cout<<day<<"/"<<month<<"/"<<year;
		}
		friend ostream & operator <<(ostream &out,date d);
		friend istream &operator>>(istream &in,date d);	
};
ostream & operator <<(ostream &out,date d)
{
	out<<d.day<<"/"<<d.month<<"/"<<d.year;
	return out;
}	
istream &operator>>(istream &in,date d)
{
	in>>d.day>>d.month>>d.year;
	return in;
}


class TRANSACTION;

class USER
{
	private:
		static int count;
		int acc_no;
		string username;
		string password;
		float balance;
		date d;
	public:
		void showdata();
		int get_acc_no();
		string new_user();
		friend TRANSACTION;
};

int USER::count=0;

int USER::get_acc_no()
{
	return acc_no;
}
void USER::showdata()
{
	cout<<"Account number: "<<acc_no<<endl;
	cout<<"User name: "<<username<<endl;
	cout<<"Current balance: "<<balance<<endl;
	cout<<"Date of last updation: "<<d<<endl;
}

string USER::new_user()
{
	string p;
	cout<<"Enter user name: "<<endl;
	cin>>username;
	cout<<"Enter password: "<<endl;
	cin>>password;
	cout<<"User registered with account number: "<<++count<<endl;
	acc_no=count;
	return password;
}


class TRANSACTION
{
	private:
		static int trno;
		int acc_no;
		date d;
		bool type;
		float amt;
	public:
		bool withdraw(USER&);
		bool deposit(USER&);
		void show_transaction();	
};

int TRANSACTION::trno=0;


void TRANSACTION::show_transaction()
{
	cout<<acc_no<<"\t\t"<<d<<"\t\t";
	if(type==true)
	{
		cout<<"Withdrawn ";
	}
	else
	{
		cout<<"Deposited ";
	}
	cout<<amt<<endl;
}

bool TRANSACTION::withdraw(USER &u)
{
	
	type=true;
	acc_no=u.acc_no;
	d.set_current_date();
	u.d.set_current_date();
	cout<<"Enter amount to be withdrawn: ";
	cin>>amt;
	if(u.balance<amt)
	{
		cout<<"Amount cannot be withdrawn due to insufficient balance\n";
		return false;
	}
	else if(amt<0)
	{
		cout<<"Negative amount cannot be withdrawn\n";
		return false;
	}
	else
	{
		u.balance-=amt;
		cout<<"Transaction successful\n";
		trno++;
		return true;
	}
}

bool TRANSACTION::deposit(USER &u)
{
	type=false;
	acc_no=u.acc_no;
	d.set_current_date();
	u.d.set_current_date();
	cout<<"Enter amount to be deposited: ";
	cin>>amt;
	if(amt<0)
	{
		cout<<"Negative amount cannot be deposited\n";
		return false;
	}
	else
	{
		u.balance+=amt;
		cout<<"Transaction successful\n";
		trno++;
		return true;
	}

}

USER u[100];
TRANSACTION t[100];
map <int,string> umap;
int i=1;
int k=0;

void menu()
{
	int ch;
	string pw,j;
	int accno;
	cout<<"\nEnter choice:\n1. New user\n2. Withdraw amount\n3. Deposit amount\n4. View account details\n5. View transaction history\n";
	cin>>ch;
	switch(ch)
	{
		case 1:	pw=u[i].new_user();
				umap[i]=pw;
				i++;
				break;
		case 2: cout<<"Enter acc_no: "<<endl;
				cin>>accno;
				cout<<"Enter password: "<<endl;
				cin>>pw;
				j=umap[accno];
				if(j!=pw)
				{
					cout<<"Invalid credentials :( "<<endl;
				}
					
				else
				{
					if(t[k].withdraw(u[accno]))
						k++;
				}
					
				break;
		case 3: cout<<"Enter acc_no: "<<endl;
				cin>>accno;
				cout<<"Enter password: "<<endl;
				cin>>pw;
				j=umap[accno];
				if(j!=pw)
				{
					cout<<"Invalid credentials :( "<<endl;
				}
					
				else
				{
					if(t[k].deposit(u[accno]))
						k++;
				}
					
				break;
		case 4: cout<<"Enter acc_no: "<<endl;
				cin>>accno;
				cout<<"Enter password: "<<endl;
				cin>>pw;
				j=umap[accno];
				if(j!=pw)
				{
					cout<<"Invalid credentials :( "<<endl;
				}
					
				else
				{
					u[accno].showdata();
				}
					
				break;
		case 5:	for(int loop=0;loop<k;loop++)
				{
					t[loop].show_transaction();
				}
				break;
	}
}

int main()
{
	char ch='y';
	srand(time(NULL));
	while(ch=='Y'||ch=='y')
	{
			menu();
			cout<<"Enter more?(Y/N)";
			cin>>ch;
	}
	
}
