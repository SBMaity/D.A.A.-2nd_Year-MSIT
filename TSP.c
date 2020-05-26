#include<stdio.h>
#include<stdlib.h>

int cost = 0;
void mincost(int, int *, int **, int);
int least(int, int *, int **, int);

void mincost(int city,int *visited,int **arr, int n)
{
	int i, ncity;
	visited[city] = 1;	
	printf("%d-->", city + 1);
	ncity = least(city, visited, arr, n);
	if(ncity == 999)
	{
		ncity = 0;
		printf("%d", ncity + 1);
		cost += arr[city][ncity];
		return;
	}
	mincost(ncity, visited, arr, n);
}

int least(int c, int *visited, int **arr, int n)
{
	int i, nc = 999;
	int min = 999, kmin;
	for(i = 0; i < n; i++)
	{
		if((arr[c][i] != 0) && (visited[i] == 0))
			if(arr[c][i] < min)
			{
				min = arr[i][0] + arr[c][i];
				kmin = arr[c][i];
				nc = i;
			}
	}
	if(min!=999)
		cost += kmin;
	return nc;
}

int main()
{
	int i, j,**arr, *visited, n;
	printf("Enter No. of Cities:\t");
	scanf("%d",&n);
	arr = (int**)malloc(n*sizeof(int*));
	for(i = 0; i < n; i++)
	{
		arr[i]=(int*)malloc(n*sizeof(int));	
	}
	visited=(int*)malloc(n*sizeof(int));
	printf("\nEnter Cost Matrix:\n");
	for(i = 0; i < n; i++){
		printf("\t%d", i + 1);
	}
	printf("\n");
	for(i = 0; i < n; i++){
		printf("\t---");
	}
	for(i = 0; i < n; i++)
	{
		printf("\n%d  |", i + 1);
		for(j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
		visited[i] = 0;
	}
	printf("\nThe cost list is:\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");	
	}
	printf("\nVisited Path is:\n");
	mincost(0, visited, arr, n);
	printf("\n\nMinimum cost:\t");
	printf("%d\n", cost);

	return 0;
}