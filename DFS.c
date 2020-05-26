#include<stdio.h>
#include<stdlib.h>

void creategraph(int n,int **graph);
void dfs( int i, int n, int *visited, int **graph);

int main()
{
	int n,**graph,*visited,i,j,v;
	printf("Enter no of vertices:\t");
	scanf("%d",&n);
	visited=(int*)malloc(n*sizeof(int));
	graph=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		graph[i]=(int*)malloc(n*sizeof(int));
	}
	printf("Enter adjacency matrix of graph:\n");
	creategraph(n,graph);
	for(i=0; i<n; i++){
		visited[i]=0;
	}
	printf("\n");
	printf("Enter starting vertex:\t");
	scanf("%d", &v);
	dfs(v, n, visited, graph);
	printf("\n");
	return 0;
}
void creategraph(int n,int **graph){
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d", &graph[i][j]);
		}
	}
}
void dfs( int i, int n, int *visited, int **graph){
	int j;
	printf("%d\t",i+1);
	visited[i]=1;
	for(j=0;j<n;j++){
		if(!visited[j] && graph[i][j] == 1)
			dfs(j,n,visited,graph);
	}
}
