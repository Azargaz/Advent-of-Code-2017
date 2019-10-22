#include <stdio.h>
#include <string.h>

const int SIZE = 16;

int comparePatterns(int pattern1[], int pattern2[])
{
	int i;
	for(i = 0; i < SIZE; i++)
	{
		if(pattern1[i] != pattern2[i])
			return 0;
	}
	return 1;
}

int findMax(int pattern[])
{
	int i;
	int max = 0;
	for(i = 0; i < SIZE; i++)
	{
		if(pattern[i] > pattern[max])
			max = i;
	}
	
	return max;
}

int main(void)
{
	FILE *file = fopen("input.txt", "r");

	char ch;
	int *i;
	int n = 0;
	int tab[SIZE];
	int x = 30000;
	int patterns[x][SIZE];
	int pCount = 0;
	
	int k, l;
	for(k = 0; k < x; k++)
	{
		for(l = 0; l < SIZE; l++)
		{
			patterns[k][l] = 0;
		}
	}
	
	while((fscanf(file, "%3d", &i)) != EOF)
	{	
		printf("%d ", i);
		tab[n] = i;
		n++;
	}
	printf("\n\n");
	fclose(file);
	
	int g;
	for(g = 0; g < SIZE; g++)
	{
		patterns[0][g] = tab[g];
	}
	
	pCount++;
	
	int loops = 0;
	int patternFound = 0;
	int loopSize = 0;
	
	while(!patternFound)
	{
		loops++;
		
		int i, j;
		//printf("#%d ", loops);
		for(i = 0; i < SIZE; i++)
		{
			patterns[pCount][i] = patterns[pCount-1][i];
			//printf("%d ", patterns[pCount][i]);
		}
		//printf("\n");
				
		int max = findMax(patterns[pCount]);
		int blocksToMove = patterns[pCount][max];
		patterns[pCount][max] = 0;
		int y = max;
		while(blocksToMove > 0)		
		{	
			y++;
			if(y >= SIZE)
				y = 0;
			
			patterns[pCount][y] += 1;
			blocksToMove--;
		}
		
				
		for(i = 0; i < pCount - 1; i++)
		{
			patternFound = comparePatterns(patterns[i], patterns[pCount]);
			
			if(patternFound)
				break;
		}
		
		if(pCount < x - 1)
			pCount++;
		else
		{
			printf("error");
			break;
		}	
	}
	
	printf("\n%d\n", loops);	

	return 0;
}
