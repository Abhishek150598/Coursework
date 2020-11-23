#include<bits/stdc++.h>
#include "get_type.h"
using namespace std;
char delimiters[] = {' ', '\n', '\t', '*', ',', '>', '<', '=', '(', ')', ';'};
int dsize = 11;

class Token
{
	private:
		static int count;
		int token_id;
		string lexeme;
		string token_type;
		int rowno;
		int colno;

	public:
		Token(string l, int r, int c)
		{
			count++;
			token_id = count;
			lexeme = l; rowno = r; colno = c;
			token_type = getType(lexeme);
		}

		string get_token_type()
		{
			return token_type;
		}

		void display()
		{
			cout << setw(15) << token_id << "|" << setw(15) << token_type << "|" << setw(15) << lexeme << "|" << setw(15) << rowno << "|" << setw(15) << colno << "|" << endl;
		}

};

int Token::count = 0;

class Symbol_table
{
	public:
	vector<Token> st;

	// Function to insert an entry into symbol table
	void insert(Token t)
	{
		st.push_back(t);
	}

	// Function to display the symbol table
	void display()
	{
		for(int j = 0; j < 80; j++)
		{
			cout << "_";
		}
		cout << endl;
		cout << setw(16) << "Token ID|" << setw(16) << "Token type|" << setw(16) << "Lexeme|" << setw(16) << "Row|" << setw(16) << "Column|" << endl;
		for(int i = 0; i < st.size(); i++)
		{
			for(int j = 0; j < 80; j++)
			{
				if(j % 16 == 15) cout << "|";
				else cout << "_";
			}
			cout << endl;
			st[i].display();	
		}
		for(int j = 0; j < 80; j++)
		{
			if(j % 16 == 15) cout << "|";
			else cout << "_";
		}
		cout << endl;
		cout << "Press Enter to continue.....\n";
		cin.get();
	}

	// Function to write the symbol table entries into a file
	void dump(string filename)
	{
		fstream fout;
		fout.open(filename, ios::out | ios::binary);
		for(int i = 0; i < st.size(); i++)
		{
			fout << st[i].get_token_type() << "\n";	
		}
		fout.close();

	}
};

// Function to check whether a character is a delimiter
bool is_delimiter(char ch)
{
	for(int i = 0; i < dsize; i++)
	{
		if(ch == delimiters[i])
			return true;
	}
	return false;
}

int main(int argc, char **argv)
{	
	fstream fin;
	fin.open("input.txt", ios::in | ios::binary);
	string word = ""; // Buffer which stores the current word while reading the file
	char ch;
	
	fin.get(ch);
	Symbol_table symtab;
	int row = 0;
	int col = 0;
	int start_col = 0;
	// Loop for reading from input file and tokenizing the words.
	while(!fin.eof())
	{
		ch = toupper(ch);
		if(is_delimiter(ch))
		{
			// Inserting the word into symbol table
			if(word != "")
			{
				Token t(word, row, start_col);
				symtab.insert(t);

			}
			// Inserting the symbol into symbol table
			if(ch != ' ' && ch != '\n' && ch != '\t')
			{
				string str(1, ch);
				Token t(str, row, col);
				symtab.insert(t);
			}
			//Making the buffer empty so that next word can be inserted
			word = "";
			start_col = col + 1;

			
		}
		else
		{
			word += ch;	
		}
		// Updating row and col no in case of new line
		if(ch == '\n')
		{
			row++;
			col = 0;
			start_col = 0;
		}
		else if(ch == '\t')
		{
			col += 4;
			start_col = col;
		}
		else
			col++;
		fin.get(ch);
	} 
	if(word != "")
	{
		Token t(word, row, start_col);
		symtab.insert(t);
	}	
	/* If there is additional argument, then display the symbol table */
	if(argc > 1 && strcmp(argv[0], "details")) {
		cout << "SYMBOL TABLE:\n";
		symtab.display();
	}
	
	symtab.dump("output.txt");
	fin.close();
	
}
