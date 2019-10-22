#include <stdio.h>
#include <stdlib.h>

int spiral(int n)
{
	int sum = 0;
	
	if(n > 2)
	{
		int i;
		int d = 2; // spaces between 'neighbours = 2'
		int c = 0; // count
		int neighbours = 2;
		int n1 = 1; // neighbour #1
		int n2 = 2;	// neighbour #2
		int n3 = 2;	// neighbour #3
		int n4 = 0; // neighbour #4
		
		for(i = 3; i < n; i++)
		{
			c++;
						
			if(c == d || c == 2*d)
			{
				neighbours = 2;
				n3++;				
			}
			else if(c == d - 1 || c == 2*d - 1)
			{
				neighbours = 3;	
				if(c == 1 || (c - d) == 1)
				{
					n2 = 2;
					n3++;
				}
				else
				{
					n2 = n3 + 1;
				}
			}
			else if(i != 3)
			{
				neighbours = 4;
				if(c == 1 || (c - d) == 1)
				{
					n2 = 2;
					n3++;
					n4 = n3 - 1;
				}
				else
				{
					n2 = n3 + 1;
					n4 = n3 - 1;
				}
			}	
			
			if(c == 2*d)
			{
				c = 0;
				d++;
			}
		}
		
		//printf("n: %d n1: %d n2: %d n3: %d n4: %d\n", n, n1, n2, n3, n4);
		//printf("--------------\n");
		
		if(neighbours == 2)
		{
			sum += spiral(n - n1) + spiral(n - n3);
		}
		else if(neighbours == 3)
		{
			sum += spiral(n - n1) + spiral(n - n2) + spiral(n - n3);
		}
		else
		{
			sum += spiral(n - n1) + spiral(n - n2) + spiral(n - n3) + spiral(n - n4);
		}
		
		return sum;
	}
	else if(n <= 0)
	{
		printf("ERROR n <= 0\n");
		return 0;	
	}
	else
		return 1;
}

int main(void) 
{
	int test = 147;
	int input = 368078;
	int debug = 0;
	int x = (debug ? test : input);

	printf("X: %d\n", x);
	
	int n = 1;	
		
	while(x > spiral(n))
	{
		n++;
	}	
		
	printf("Spiral: %d\n", spiral(n));
	return 0;
}
