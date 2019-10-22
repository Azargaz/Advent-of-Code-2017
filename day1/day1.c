#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	FILE *file = fopen("input.txt", "r");
	char ch;
	int first = 0;
	int last = -1;
	int n = 1;
	int sum = 0;

	while ((ch = getc(file)) != EOF) 
	{
		int i = ch - '0';
		
		if(n == 1)
			first = i;
			
		if(i == last)
		{
			sum += i;	
		}
		
		last = i;		
		n++;		
	}
	
	if(last == first)
		sum += last;
	
	
	printf("Last: %d First: %d n: %d\n", last, first, n);
	printf("Wynik: %d", sum);
	
	return 0;
}
