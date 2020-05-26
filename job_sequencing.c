/************************************************************************
*	Topic:	Job Sequencing with deadlines using greedy method			*
*	Owner:	Sumit Bikram Maity											*
*************************************************************************/
#include<stdio.h>
#include<stdlib.h>

//Structure of jobs...
typedef struct jobs{
	char id[15];
	int deadline;
	int profit;
}jobs;

//Function prototypes.....
void bubbleSort(jobs*, int);
void swap(jobs*, jobs*);
void sequence(jobs*, int, int);
int main()
{
	int n, i, j, max = 0;
	printf("Enter the number of jobs:\t");
	scanf("%d", &n);
	jobs *arr = (jobs *)malloc(n * sizeof(jobs));
	printf("=====================================================\n");
	printf("Enter :: (Job ID)<<space>>(Deadline)<<spcae>>(Profit)\n");
	for(i = 0; i < n; i++){
		printf("==========Enter Job %d's details==========\n", i + 1);
		scanf("%s %d %d", arr[i].id, &arr[i].deadline, &arr[i].profit);
		if( arr[i].deadline >= max){
			max = arr[i].deadline;
		}
	}
	printf("Maximum deadline is:\t %d", max);
	//Printing the summary of all details...
	printf("\n=================Check all the Details===============\n");
	for(i = 0; i < n; i++){
		printf("\t%s", arr[i].id);
	}
	printf("\nTime:");
	for(i = 0; i < n; i++){
		printf("\t%d", arr[i].deadline);
	}
	printf("\nProfit:");
	for(i = 0; i < n; i++){
		printf("\t%d", arr[i].profit);
	}
	//sorting the structure array non-inceasingly...
	bubbleSort(arr, n);
	//Structure array sorted according to their profit.
	printf("\n\n===========Table after sorting(Profit Basis)=========\n");
	for(i = 0; i < n; i++){
		printf("\t%s", arr[i].id);
	}
	printf("\nTime:");
	for(i = 0; i < n; i++){
		printf("\t%d", arr[i].deadline);
	}
	printf("\nProfit:");
	for(i = 0; i < n; i++){
		printf("\t%d", arr[i].profit);
	}
	sequence(arr, n, max);
	free(arr);
	printf("\n");
	return 0;
}

//Swap function definition...
void swap(jobs *a, jobs *b)
{
	jobs temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//Bubble sorting function...
void bubbleSort(jobs *arr, int n){
	int i, j;
	for(i = 0; i < (n - 1); i++){
		for( j = 0; j < (n-i-1); j++){
			if(arr[j].profit < arr[j + 1].profit){
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
//Function for sequencing the jobs...
void sequence(jobs* arr, int n, int max){
	int i, j, res = 0;

	int *s = (int *)malloc(max * sizeof(int));
	for(i = 0; i < max; i++){
		s[i] = -1;
	}
	for(i = 0; i < n; i++){
		for(j = arr[i].deadline; j >= 0; j--){
			if((s[j] == -1) && (j < arr[i].deadline)){
				s[j] = i;
				res += arr[i].profit;
				break;
			}
		}
	}
	printf("\n\n\nTotal Profit is:\t%d", res);
	printf("\nRequired Sequece is:\n");
	for(i = 0; i < max; i++){
		if(s[i] != -1){
			printf("%s\t", arr[s[i]].id);
		}
	}
	free(s);
}
