#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <iomanip>


#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <ctime>
#include <cmath>

#include <sys/time.h>

#define START 1
//#define MAX_VERTEX 20
int N;
#define MAX_VERTEX 210
#define MAX_VALUE 10000

using namespace std;


#define DEBUG
//#define RELEASE
/*

class wndbgn
{

private:
	int qess;

    int efsfcsc[MAX_VERTEX],wbngjgf[MAX_VERTEX];

    int c[MAX_VERTEX][MAX_VERTEX];

    int k;

public:

    wndbgn(int b[MAX_VERTEX][MAX_VERTEX])
	{
		k = 0;
		for(int i = 0; i < N ; i++)
		{
			efsfcsc[i] = -1;
			for(int j = 0; j < N; j++)
            {
				c[i][j] = b[i][j];
		    }
        }
		qess = MAX_VALUE;
	}

	void opwbngjgf(int n, int lon)
	{
	   if(n == N)
	   {
		   if(efsfcsc[N - 1] == START - 1 && qess > iokgb( ))
		   {
			   qess = iokgb();

               for(int i = 0; i < N; i++)
               {
                   wbngjgf[i] = efsfcsc[i];
		       }
           }
	   }
	   else if(n == 0)
	   {
		   for(int i = 0; i < N; i++)
		   {
			   efsfcsc[n] = i;
               opwbngjgf(n + 1, lon);
			   efsfcsc[n] = -1;
		   }
	   }
	   else
	   for(int i = 0;i < N; i++)
	   {
		   int lon1 = lon + c[efsfcsc[n - 1]][i];
		   if(!uninclude(i) && lon1 < qess)
		   {
			   efsfcsc[n] = i;
               opwbngjgf(n + 1, lon1);
			   efsfcsc[n] = -1;
		   }
		   lon = lon - c[efsfcsc[n - 1]][efsfcsc[n]];
	   }
	}

	int iokgb()
	{
        int i, j, qess1;
		for(qess1 = 0,j = START - 1,i = 0; i < N; i++)
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

	    cout <<START;

        for(int i = 0; i < N; i++)
        {
		    cout<<"-=>"<<wbngjgf[i] + 1;
        }
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
       }

       return 0;
	}
};
*/


class QueueNode
{
private:

    int dadadwe;

    int hkhkhg[2][MAX_VERTEX];

    int gywew[2][MAX_VERTEX];

    int c[MAX_VERTEX][MAX_VERTEX];

public:
	int path[MAX_VERTEX];

    int trygm;

    int yrnfgagh;

