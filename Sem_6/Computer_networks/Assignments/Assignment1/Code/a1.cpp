#include <bits/stdc++.h>
using namespace std;

// Function to implement LRC encoding scheme
void lrc_encode(int no_of_frames, bitset<8>* b)
{
	ofstream fout;
	fout.open("lrc_op.txt", ios::out);

	bitset<8> new_frame = 0;
	for(int i = 0; i < no_of_frames; i++)
	{
		fout << b[i];
		new_frame ^= b[i];
	}

	fout << new_frame;
	fout.close();
}

// Function to implement VRC encoding scheme
void vrc_encode(int no_of_frames, bitset<8>* b)
{
	ofstream fout;
	fout.open("vrc_op.txt", ios::out);

	for(int i = 0; i < no_of_frames; i++)
	{
		bitset<1> new_bit = b[i].count() % 2;
		fout << b[i];
		fout << new_bit;	
	}

	fout.close();
}

bitset<8> checksum_calculate(bitset<8>* b, int no_of_frames)
{
	int sum = 0;
	for(int i = 0; i < no_of_frames; i++)
	{
		int val = b[i].to_ulong();
		sum += val;
		int sum1 = sum & ((1<<8)-1);
		int sum2 = sum>>8;
		sum = sum1 + sum2;
	}
	
	
	bitset<8> checksum = ~(bitset<8>)(sum);	
	return checksum;
}

void checksum_encode(int no_of_frames, bitset<8>* b)
{
	
	ofstream fout;
	fout.open("checksum_op.txt", ios::out);

	for(int i = 0; i < no_of_frames; i++)
	{
		fout << b[i];
	}
	
	bitset<8> checksum = checksum_calculate(b, no_of_frames);
	fout << checksum;
	fout.close();
}

bitset<12> division(bitset<12> msg)
{
	bitset<12> temp = msg;
	bitset<5> gen(string("10011"));
	for(int i = 11; i >= 4; i--)
	{

		if(temp[i] == 1)
		{
			for(int j = 4, k = i; j >= 0; j--, k--)
                temp[k] = temp[k] ^ gen[j];
             
		}
	}
	
	bitset<12> rem = temp & (bitset<12>)((1<<4)-1);
	return rem;
	
}

void crc_encode(int no_of_frames, bitset<8>* b)
{

	ofstream fout;
	fout.open("crc_op.txt", ios::out);

	for(int i = 0; i < no_of_frames; i++)
	{
		bitset<12> msg = (b[i].to_ulong())<<4;
		bitset<12> rem = division(msg);
		msg = msg | rem;
		fout << msg;
	}

	fout.close();
}

void read_frames(string filename, bitset<8>* b, int* frames)
{
	ifstream fin;
	fin.open(filename, ios::in);

	int i = 0;
	fin >> b[i];
	while(!fin.eof())
	{	
		i++;
		fin >> b[i];
	}
	*frames = i;
	fin.close();
}

void checksum_decode()
{
	bitset<8> b[100] = {0};
	int no_of_frames;
	read_frames("checksum_op.txt", b, &no_of_frames);

	bitset<8> checksum = checksum_calculate(b, no_of_frames);

	if(checksum == 0){
		cout << "Checksum: No error detected" << endl;
	}
	else
	{
		cout << "Checksum: Error detected" << endl;
	}
}

void lrc_decode()
{
	bitset<8> b[100] = {0};
	int no_of_frames;
	read_frames("lrc_op.txt", b, &no_of_frames);
	
	//Calculate syndrome
	bitset<8> syndrome = 0;
	for(int i = 0; i < no_of_frames; i++)
	{
		syndrome ^= b[i];
	}

	if(syndrome == 0)
	{
		cout << "LRC: No error detected" << endl;
	}
	else
	{
		cout << "LRC: Error detected" << endl;
	}

}
		
void vrc_decode()
{
	ifstream fin;
	fin.open("vrc_op.txt", ios::in);
	bitset<9> b[100] = {0}; 

	//Read frames from file
	int i = 0;
	fin >> b[i];
	while(!fin.eof())
	{	
		i++;
		fin >> b[i];
	}
	int no_of_frames = i;
	fin.close();

	//Calculate syndrome
	bitset<1> syndrome = 0;
	for(i = 0; i < no_of_frames; i++)
	{
		syndrome = b[i].count() % 2;
		if(syndrome == 1)
		{
			cout << "VRC: Error detected" << endl;
			return;
		}
	}

	if(syndrome == 0)
		cout << "VRC: No error detected" << endl;
}

void crc_decode()
{
	ifstream fin;
	fin.open("crc_op.txt", ios::in);
	bitset<12> b[100] = {0}; 

	//Read frames from file
	int i = 0;
	fin >> b[i];
	while(!fin.eof())
	{	
		i++;
		fin >> b[i];
	}
	int no_of_frames = i;
	fin.close();

	for(i = 0; i < no_of_frames; i++)
	{
		bitset<12> rem = division(b[i]);
		if(rem != 0)
		{
			cout << "CRC: Error detected" << endl;
			return;
		}
	}

	cout << "CRC: No error detected" << endl;
}

void error_generator(int k, int* error_pos)
{
	string files[] = {"lrc_op.txt", "vrc_op.txt", "checksum_op.txt", "crc_op.txt"};
	srand(time(NULL));
	for(int i = 0; i < 4; i++)
	{
		ifstream fin;
		fin.open(files[i], ios::in);
		string stream;
		fin >> stream;
		fin.close();

		for(int j = 0; j < k; j++)
		{	
			int pos = error_pos[j];
			if(stream[pos] == '0') stream[pos] = '1';
			else stream[pos] = '0';
		}
		ofstream fout;
		fout.open(files[i], ios::out);
		fout << stream;
		fout.close();
	}
}

void inject_errors(int no_of_frames)
{

	int errors;
	
	cout << "Enter number of erroneous bits: " << endl;
	cin >> errors;
	if(errors < 0 || errors > no_of_frames)
	{
		cout << "Invalid input" << endl;
		return;
	}
	else if(errors != 0)
	{
		int ch, error_pos[100];
		cout << "Inject errors:\n1. Manually\n2. Randomly\n";
		cin >> ch;
		if(ch == 1)
		{
			cout << "Enter error positions:";
			for(int i = 0; i < errors; i++)
			{
				cin >> error_pos[i];
			}
		}
		else if(ch == 2)
		{
			for(int i = 0; i < errors; i++)
			{
				error_pos[i] = rand() % (8 * no_of_frames);
			}
			
		}
		else
		{
			cout << "Invalid choice" << endl;
			return;
		}
		error_generator(errors, error_pos);

	}
}

int main(int argc, char** argv)
{

	// Reading from input file and store as 8-bit frames
	bitset<8> b[100] = {0};
	int no_of_frames;
	read_frames(argv[1], b, &no_of_frames);

	
	srand(time(NULL));

	// Calling functions for the 4 encoding schemes
	lrc_encode(no_of_frames, b);
	vrc_encode(no_of_frames, b);
	checksum_encode(no_of_frames, b);
	crc_encode(no_of_frames, b);

	// Calling error generating function
	inject_errors(no_of_frames);
	
	// Calling functions for the 4 decoding schemes
	lrc_decode();
	vrc_decode();
	checksum_decode();
	crc_decode();	

	cout << endl;
	
}