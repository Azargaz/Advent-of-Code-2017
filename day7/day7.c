#include <stdio.h>
#include <string.h>
const int SIZE = 10;

int main(void)
{
	FILE *file = fopen("input.txt", "r");

	char ch;
	char str[SIZE];
	int x = 10000;
	char functions[x][SIZE];
	char deeperFunctions[x][SIZE];
	int goDeeper = 0;
	int fCount = 0;
	int dfCount = 0;

	while((fscanf(file, "%s", &str)) != EOF)
	{	
		ch = fgetc(file);
		int eol = (ch == '\n' || ch == EOF);
		
		//printf("%s ", str);
		
		if(goDeeper)
		{
			strcpy(deeperFunctions[dfCount++], str);
		}
		
		if(strcmp(str, "->") == 0)
			goDeeper = 1;
		
		if(str[0] != '(' && !goDeeper)
		{
			strcpy(functions[fCount++], str);
		}
		
		if(eol)
		{
			//printf("\n");
			goDeeper = 0;
		}
	}
	
	int i,j;
	for(i = 0; i < dfCount; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			if(deeperFunctions[i][j] == ',')
				deeperFunctions[i][j] = '\0';
		}
	}
	
	for(i = 0; i < fCount; i++)
	{
		int uniq = 1;
		for(j = 0; j < dfCount; j++)
		{
			//printf("%s =?= %s\n", functions[i], deeperFunctions[j]);
			if(strcmp(functions[i], deeperFunctions[j]) == 0)
				uniq = 0;
		}	
		if(uniq)
			printf("%s\n", functions[i]);
	}
	
	fclose(file);
	
	return 0;
}
