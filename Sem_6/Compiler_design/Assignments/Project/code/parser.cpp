#include <bits/stdc++.h>
using namespace std;

class Parser
{
	private: 
		set<string> terminals;
		set<string> non_terminals;
		map<string, vector<vector<string > > > P; // Production rules
		string start_symbol; 
		map<string, set<string> > first;
		map<string, set<string> > follow;
		map<string, map<string, int> > parsing_table; // Stores the index no of the rule in P, stores -1 if no rule correspons to that entry
		vector<string> input_string;

		/* Function to get the set of terminal symbols from file */
		void get_terminals(string filename)
		{
			fstream fin;
			fin.open(filename, ios::in| ios::binary);
			string s;
			fin >> s;
			while(!fin.eof())
			{
				terminals.insert(s);
				fin >> s;
			}
			fin.close();
		}

		/* Function to get the set of non-terminal symbols from file */
		void get_non_terminals(string filename)
		{
			fstream fin;
			fin.open(filename, ios::in| ios::binary);
			string s;
			fin >> s;
			start_symbol = s; // First symbol in the file is taken as start symbol
			while(!fin.eof())
			{
				non_terminals.insert(s);
				fin >> s;
			}
			fin.close();
		}

		/* Function to get the set of production rules from file */
		void get_productions(string filename)
		{
			fstream fin;
			fin.open(filename, ios::in| ios::binary);
			string s, t;
			fin >> t;
			vector<string> v;
			
			while(!fin.eof())
			{
				if(s == ":")
				{
					v.clear();
				}
				else if(s == "|")
				{
					P[t].push_back(v);
					v.clear();
				}
				else if(s == ";")
				{
					P[t].push_back(v);
					fin >> t;
					if(fin.eof()) break;
				}
				else
				{
					v.push_back(s);
				}

				fin >> s;
			}
			fin.close();
		}

		/* function to check whether a symbol is a terminal symbol */
		bool is_terminal(string s)
		{
			if(terminals.find(s) != terminals.end())
				return true;
			else
				return false;
		}

		/* function to check whether a symbol is a non-terminal symbol */
		bool is_non_terminal(string s)
		{
			if(terminals.find(s) != terminals.end())
				return true;
			else
				return false;
		}

		/* Recursive function to calculate first of a given symbol */
		void calc_first(string i)
		{
			for(auto j : P[i])
			{
				set<string> f;
				for(auto str : j)
				{
					f.erase("eps");

					if(first[str].empty())
						calc_first(str);

					set<string> st = first[str];
					f.insert(st.begin(), st.end());

					if(f.find("eps") == f.end())
						break;
				}

				first[i].insert(f.begin(), f.end());
			}
		}


		void calculate_first()
		{
			/* First of epsilon is epsilon */
			first["eps"].insert("eps");

			/* First of terminal symbol is the symbol itself */
			for(auto i : terminals)
			{
				first[i].insert(i);
			}

			/* Calculating first of non-terminal symbols */
			for(auto i : non_terminals)
			{
				if(first[i].empty())
				{
					calc_first(i);
				}
			}
		}

		/* Recursive function to calculate follow of a given non-terminal symbol */
		void calc_follow(string i)
		{

			if(i == start_symbol)
			{
				follow[i].insert("$");
			}

			for(auto j : non_terminals)
			{
				for(auto k : P[j])
				{
					bool flag = false;
					for(auto str : k)
					{
						if(flag == true)
						{
							follow[i].insert(first[str].begin(), first[str].end());
							follow[i].erase("eps");

							if(first[str].find("eps") == first[str].end())
								flag = false;
						}
						if(str == i)
						{
							flag = true;
							//cout << str << flag << endl;
						}

					}

					if(flag == true)
					{
						if(follow[j].empty() && i != j)
						{
							calc_follow(j);
						}
						follow[i].insert(follow[j].begin(), follow[j].end());
					}
				}
			}
		}


		void calculate_follow()
		{
			for(auto i : non_terminals)
			{
				if(follow[i].empty())
				{
					calc_follow(i);
				}
			}

		}

