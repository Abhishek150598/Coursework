#include <stdio.h>
#include <stdlib.h>

int in(int x)
{
	int a[] = {1, 3, 6, 8, 11, 13, 16, 18, 21, 23 };
	int n = 10;

	for(int i=0;i<n;i++)
	{
		if(a[i] == x) return 1;
	}

	return 0;
}

int main()
{
	FILE* fp = fopen("bangla.txt", "w");
	char** a = (char**)malloc(100*sizeof(char*));
	char** c = (char**)malloc(100*sizeof(char*));
	//string s;

	a[0] = "ক"; 
	a[1] = "খ";	
	a[2] = "গ"; 
	a[3] = "ঘ"; 
	a[4] = "ঙ"; 
	a[5] = "চ"; 
	a[6] = "ছ"; 
	a[7] = "জ"; 
	a[8] = "ঝ"; 
	a[9] = "ঞ"; 
	a[10] = "ট";
	a[11] = "ঠ";
	a[12] = "ড";
	a[13] = "ঢ";
	a[14] = "ণ";
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

	c[0] = "্";	
	c[1] = "া";	
	c[2] = "ি";	
	c[3] = "ী";	
	c[4] = "ু";	
	c[5] = "ূ";	
	c[6] = "ৃ";	
	c[7] = "ৄ";	
	c[8] = "ে";	
	c[9] = "ৈ";	
	c[10] = "ো";
	c[11] = "ৌ";
	c[12] = "ঁ";
	c[13] = "ং";
	c[14] = "ঃ";

	// scanf("%c%c%c\n", &a, &b, &c);
	// printf("%d %d %d\n", a, b, c);

	printf("tttttt\n");

	fprintf(fp,"--->%s\n" , a[0]);

	//return 0;

	int i=0;
	// for(i=0;i <=34; i++)
	// {
	// 	if(in(i)) continue;
	// 	if(in(i+1))
	// 	fprintf(fp, "else if(is1(chr, 'k')) /* %s */\n", a[i]);
	// 	else
	// 	fprintf(fp, "else if(is(chr, 'k')) /* %s */\n", a[i]);

	// 	fprintf(fp, "{\n");
	// 	fprintf(fp, "	last = %d;\n", i);

	// 	if(in(i+1))
	// 	fprintf(fp, " 	last += shift;\n");

	// 	fprintf(fp, " 	fprintf(fp, \" s\", a[last]);\n");	
	// 	fprintf(fp, "}\n");
	// }

	for(i=1;i <=11; i++)
	{
		fprintf(fp, "else if(is1(chr, 'e')) /* %s */\n", c[i]);
		fprintf(fp, "{\n");
		fprintf(fp, " 	kar = %d;\n", i);
		fprintf(fp, "	if(last != -1 && shift == 0)\n");
		fprintf(fp, "	{\n");
		fprintf(fp, "		backspace();\n");
		fprintf(fp, "		fprintf(fp,\" s s\", a[last], c[kar]);\n");
		fprintf(fp, "	}\n");
		fprintf(fp, "	else\n");
		fprintf(fp, "	{\n");
		fprintf(fp, " 		fprintf(fp,\" s\", b[kar]);\n");
		fprintf(fp, "	}\n");
		fprintf(fp, "  	last = -1;\n");
		fprintf(fp, "}\n");


	}

	fclose(fp);
	return 0;
}


// if(is(chr, 'k')) /* ক */
// 	    {
// 	    	last = 0;
// 	    	last += shift;
// 	    	/* printf("%s", a[last]); */
// 	    	fprintf(fp, "%s", a[last]);
// 	    }


// else if(is(chr, 'e')) /* া */
// 	    {
// 	    	kar = 1;
// 	    	if(last != -1 && shift == 0)
// 	    	{
// 	    		backspace();
// 	    		fprintf(fp,"%s%s", a[last], c[kar]);
// 	    	}
// 	    	else
// 	    	{
// 	    		fprintf(fp,"%s", b[kar]);
// 	    	}
// 	    	last = -1;
// 	    }
