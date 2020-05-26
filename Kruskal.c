#include<stdio.h>
#include<stdlib.h>
typedef struct Gnode
{
        int start;
        int end;
        int weight;
}G;
typedef struct Node
{
        int value;
        struct Node *next;
}node;
typedef struct SET
{
        node *head;
        node *tail;
}set;
void kruskal(G *edges, set *d_set, int *parent, int n, int k);
void insertAtEnd(node **head, node **tail, int val);
void quick_sort(G *a, int p, int r);
int partition(G *a, int p, int r);
void swap(G *x, G *y);
int main()
{
        int **adj, n, i, j, *parent, k;
        set *d_set;
        printf("Enter number of vertices:\t");
        scanf("%d", &n);
        adj = (int **)malloc((n + 1) * sizeof(int *));
        parent = (int *)malloc((n + 1) * sizeof(int));
        d_set = (set *)malloc((n + 1) * sizeof(set));
        //adj = (int **)malloc((n + 1) * sizeof(int *));
        for(i = 1; i <= n; i++)
        {
            adj[i] = (int *)malloc((n + 1) * sizeof(int));
            d_set[i].head = NULL;
            d_set[i].tail = NULL;
            insertAtEnd(&d_set[i].head, &d_set[i].tail, i);
            parent[i] = i;
        }
        printf("Enter Adjacency Matrix\n");
        for(i = 1; i <= n; i++)
        {
                for(j = 1; j <= n; j++)
                {
                        scanf("%d", &adj[i][j]);
                        if(adj[i][j] != 0)
                                k++;
                }
        }
        G *edges = (G *)malloc(k * sizeof(G));
        k = 0;
        for(i = 1; i <= n; i++)
        {
                for(j = 1; j <= n; j++)
                {
                        if(adj[i][j] != 0)
                        {
                                edges[k].start = i;
                                edges[k].end = j;
                                edges[k].weight = adj[i][j];
                                k++;
                        }
                }
        }
        quick_sort(edges, 0, k - 1);
	printf("\nThe MST is :\t\n");
        kruskal(edges, d_set, parent, n, k);
        return 0;
}
void kruskal(G *edges, set *d_set, int *parent, int n, int k)
{
        int i, j, x, y, t, total = 0;
        node *temp;
        for(i = 0; i < k; i++)
        {
                x = parent[edges[i].start];
                y = parent[edges[i].end];
                if(x != y)
                {
                        if(x > y)
                        {
                                t = x;
                                x = y;
                                y = t;
                        }
                        (d_set[x].tail)->next = d_set[y].head;
                        temp = d_set[y].head;
                        while(temp != NULL)
                        {
                                parent[temp->value] = parent[x];
                                temp = temp->next;
                        }
                        d_set[y].head = d_set[y].tail = NULL;
                        printf("%d --> %d : %d\n", edges[i].start, edges[i].end, edges[i].weight);
                        total += edges[i].weight;
                }

        }
        printf("Total minimum cost is :\t%d\n", total);
}
void insertAtEnd(node **head, node **tail, int val)
{
        node *new = (node *)malloc(sizeof(node));
        new->value = val;
        new->next = NULL;
        if((*tail) == NULL)
        {
                *head = new;
                *tail = new;
        }
        else
        {
                (*tail)->next = new;
                *tail = new;
        }
}
void quick_sort(G *a, int p, int r)
{
        int q;
        if(p < r)
        {
                q = partition(a, p, r);
                quick_sort(a, p, q - 1);
                quick_sort(a, q + 1, r);
        }
}
int partition(G *a, int p, int r)
{
        int i, j;
        int  x;
        x = a[r].weight;
        i = p - 1;
        for(j = p; j <= r - 1; j++)
        {
                if(a[j].weight <= x)
                {
                        i++;
                        swap(&a[i], &a[j]);
                }
        }
        swap(&a[i + 1], &a[r]);
        return i + 1;
}
void swap(G *x, G *y)
{
        G t;
        t = *x;
        *x = *y;
        *y = t;
}
