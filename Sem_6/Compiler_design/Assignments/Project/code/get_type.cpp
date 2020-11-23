//This is a utility program used by lex_analyser.cpp to get the type of token from the corresponding lexeme

#include <bits/stdc++.h>
#include "get_type.h"
using namespace std;

set <string> keywords = {"CREATE", "TABLE","INSERT","INTO","SELECT","FROM","PRIMARY","KEY","VALUES","BETWEEN","LIKE","IN","WHERE","AND"};
set <string> relop = {"<", ">", "="};
set <string> star = {"*"};
set <string> comma = {","};
set <string> bopen = {"("};
set <string> bclose = {")"};
set <string> eos = {";"};
set <string> datatype = {"CHAR", "VARCHAR", "NUMBER"};

int is_alphabet(char c)
{
	return ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'));
}
int is_number(char c)
{
	return ((c >= '0') && (c <= '9'));
}

/* Performs state transition based on input. Returns a string corresponding to the final state reached
State 0 - Start state
State 1 - integer
State 2 - float
State 3 - identifier(id)
State 4 - quoted string
State 5 - error
State 6 - string with open quotes
*/
string get_state(string s)
{
	int state = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(state == 0) 
		{
			if(is_number(s[i]))
				state = 1;
			else if(s[i] == '.')
				state = 2;
			else if(is_alphabet(s[i]) || s[i] == '_')
				state = 3;
			else if(s[i] == '\"')
				state = 6;
			else
				state = 5;
			continue;
		}
		else if(state == 1)
		{
			if(is_number(s[i]))
				state = 1;
			else if(s[i] == '.')
				state = 2;
			else if(s[i] == is_alphabet(s[i]) || s[i] == '_')
				state = 3;
			else
				state = 5;
			continue;
		}
		else if(state == 2)
		{
			if(is_number(s[i]))
				state = 2;
			else
				state = 5;
			continue;
		}
		else if(state == 3)
		{
			if(is_number(s[i]) || is_alphabet(s[i]) || s[i] == '_')
				state = 3;
			else
				state = 5;
			continue;
		}
		else if(state == 4)
		{
			if(s[i] == '\"')
				state = 4;
			else
				state = 6;
			continue;
		}
		else if(state == 6)
		{
			if(s[i] == '\"')
				state = 4;
			else
				state = 6;
			continue;
		}

	}

	switch(state)
	{
		
		case 1: return "INTEGER"; break;
		case 2: return "FLOAT"; break;
		case 3: return "ID"; break;
		case 4: return "STRING"; break;
		case 5: return "ERROR"; break;
		case 6: return "ERROR"; break;
		default: return NULL;
	}
}


string getType(string s)
{
	if(keywords.find(s) != keywords.end())
		return s;
	if(relop.find(s) != relop.end())
		return "RELOP";
	if(star.find(s) != star.end())
		return "STAR";
	if(comma.find(s) != comma.end())
		return "COMMA";
	if(bopen.find(s) != bopen.end())
		return "BOPEN";
	if(bclose.find(s) != bclose.end())
		return "BCLOSE";
	if(eos.find(s) != eos.end())
		return "EOS";
	if(datatype.find(s) != datatype.end())
		return "TYPE";

	return get_state(s);
}
