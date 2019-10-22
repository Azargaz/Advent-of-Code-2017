#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *file = fopen("input.txt", "r");

	char ch;
	char s[12];
	char uniq[12][12];
	int col = 0;
	int pwdCount = 0;
	int count = 0;

	while((fscanf(file, "%s", &s)) != EOF)
	{
		int eol = (ch = fgetc(file)) == '\n' || ch == EOF;		
		//printf("%s ", s);
		
		strcpy(uniq[col], s);
		
		col++;
		
		if(eol)
		{
			int i, j;
			
			for(i = 0; i < col; i++)
			{
				for(j = 0; j < col; j++)
				{
					if(i != j && strlen(uniq[i]) == strlen(uniq[j]))
					{
						int tf = strcmp(uniq[i], uniq[j]);
						count += (tf == 0);
					}
					
					if(count > 0)
						break;
				}
				if(count > 0)
					break;
			}
			
			if(count <= 0)
				pwdCount++;
							
			col = 0;
			count = 0;
			//printf("\n+------+\n");
		}
	}
	
	printf("Viable passwords: %d\n", pwdCount);
	
	fclose(file);
	
	return 0;
}
