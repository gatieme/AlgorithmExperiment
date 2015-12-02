/*************************************************************************
    > File Name: Random.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: 2015年11月30日 星期一 15时48分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTEX 200


int main()
{
    freopen("input.txt", "w", stdout);

    srand(time(NULL));

    for(int vertex = 5; vertex <= MAX_VERTEX; vertex += 5)     //  顶点数目为vertex
    {
        printf("%d\n", vertex);
        for(int i = 0; i < vertex; i++)                 //  循环每行
        {
            for(int j = 0; j < vertex; j++)
            {
                printf("%4d", rand() % 100 + 1);
            }
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}
