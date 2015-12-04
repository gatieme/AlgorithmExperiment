/// 动态规划求解0-1背包问题

/// 根据递归式填写相应的最优解矩阵


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define MaxNode 10000
#define MAXINT 147483647

//代价矩阵计算
void BoolPackCost(int Weight[],int valueApprox[],int C,int num);

//最优解输出
void BoolPackSolution(int B[][MaxNode+1],int Weight[],int valueApprox[],int num,int C);

//寻找价值量最大值
int FindMax(int Value[],int n);

int C,Weight[MaxNode+1] = {0},Value[MaxNode+1] = {0},B[MaxNode+1][MaxNode+1] = {0};

int main()
{
    int i;
    int num;

    double epsilon;
#ifdef DEBUG
    printf("input the arg:");
#endif

    scanf("%lf", &epsilon);

#ifdef DEBUG
    /*FILE *ifp = */freopen("input.txt", "r", stdin);
//    /*FILE *ofp = */freopen("ApproxOutput.txt", "w", stdout);
#endif

#ifdef RELEASE
    /*FILE *ifp = */freopen("input.txt", "r", stdin);
    /*FILE *ofp = */freopen("ApproxOutput.txt", "w", stdout);
#endif


    while(scanf("%d", &num) != EOF)
    {
        int valueApprox[MaxNode+1] = {0};//totalValue = 0;
        scanf("%d", &C);
        for(i = 1; i <= num; i++)
        {
            scanf("%d%d", &(Weight[i]), &(Value[i]));
            //totalValue += Value[i];
            //printf("%d:\t%10d%10d\n", i,Weight[i], Value[i]);
        }

        int maxValue = FindMax(Value,num);
        //printf("%d\n", maxValue);

        double k = (double)num / epsilon;
        //printf("k = num / epsilon = %f\n", k);

        for ( i = 1; i <= num; ++ i )
        {
            valueApprox[i] = (int)(Value[i] * k / maxValue);
            //printf("valueApprox[i] = (int)(Value[i] * k / maxValue) = %d\n", valueApprox[i]);
            //totalValue += valueApprox[i];
        }

        //printf("totalValue = %d\n", totalValue);

        struct timeval start, end;

        gettimeofday( &start, NULL );

        ////代价矩阵计算
        //BoolPackCost(int Weight[],int valueApprox[],int C,int num)
        BoolPackCost(Weight,valueApprox,C,num);

        //BoolPackSolution(int B[][MaxNode+1],int Weight[],int Value[],int num,int C)
        BoolPackSolution(B,Weight,Value,num,C);

        gettimeofday( &end, NULL );

        int runtime = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
#ifdef DEBUG
        printf("\nN =%d, timeuse = %dus\n", num, runtime);
#endif

#ifdef RELEASE
        printf("%5d %10d\n", num, runtime);
#endif
    }

    return EXIT_SUCCESS;
}

//代价矩阵计算
void BoolPackCost(int Weight[],int valueApprox[],int C,int num)
{
    int i,j;
    for(j = 1; (j < Weight[num])&& (j < C); j++)
        B[num][j] = 0;
    for(j = Weight[num]; j <= C; j++)
        B[num][j] = valueApprox[num];
    for(i = num - 1; i > 1; i--)
    {
        for(j = 1; (j < Weight[i]) && (j <= C); j++)
            B[i][j] = B[i+1][j];
        for(j = Weight[i]; j <= C; j++)
        {
            B[i][j] = B[i + 1][j - Weight[i]] + valueApprox[i];
            if(B[i][j] < B[i + 1][j])
                B[i][j] = B[i + 1][j];
        }
    }
    B[1][C] = B[2][C - Weight[1]] + valueApprox[1];
    if(B[1][C] < B[2][C])
       B[1][C] = B[2][C];
    /*for(i = 1;i <= num;i++)
    {
        for(j=1;j <= C;j++)
            printf("%10d",B[i][j]);
        printf("\n");
    }*/
}

//最优解输出
void BoolPackSolution(int B[][MaxNode+1],int Weight[],int Value[],int num,int C)
{
    int j = C,totalWeight = 0,totalValue = 0;
    int i,X[MaxNode+1] = {0};
#ifdef DEBUG
    printf("Package Weight = %d\n",C);
    printf("\nPackeage List: \n");
#endif
    for(i = 1;i < num; i++)
    {
        if(B[i][j] == B[i + 1][j])
            X[i] = 0;
        else{
            X[i] = 1;
            //printf("%10d%10d\n",Weight[i],Value[i]);
            j = j - Weight[i];
        }
    }
    if(B[num][j] == 0)
        X[num] = 0;
    else{
        X[num] = 1;
        //printf("%10d%10d\n",Weight[num],Value[num]);
    }
    for(i = 1;i <= num; i++)
    {
        if(X[i])
        {
            totalWeight += Weight[i];
            totalValue += Value[i];
#ifdef DEBUG
            //printf("%4d:",i);
            printf("%10d%10d\n",Weight[i],Value[i]);
#endif
        }
    }
#ifdef DEBUG
    printf("\nTotal Weight = %d\nTotalValue = %d\n",totalWeight,totalValue);
#endif
}

//寻找价值量最大值
int FindMax(int Value[],int n)
{
    int Vmax = -1;
    for(int i = 1; i < n; i++)
        if(Value[i] > Vmax)
            Vmax = Value[i];
    return Vmax;
}


