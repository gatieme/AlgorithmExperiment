

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 10000 //µãµÄ¸öÊý¿ÉÒÔ×Ô¼º¶¨Òå

int used[Vertexnum+1];
int s;//
int counter = 1;//¼ÆËã´ÓÒÔx[1]ÎªÆðµãµÄ×ÜµÄ¹þÃÜ¶Ù»·Â·

int path_ok(int adj[][Vertexnum+1],int k,int x[])
{
    if(used[x[k]])
    {
        return false;
    }
    if(k<Vertexnum)
    {
        return adj[x[k-1]][x[k]];
    }
    else
    {
        return adj[x[Vertexnum-1]][x[Vertexnum]]&&adj[x[1]][x[Vertexnum]];
    }
}

bool rehamilton(int adj[][Vertexnum+1],int k,int x[])
{
    for( x[k]=1;x[k]<=Vertexnum;x[k]++)
    {
        if(path_ok(adj,k,x))
        {
            used[x[k]]=true;
            if(k==Vertexnum||rehamilton(adj,k+1,x))
            {
                printf("begin Case %-2d: %d",counter++,x[1]);//Êä³öÒ»¸ö¹þÃÜ¶Ù»·Â·
    
                for(int i=2;i<=Vertexnum;i++)
                {
                    printf("=> %d",x[i]);
                }
                printf("=>%d\n",x[1]);
            }
            used[x[k]]=false;
        }
   }
   return false;
}


void hamilton(int adj[][Vertexnum+1],int x[])
{
    int t = 2;
    for(s = 1; s <= Vertexnum; s++)
    {
        for(int i=1;i<=Vertexnum;i++)
        {
            used[i]=false;
        }

        x[1]=s;//´Ós³ö·¢

        used[x[1]]=true;
     
        rehamilton(adj,2,x);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);

    int i,j,adj[Vertexnum+1][Vertexnum+1],x[Vertexnum+1];
    
    for(i=1;i<=Vertexnum;i++)
    {
        for(j=1;j<=Vertexnum;j++)
        {
            scanf("%d",&adj[i][j]);//ÊäÈëÁÚ½Ó¾ØÕó
        }
    }

   hamilton(adj,x);
   printf("END\n");
   return 0;
}
