#include "Graph.h"

Graph* CreateGraph()
{
	Graph* graph = new Graph();
	graph->size = SIZE;
	graph->vertexArray = new Vertex[SIZE];
	graph->vertexCount = 0;
	Vertex* vArray = graph->vertexArray;
	Edge dummy;
	dummy.isEdge = false;
	dummy.weight = 0;
	for (int i = 0; i < graph->size; i++){
		vArray[i].visit = NOTVISITED;
		vArray[i].isVertex = false;
		vArray[i].edgeCount = 0;
		vArray[i].edgeArray = new Edge[graph->size];
		for (int j = 0; j < graph->size; j++){
			vArray[i].edgeArray[j] = dummy;
		}
	}
	//생성 및
	//초기화
	return graph;
}
void insertEdge(Graph* g, int src, int dest){
	if (g->vertexArray[src].isVertex == false)
		g->vertexCount++;

	if (g->vertexArray[dest].isVertex == false)
		g->vertexCount++;
	if (g->vertexArray[src].edgeArray[dest].isEdge == false)
		g->vertexArray[src].edgeCount++;
	if (g->vertexArray[dest].edgeArray[src].isEdge == false)
		g->vertexArray[dest].edgeCount++;

	g->vertexArray[src].edgeArray[dest].isEdge = true;
	g->vertexArray[src].edgeArray[dest].src = src;
	g->vertexArray[src].edgeArray[dest].dest = dest;
	g->vertexArray[dest].edgeArray[src].isEdge = true;
	g->vertexArray[dest].edgeArray[src].src = dest;
	g->vertexArray[dest].edgeArray[src].dest = src;
	g->vertexArray[src].isVertex = true;
	g->vertexArray[dest].isVertex = true;
}
void removeEdge(Graph* g, int src, int dest){
	if (g->vertexArray[src].edgeArray[dest].isEdge)
		g->vertexArray[src].edgeCount--; 
	if (g->vertexArray[dest].edgeArray[src].isEdge)
		g->vertexArray[dest].edgeCount--;

	if (g->vertexArray[src].edgeCount == 0)
		g->vertexArray[src].isVertex = false;
	if (g->vertexArray[dest].edgeCount == 0)
		g->vertexArray[dest].isVertex = false;

	g->vertexArray[src].edgeArray[dest].isEdge = false;
	g->vertexArray[dest].edgeArray[src].isEdge = false;
}
void printGraph(Graph* g){
	for (int i = 0; i < g->size; i++){
		if (g->vertexArray[i].isVertex == true){
			printf("정점: %d\n", i);
			for (int j = 0; j < g->size; j++){
				if (g->vertexArray[i].edgeArray[j].isEdge){
					printf("간선: [%d->%d], ", i, j);
				}
			}
			printf("\n\n");
		}
	}
}