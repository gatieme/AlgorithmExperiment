#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef WINDOWS
#include <windows.h>
#endif

#ifdef LINUX
#include <sys/time.h>
#endif
#define MAX_SIZE  10000
//#define DEBUG
//#define TIME


typedef struct {
	int x,y;
}Point;

//  ��������
void RandInput(Point *point, int length);

//  ����λ��
void Swap(Point *left, Point *right);
//  ��ӡ��Ϣ
int Print(Point *convex, int length);
// ����x�Ĵ�С�����������X��ͬ����Y��С��������
int CmpByX(const void *left, const void *right);

//��convex�����������point������β��
void AddHeadTail(Point *point, Point *convex);

//��convex����������� point[i]
void AddPosition(Point *point,Point *convex,int i);


//����point[first]->point[final]�������ĵ�
void DealWithLeft(int first,int final,Point *point,Point *convex);
void DivideConvexHull(Point *point,Point *convex);

int PrintPoints(Point *convex, int length);

int N;
Point point[MAX_SIZE];
Point convex[MAX_SIZE];
int position[MAX_SIZE];
int convexCount=0;	//convex[15]�������ֵ�ĸ���


int main(void)
{
#ifdef TIME
    FILE *ifp = freopen("input.txt", "r", stdin);
    FILE *ofp = freopen("divideoutput.txt", "w", stdout);
#endif // TIME


	while(scanf("%d", &N) != EOF)
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%d%d",&point[i].x,&point[i].y);
            //printf("%d\t%d\n",point[i].x,point[i].y);
        }
#ifdef DEBUG
        printf("��������\n");
        PrintPoints(point, N);
#endif // DEBUG

#ifdef TIME
        struct timeval start, end;
        gettimeofday( &start, NULL );
        //double cl = (double)start.tv_sec + (double)start.tv_usec / 1000000;

#endif // TIME
        //���������򣬰�x��С����
        qsort(point, N, sizeof(point[0]), CmpByX);

#ifdef DEBUG
        printf("���������ݣ�\n");
        PrintPoints(point,N);
#endif // DEBUG

        //��ȡconvex���飬������н������
        DivideConvexHull(point,convex);
#ifdef TIME
        gettimeofday( &end, NULL );
        int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
        //printf("N : %5d, time: %dus\n", N, timeuse);
        printf("%5d%20d\n", N, timeuse);

        //cl = ((double)end.tv_sec + (double)end.tv_usec / 1000000) - cl;
        //printf("execution time : %0.3fs\n", cl);

#endif // TIME


#ifdef DEBUG
        printf("�������\n\n");
        PrintPoints(convex,convexCount);
#endif // DEBUG
    }
	return EXIT_SUCCESS;
}



//  ��������
void RandInput(Point *point, int length)
{
    srand(time(NULL));
    for(int i = 0; i < length; i++)
    {
        point[i].x = rand() % 100 + 1;
        point[i].y = rand() % 100 + 1;
    }
}




//����λ��
void Swap(Point *left, Point *right)
{
    Point temp;
    temp = *left;
    *left = *right;
    *right = temp;
}



// ����x�Ĵ�С�����������X��ͬ����Y��С��������
int CmpByX(const void *left, const void *right)
{
    Point *leftPoint = (Point *)left;
    Point *rightPoint = (Point *)right;
    if(leftPoint->x != rightPoint->x)
    {
        return (leftPoint->x - rightPoint->x);
    }
    else
    {
        return (leftPoint->y - rightPoint->y);
    }
}



//��convex�����������point������β��
void AddHeadTail(Point *point, Point *convex)
{
	convex[convexCount].x=point[0].x;
	convex[convexCount++].y=point[0].y;

	convex[convexCount].x=point[14].x;
	convex[convexCount++].y=point[14].y;
}

//��convex����������� point[i]
void AddPosition(Point *point,Point *convex,int i)
{
	convex[convexCount].x=point[i].x;
	convex[convexCount++].y=point[i].y;
}

//����point[first]->point[final]�������ĵ�
void DealWithLeft(int first, int final, Point *point, Point *convex)
{
	int max = 0, index = -1;
	int i = first;
	if(first < final)  //point[first]->point[final]�������
	{
		for(i ; i < final; i++)
		{
			int x1 = point[first].x,y1 = point[first].y;
			int x2 = point[final].x,y2 = point[final].y;
			int x3 = point[i].x;
			int y3 = point[i].y;


			int compute = x1 * y2 + x3 * y1 + x2 * y3 - x3 * y2 - x2 * y1 - x1 * y3;
			if(compute > max)
			{
				max = compute;
				index = i;
			}
		}
	}
	else
	{
		for(i; i >= 0; i--)//point[final]->point[first]�������
		{
			int x1 = point[first].x,y1 = point[first].y;
			int x2 = point[final].x,y2 = point[final].y;
			int x3 = point[i].x,y3 = point[i].y;


			int compute = x1 * y2 + x3 * y1 + x2 * y3 - x3 * y2 - x2 * y1 - x1 * y3;
			if(compute > max)
			{
				max = compute;
				index = i;
			}
		}
	}


	if(index!=-1)	//ȡ��point[index]������ߵ㣩 ���������point[final]��point[first]���ɵ�������������
	{
		AddPosition(point,convex,index);
		DealWithLeft(first,index,point,convex);
		DealWithLeft(index,final,point,convex);
	}
}
void DivideConvexHull(Point *point,Point *convex)
{
	AddHeadTail(point,convex);	//����β�����㲢��convex[15]

	DealWithLeft(0,N - 1,point,convex);	//����point[0]->point[14]������ߵĵ�
	DealWithLeft(N - 1,0,point,convex);	//����point[14]->point[0]�����ұߵĵ�
}


int PrintPoints(Point *convex, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d\t%d\n", convex[i].x, convex[i].y);
    }
}
