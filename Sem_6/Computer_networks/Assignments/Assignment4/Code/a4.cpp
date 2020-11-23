#include <bits/stdc++.h>
using namespace std;

int flip(int x)
{
	if(x==-1)
		return 1;
	else
		return -1;
}

int main()
{
	int senders;
	cout << "Enter number of senders: ";
	cin >> senders;
	int n_ceil = ceil(log(senders)/log(2));
	int m = pow(2,n_ceil);
	int x = 1;
	int t = 0;
	int wCode[100][100];
	wCode[0][0] = 1;
	while(pow(2,t) != m)
	{
		for(int row = 0; row < x; row++)
		{
			for(int col =0; col < x; col++)
			{
				wCode[row + x][col] = wCode[row][col];
				wCode[row][col + x] = wCode[row][col];
				wCode[row + x][col + x] = flip(wCode[row][col]);
			}
		}
		t++;
		x *= 2;
	}
	cout<<"\nThe walsh codes for the sender are: "<<endl;
	for(int i = 0; i < senders; i++)
	{
		cout << "Sender " << i << ": [";
		for(int j = 0;j < m; j++) {
			cout << wCode[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;
	cout << "Enter data bit(0 or 1) for each sender(-1 for no data)" << endl;
	int data[senders];
	for(int i = 0; i < senders; i++)
	{
		cout << "Sender " << i << ": ";
		int bit;
		cin >> bit;
		/* Encode 1 bit as 1, 0 bit as -1 and no data as 0 */
		if(bit == 1)
			data[i] = 1;
		else if(bit == 0)
			data[i] =-1;
		else
			data[i] = 0;
	}

	int sum[m];
	for(int i = 0; i < m; i++)
		sum[i] = 0;

	cout << "\nThe resultant codes after multiplying with data are:\n";
	for(int i = 0; i < senders; i++)
	{
		cout << "Sender " << i << ": [";
		for(int j = 0; j < m; j++)
		{
			cout << (data[i] * wCode[i][j]) << " ";
			sum[j] += data[i] * wCode[i][j];
		}
		cout << "]\n";
	}
	cout << endl;

	cout << "The resultant code after multiplexing: [";
	for(int i = 0; i < m; i++)
		cout << sum[i] << " ";

	cout << "]" << endl << endl;
	
	cout << "After demultiplexing..... " << endl;
	while(1)
	{
		int sender = 0;
		cout<<"CHOICE"<<endl;
		cout<<"1.Sender"<<endl;
		cout<<"2.Exit"<<endl;
		cout<<"Enter choice:";
		int choice;
		cin >> choice;
		if(choice==1)
		{
			cout<<"Enter sender number:";
			cin>>sender;
			int s = 0;
			for(int i = 0; i < m; i++)
			{
				s += (sum[i] * wCode[sender][i]);
			}
			int ans = s / m;
			if(ans == -1)
				cout << "Sender sent 0" << endl << endl;
			else if(ans == 0)
				cout << "Sender sent no data" << endl << endl;
			else
				cout << "Sender sent "<< 1 <<endl << endl;
		}
		else if(choice == 2)
			break;
	}
}