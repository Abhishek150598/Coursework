#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fts.h>
#include <errno.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
/*
  Function Declarations for builtin shell commands:
 */
int sh_cd(char **args);
int sh_ls(char **args);
int sh_echo(char **args);
int sh_cp(char **args);
int sh_pwd(char **args);

/*
  List of builtin commands.
 */
char *builtin_str[] = {"cd","ls","echo","cp","pwd"};

/* List of built-in functions*/

int (*builtin_func[])(char **)={&sh_cd, &sh_ls, &sh_echo, &sh_cp, &sh_pwd};

/*Two comapre two file names*/
int compare(const FTSENT** one, const FTSENT** two){

    return (strcmp((*one)->fts_name, (*two)->fts_name));
}
/*Display file data*/

void display_info(struct stat* info){

    struct passwd *p;
    struct group *g;
    struct tm *t;
    char time[26];
    printf("\n");
    if(S_ISDIR(info->st_mode))  //is directory
        printf("d");
    else if(S_ISREG(info->st_mode)) //is regular file
        printf("-");
    else if(S_ISCHR(info->st_mode)) //is character special file
        printf("c"); 
    else if(S_ISBLK(info->st_mode)) //is block special
        printf("b");
    else if(S_ISLNK(info->st_mode)) //is symlink
        printf("l");
    else if(S_ISFIFO(info->st_mode)) //is fifo special file
        printf("p"); 
    else if(S_ISSOCK(info->st_mode))  //is socket
        printf("s");
    else
        printf("-");
    /*Read write access*/
    printf( (info->st_mode & S_IRUSR) ? "r" : "-");
    printf( (info->st_mode & S_IWUSR) ? "w" : "-");
    printf( (info->st_mode & S_IXUSR) ? "x" : "-");
    printf( (info->st_mode & S_IRGRP) ? "r" : "-");
    printf( (info->st_mode & S_IWGRP) ? "w" : "-");
    printf( (info->st_mode & S_IXGRP) ? "x" : "-");
    printf( (info->st_mode & S_IROTH) ? "r" : "-");
    printf( (info->st_mode & S_IWOTH) ? "w" : "-");
    printf( (info->st_mode & S_IXOTH) ? "x" : "-");
   
    printf(" ");                                                
    printf("%ld ",(long)info->st_nlink);                                                             
    p=getpwuid(info->st_uid);
    printf("%s ",p->pw_name);                                                              
    g=getgrgid(info->st_gid);
    printf("%s ",g->gr_name);                                                             
    printf("%ld ",info->st_size);                                                               
    t=localtime(&info->st_mtime);                                                           
    strftime(time,sizeof(time),"%b %d %H:%M",t);
    printf("%s ", time);
}
/*TO list files using FTS(File tracking system)*/
void ls(char **args){

    FTS* file_system;                     
    FTSENT *parent,  *child; //FTSENT, the structure that represents a file in the file hierarchy
    /* The  fts_open()  function  takes a pointer to an array of character 
    pointers naming one or more paths which make up a logical file hierarchy to be traversed.*/
    if((file_system=fts_open(args,FTS_COMFOLLOW,compare))==NULL){
    
        fprintf(stderr,"s_shell: ls : Error in accessing directory/file %s\n",args[0]);
        return ;
    }                                                   
    // The function fts_open() may fail and set errno for any of the errors specified 
    // for open(2) and malloc(3).
    if(errno!=0){
    
        fprintf(stderr,"s_shell: ls : Error in accessing directory/file %s\n",args[0]);
        return ;
    }
    // The  fts_read()  function returns a pointer to an FTSENT structure describing a file in the hierarchy.  
    // Directories (that are readable and do not cause cycles) are visited at least twice, once
    // in preorder and once in postorder.  All other files are visited at least once.
    // If  all the members of the hierarchy have been returned, 
    // fts_read() returns NULL and sets the external variable errno to 0.
    parent=fts_read(file_system);
    if(parent==NULL){

        fprintf(stderr,"s_shell: ls : %s : Directory does not exist\n",args[0]);
        return ;
    }
    // The fts_children() function returns a pointer to an FTSENT structure describing the first entry 
    // in a NULL-terminated linked list of the files in the directory represented by the FTSENT  
    // structure  most  recently returned by fts_read(). 
    child=fts_children(file_system,0);
    // fts_children() may fail and set errno for any of the errors specified 
    // for chdir(2), malloc(3), opendir(3), readdir(3) and stat(2).
    if (errno != 0){
        perror("fts_children");
    }
    if(child==NULL)                                              //In case the child is NULL, returns
        return ;
    printf("\n%s:\n",parent->fts_path);
    while(child!=NULL){                // traverses the file structure
            
        struct stat *info=child->fts_statp;                  
        display_info(info);   
        printf(ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET,child->fts_name);         
        child=child->fts_link;
    }
    fts_close(file_system);                             
    // The  fts_close()  function  closes  a  file  hierarchy  stream ftsp and 
    // restores the current directory to the directory from which fts_open()  was called to open ftsp
}

