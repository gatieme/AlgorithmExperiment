/// ������ʽ���͹������
///
/// ��ʾ��
/// ����Q�е������ĸ���A��B��C��D�����A����BCD���ɵ��������ڲ���
/// ��ôAһ��������͹��P�Ķ��㼯�ϡ�

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef WINDOWS
#include <windows.h>
#endif

#ifdef LINUX
#include <sys/time.h>
#endif

#define MaxNode 100015


//#define TIME

//  �㼯
typedef struct Point
{
    int x;
    int y;
}Point;




// ����
//void Swap(Point *point, int i, int j);
void Swap(Point *left, Point *right);
//���,������͹�������
double Multiply(Point p1, Point p2, Point p0);

/// ��������p1��p2�ľ���
double Distance(Point p1,Point p2); //p1,p2�ľ���

// GrahamScan��͹��
void BruteForce(int n);

// �Ƚ������������
int Cmp(const void *left, const void *right);

//��͹�������
double PolygonArea(Point *point, int length);

// ��ʱ�뷽ʽ��ӡ͹��
void PrintPloygon(Point *p, int length);
double PolygonCircumference(Point *point, int n);
//4
//0 0
//0 101
//75 0
//75 101
// 7575
Point point[MaxNode];           //  �㼯��
int stack[MaxNode];             //  �洢͹���еĵ㼯�ϵ�λ��
int top = 0;                    //  [0~top)�洢��λ�ýڵ���Ϣ
//

int main()
{
    int i;
    int N/*, length*/;

#ifdef TIME
    /*FILE *ifp = */freopen("input.txt", "r", stdin);
    /*FILE *ofp = */freopen("bruteforceoutput.txt", "w", stdout);
#endif // TIME

    ///
    while(scanf("%d", &N) != EOF)           ///  ���붥�����
    {

        for(i = 0; i < N; i++)
        scanf("%d%d", &(point[i].x), &(point[i].y));

#ifdef TIME
        struct timeval start, end;
        gettimeofday( &start, NULL );
        //double cl = (double)start.tv_sec + (double)start.tv_usec / 1000000;

#endif // TIME
        BruteForce(N);
#ifdef TIME
        gettimeofday( &end, NULL );
        int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
        //printf("N : %5d, time: %dus\n", N, timeuse);
        printf("%5d%20d\n", N, timeuse);

        //cl = ((double)end.tv_sec + (double)end.tv_usec / 1000000) - cl;
        //printf("execution time : %0.3fs\n", cl);

#endif // TIME
        //PrintPloygon(point, top);

        //printf("%lf\n", PolygonArea(point, top));
        //printf("%lf\n", PolygonCircumference(point, top));
    }

    return EXIT_SUCCESS;
}


/// ��������p1��p2�ľ���
double Distance(Point p1,Point p2) //p1,p2�ľ���
{
    return sqrt((double)(p1.x-p2.x) * (double)(p1.x-p2.x) + (double)(p1.y-p2.y)*(double)(p1.y-p2.y));
}


void InsertPoint(int pos)
{
    int i;
    for(i = 0; i < top; i++)
    {
        if(stack[i] == pos)
        {
            break;
        }
    }
    if(i == top)
    {
        stack[top++] = pos;
        //printf("%d -=> [%d, %d] insert\n", pos, point[stack[top - 1]].x, point[stack[top - 1]].y);
    }
}
//  �㷨˼��
//  ����N���㹹�ɵĻ�����������ѡ��������Pi��Pj��
//  ���ҽ����ü��ϵ������㶼λ�ڴ����������ֱ�ߵ�ͬһ��ʱ
//  ���ǵ������Ǹü���͹���߽��һ����
void BruteForce(int n)
{
    int i, j, k;                            //  ö�ٱ���
    int a, b, c;                            //  ֱ�߷���
    int result, left, right;                    //  ���Թ滮

    top = 0;
    for(i = 0; i < n; i++)                  //  ѭ����1����
    {
        for(j = i + 1; j < n; j++)          //  ѭ����2����
        {
            ///  ǰ��������ɵ�ֱ��Ϊax + by = c �� ax + by - c = 0;
            a = point[j].y - point[i].y;
            b = point[i].x - point[j].x;
            c = point[i].x * point[j].y - point[i].y * point[j].x;

            left = right = 0;
            for(k = 0; k < n; k++)          //  ѭ����������
            {
                //  ������������������ǰ���������߹��ɵķ���ax + by��
                result = a * point[k].x + b * point[k].y - c;

                if(result < 0)      // ax + by - c < 0����ֱ�ߵ����
                {
                    left++;
                }
                else if(result > 0) //  ax + by -c > 0 ����ֱ�ߵ��Ҳ�
                {
                    right++;
                }

                if(left * right != 0)
                {
                    break;
                }
            }
            ///  ���ѭ������ʱk == n, ��˵����pi��pj������͹���ڵĵ�
            if(k == n)
            {
                //  ��ӵ�ʱ��
                //  ��C++�п���STL��set
                InsertPoint(i);
                InsertPoint(j);
                //printf("")
            }
        }
    }
}



//��͹�������
double PolygonArea(Point p[], int n)
{
    double area;
    int i;
    area = 0;
    for(i = 1; i < n; i++)
    {
        area += ((double)p[stack[i - 1]].x * (double)p[stack[i % n]].y - (double)p[stack[i % n]].x * (double)p[stack[i - 1]].y);
        //printf("%lf\n", (double)p[stack[i - 1]].x * (double)p[stack[i % n]].y - (double)p[stack[i % n]].x * (double)p[stack[i - 1]].y);
    }

    return fabs(area) / 2;
}

double PolygonCircumference(Point *point, int n)
{
    double sum = 0.0;
    for(int i = 0; i < n - 1; i++)
    {
        sum += Distance(point[stack[i]], point[stack[i+1]]);
    }
    sum += Distance(point[stack[top]], point[stack[0]] );

    return sum;
}

void PrintPloygon(Point p[], int n)
{
    for(int i = 0;i < n;i++)
    {
        printf("%d %d\n", p[stack[i]].x, p[stack[i]].y);
    }
}




