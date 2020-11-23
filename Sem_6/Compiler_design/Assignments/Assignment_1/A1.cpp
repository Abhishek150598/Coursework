#include<bits/stdc++.h>
using namespace std;
char delimiters[] = {' ', ',', '.', '?', '!', '\"', '\n'};

// Funtion to find the word in the given file
bool find_word(string filename, string w)
{
	fstream f;
	f.open(filename, ios::in);
	
	string word;
	f >> word;
	
	while(!f.eof())
	{
		if(word == w)
		{
			f.close();
			return true;
		}
		f >> word;
	}
	
	f.close();
	return false;	
}

// Function to display all words of a particular type
void display_words(vector <string> v)
{
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

// Function to check whether a character is a delimiter
bool is_delimiter(char ch)
{
	for(int i = 0; i < 7; i++)
	{
		if(ch == delimiters[i])
			return true;
	}
	return false;
}

int main()
{	
	fstream fin;
	fin.open("input.txt", ios::in | ios::binary);
	string word = "";
	char ch;
	
	fin.get(ch);
	set<string> s;
	
	// Loop for reading from input file and tokenizing the words.
	while(!fin.eof())
	{
		if(!is_delimiter(ch))
			word += tolower(ch);
		else
		{
			if(word != "")
				s.insert(word);
			word = "";
		}
		
		fin.get(ch);
	} 
	if(word != "")	
		s.insert(word);
	fin.close();
	
	vector <string> verbs, articles, prepositions, adjectives;
	
	

	for(auto i = s.begin(); i != s.end(); i++)
	{
		
		if(find_word("verbs.txt", *i))
			verbs.push_back(*i);
		if(find_word("articles.txt", *i))
			articles.push_back(*i);
		if(find_word("prepositions.txt", *i))
			prepositions.push_back(*i);
		if(find_word("adjectives.txt", *i))
			adjectives.push_back(*i);
		
	}
	
	cout << "Verbs are: " << endl;
	display_words(verbs);
	cout << endl;
	cout << "Articles are: " << endl;
	display_words(articles);
	cout << endl;
	cout << "Prepositions are: " << endl;
	display_words(prepositions);
	cout << endl;
	cout << "Adjectives are: " << endl;
	display_words(adjectives);
	
}
