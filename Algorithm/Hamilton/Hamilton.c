//
//http://blog.csdn.net/Wiking__acm/article/details/12709023void Hamilton()
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


#define maxn 200
#define INF 1000000000

int N, M;
bool graph[maxn][maxn];
int hami[maxn];            //记录回路中的第i个点
bool flag[maxn];



//  哈密顿环求解
void Hamilton();
//  打印哈密顿回路
void PrintHamilton();

int main()
{
    freopen("in.txt", "r", stdin);

    while(scanf("%d%d", &N, &M) != EOF)
    {
        memset(graph, 0, sizeof(graph));
        memset(flag, 0, sizeof(flag));
        memset(hami, 0, sizeof(hami));

        for(int i = 0; i < M; i++)
        {
            int a, b;

            scanf("%d%d",&a,&b);
            a--;
            b--;
            graph[a][b] = graph[b][a] = true;
        }

        Hamilton();
        PrintHamilton();
    }

    return EXIT_SUCCESS;
}



void PrintHamilton()
{
    bool f = false;
    for(int i = 0; i < N; i++)
    {
        flag[hami[i]] = 1;
    }
    for(int i = 0; i < N; i++)
    {
        if(flag[i] != true)
        {
            f = true;
        }
    }
    if(f == true)
    {
        printf("no solution\n");
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            if(i == N - 1)
            {
                printf("%d\n", hami[i] + 1);
            }
            else
            {
                printf("%d ", hami[i] + 1);
            }
        }
    }
}


void Hamilton()
{
    int k;
    bool s[maxn];

    //  初始化设置图中没有哈密顿环
    for(int i = 0; i < N; i++)
    {
        hami[i] = -1;
        s[i] = false;
    }

    // 从第一个点出发开始寻找
    k = 1;
    s[0] = true;
    hami[0] = 0;

    while(k >= 0)
    {
        hami[k]++;              //

        while(hami[k] < N)                      //  走到最后一个定点为止
        {
            if(s[hami[k]] != true
            && graph[hami[k - 1]][hami[k]])     //  从k-1到当前顶点有路可达
            {
                break;
            }
            else                //  否则此路不可达, 继续寻找下一个顶点
            {
                hami[k]++;
            }
        }

        if((hami[k] < N)
        && (k != N - 1))
        {
            s[hami[k++]] = true;
        }
        else if((hami[k] < N)
             && (k == N - 1)
             && graph[hami[k]][hami[0]])
        {
            break;
        }
        else
        {
            hami[k] = -1;
            k--;
            s[hami[k]] = false;
        }
    }
}

