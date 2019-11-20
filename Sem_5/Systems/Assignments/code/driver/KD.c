#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

#pragma inline

FILE*  fp;
int shift;

int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO); //knock down keybuffer
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    system("stty -echo"); //shell out to kill echo
    ch = getchar();
    system("stty echo");
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}


int is_eng(char c)
{
	if(c == ' ') return 1;
	if(c == '\n') return 1;
	if(c == '.') return 1;
	return 0;
}

void backspace()
{
	int idx = 0, i = 0; char c; int limit;
	char* t = (char*)malloc(1000*sizeof(char));
	fclose(fp);

  	fp = fopen("kd_out.txt", "r");
  	
  	while ((c = fgetc(fp)) != EOF)
  	{
      	t[idx++] = c;
  	}
  	fclose(fp);

  	if(is_eng(t[idx-1])) limit = idx-1;
  	else limit = idx - 3;

	fp = fopen("kd_out.txt", "w");
	while(i < limit)
	{
  		fprintf(fp, "%c", t[i]);
  		i++;
	}
	fclose(fp);
	fp = fopen("kd_out.txt", "a");
}

int is1(char c, char x)
{
	if(c == x) { shift  = 0; return 1; }
	if(c == (x - ('a' - 'A') )) 
	{ shift  = 1; return 1; }

	if(x == ';' && c == ':') { shift  = 1; return 1; }
	if(x == '\'' && c == '"') { shift  = 1; return 1; }
	if(x == '[' && c == '{') { shift  = 1; return 1; }
	if(x == ']' && c == '}') { shift  = 1; return 1; }
	if(x == ',' && c == '<') { shift  = 1; return 1; }
	if(x == '.' && c == '>') { shift  = 1; return 1; }
	if(x == '/' && c == '?') { shift  = 1; return 1; }
	if(x == '-' && c == '_') { shift  = 1; return 1; }
	if(x == '=' && c == '+') { shift  = 1; return 1; }

	if(x == '1' && c == '!') { shift  = 1; return 1; }
	if(x == '2' && c == '@') { shift  = 1; return 1; }
	if(x == '3' && c == '#') { shift  = 1; return 1; }
	if(x == '4' && c == '$') { shift  = 1; return 1; }
	if(x == '5' && c == '%') { shift  = 1; return 1; }
	if(x == '6' && c == '^') { shift  = 1; return 1; }
	if(x == '7' && c == '&') { shift  = 1; return 1; }
	if(x == '8' && c == '*') { shift  = 1; return 1; }
	if(x == '9' && c == '(') { shift  = 1; return 1; }
	if(x == '0' && c == ')') { shift  = 1; return 1; }

	shift = 0;
	return 0;
}

int is(char c, char x)
{
	if(c == x) { shift  = 0; return 1; }
	shift = 0;
	return 0;
}

int main()
{
	char chr = 'a';
	int last = -1,kar = 0,idx = 0;
	char** a = (char**)malloc(100*sizeof(char*));
	char** b = (char**)malloc(100*sizeof(char*));
	char** c = (char**)malloc(100*sizeof(char*));
	char** d = (char**)malloc(100*sizeof(char*));
	int *history = (int*)malloc(10000*sizeof(int));
	fp = fopen("kd_out.txt", "w");
	fprintf(fp, "\n");
	fclose(fp);
	shift = 0;

    a[0] = "ক"; 	c[0] = "্";		b[0] = "অ";	   	d[0] = "০";
    a[1] = "খ";		c[1] = "া";		b[1] = "আ";	d[1] = "১";	
    a[2] = "গ"; 	c[2] = "ি";		b[2] = "ই";		d[2] = "২";
    a[3] = "ঘ"; 	c[3] = "ী";		b[3] = "ঈ";		d[3] = "৩";
    a[4] = "ঙ"; 	c[4] = "ু";		b[4] = "উ";		d[4] = "৪";
    a[5] = "চ"; 	c[5] = "ূ";		b[5] = "ঊ";		d[5] = "৫";
    a[6] = "ছ"; 	c[6] = "ৃ";		b[6] = "ঋ";		d[6] = "৬";
    a[7] = "জ"; 	c[7] = "ৄ";		b[7] = "ঌ";		d[7] = "৭";
    a[8] = "ঝ"; 	c[8] = "ে";		b[8] = "এ";		d[8] = "৮";
    a[9] = "ঞ"; 	c[9] = "ৈ";		b[9] = "ঐ";		d[9] = "৯";
    a[10] = "ট";	c[10] = "ো";	b[10] = "ও";	
    a[11] = "ঠ";	c[11] = "ৌ";	b[11] = "ঔ";	
    a[12] = "ড";	c[12] = "ঁ";
    a[13] = "ঢ";	c[13] = "ং";
    a[14] = "ণ";	c[14] = "ঃ";
    a[15] = "ত";
    a[16] = "থ";
    a[17] = "দ";
    a[18] = "ধ";
    a[19] = "ন";
    a[20] = "প";
    a[21] = "ফ";
    a[22] = "ব";
    a[23] = "ভ";
    a[24] = "ম";
    a[25] = "য";
    a[26] = "র";
    a[27] = "ল";
    a[28] = "শ";
    a[29] = "ষ";
    a[30] = "স";
    a[31] = "হ";
    a[32] = "য়";
    a[33] = "ড়";
    a[34] = "ঢ়";

    while(1)
    {
    	fp = fopen("kd_out.txt", "a");
    	shift = 0;

	    // asm mov ah, 7
	    // asm int 21h
	    // asm mov chr, al

	    chr = getche();

	    //printf("%d\n", chr);
	    //continue;

	    printf("\n%d", (int)chr);

	    

		if(is1(chr, 'k')) /* ক */
		{
			last = 0;
 			last += shift;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is1(chr, 'i')) /* গ */
		{
			last = 2;
 			last += shift;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, 'U')) /* ঙ */
		{
			last = 4;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is1(chr, ';')) /* চ */
		{
			last = 5;
 			last += shift;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is1(chr, 'p')) /* জ */
		{
			last = 7;
 			last += shift;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, '}')) /* ঞ */
		{
			last = 9;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is1(chr, '\'')) /* ট */
		{
			last = 10;
 			last += shift;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is1(chr, '[')) /* ড */
		{
			last = 12;
 			last += shift;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, 'C')) /* ণ */
		{
			last = 14;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is1(chr, 'l')) /* ত */
		{
			last = 15;
 			last += shift;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is1(chr, 'o')) /* দ */
		{
			last = 17;
 			last += shift;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, 'v')) /* ন */
		{
			last = 19;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is1(chr, 'h')) /* প */
		{
			last = 20;
 			last += shift;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is1(chr, 'y')) /* ব */
		{
			last = 22;
 			last += shift;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, 'c')) /* ম */
		{
			last = 24;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, '?')) /* য */
		{
			last = 25;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, 'j')) /* র */
		{
			last = 26;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, 'n')) /* ল */
		{
			last = 27;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, 'M')) /* শ */
		{
			last = 28;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, '<')) /* ষ */
		{
			last = 29;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, 'm')) /* স */
		{
			last = 30;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, 'u')) /* হ */
		{
			last = 31;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, '/')) /* য় */
		{
			last = 32;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, '#')) /* ড় */
		{
			last = 33;
 			fprintf(fp, "%s", a[last]);
		}
		else if(is(chr, '$')) /* ঢ় */
		{
			last = 34;
 			fprintf(fp, "%s", a[last]);
		}
