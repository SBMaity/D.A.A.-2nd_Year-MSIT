#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,n,i,j,ne=1,min,mincost=0,*visited,**cost,k;
	printf("Enter the number of nodes:\t");
	scanf("%d",&n);
	k=n+1;
	visited=(int*)malloc(k*sizeof(int));
	for(i=0;i<k;i++)
	{
		visited[i]=0;
	}
	cost=(int**)malloc(k*sizeof(int*));
	for(i=0;i<k;i++)
	{
		cost[i]=(int*)malloc(k*sizeof(int));
	}
	printf("\nEnter the adjacency matrix:\n");
	for (i=1;i<k;i++)
	  for (j=1;j<k;j++) {
		scanf("%d",&cost[i][j]);
		if(cost[i][j] == 0)
		    cost[i][j] = 999;
	}
	visited[1]=1;
	while(ne < n) 
	{
		for (i=1,min=999;i<=n;i++)
			for (j=1;j<=n;j++)
				if(cost[i][j]<min)
					if(visited[i] != 0) {
						min=cost[i][j];
						a = i;
						b = j;
					}
		if(visited[a]==0 || visited[b]==0) {
			printf("\nEdge %d:\t(%d %d)\tCost:%d",ne++,a,b,min);
			mincost += min;
			visited[b] = 1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\nMinimum cost =\t%d",mincost);
	printf("\n");
	return 0;
}
