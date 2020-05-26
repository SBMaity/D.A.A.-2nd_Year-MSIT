#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
void queen(int row, int n, int *board);
void print(int n, int *board);
int place(int row, int column, int *board);
int count = 0;
 
int main()
{
	int n, i, j, *board;
	printf("Enter number of Queens:\t");
	scanf("%d", &n);
	board = (int *)malloc(n * sizeof(int));
	queen(1, n, board);
	printf("\n");
	return 0;
}

void print(int n, int *board)
{
	int i,j;
	printf("\n\nSolution %d:\n",++count);
 
	for(i=1; i<=n; ++i)
		printf("\t%d",i);
 
	for(i=1; i<=n; ++i)
 	{
		printf("\n%d",i);
  		for(j=1; j<=n; ++j) 
  		{
   			if(board[i] == j){
    				printf("\tQ"); 
			}else{
    				printf("\t~");
			}
  		}
 	}
}
 
int place(int row, int column, int *board)
{
	int i;
 	for(i=1; i<=row-1; ++i)
 	{
  		if(board[i] == column)
   			return 0;
  		else
   			if(abs(board[i] - column) == abs(i-row))
	   			return 0;
	}
 	return 1; 
}
void queen(int row, int n, int *board)
{
	int column;
	 for(column=1; column<=n; ++column){
		if(place(row, column, board) == 1){
			board[row] = column; 
			if(row == n) 
				print(n, board); 
			else 
				queen(row + 1, n, board);
		}
	}
}