/*------------------------------------------------------------------------*/
		else if(is1(chr, 'd')) /* ্ */
		{
		 	kar = 0;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, 'e')) /* া */
		{
		 	kar = 1;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, 'f')) /* ি */
		{
		 	kar = 2;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, 'r')) /* ী */
		{
		 	kar = 3;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, 'g')) /* ু */
		{
		 	kar = 4;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, 't')) /* ূ */
		{
		 	kar = 5;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, '=')) /* ৃ */
		{
		 	kar = 6;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, 0)) /* ৄ */
		{
		 	kar = 7;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, 's')) /* ে */
		{
		 	kar = 8;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, 'w')) /* ৈ */
		{
		 	kar = 9;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, 'a')) /* ো */
		{
		 	kar = 10;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(is1(chr, 'q')) /* ৌ */
		{
		 	kar = 11;
			if(last != -1 && shift == 0)
			{
				backspace();
				fprintf(fp,"%s%s", a[last], c[kar]);
			}
			else
			{
		 		fprintf(fp,"%s", b[kar]);
			}
		  	last = -1;
		}
		else if(chr == '0')
		{
			int i = chr - '0';
			fprintf(fp,"%s", d[i]);
		}
		else if(chr == '1')
		{
			int i = chr - '0';
			fprintf(fp,"%s", d[i]);
		}
		else if(chr == '2')
		{
			int i = chr - '0';
			fprintf(fp,"%s", d[i]);
		}
		else if(chr == '3')
		{
			int i = chr - '0';
			fprintf(fp,"%s", d[i]);
		}
		else if(chr == '1')
		{
			int i = chr - '0';
			fprintf(fp,"%s", d[i]);
		}
		else if(chr == '4')
		{
			int i = chr - '0';
			fprintf(fp,"%s", d[i]);
		}
		else if(chr == '5')
		{
			int i = chr - '0';
			fprintf(fp,"%s", d[i]);
		}
		else if(chr == '6')
		{
			int i = chr - '0';
			fprintf(fp,"%s", d[i]);
		}
		else if(chr == '7')
		{
			int i = chr - '0';
			fprintf(fp,"%s", d[i]);
		}
		else if(chr == '8')
		{
			int i = chr - '0';
			fprintf(fp,"%s", d[i]);
		}

	    else if(is(chr, ' '))
	    {
	    	fprintf(fp, " ");
	    	last = -1;
	    }
	    else if(chr == 10)
	    {
	    	fprintf(fp, "\n");
	    	last = -1;
	    }
	    else if(is(chr,'\\'))
	    {
	    	printf(" break\n");
	    	break;
	    }
	    else 
	    {
	    	if(idx == 0) 
	    	{ printf(" kichu nei\n"); continue; }
	    	backspace();
	    	idx--;
	    	if(idx == 0) last = -1;
	    	else
	    	last = history[idx - 1];

	    	printf(" %d %d\n", last, idx);
	    	fclose(fp);
	    	continue;
	    }

	    history[idx++] = last;
	    printf(" %d %d\n", last, idx);
	    fclose(fp);
	}
    return 0;
}
