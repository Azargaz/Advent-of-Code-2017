#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	FILE *file = fopen("input2.txt", "r");
	int *i;
	int n = 0;
	int sum = 0;
	int min = 0;
	int max = 0;
	char ch;
	int eolLast = 0;
	
	while ((fscanf(file, "%4d", &i)) != EOF) 
	{		
		int eol = (ch = fgetc(file)) == '\n' || ch == EOF;
		printf("%d\n", i);
		
		if(eolLast)
		{
			max = 0;
			min = i;
			eolLast = 0;
		}
		
		if(i < min)
			min = i;
		if(i > max)
			max = i;
			
		if(eol)
		{
			eolLast++;
			sum += max - min;
			printf("max: %d min: %d diff: %d\n", max, min, max-min);			
		}
			
		if(n == 0)
		{
			max = 0;
			min = i;
		}			
		
		n++;
	}

	printf("Wynik: %d\n", sum);
	
	return 0;
}
