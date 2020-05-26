#include<stdio.h>
#include<stdlib.h>

int  front = -1,rear = -1; 
void BF_Traversal(int n,int *state,int *queue,int **adj);
void BFS(int v,int n,int *queue,int *state,int **adj);
void insert_queue(int vertex,int *queue,int n);
int delete_queue(int *queue);
int isEmpty_queue(int *queue);

int main()
{
	int n,i,j,**adj,*state,*queue;
	printf("Enter number of vertices:\t");
	scanf("%d",&n);
	adj=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		adj[i]=(int*)malloc(n*sizeof(int));
	}
	printf("\nEnter adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	state=(int*)malloc(n*sizeof(int));
	queue=(int*)malloc(n*sizeof(int));
	BF_Traversal(n,state,queue,adj);
	return 0;
}
 
void BF_Traversal(int n,int *state,int *queue,int **adj)
{
	int v;	
	for(v=0; v<n; v++) 
		state[v] = 1;

	printf("\nEnter Start Vertex for BFS:\t");
	scanf("%d", &v);
	printf("BFS Traversal: ");
	BFS(v,n,queue,state,adj);
}
void BFS(int v,int n,int *queue,int *state,int **adj)
{
	int i;
	insert_queue(v,queue,n);
	state[v] = 2;
	while(!isEmpty_queue(queue))
	{
		v = delete_queue(queue);
		printf("%d\t",v+1);
		state[v] = 3;
		
		for(i=0; i<n; i++)
		{
			if(adj[v][i] == 1 && state[i] == 1) 
			{
				insert_queue(i,queue,n);
				state[i] = 2;
			}
		}
	}
	printf("\n");
}
void insert_queue(int vertex,int *queue,int n)
{
	if(rear == n-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1) 
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}
 
int isEmpty_queue(int *queue)
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
} 
int delete_queue(int *queue)
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
		
	delete_item = queue[front];
	front = front+1;
	return delete_item;
}
