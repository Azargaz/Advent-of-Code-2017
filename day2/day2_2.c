#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	char src[] = "input2.txt";
	FILE *file = fopen(src, "r");
	int *i;
	int x = 0;
	int y = 0;
	int max_x = 0;
	int max_y = 0;
	char ch;
	
	while ((fscanf(file, "%4d", &i)) != EOF) 
	{		
		int eol = (ch = fgetc(file)) == '\n' || ch == EOF;
		//printf("%d\n", i);		
		
		if(eol)
		{
			x = 0;
			y++;
		}
		
		x++;
		
		if(x > max_x)
			max_x = x;
			
		if(y > max_y)
			max_y = y;
	}
	
	fclose(file);
	
	printf("x: %d y: %d\n", max_x, max_y);
	
	FILE *file2 = fopen(src, "r");
	
	int **tab;

	tab = malloc(max_x * sizeof(int*));
	
	int j;
	for (j = 0; j < max_x; j++) {
	  	tab[j] = malloc(max_y * sizeof(int));
	}
	
	x = 0;
	y = 0;
	
	while ((fscanf(file2, "%4d", &i)) != EOF) 
	{
		int eol = (ch = fgetc(file2)) == '\n' || ch == EOF;
		//printf("%d\n", i);		
		
		if(x < max_x && y < max_y)
			tab[x][y] = i;
		
		if(eol)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	
	int sum = 0;
	
	int k,l,m;
	for(k = 0; k < max_y; k++)
	{
		for(l = 0; l < max_x; l++)
		{
			for(m = 0; m < max_x; m++)
			{
				if(tab[l][k] % tab[m][k] == 0 && l != m)
					sum += tab[l][k] / tab[m][k];
			}
		}
	}

	fclose(file2);
	
	printf("Wynik: %d", sum);
	
	return 0;
}
