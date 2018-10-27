#include <stdio.h>

//Swap function
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
//Bubble sort
void sort_num(int *arr, int length){
	for (int idex = length-1; idex != 0; idex--){
		for (int i = 0; i < idex; i++){
			if (arr[i] < arr[i + 1])
				swap(&arr[i], &arr[i + 1]);
		}
	}
}

int main(){

	char arr[20];
	int int_arr[20];
	int length, i;
	//get the string of number
	scanf("%s", arr);

	//change to int
	for (i = 0; arr[i]!='\0';i++){
		int_arr[i] = arr[i] - '0';
	}
	length = i;

	//sort the number
	sort_num(int_arr, length);
	
	//print the sorted number
	for (i = 0; i<length; i++){
		printf("%d", int_arr[i]);
	}
	printf("\n");
	return 0;
}
