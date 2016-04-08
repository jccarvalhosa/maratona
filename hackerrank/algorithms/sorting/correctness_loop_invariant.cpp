#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/* Head ends here */
void insertionSort(int ar_size, int *  ar) {    
	int i,j;
	int value;
	for(i=1;i<ar_size;i++)
	{
		j=i;
		while(j>0 && ar[j]<ar[j-1])
		{
			value = ar[j];
			ar[j] = ar[j-1];
			ar[j-1] = value;
			j=j-1;
		}
	}
	for(j=0;j<ar_size;j++)
	{
		printf("%d",ar[j]);
		printf(" ");
	}
}
/* Tail starts here */
int main(void) {

	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
		scanf("%d", &_ar[_ar_i]); 
	}

	insertionSort(_ar_size, _ar);

	return 0;
}
