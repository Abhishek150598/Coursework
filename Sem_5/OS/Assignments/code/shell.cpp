#include <bits/stdc++.h>
using namespace std;

char* read_line()
{
	int bufsize = 1024;
	int pos = 0;
	char* buff = (char*)malloc(sizeof(char) * bufsize);
	int c;
	while(1)
	{
		c = getchar();
		if(c == '\n')
		{
			buff[pos] = '\0';
			return buff;
		}
		else
		{
			buff[pos] = c;
		}
		pos++;
	}
}

list <string> string_tokenize(char *line)
{
    int i=0;
    list <string> tokens;
    string token;

    while(line[i])
    {
    	if(line[i] == ' ' && !token.empty())
    	{
    		tokens.push_back(token);
    		token.clear();
    	}
    	else if(line[i] != ' ')
    	{
    		token.push_back(line[i]);
    	}
    	i++;
    }
    if(!token.empty()) tokens.push_back(token);
    return tokens;
}

void dirnew(list <string> arguments)
{
	if(arguments.size() == 0)
	{
		cout << "Arguments required" << endl;
		return;
	}

	for(auto i = arguments.begin(); i != arguments.end(); i++)
	{
		string str = "mkdir " + *i + "> /dev/null 2>&1";
		const char* command = str.c_str();
		if(!system(command))
			cout << "Directory created" << endl;
		else
			cout << "Directory " << *i << " already exists" <<endl;
	}	
}

void editfile(list <string> arguments)
{
	if(arguments.size() == 0)
	{
		system("vi");
		return;
	}
	
	for(auto i = arguments.begin(); i != arguments.end(); i++)
	{
		string str = "vi " + *i;
		const char* command = str.c_str();
		system(command);
	}
}

void info(list <string> arguments)
{
	if(arguments.size() == 0)
	{
		cout << "Arguments required" << endl;
		return;
	}

	for(auto i = arguments.begin(); i != arguments.end(); i++)
	{
		ifstream file(*i);
		// Checking if the file exists
		if(!file)
		{
			cout << "File " << *i << " does not exist" << endl;
			continue;
		}

		cout << "For file " << *i << ": " << endl;
		// Full path of the file 
		string str = "pwd";
		const char* command = str.c_str();
		cout << "Full path: " << endl;
		system(command); 

		// Size of the file in bytes
		str = "stat -c \"%s\" " + *i;
		command = str.c_str();
		cout << "File size: " << endl;
		system(command);

		// Time of last modification
		str = "stat -c \"%y\" " + *i;
		command = str.c_str();
		cout << "Time of last modification: " << endl;
		system(command);

		// Creator of file
		str = "stat -c \"%U\" " + *i;
		command = str.c_str();
		cout << "Creator of file: " << endl;
		system(command);
	}
	

}

map <string, int> create_map()
{
	map <string, int> id;
	id["dirnew"] = 1;
	id["editfile"] = 2;
	id["info"] = 3;
	id["exitnewshell"] = 4;
	return id;
}

int main()
{
	char* line;

	map <string, int> id = create_map();

	while(1)
	{
		cout << "\033[1;31mBCSE!!\033[0m"; // Prompt
		line = read_line(); // Reading the command and arguments as a character array
		list <string> arguments = string_tokenize(line); // Tokenising the different strings
		string command = arguments.front(); // First string is the command
		arguments.pop_front(); // All other strings are arguments

		switch(id[command])
		{
			case 1 	: 	dirnew(arguments);
						break;
			case 2	:	editfile(arguments);
						break;
			case 3	:   info(arguments);
						break;
			case 4 	:	exit(0);
						break;
			default :	cout << "Unknown command\n";
		}
	}
}