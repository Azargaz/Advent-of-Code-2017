#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} List;

void initList(List *a, size_t startSize)
{
	a->array = (int *)malloc(startSize * sizeof(int));
	a->used = 0;
	a->size = startSize;
}

void insertToList(List *a, int element)
{
	if(a->used == a->size)
	{
		a->size *= 2;
		a->array = (int *)realloc(a->array, a->size * sizeof(int));
	}
	a->array[a->used++] = element;
}

int main(void) 
{
	FILE *file = fopen("input.txt", "r");
	char ch;
	int n = 0;
	int sum = 0;
	
	List list;
	initList(&list, 2);
	
	while ((ch = getc(file)) != EOF) 
	{
		int i = ch - '0';
		
		insertToList(&list, i);		
		n++;		
	}
	
	int i;
	for(i = 0; i < n; i++)
	{
		int id = i + (n / 2);
		
		if(i >= (n / 2))
		{
			id = i - n / 2;
		}
		
		if(list.array[i] == list.array[id])
		{
			sum += list.array[i];
		}
	}

	printf("Wynik: %d", sum);
	
	return 0;
}
