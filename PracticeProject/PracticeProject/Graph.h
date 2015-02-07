/*인접행렬로 구현한 그래프
인접행렬 및 인접리스트 - 정점과 정점을 나타내는 자료구조 
*/

/*데이터가 숫자라 가정 숫자라 가정*/

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
