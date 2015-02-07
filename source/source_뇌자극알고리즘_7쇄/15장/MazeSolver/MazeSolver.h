#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define INIT_VALUE -1

#define START    'S'    /* ������ */
#define GOAL     'G'    /* Ż�ⱸ */
#define WAY      ' '    /* �� */
#define WALL     '#'    /* �� */
#define MARKED   '+'    /* Ż�ⱸ�� ���ϴ� �� ǥ�� */


enum DIRECTION { NORTH, SOUTH, EAST, WEST };
enum RESULT    { FAIL, SUCCEED }; 

typedef struct tagPosition
{
    int X;
    int Y;
} Position;

typedef struct tagMazeInfo
{
    int ColumnSize;
    int RowSIze;

    char** Data;    
} MazeInfo;

int Solve( MazeInfo* Maze );
int MoveTo( MazeInfo* Maze, Position* Current, int Direction );
int GetNextStep( MazeInfo* Maze, Position* Current, int Direction, Position* Next );
int GetMaze( char* FilePath, MazeInfo* Maze );

#endif