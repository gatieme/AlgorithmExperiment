#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstring>
#include <cstdlib>


//#include<windows.h>


#include <ctime>
#include <cmath>
#define L 1
#define N 20

#define MAX_VALUE 10000

using namespace std;



class wndbgn
{

private:
	int qess;
	int efsfcsc[N],wbngjgf[N];
	int c[N][N];
	int k;
public:
	wndbgn(int b[N][N])
	{
		k=0;
		for(int i=0;i<N;i++)
		{
			efsfcsc[i]=-1;
			for(int j=0;j<N;j++)
				c[i][j]=b[i][j];
		}
		qess=MAX_VALUE;
	}
	void  opwbngjgf(int n ,int lon)
	{
	   if(n==N)
	   {
		   if(efsfcsc[N-1]==L-1&& qess>iokgb())
		   {
			   qess=iokgb();
			   for(int i=0;i<N;i++)
               wbngjgf[i]=efsfcsc[i];
		   }
	   }
	   else if(n==0)
	   {
		   for(int i=0;i<N;i++)
		   {
			   efsfcsc[n]=i;
               opwbngjgf(n+1,lon);
			   efsfcsc[n]=-1;
		   }
	   }
	   else
	   for(int i=0;i<N;i++)
	   {
		   int lon1=lon+c[efsfcsc[n-1]][i];
		   if(!uninclude(i)&&lon1<qess)
		   {
			   efsfcsc[n]=i;
               opwbngjgf(n+1,lon1);
			   efsfcsc[n]=-1;
		   }
		   lon=lon-c[efsfcsc[n-1]][efsfcsc[n]];
	   }
	}
	int iokgb()
	{
        int i, j, qess1;
		for(qess1 = 0,j = L - 1,i = 0; i < N; i++)
		{
			qess1=qess1+c[j][efsfcsc[i]];
            j=efsfcsc[i];
	    }
		return qess1;
	}

    void prin()
	{
	   cout<<endl;

	   cout<<qess<<endl;

	   cout<<L;
	   for(int i=0;i<N;i++)
		   cout<<"-->"<<wbngjgf[i]+1;
	   cout<<endl;
	}

	int uninclude(int n)
	{
	   for(int i = 0; i < N && efsfcsc[i] >= 0; i++)
       {
		   if(efsfcsc[i]==n)
           {
			   return 1;

           }

           return 0;
				 }
			 }
};

class NOOOO
{
private:

    int dadadwe;
	int hkhkhg[2][N];
	int gywew[2][N];
	int c[N][N];

public:
	int path[N];
	int trygm;
	int yrnfgagh;

    NOOOO(int k,int A[N][N],int n)
	{
		for(int i=0;i<2;i++)
			for(int j=0;j<N;j++)
			{
				hkhkhg[i][j]=0;
				gywew[i][j]=0;
			}

            trygm = n;

            yrnfgagh = 0;

            dadadwe = k;

            for(int i = 0; i < N; i++)
            {
				path[i] = 0;
            }

            path[dadadwe] = trygm + 1;

            cdfraasf(c, A);

            gy();
	}

	NOOOO(int k,NOOOO A)
	{
		cdfraasf(hkhkhg,A.hkhkhg);
		cdfraasf(gywew,A.gywew);
		trygm=A.trygm+1;
		dadadwe=k;
		cdfraasf(c,A.c);
		yrnfgagh=A.yrnfgagh+c[A.dadadwe][dadadwe];
		cdfraasf(path,A.path);
		path[dadadwe]=trygm+1;

		for(int i=0;i<N;i++)
		{
			if(!c[A.dadadwe][i])
			{
				hkhkhg[0][A.dadadwe]--;
				hkhkhg[1][i]--;
			}
			c[A.dadadwe][i]=MAX_VALUE;
		}
		gywew[0][A.dadadwe]=1;

        for(int i = 0; i < N; i++)
		{
			if(!c[i][dadadwe])
			{
				hkhkhg[0][i]--;
				hkhkhg[1][dadadwe]--;
			}
			c[i][dadadwe]=MAX_VALUE;
		}

        gywew[1][dadadwe]=1;

		if(trygm!=N-1)
		{
			if(!c[dadadwe][L-1])
			{
				hkhkhg[0][dadadwe]--;
				hkhkhg[1][L-1]--;
			}
			c[dadadwe][L-1]=MAX_VALUE;

        }
		gy();
	}
	void gy()
	{
		int j;

		for(int i=0;i<N;i++)
			if(!gywew[0][i]&&!hkhkhg[0][i])
			{
				int m=lqess(i,c);
				yrnfgagh=yrnfgagh+m;
				for(int j=0;j<N;j++)
				{
					c[i][j]=c[i][j]-m;
					if(!c[i][j])
					{
						hkhkhg[0][i]++;
						hkhkhg[1][j]++;
					}
				}
			}

			for(int i = 0; i < N; i++)
				if(!gywew[1][i]&&!hkhkhg[1][i])
				{
					int m=cqess(i,c);
					yrnfgagh=yrnfgagh+m;
					for(j=0;j<N;j++)
					{
						c[j][i]=c[j][i]-m;
						if(!c[j][i])
						{
							hkhkhg[0][j]++;
							hkhkhg[1][i]++;
						}
					}
				}
	}

	void cdfraasf(int A[N],int B[N])
	{
		for(int i=0;i<N;i++)
			A[i]=B[i];
	}

	void cdfraasf(int A[N][N],int B[N][N])
	{
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				A[i][j]=B[i][j];
	}

	int lqess(int i,int A[N][N])
	{
		int qess=A[i][0];
		for(int j=0;j<N;j++)
			if(qess>A[i][j])
				qess=A[i][j];
		return qess;
	}

	int cqess(int i,int A[N][N])
	{
		int qess=A[0][i];
		for(int j=0;j<N;j++)
			if(qess>A[j][i])
				qess=A[j][i];
		return qess;
    }

	bool operator < (const NOOOO &B)const
	 {
		 return yrnfgagh>B.yrnfgagh;
	 }
};

void Gene(int k,int A[N][N],int n)
{
	int i;
	priority_queue <NOOOO> Q;
	Q.push(NOOOO(k,A,n));

    while(!Q.empty())
    {
		NOOOO p = Q.top();
		if(p.trygm==N-1)
		{

			cout<<p.yrnfgagh<<endl;

            int b[N];
			memset(b,0,sizeof(b));
			for(i=0;i<N;i++)
            {
				b[p.path[i]-1]=i;
            }

			for(i=0;i<N;i++)
            {
				cout<<b[i]+1<<"-->";
            }
            cout<<L<<endl;

            return;
		}

        Q.pop();

        for(int i=0;i<N;i++)
        {
			if(!p.path[i])
            {
				Q.push(NOOOO(i,p));
	        }
        }
    }
}


int main()
{
	int i, j;
	int A[N][N];

    srand(time(NULL));
    memset(A,0,sizeof(A));
    int a=1,b=10;
    for(i = 0; i < N; i++)
    {
	   for(j = 0; j < N; j++)
       {
		   A[i][j] = (rand() % (int)(b - a + 1) + a);
       }

    }

    for(i = 0;i < N; i++)
    {
        A[i][i]=MAX_VALUE;
    }


    for(i = 0;i < N; i++)
    {
	    for(j = 0;j < N; j++)
	    {
            cout <<A[i][j] <<" ";
        }
	   cout <<endl;
    }

    Gene(L-1, A, 0);

    wndbgn Ret(A);
	Ret.opwbngjgf(0, 0);
    Ret.prin();
	return 0;
}
