#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_VECTOR 50000

void print_vector(int v[]);
void assign_vector(int v[]);
double millisecondsToSeconds(int time);
void bubble_sort(int v[], int n);
void insertion_sort(int v[], int n);
void selection_sort(int v[], int n);

int main(int nargs, char* args[]) {
	
	int i, n;
	clock_t begging, end;
	int vector[SIZE_VECTOR];
	double bubble_time, insertion_time, selection_time;

	srand(time(NULL));

	begging = clock();

	assign_vector(vector);
	//print_vector(vector);


	bubble_sort(vector, SIZE_VECTOR);
	//print_vector(vector);

	end = clock();

	bubble_time = millisecondsToSeconds(end - begging);

	printf("BUBBLE SORT:\t%.2f segundos\n", bubble_time);

	begging = clock();

	assign_vector(vector);
	//print_vector(vector);

	insertion_sort(vector, SIZE_VECTOR);
	//print_vector(vector);

	end = clock();

	insertion_time = millisecondsToSeconds(end - begging);

	printf("INSERTION SORT:\t%.2f segundos\n", insertion_time);

	begging = clock();

	assign_vector(vector);
	//print_vector(vector);

	selection_sort(vector, SIZE_VECTOR);
	//print_vector(vector);
	
	end = clock();

	selection_time = millisecondsToSeconds(end - begging);

	printf("SELECTION SORT:\t%.2f segundos\n", selection_time);
	printf("\n");
	

	if(bubble_sort > insertion_sort) {
		if(bubble_sort > selection_sort)
			printf("O ALGORITMO MAIS EFICIENTE FOI O BUBBLE SORT\n");	

		printf("O ALGORITMO MAIS EFICIENTE FOI O SELECTION SORT\n");	
    } else {
		if(insertion_sort > selection_sort)
			printf("O ALGORITMO MAIS EFICIENTE FOI O INSERTION SORT\n");			

		printf("O ALGORITMO MAIS EFICIENTE FOI O SELECTION SORT\n");
	}
	

	return EXIT_SUCCESS;
}

/*
* Print all the elements of a vector
*/
void print_vector(int v[]) {
	int i; 

	for (i = 0; i < SIZE_VECTOR; ++i)
	{
		printf("vector[%d]: %d\n", i, v[i]);
	}
	printf("\n");
}

/*
* Initial random assign of a vector 
* Range: 1..5000000
*/
void assign_vector(int v[]) {
	int i;

	for (i = 0; i < SIZE_VECTOR; ++i)
	{
		v[i] = (rand()%5000001);
	}
}

/*
* Converts millisecongs to seconds
*/
double millisecondsToSeconds(int ms) {
	return (double)ms / CLOCKS_PER_SEC;
}

/*
* Bubble sort implementetion
*/
void bubble_sort(int v[], int n) {
	int i, j;
	int aux;

	for( i = 0; i < n; i++ )
	{
		for( j = i + 1; j < n; j++ )
		{
			if ( v[i] > v[j] )
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

/*
* Insertion sort implementetion
*/
void insertion_sort(int v[], int n) {
	int i, aux;
 
	for(i = 1; i < n; i++){
	        while((i != 0) && (v[i] < v[i - 1])) {

	                aux = v[i];
	                v[i] = v[i - 1];
	                v[i - 1] = aux;
	                i--;    
	        }               
	}
}

/*
* Selection sort implementetion
*/
void selection_sort(int v[], int n) {
	int i, j, min, swap;

	for (i = 0; i < (n-1); i++) {
		min = i;
		for (j = (i+1); j < n; j++) {
		  if(v[j] < v[min]) {
		    min = j;
		  }
		}
		if (i != min) {
		  swap = v[i];
		  v[i] = v[min];
		  v[min] = swap;
		}
	}
}
