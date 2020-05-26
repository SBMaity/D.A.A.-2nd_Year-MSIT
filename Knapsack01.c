/****************************************************************************************
*	This is the implementaion of 0/1 knapsack problem using Dynamic Programming...		*
*	Owner:	Sumit Bikram Maity.															*
*****************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct kscak{
	char item[15];
	int weight;
	int profit;
}ksack;

//Function prototypes...
int max (int a, int b);
int knapsack(int, ksack *, int);

int main(){
	int n, i, capacity;
	ksack* arr;
	printf("Enter the knapsack capacity:\t");
	scanf("%d", &capacity);

	printf("Enter total no of items:\t");
	scanf("%d", &n);

	arr = (ksack *)malloc(n * sizeof(ksack));

	printf("\nEnter Asked Details:\n");
	printf("-------------------------------------\n");
	for(i = 0; i < n; i++){
		printf("=====Enter details of the item %d=====", i+1);
		printf("\nEnter item name:\t");
		scanf("%s", arr[i].item);
		printf("Weight:\t");
		scanf("%d", &arr[i].weight);
		printf("Profit:\t");
		scanf("%d", &arr[i].profit);
	}
	printf("-------------------------------------\n");
	printf("All Inputs are taken.\nThe table is:\n");
	printf("\nMaximum Profit:\t%d\n", knapsack(capacity, arr, n));
	free(arr);
	return 0;
}

//Max function definition...
int max(int a, int b){
	return (a > b) ? a : b;
}

//Knapsack function definition...
int knapsack(int capacity, ksack *arr, int n){
	int i, j, k;
	int **table = (int **)malloc((n + 1) * sizeof(int *));
	for(i = 0; i <= (n + 1); i++)
		table[i] = (int *)malloc((capacity + 1) * sizeof(int));
	
	for(j = 0; j <= n; j++){
		for(k = 0; k <= capacity; k++){
			if(j == 0 || k == 0){
				table[j][k] = 0;
			}else if(arr[j - 1].weight <= k){
				table[j][k] = max(arr[j - 1].profit + table[j - 1][k - arr[j - 1].weight], table[j - 1][k]);
			}else{
				table[j][k] = table[j - 1][k];
			}
		}
	}
	for(j = 0; j <= n; j++){
		for(k = 0; k <= capacity; k++){
			printf("%.2d  ", table[j][k]);
		}
		printf("\n");
	}
	return table[n][capacity];
	free(table);
}
