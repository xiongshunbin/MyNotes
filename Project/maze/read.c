#include <stdio.h>
#include <stdlib.h>

#define N 101
#define M 101

int main()
{
    int i,j;
    FILE *fp = fopen("maze_101_101.txt","r");
    char str[M+2];
    char maze[N][M];
    if(fp==NULL)
    {
        printf("Can't open maze_101_101.txt!");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<N;i++)
    {
        fgets(str,M+2,fp);
        for(j=0;j<M;j++)
            maze[i][j]=str[j];
    }
    fclose(fp);
}