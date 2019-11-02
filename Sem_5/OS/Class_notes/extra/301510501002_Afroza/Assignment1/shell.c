/*7. Create a new file xx-shell.c (or .cpp if you prefer C++). Remember to replace xx by the last two digits of your roll number. The program should be able to interpret and execute common commands like: echo, cd, pwd, ls, cp. Write down routines to (a) parse the command line input and (b) execute the command. If necessary, ask user for further inputs.*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
//#include <fts.h>
//#include <errno.h>
//#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
//#include <grp.h>
//#include <time.h>
//#include <fcntl.h>
//#include <readline/readline.h>
//#include <readline/history.h>

#define ANSI_COLOR_GREEN   "\x1b[32m"
//#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char PWD[10000]="/home";

/*input line from user*/
char *read_line()
{
	int bufsize=1024;
  	int pos=0;
  	char *buff=malloc(sizeof(char)*bufsize);
  	int c;
  	if (!buff)
	{
    	fprintf(stderr, "shell:Memory allocation error\n");
    	exit(EXIT_FAILURE);
  	}
  	while(1)
	{
		c=getchar();
    	if(c==EOF || c=='\n')
		{
			buff[pos]='\0';
      		return buff;
    	} 
    	else
		{
     
      		buff[pos]=c;
    	}
    	pos++;
    	// If exceeded the buffer, reallocate.
    	if(pos>=bufsize)
		{
      		bufsize+=1024;
      		buff=realloc(buff, bufsize);
      		if(!buff)
			{
        		fprintf(stderr, "shell:Memory allocation error\n");
        		exit(EXIT_FAILURE);
      		}
    	}
  	}
}