		/* Function to create the parsing table using the first and follow values */
		void create_parsing_table()
		{
			/* Initialising the parsing table with -1 */
			for(auto i : non_terminals)
			{
				for(auto j : terminals)
				{
					parsing_table[i][j] = -1;
				}
				parsing_table[i]["$"] = -1;
			}

			for(auto i : non_terminals)
			{
				for(int j = 0; j < P[i].size(); j++)
				{
					if(P[i][j][0] == "eps")
					{
						for(auto k : follow[i])
							parsing_table[i][k] = j;
					}
					else
					{
						string str;
						for(int k = 0; k < P[i][j].size(); k++)
						{
							str = P[i][j][k];
							for(auto l : first[str])
							{
								if(l != "eps")
									parsing_table[i][l] = j;
							}

							/* If the first of current token doesn't contain epsilon, break */
							if(first[str].find("eps") == first[str].end())
								break;
						}

						if(first[str].find("eps") != first[str].end())
						{
							for(auto k : follow[i])
								parsing_table[i][k] = j;
						}
					}
					
				}
			}
		}

		/* Function to parse a single SQL statement */
		void parseStatement(vector<string> input_string)
		{

			input_string.push_back("$");
			
			stack<string> pstack;
			pstack.push("$");
			pstack.push(start_symbol);
			int index = 0;
			
			while(!pstack.empty())
			{
				string top = pstack.top();
				if(top == "$")
				{
					if(input_string[index] == "$")
					{
						cout << "Valid statement" << endl;
					}
					else
					{
						cout << "Invalid statement" << endl;
					}
					return;
				}
				else if(is_terminal(top))
				{
					if(top == input_string[index])
					{
						pstack.pop();
						index++;
					}
					else
					{
						cout << "Invalid statement" << endl;
						return;
					}
				}
				else
				{
					int rule_no = parsing_table[top][input_string[index]];
					if(rule_no == -1)
					{
						cout << "Invalid statement" << endl;
						return;
					}
					else
					{
						pstack.pop();

						if(P[top][rule_no][0] != "eps")
						{
							int size = P[top][rule_no].size();

							for(int i = size-1; i >=0; i--)
							{
								pstack.push(P[top][rule_no][i]);
							}
						}
						
					}
				}
			}
		}

		/* Function to read input fom file and parse using parsing table */
		void parse_input(string filename)
		{
			fstream fin;
			fin.open(filename, ios::in| ios::binary);
			string s;
			fin >> s;

			vector<string> input_string;
			while(!fin.eof())
			{
				input_string.push_back(s);

				if(s == "EOS")
				{
					parseStatement(input_string);
					input_string.clear();
				}
				fin >> s;
			}
			fin.close();
	
		}

		void show_first()
		{
			for(auto i : first)
			{
				cout << "FIRST of " << i.first << ": ";
				for(auto j : i.second)
				{
					cout << j << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "Press Enter to continue.....\n";
			cin.get();
		}

		void show_follow() 
		{
			for(auto i : follow)
			{
				cout << "FOLLOW of " << i.first << ": ";
				for(auto j : i.second)
				{
					cout << j << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "Press Enter to continue.....\n";
			cin.get();
		}

		void show_parsing_table()
		{
			cout << "_" << "\t\t";
			for(auto i : parsing_table[start_symbol])
			{
				cout << i.first << "\t";
			}
			cout << endl;
			for(auto i : parsing_table)
			{
				cout << i.first << "\t\t";
				for(auto j : i.second)
				{
					cout << j.second << "\t";
				}
				cout << endl;
			}
			cout << "Press Enter to continue.....\n";
			cin.get();
		}

	public:
		Parser(string t = "terminals.txt", string nt = "non_terminals.txt", string p = "productions.txt")
		{
			// Calling functions to store the grammar(terminals, non-terminals and rules) into memory
			get_terminals(t);
			get_non_terminals(nt);
			get_productions(p);

			// Calling functions to generate the parsing table
			calculate_first();
			calculate_follow();
			create_parsing_table();
		}

		/* Function to display FIRST, FOLLOW and parsing table */
		void show_details()
		{
			show_first();
			show_follow();
			show_parsing_table();	
		}

		void parse(string input_file = "output.txt")
		{
			parse_input(input_file);		
		}
};




int main(int argc, char **argv)
{
	// Creating a parse object
	Parser parser;

	// Show details depending on command line argument
	if(argc > 1 && strcmp(argv[0], "details")) {
		parser.show_details();
	}

	// Parsing the output file
	parser.parse();

}