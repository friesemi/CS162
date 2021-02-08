#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int **array, int length, int width);

void deleteArray(int **array, int length){
	int i;
	for(i = 0; i < length; i++){
		free(array[i]);
	}
	free(array);
}

void addNum(int **array, int length, int width){
	int i, j, num;
	do{
		printf("Enter a number to add everywhere: ");
		scanf("%d", &num);
	}while(num < 0 && num > 100);
	for(i = 0; i < length; i++){
		for(j = 0; j < width; j++){
			array[i][j] = array[i][j] + num;
		}
	}
	printArray(array, length, width);
	deleteArray(array, length);
}

void printArray(int **array, int length, int width){
	int i, j;
	for(i = 0; i < length; i++){
		for(j = 0; j < width; j++){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

void popArray(int **array, int length, int width){
	int i, j;
	srand(time(NULL));
	for(i = 0; i < length; i++){
		for(j = 0; j < width; j++){
			array[i][j] = (rand() % 50) + 1;
		}
	}
	printArray(array, length, width);
}

void makeArray(){
	int width, length, i;
	int **array;
	do{
		printf("Enter a width: ");
		scanf("%d", &width);
	}while(width < 0 && width > 10);
	do{
		printf("Enter a length: ");
		scanf("%d", &length);
	}while(length < 0 && length > 10);

	array = (int**)malloc(length * sizeof(int *));
	for(i = 0; i < length; i++){
		array[i] = (int*)malloc(width * sizeof(int));
	}
	popArray(array, length, width);
	addNum(array, length, width);
}

int main(){
	makeArray();
}