/*http://man7.org/linux/man-pages/man3/fts.3.html*/
/*
           typedef struct _ftsent {
               unsigned short fts_info;     //flags for FTSENT structure
               char          *fts_accpath;  //access path
               char          *fts_path;     //root path
               short          fts_pathlen;  //strlen(fts_path)
               char          *fts_name;     //filename
               short          fts_namelen;  //strlen(fts_name)
               short          fts_level;    //depth (-1 to N)
               int            fts_errno;    //file errno
               long           fts_number;   //local numeric value
               void          *fts_pointer;  //local address value
               struct ftsent *fts_parent;   //parent directory
               struct ftsent *fts_link;     //next file structure
               struct ftsent *fts_cycle;    //cycle structure
               struct stat   *fts_statp;    //stat(2) information
           } FTSENT;


*/

/*
            struct stat {
               dev_t     st_dev;     // ID of device containing file 
               ino_t     st_ino;     // inode number 
               mode_t    st_mode;    // protection 
               nlink_t   st_nlink;   // number of hard links 
               uid_t     st_uid;     // user ID of owner 
               gid_t     st_gid;     // group ID of owner 
               dev_t     st_rdev;    // device ID (if special file) 
               off_t     st_size;    // total size, in bytes 
               blksize_t st_blksize; // blocksize for filesystem I/O 
               blkcnt_t  st_blocks;  // number of 512B blocks allocated 
               time_t    st_atime;   // time of last access 
               time_t    st_mtime;   // time of last modification 
               time_t    st_ctime;   // time of last status change 
           };

*/

/*Function to change directory*/
int sh_cd(char **args){

   
    if(args[1]==NULL){

        fprintf(stderr, "s_shell: expected argument to \"cd\"\n");
    } 
    else {
        if(chdir(args[1])!=0){  //change directory

            perror("s_shell");
        }
        else
            printf("Directory changed to %s\n",args[1]);
    }
    return 1;
}

