/************************************************************
*	This is the implementation of graph coloring...	        *
*	~© Sumit Bikram Maity.					                *
*************************************************************/

#include<stdio.h>
#include<stdlib.h>

void graph_color(int k, int **arr, int *color){
	int i, j;
	for(i = 0; i < k; i++){
		if(arr[i][k] != 0 && color[k] == color[i]){
			color[k] = color[i] + 1;
		}
	}
}
int main()
{
	int n, i, j;
	printf("Enter the number of vertices:\t");
	scanf("%d", &n);
	//Creating the color array list...
	int *color = (int *)malloc(n * sizeof(int));
	//Forming the 2D array...
	int **arr = (int**)malloc(n * sizeof(int *));
	for(i = 0; i < n; i++)
		arr[i] = (int *)malloc(n * sizeof(int));
	
	printf("\n====================================");
	printf("\nEnter the adjacent matrix...\n");
	//Taking the inputs for 2D array...
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	//Confirmation...
	printf("========Entered Adjacency Matrix========\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	//Traversing the vertices to assign color...
	for(i = 0; i < n; i++){
		color[i] = 1;
		graph_color(i, arr, color);
	}
	//Printing all the vertices with its color...
	printf("\nSo, Our required color combination is:");
	for(i = 0; i < n; i++){
		printf("\nv(%d):\tc(%d)", i + 1, color[i]);
	}
	printf("\n\nSo, Minimum number of color required is:\t%d", color[i-1]);
	printf("\n");
	return 0;
}
