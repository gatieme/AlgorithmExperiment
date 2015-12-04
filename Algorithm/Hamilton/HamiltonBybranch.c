#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 21

//���һ�·����
void getHamiltonPathBybranch(int graph[MAX_SIZE][MAX_SIZE],int visited[MAX_SIZE],
                             int path[MAX_SIZE],int bestpath[MAX_SIZE],
                             int len,int currentlen,int *mincost);
//���㵱ǰ·���Ĵ���
int getPathcost(int path[MAX_SIZE],int graph[MAX_SIZE][MAX_SIZE],int currentlen);

int main(void)
//HamiltonBybranch()
{
    int len,i,j,mincost;//lenΪ����
    int graph[MAX_SIZE][MAX_SIZE];//�ڽӾ���
    int visited[MAX_SIZE],path[MAX_SIZE],bestpath[MAX_SIZE];//����Ѷ���·��


    freopen("in.txt","r",stdin);
   // freopen("BranchOutput.txt","w",stdout);
    //
    while(scanf("%d", &len) != EOF)
    {
        //��ʼ��
        for(i = 1; i<= len; i++)
        {
            visited[i] = 0;
            path[i] = -1;
            bestpath[i] = -1;
            for(j = 1; j <= len; j++)
            {
                scanf("%d", &graph[i][j]);
                printf("%4d", graph[i][j]);
            }
            printf("\n");
        }

        path[1] = 0;
        visited[1] = 1;
        mincost = 100 * len;
        getHamiltonPathBybranch(graph, visited, path, bestpath, len, 1, &mincost);

        printf("\nLines \n");
        for(int i = 1; i <= len; i++)
        {
            printf("%4d", bestpath[i]);
        }
        printf("\ncost = %d\n",mincost);
    }
}

void getHamiltonPathBybranch(int graph[MAX_SIZE][MAX_SIZE],int visited[MAX_SIZE],
                             int path[MAX_SIZE],int bestpath[MAX_SIZE],
                             int len,int currentlen,int *mincost)
{
    int i, costpath;
    if(len == currentlen)
    {
        costpath = getPathcost(path, graph, currentlen) + graph[path[currentlen - 1]][1];
        if(costpath < *mincost)
        {
            *mincost = costpath;
            for(i = 1; i<= len; i++)
            {
                bestpath[i] = path[i];
            }

            return;
        }
    }

    for(i = 2; i <= len; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            path[currentlen] = i;
            if(getPathcost(path, graph, currentlen + 1) < *mincost)
            {
                getHamiltonPathBybranch(graph, visited, path, bestpath, len, currentlen + 1, mincost);
            }

            path[currentlen] = -1;

            visited[i] = 0;
        }
    }
}

int getPathcost(int path[MAX_SIZE], int graph[MAX_SIZE][MAX_SIZE], int currentlen)
{
    int i, cost;
    cost = 0;
    for(i = 2; i <= currentlen; i++)
    {
        cost = cost + graph[path[i - 1]][path[i]];
    }
    return cost;
}
