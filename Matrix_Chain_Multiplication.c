/*________________MATRIX CHAIN MULTIPLICATION____________*/
#include<stdio.h>
#include<stdlib.h>

void print(int **, int, int);

int main()
{
        int n, i, j, k, l, q, *dim, x, y, z;
        printf("Number of the matrices:\t");
        scanf("%d", &n);

        n++;
        dim = (int *)malloc(n * sizeof(int));
        for(i = 0; i < n; i++){
                printf("Enter Value:\t");
                scanf("%d", &dim[i]);
        }
        printf("\nDone..");
        int **m, **s;
        //2D array for m..
        m = (int **)malloc(n * sizeof(int *));
        for(j = 0; j < n; j++){
                m[j] = (int *)malloc(n * sizeof(int));
        }
        //2D array for n...
        s = (int **)malloc(n * sizeof(int *));
        for(j = 0; j < n; j++){
                s[j] = (int *)malloc(n * sizeof(int));
        }
        for(i = 1; i < n; i++){
                for ( j = 1; j < n; j++)
                {
                        m[i][j] = 0;
                        s[i][j] = 0;
                }
        }
        for(l = 2; l < n; l++){
                for(i = 1; i < (n-l+1); i++){
                        j = i+l-1;
                        m[i][j] = 999999;
                        for(k = i; k < j; k++){
                                q = m[i][k] + m[k+1][j] + (dim[i-1] * dim[k] * dim[j]);
                                if(q < m[i][j]){
                                        m[i][j] = q;
                                        s[i][j] = k;
                                }
                        }
                }
        }
        printf("\n");
        //Printing all the costs...
        printf("\nCost table is:\n");
        for(x = 1; x < n; x++){
                for(y = 1; y < n; y++){
                        printf("%d\t", m[x][y]);
                }
                printf("\n");
        }
        //Minimum cost printing...
        printf("\nSo, Min cost:\t%d", m[1][n-1]);
        printf("\n");
        printf("\nMultiplication parenthesization:\n");
        //Parenthesized Multiplication...
        print(s, 1, n-1);
        printf("\n");
        return 0;
}
//function for pinting the chian..
void print(int **s, int i, int j){
        if(i == j)
        {
                printf("M%d ", i);
        }else{
                printf(" ( ");
                print(s, i, s[i][j]);
                print(s, s[i][j]+1, j);
                printf(" ) ");
        }
}
