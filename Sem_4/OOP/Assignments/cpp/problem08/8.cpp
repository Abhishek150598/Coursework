#include<bits/stdc++.h>
using namespace std;

class TOLLTAX
{
	static int no_of_cars;
	static float amount_collected;
	
	public:
		static void receive_toll();
		static void display_cars();
		static void display_amt();
		static void display_fare();
};

int TOLLTAX::no_of_cars=0;
float TOLLTAX::amount_collected=0.0;

void TOLLTAX::receive_toll()
{
	int n;
	cout<<"Enter mode of payment:\n1.Instant\n2.Prepaid\n";
	cin>>n;
	cout<<"Enter vehicle type:\n";
	display_fare();
	cin>>n;
	no_of_cars++;
	switch(n)
	{
		case 1: amount_collected+=45.0;
				break;
		case 2: amount_collected+=70.0;
				break;
		case 3: amount_collected+=150.0;
				break;
		case 4: amount_collected+=165.0;
				break;
		case 5: amount_collected+=235.0;
				break;
		case 6: amount_collected+=235.0;
				break;
		case 7: amount_collected+=290.0;
				break;
	}
	cout<<"Transaction succesful"<<endl;
}

void TOLLTAX::display_fare()
{
	cout<<"1\tCar/Jeep/Van\t\t\t\tRs 45"<<endl;
	cout<<"2\tLight Commercial vehicles\t\tRs 70"<<endl;
	cout<<"3\tBus/Truck\t\t\t\tRs 150"<<endl;
	cout<<"4\tUpto 3 Axle Vehicle\t\t\tRs 165"<<endl;
	cout<<"5\t4 to 6 Axle\t\t\t\tRs 235"<<endl;
	cout<<"6\tHCM/EME\t\t\t\t\tRs 235"<<endl;
	cout<<"7\t7 or more Axle\t\t\t\tRs 290"<<endl;
}

void TOLLTAX::display_amt()
{
	cout<<"Total amount collected is: "<<amount_collected<<endl;
}

void TOLLTAX::display_cars()
{
	cout<<"Total number of vehicles passed: "<<no_of_cars<<endl;
}

int main()
{
	int ch;
	cout<<"Enter choice:\n1. Receive tax:\n2. Display tax chart\n3. Display no of vehicles passed\n4. Display total amount collected.\n";
	cin>>ch;
	while(ch>=1&&ch<=4)
	{
		switch(ch)
		{
			case 1: TOLLTAX::receive_toll();
					break;
			case 2: TOLLTAX::display_fare();
					break;
			case 3: TOLLTAX::display_cars();
					break;
			case 4: TOLLTAX::display_amt();
					break;
		}
		
		cout<<"\nEnter choice:\n1. Receive tax:\n2. Display tax chart\n3. Display no of vehicles passed\n4. Display total amount collected.\n";
		cin>>ch;
	}
}
	
	
	
	
	