int sh_ls(char **args){

    int argc=1,temp;
    char *path;
    for(;args[argc]!=NULL;argc++);       
    if(argc==1){

        char *path=(char*)malloc(sizeof(char)*255);
        getcwd(path,255);   //get current working directory
        args[1]=path;    
        args[2]=NULL;
        argc=2;
    }
    temp=1;
    while(temp<argc){         //ls is performed for each of the argument
        
        char *arg[2]={args[temp],NULL};
        ls(arg);    
        temp++;
    }
    return 1;
    
}
/*Function to echo*/
/*Space not working, need to change tokenize(), To display "hello world", cmd is echo "hello" "world", or echo hello world*/
int sh_echo(char **args){

    int argc=0;
    for(;args[argc]!=NULL;argc++);
    int option=0; 
    int opterr=0;
    int newline=0,escape=0,oth=0;
    int index=1,i;
    while((option=getopt(argc,args,"neE"))!=-1)            
    {
        switch(option)
        {
            case 'n':                                //Not newline terminated option -n
                newline=1;
                index=optind;
                break;
            case 'e':                             //Escape character option -e
                escape=1;
                index=optind;
                break;
            case 'E':     
                escape=0;                          //No escaping characters option -E
                break;
            case '?': 
                index=optind;
                oth=1;                            //in case an unknown option is entered, echo treats it like a string;
                break;
        }
        if(oth)
            break;
    }

    for(;index<argc;index++){                       //if no escape, displays message as it is
    
        if(!escape){
            
            for(i=0;args[index][i]!='\0';i++)
                printf("%c",args[index][i]);
        }    
        else{                                                
            
            int j=0;
            for(;args[index][j]!='\0';j++){

                if(args[index][j]!='\\' || args[index][j+1]=='\0')   //If current character is \ or next charcter is NULL display
                    printf("%c",args[index][j]);
                else{

                    j++;
                    switch(args[index][j]){
                        
                        case 'n':
                            printf("\n");                           //Displays newline
                            break;
                        case 'r':
                            printf("\r");                           //Displays return character
                            break;
                        case 't':
                            printf("\t");                           //Displays tab
                            break;
                        default:                                    //Otherwise displays \ followed by the character
                            printf("\\%c",args[index][j]);
                            break;
                    }
                }
            } 
        }       
        printf(" ");                                       
    }                                                  
    if(!newline)                                          //if newline flag is off, then displays a newline at the end
        printf("\n");
    return 1;
}