/*tokenize the line*/
char **tokenize_line(char *line)
{

    int bufsize=64,pos=0,i,j;
    char **tokens=malloc(bufsize*sizeof(char*));
    char *token;

    if(!tokens)
	{
        fprintf(stderr, "shell:Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    token=strtok(line," \t\n\r");
    while(token!=NULL)
	{
		tokens[pos]=token;
        if(*token=='"')
		{
			i=1;
           // printf("%s\n",token );
            while(token[i]!='\0')
			{
		    	if(token[i]=='"' && token[i-1]=='\\')
                	i++;
                else if(token[i]=='"' && token[i-1]!='\\')
                    break;
                else
                    i++;
            }
			if(token[i]=='\0')
			{
               
                fprintf(stderr, "shell: error in input: missing \" sign\n" );
                free(tokens);
                return NULL;
            }
            i++;
            if(token[i]=='\0' || token[i]==' ' || token[i]=='\t' || token[i]=='\n' || token[i]=='\r')
                token[i]='\0';
            else
			{
            
                fprintf(stderr, "shell: error in input: missing space after \" sign\n" );
                free(tokens);
                return NULL;
            }
            char *temp=NULL;
            temp=malloc(strlen(token)*sizeof(char));
            j=0;
            for(i=1;token[i]!='\0';i++)
			{
                if(token[i]=='"' && token[i-1]=='\\')
                    temp[j++]='"';
                else if(token[i]=='"' && token[i-1]!='\\')
                    break;
                else
                    temp[j++]=token[i];
            }
            temp[j]='\0';
            tokens[pos]=temp;
        }

        pos++;
        if(pos>=bufsize)
		{
            
            bufsize+=64;
            tokens=realloc(tokens,bufsize*sizeof(char*));
            if(!tokens)
			{
                fprintf(stderr, "shell:Memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token=strtok(NULL, " \t\n\r");
    }
    tokens[pos]=NULL;
    return tokens;
}

/*implement ls; path takes the current path, option=1 or 2*/
void ls(char *path, int option)
{
	DIR *d;
	struct dirent *dir;
	d=opendir(path);
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			if(option==1) //default ls
			{
				if((strcmp(dir->d_name,".")!=0) && (strcmp(dir->d_name,"..")!=0))
					printf("%s\n",dir->d_name);
			}
			else if(option==2) //ls -d
			{
				if(dir->d_type==DT_DIR && (strcmp(dir->d_name,".")!=0) && (strcmp(dir->d_name,"..")!=0))
					printf("%s\n",dir->d_name);
			}			
		}
		closedir(d);
	}

}

/*implement echo*/
void echo(char **tok)
{
	int i;
	if(strcmp(tok[0], "-n")==0) //echo -n str
	{
		for(i=1; tok[i]!=NULL; i++)
			printf("%s  ", tok[i]);
	}
	else if(strcmp(tok[0], "*")==0 && tok[1]==NULL) //echo *
		ls(PWD, 1);
	else // echo str
	{
		for(i=0; tok[i]!=NULL; i++)
			printf("%s  ", tok[i]);
		printf("\n");
	}
}

/*implement cd; path starts at /home and keeps old path, path1 is current path*/
void cd(char *path, char *path1)
{
	int f=0;
    DIR *dir;
    struct dirent *ent;
    char newpath[100];
    if ((dir = opendir(path)) != NULL) 
	{
					//printf("%s\n", path);
	    while ((ent = readdir(dir)) != NULL)
		{
			if((strcmp(ent->d_name,"..") != 0) && (strcmp(ent->d_name,".") != 0) && (strcmp(path1,".."))!=0)
			{
		        if(strcmp(ent->d_name,path1)==0)
				{
					f=1;
					if(ent->d_type == DT_DIR)
					{
						if ((strlen(path) + strlen(ent->d_name) + 2) > 255)
	    				{
	    	    			printf("Path too long\n");
	    	    			return;
	    				}
					    char fullpath[255];
	    				strcpy(fullpath, path);
	   					strcat(fullpath, "/");
	    				strcat(fullpath, ent->d_name);
						strcpy(PWD, fullpath);
						printf("%s\n",fullpath);
						break; 
					}
				}
	    	}  // end of if condition
    	}     // end of while loop
     	if(strcmp(path1, "..")==0)
		{
			//printf("\nHERE 2");
			int len,i,j,flag;
			len=strlen(path);
     		i=len-1;
     		j=0;
     		flag=0;
     		do
			{
				if(path[i]=='/')
     				flag=1;
     			i--;
     		 }while(flag==0);
     		while(j<=i)
			{
     			newpath[j]=path[j];
     			j++;
     		}
     		newpath[j]='\0'; //printf("\nHERE 3");
			//opendir(newpath);
			strcpy(PWD,newpath);
     		printf("%s\n",newpath);
		}	
     	else if(f==0)
		{
			printf("No such directory exists.\n");
		  	return;
		}
	     closedir (dir);
	}
}

/*implement pwd command; path takes the current path*/
void pwd(char *path)
{   
    /*DIR *dir;
    struct dirent *ent;
   
    if((dir=opendir(path)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
      		if((strcmp(ent->d_name,"..") != 0) && (strcmp(ent->d_name,".") != 0))
			{
     
		        if(strcmp(ent->d_name,"Question7.c")==0)
				{
					printf("%s\n", path);
					strcpy(PWD, path);
			
				}
		        if(ent->d_type == DT_DIR)
				{
					if ((strlen(path) + strlen(ent->d_name) + 2) > 255)
		    		{
		        		printf("Path too long\n");
		        		return;
		    		}
					char fullpath[255];
    				strcpy(fullpath, path);
   					strcat(fullpath, "/");
    				strcat(fullpath, ent->d_name);
					pwd(fullpath); 
		  
      			}
      	      }   // end of if condition
      	}     // end of while loop
      	closedir (dir);
    }*/
	printf("%s\n", PWD);
}

/*implement cp; file1 to file2*/
void cp(char *file1, char *file2, char *path)
{
	printf("%s", path);
	FILE *fp1, *fp2; 
	
		char ch='a';
		fp1=fopen(file1, "r"); 			fp2=fopen(file2, "w");
		if(fp1==NULL)
			                fprintf(stderr, "shell:FIle not found error\n");
		else{

 			while(1) 
			{
      			ch = fgetc(fp1);
 
      			if (ch == EOF)
         			break;
     			 else
         			putc(ch, fp2);
  			}
 			printf("File copied Successfully!\n");	fclose(fp1);
    	fclose(fp2);
		}
}
	
/*execute subroutine; takes the tokenized user input as argument*/
void execute(char **tok)
{
	char *path=malloc(255*sizeof(char));
	if(strcmp(tok[0], "echo")==0)
		echo(tok+1);
	else if(strcmp(tok[0], "ls")==0)
	{		
		if(tok[1]==NULL) //default ls
		{
			ls(PWD, 1);
		}
		else //ls -d
		{
			if(strcmp(tok[1], "-d")==0 && tok[2]!=NULL) //ls -d path
			{
				strcpy(path, tok[2]);
				ls(path, 2);	
			}
			else if(strcmp(tok[1], "-d")==0 && tok[2]==NULL) //ls -d
			{
				//getcwd(path, 255);
				ls(PWD, 2);
			}
			else //ls path
			{
				strcpy(path, tok[1]);
				ls(path, 1);
			}
		}		
	}
	else if(strcmp(tok[0], "pwd")==0)
	{
		char *path=malloc(255*sizeof(char));
		strcpy(path, "/home");
		pwd(path);
	}
	else if(strcmp(tok[0], "cd")==0)
	{
		char *path=malloc(255*sizeof(char));
		char *path1=malloc(255*sizeof(char));
		//strcpy(path, "/home");
		if(tok[1]==NULL)
		{
			cd(PWD, "");
		}
		else if(strcmp(tok[1], "..")==0)
		{
			cd(PWD, "..");
		}
		else // cd path
		{
			strcpy(path1, tok[1]);
			cd(PWD, path1);
		}
	}
	else if(strcmp(tok[0], "cp")==0)
	{
		cp(tok[1], tok[2], PWD); 		printf("AFTER");
	}					
}

/*starts the shell, returns 1 as a signal*/	
int run_shell()
{
		
	char *line;
	char **tok;
	do
	{
		char *path=malloc(255*sizeof(char));
    	//getcwd(path, 255);
    	//strcat(path, "$");
		//pwd("/home");
		strcpy(path, PWD);
		strcat(path, "$"); //printf("PWD is now %s and path is now %s ",PWD,path);
    	printf(ANSI_COLOR_CYAN "%s@" ANSI_COLOR_RESET, getenv("USER")); 	
    	printf(ANSI_COLOR_GREEN "%s  " ANSI_COLOR_RESET, path);
		line=read_line();
		if(!strcmp(line, "exit"))
            break;
        tok=tokenize_line(line);
	
		/*printf("\nShowing tokens: ");
		int i;
		for(i=0; tok[i]!=NULL; i++)
			printf("%s-", tok[i]);*/

        execute(tok);
		
		
	}while(strcmp(line, "exit"));
	return 1;
}

/*main function that uses fork to run this new shell as a child process*/
int main(int agrc, char const *argv[])
{
	int i;
    pid_t pid, wpid;
    int status=0,flag=0;
    pid=fork();
    if(pid==0)
	{
    // Child process
		printf("child process entered\n");
		status=run_shell(); printf("child process exited\n");
		exit(EXIT_SUCCESS); //exit child process
	}
	else if (pid<0)	
	{
    // Error forking
        perror("shell");
    } 
    else{
//printf("PPEntered\n");
    // Parent process
 		do{
			wpid = waitpid(pid, &status, WUNTRACED);
			printf("Parent process inside\n");
        }while (!WIFEXITED(status) && !WIFSIGNALED(status)); //process not signaled out, or not exited
    }
	return 1;
}
