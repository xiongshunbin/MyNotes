#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#define winWidth 909
#define winHeight 909

#define N 101
#define M 101

const char RODE = ' ';
const char WALL = '#';

void ReadMaze(char maze[][M], const char *filename);
void InitMaze(const char maze[][M]);

int main()
{
    char maze[N][M];
    const char *str = "maze_101_101.txt";
    ReadMaze(maze, str);
    InitMaze(maze);

    return 0;
}

void InitMaze(const char maze[][M])
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(winWidth, winHeight, "Maze");

    SetTargetFPS(60);

    int w = winWidth / M;
    int h = winHeight / N;

    Color col;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (maze[i][j] == WALL)
                    col = SKYBLUE;
                else
                    col = WHITE;
                DrawRectangle(j * w, i * h, w, h, col);
            }
        }
        EndDrawing();
    }
    CloseWindow();
}

void ReadMaze(char maze[][M], const char *filename)
{
    int i, j;
    FILE *fp = fopen(filename, "r");
    char str[M + 2];
    if (fp == NULL)
    {
        printf("Can't open %s!", filename);
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < N; i++)
    {
        fgets(str, M + 2, fp);
        for (j = 0; j < M; j++)
            maze[i][j] = str[j];
    }
    fclose(fp);
}