#include <stdio.h>

int main(void)
{
	FILE *file = fopen("input.txt", "r");

	char ch;
	int *i;
	int lines = 0;
	
	while((fscanf(file, "%5d", &i)) != EOF)
	{
		int eol = (ch = fgetc(file)) == '\n' || ch == EOF;		
		//printf("%d ", i);
		
		if(eol)
		{
			lines++;
			//printf("\n+------+\n");
		}
	}
		
	fclose(file);
	
	int *tab = malloc(sizeof(int) * lines);
	
	FILE *file2 = fopen("input.txt", "r");
	
	int n = 0;
	
	while((fscanf(file2, "%5d", &i)) != EOF)
	{
		int eol = (ch = fgetc(file2)) == '\n' || ch == EOF;		
				
		tab[n] = i;
		//printf("%d\n", tab[n]);
		
		n++;
	}
	
	fclose(file2);
	long int steps = 0;
	int k;
	
	int part2mode = 1;
	int debug = 0;
	
	for(k = 0; k < lines;)
	{
		if(k == lines)
			break;
		
		if(debug)
		{
			printf("#%d steps: %d tab[k]=%d", k, steps, tab[k]);
			getchar();
		}
		
		steps++;
		
		int temp = tab[k];
		
		if(part2mode)
		{
			if(tab[k] >= 3)
				tab[k] -= 1;
			else
				tab[k] += 1;
		}
		else
			tab[k] += 1;
		
		k += temp;
	}
	
	printf("No of steps: %li", steps);
	
	return 0;
}