/*Copy file */
int sh_cp(char **args){

    int argc=0;
    for(;args[argc]!=NULL;argc++);
    if(argc<3){
        fprintf(stderr, "s_shell: Too few arguments\n");
        return 0;
    }
    char *src=args[1];
    char *dest=args[2];
    int inp, oup, status;
    char buff[255];
    if((inp=open(src, O_RDONLY))==-1){      //input file read only
        
        fprintf(stderr, "s_shell: Error in opening file %s\n",src);
        return 0;
    }
    if((oup=open(dest, O_WRONLY|O_CREAT|O_TRUNC)==-1)){     //output file
        
        fprintf(stderr, "s_shell: Error in creating file %s\n",dest);
        return 0;
    }
    while((status=read(inp,buff,255))>0){

        if(write(oup,buff,status)!=status){
           
           fprintf(stderr, "Error writing to%s\n",dest);
           return 0;
        }   
    }
    if(status==-1){
      
        fprintf(stderr, "s_shell: Error in reading file %s\n",src);
        return 0;
    }
    close(inp);
    close(oup);
    return 1;
}
/*FUnction for parent working directory*/
int sh_pwd(char **args){

    int argc=0;
    for(;args[argc]!=NULL;argc++);
    int option=0; 
    int opterr=0;
    int logic=0,phy=0;
    while((option=getopt(argc,args,"LP"))!=-1){             //checks for options
        switch(option){

            case 'L':                                 
                logic=1;
                break;
            case 'P':                                     
                phy=1;                                     
                break;
            case '?':                                       //For an invalid option
                fprintf(stderr,"s_shell: invalid option\n");
                return 0;
        }
    }
    if(logic && phy)        //if both are entered
        fprintf(stderr,"s_shell: invalid option\n");
    if(logic)                                           //-L option
        printf("%s\n",getenv("PWD"));   
    else{
                                                       // -P is default
        char *path=(char*)malloc(sizeof(char)*255);
        getcwd(path,255);
        printf("%s\n",path);
    }
    return 1;
}
char *read_line(){

	int bufsize=1024;
  	int pos=0;
  	char *buff=malloc(sizeof(char)*bufsize);
  	int c;
  	if (!buff) {
    
    	fprintf(stderr, "s_shell:Memory allocation error\n");
    	exit(EXIT_FAILURE);
  	}
  	while (1) {

    	c = getchar();
    	if (c==EOF || c=='\n') {

      		buff[pos]='\0';
      		return buff;
    	} 
    	else{
     
      		buff[pos]=c;
    	}
    	pos++;
    	// If exceeded the buffer, reallocate.
    	if (pos>=bufsize) {
      		
      		bufsize+=1024;
      		buff=realloc(buff,bufsize);
      		if (!buff) {
        		fprintf(stderr, "s_shell:Memory allocation error\n");
        		exit(EXIT_FAILURE);
      		}
    	}
  	}
}
char **tokenize_line(char *line){

    int bufsize=64,pos=0,i,j;
    char **tokens=malloc(bufsize*sizeof(char*));
    char *token;

    if(!tokens){

        fprintf(stderr, "s_shell:Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    token=strtok(line," \t\n\r");
    while(token!=NULL){

        tokens[pos]=token;
        if(*token=='"'){

            i=1;
           // printf("%s\n",token );
            while(token[i]!='\0'){
                if(token[i]=='"' && token[i-1]=='\\')
                    i++;
                else if(token[i]=='"' && token[i-1]!='\\')
                    break;
                else
                    i++;
            }
            if(token[i]=='\0'){
               
                fprintf(stderr, "s_shell: error in input: missing \" sign\n" );
                free(tokens);
                return NULL;
            }
            i++;
            if(token[i]=='\0' || token[i]==' ' || token[i]=='\t' || token[i]=='\n' || token[i]=='\r')
                token[i]='\0';
            else{
            
                fprintf(stderr, "s_shell: error in input: missing space after \" sign\n" );
                free(tokens);
                return NULL;
            }
            char *temp=NULL;
            temp=malloc(strlen(token)*sizeof(char));
            j=0;
            for(i=1;token[i]!='\0';i++){
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
        if(pos>=bufsize) {
            
            bufsize+=64;
            tokens=realloc(tokens,bufsize*sizeof(char*));
            if(!tokens){
                fprintf(stderr, "s_shell:Memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token=strtok(NULL, " \t\n\r");
    }
    tokens[pos]=NULL;
    return tokens;
}

int execute(char **tok){

    int i;
    if(tok[0]==NULL){
    // An empty command was entered.
        return 1;
    }
    pid_t pid, wpid;
    int status,flag=0;
    pid=fork();
    if(pid==0){
    // Child process
    	for (i=0;i<5;i++){
       	//printf("%s\n",tok[0] );
        	if(strcmp(tok[0],builtin_str[i])==0){
        		flag=1;
            	return (*builtin_func[i])(tok);
        	}
    	}
    	if(!flag){
        	if(execvp(tok[0], tok)==-1){
            	perror("s_shell");
                exit(EXIT_FAILURE);
        	}

        }	
        exit(EXIT_SUCCESS); //exit child process
    } 
    else if (pid < 0) {
    // Error forking
        perror("s_shell");
    } 
    else{
    // Parent process
        do{
            wpid = waitpid(pid, &status, WUNTRACED);
        }while (!WIFEXITED(status) && !WIFSIGNALED(status)); //process not signaled out, or not exited
    }
    return 1;
}
void start_shell(){

	char *line;
	char **tok;
	int status;
    printf("\n");
	do{

        char *path=malloc(255*sizeof(char));
        getcwd(path,255);
        strcat(path,"$");
        printf(ANSI_COLOR_RED "%s@" ANSI_COLOR_RESET,getenv("USER") );
        printf(ANSI_COLOR_GREEN"%s  " ANSI_COLOR_RESET,path);
		line=read_line();
        if(!strcmp(line,"exit"))
            break;
        tok=tokenize_line(line);
        status=execute(tok);
	}while(strcmp(line,"exit"));
}
int main(int argc, char const *argv[]){

	start_shell();
	return 0;
}