    QueueNode(int k, int A[MAX_VERTEX][MAX_VERTEX], int n)
	{
		for(int i = 0;i < 2; i++)
        {
			for(int j = 0;j < N; j++)
			{
				hkhkhg[i][j] = 0;
				gywew[i][j] = 0;
			}
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

	QueueNode(int k, QueueNode A)
	{
		cdfraasf(hkhkhg, A.hkhkhg);
		cdfraasf(gywew, A.gywew);
		trygm = A.trygm + 1;
		dadadwe = k;
		cdfraasf(c, A.c);

        yrnfgagh = A.yrnfgagh+c[A.dadadwe][dadadwe];

        cdfraasf(path,A.path);
		path[dadadwe]=trygm+1;

		for(int i = 0;i < N; i++)
		{
			if(!c[A.dadadwe][i])
			{
				hkhkhg[0][A.dadadwe]--;
				hkhkhg[1][i]--;
			}
			c[A.dadadwe][i] = MAX_VALUE;
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

		if(trygm != N - 1)
		{
			if(!c[dadadwe][START-1])
			{
				hkhkhg[0][dadadwe]--;
				hkhkhg[1][START-1]--;
			}
			c[dadadwe][START - 1]=MAX_VALUE;

        }
		gy();
	}

	void gy()
	{
		int j;

		for(int i = 0;i < N; i++)
			if(!gywew[0][i]&&!hkhkhg[0][i])
			{
				int m=lqess(i,c);
				yrnfgagh=yrnfgagh+m;
				for(int j = 0;j < N; j++)
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
					for(j = 0;j < N;j++)
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

	void cdfraasf(int A[MAX_VERTEX],int B[MAX_VERTEX])
	{
		for(int i = 0;i < N; i++)
			A[i]=B[i];
	}

	void cdfraasf(int A[MAX_VERTEX][MAX_VERTEX],int B[MAX_VERTEX][MAX_VERTEX])
	{
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				A[i][j]=B[i][j];
	}

	int lqess(int i,int A[MAX_VERTEX][MAX_VERTEX])
	{
		int qess=A[i][0];
		for(int j=0;j<N;j++)
			if(qess>A[i][j])
				qess=A[i][j];
		return qess;
	}

	int cqess(int i,int A[MAX_VERTEX][MAX_VERTEX])
	{
		int qess=A[0][i];
		for(int j=0;j<N;j++)
			if(qess>A[j][i])
				qess=A[j][i];
		return qess;
    }

	bool operator < (const QueueNode &B)const
	 {
		 return yrnfgagh>B.yrnfgagh;
	 }
};

class Hamilton
{
private :
    //  图的基本信息存储
    int m_vervex;
    int m_graph[MAX_VERTEX][MAX_VERTEX];

    //  优先队列
    priority_queue<QueueNode> m_queue;

public:
    friend istream& operator>>(istream& in, Hamilton& hami)
    {
        int i, j;
#ifdef DEBUG
        cout <<"There are " <<N <<" points in this graph" <<endl;
#endif
        for(i = 0;i < N; i++)
        {
	        for(j = 0;j < N; j++)
	        {
                in >>hami.m_graph[i][j];
#ifdef DEBUG
                cout <<std::setw(5)<<hami.m_graph[i][j] <<" ";
#endif
            }
	        cout <<endl;
        }

        return in;
    }


    void Generation(int k, int n)
    {
	    //priority_queue <QueueNode> queue;      //  优先队列
	    m_queue.push(QueueNode(k, this->m_graph, n));



        while(!m_queue.empty())
        {
		    QueueNode p = m_queue.top();


		    if(p.trygm == N - 1)
		    {


#ifdef  DEBUG
			    cout <<endl <<"Cost" <<std::setw(4) <<p.yrnfgagh <<" : ";

                int b[MAX_VERTEX];

                memset(b,0,sizeof(b));
			    for(int i = 0; i < N; i++)
                {
				    b[p.path[i] - 1] = i;
                }

			    for(int i = 0; i < N; i++)
                {
				    cout <<b[i] + 1 <<"-=>";
                }
                cout <<START<<endl;
#endif
                return;
		    }

            m_queue.pop();


            for(int i = 0; i < N; i++)
            {

			    if(!p.path[i])
                {
				    m_queue.push(QueueNode(i,p));
	            }

            }


        }
    }
};

int main()
{
#ifdef DEBUG
    ifstream fin("in2.txt");
    cin.rdbuf(fin.rdbuf());
#endif

#ifdef RELEASE
    ifstream fin("input2.txt");
    cin.rdbuf(fin.rdbuf());

    ofstream fout("FzjxOutput.txt");
    cout.rdbuf(fout.rdbuf());
#endif

    Hamilton hami;
    while(cin >>N)
    {

#ifdef DEBUG
        printf("=================START=================\n\n");
#endif

        cin >>hami;                         //  输入哈密顿环的信息

        //  计算运行时间
        struct timeval start, end;
        gettimeofday(&start, NULL);


        hami.Generation(START - 1, 0);      //  生成哈密顿回路的信息

        //wndbgn Ret(A);
	    //Ret.opwbngjgf(0, 0);
        //Ret.prin();

		gettimeofday(&end, NULL);
        int timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;

#ifdef DEBUG
        cout <<endl <<"N = " <<std::setw(5) <<N <<", " <<std::setw(10)<<timeuse <<"us" <<endl <<endl;
        cout <<"==================END==================" <<endl <<endl <<endl;
#endif

#ifdef RELEASE
        cout <<std::setw(5) <<N <<std::setw(10)<<timeuse <<endl;
#endif

    }
	return EXIT_SUCCESS;
}

