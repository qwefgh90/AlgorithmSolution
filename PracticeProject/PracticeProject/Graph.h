/*������ķ� ������ �׷���
������� �� ��������Ʈ - ������ ������ ��Ÿ���� �ڷᱸ�� 
*/

/*�����Ͱ� ���ڶ� ���� ���ڶ� ����*/

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000

enum VISIT {NOTVISITED,VISITED};

struct Edge{
	bool isEdge;
	int weight;
	int src;
	int dest;
};

struct Vertex{
	Edge* edgeArray;
	VISIT visit;
	bool isVertex;
	int edgeCount;
};

struct Graph{
	int size;
	Vertex* vertexArray;
	int vertexCount;
};


Graph* CreateGraph();
void insertEdge(Graph*,int src, int dest);
void removeEdge(Graph*, int src, int dest);
void printGraph(Graph*);
