#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int test = 12;
	int input = 368078;
	int debug = 0;
	int x = (debug ? test : input);

	printf("X: %d\n", x);
	
	int n = 1;
	int i = 1;
	
	while(x > n*n)
	{
		n += 2;		
		i++;
	}

	int distToSqr = (x - (n*n)) % (n-1);
	distToSqr *= (distToSqr > 0) ? 1 : -1;	
	distToSqr = (distToSqr > (n/2)) ? n-1-distToSqr : distToSqr;	
	
	printf("%d\n", distToSqr);
	
	printf("Sqr: %d\nNo. of paths: %d\nLongest path: %d\nShortest path: %d\nPathToCenter: %d\n", n, i, ((i-1)*2), i-1, ((i-1)*2) - distToSqr);
	
	return 0;
}
