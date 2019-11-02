#include <iostream>
#include <string>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>

using namespace std;

string get_current_path() {
	char path[1024];
	getcwd(path,1024);
	string cur_path(path);
	return cur_path;
}

void execute_command(string &current_path, string &operation, string &arguements) {
	if(operation == "echo") {
		cout<<arguements<<endl;
		return;
	}
	if(operation == "pwd") {
		cout<<current_path<<endl;
		return;
	}
	if(operation == "cd") {
		if(arguements[0] == '.' && arguements[1] == '.')	{
			if(current_path == "/") {
				return;
			}
			else {

				int prev = current_path.rfind('/');
				//cout<<prev<<endl;
				if(prev != string::npos) {
					current_path = current_path.substr(0,prev);
				}
			}
		}
		else if (arguements[0] == '.') {
			return;
		}
		else {
			string input_path(current_path);
			input_path.append("/");
			input_path.append(arguements);
			DIR* dir = opendir(input_path.c_str());
			if(dir) {
				current_path = input_path;
				return;
			}
			else if(ENOENT == errno) {
				cout<<"No such file or directory"<<endl;
				return;
			}
		}
		return;
	}
	if(operation == "ls") {
		string input_path(current_path);
		if(!arguements.empty()) {
			input_path.append("/");
			input_path.append(arguements);
		}
		cout<<input_path<<endl;
		DIR *dir;
		struct dirent *file;
		dir = opendir(input_path.c_str());
		if(dir == NULL) {
			cout<<"No such file or directory"<<endl;
			return;
		}
		while((file = readdir(dir)) != NULL) {;
			if(file->d_name[0] != '.') {
				printf("%s ",file->d_name);
			}
			printf(" ");
		}
		printf("\n");
		closedir(dir);
		return;
	}
	if(operation == "cp") {
		string source("");
		string dest("");
		int index = arguements.find(' ');
		if(index == string::npos) {
			cout<<"missing file operand"<<endl;
		}
		else {
			source = arguements.substr(0,index);
			dest = arguements.substr(index+1,arguements.size());
			if(source[0] == ' ' || dest[0] == ' ') {
				cout<<"missing source or destination file operand after "<<arguements<<endl;
			}
			else {
				source.insert(0,"/");
				source.insert(0,current_path);
				dest.insert(0,"/");
				dest.insert(0,current_path);
				const char *s = source.c_str();
				const char *d = dest.c_str();
				if (access(s,F_OK) == -1) {
					cout<<"missing source file"<<endl;
				}
				else {
					FILE *sou, *des;
					sou = fopen(s,"r");
					des = fopen(d,"w");
					char ch;
					while(true) {
						ch = fgetc(sou);
						if(ch == EOF) {
							break;
						}
						putc(ch,des);
					}
					fclose(sou);
					fclose(des);
				}
			}
		}
		return;
	}	
	cout<<operation<<" : "<<"comand not found"<<endl;
	return;
}

int main(void) {
	string cur_path;
	cur_path = get_current_path();
	while(true) {
		string command = "";
		string oper =  "";
		string rest = "";
		getline(cin,command);
		//command.strip();
		size_t index = command.find(' ');
		if(index  != string::npos) {
			oper = command.substr(0,index);
			rest = command.substr(index + 1, command.size());
		}
		else {
			oper = command;
		}
		if(command == "exit") {
			break;
		}
		execute_command(cur_path,oper,rest);
	}		
	
}