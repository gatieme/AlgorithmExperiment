//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10001		

int N, M;
int used[MAX_SIZE];

int graph[MAX_SIZE][MAX_SIZE],x[MAX_SIZE];
int s;//

int counter = 1;			

int path_ok(int graph[][MAX_SIZE],int k,int x[])
{
    if(used[x[k]])
    {
        return false;
    }
    
    if(k < N)
    {
		return graph[x[k-1]][x[k]];
    }
	else
	{
   		return graph[x[N-1]][x[N]] && graph[x[1]][x[N]];
	}
}

bool rehamilton(int graph[][N + 1],int k, int x[])
{
    for(x[k] = 1; x[k] <= N; x[k]++)
    {
    	if(path_ok(graph, k, x))
   		{
			used[x[k]] = true;
            if(k == N || rehamilton(graph, k+1, x))
      	    {
				printf("begin Case %-2d: %d",counter++,x[1]);
     			
     	        for(int i = 2; i <= N; i++)
     		    {
      				printf("=> %d", x[i]);
     			}
     			printf("=> %d\n", x[1]);
     		}
    	
    		used[x[k]] = false;
		}
    }
	return false;
}

void hamilton(int graph[][MAX_SIZE],int x[])
{
    int t = 2;
    for(s = 1; s <= N; s++)
    {
        for(int i=1;i<=N;i++)
        {
            used[i]=false;
        }

        x[1]=s;

        used[x[1]]=true;
     
        rehamilton(graph,2,x);
    }
}


int main()
{
	freopen("in.txt", "r", stdin);
	int a,b;
	
    while(scanf("%d%d", &N, &M) != EOF)
    {
		printf("%d %d\n", N, M);
		memset(graph, 0, MAX_SIZE);
        for(int i = 1; i <= M; i++)
        {
            scanf("%d%d", &a, &b);
            printf("%d %d\n", a, b);
			graph[a][b] = 1;
            graph[b][a] = 1;
        }

		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				printf("%3d", graph[i][j]);
			}
			printf("\n");
		}
		hamilton(graph, x);
	}
	printf("END\n");
    return 0;
}
