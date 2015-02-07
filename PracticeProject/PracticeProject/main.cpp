#include "Graph.h"
#include "PriorityQueue.h"

int main(){

	
	Graph* g =CreateGraph();
	printGraph(g);
	insertEdge(g, 1, 2);
	insertEdge(g, 2, 3);
	insertEdge(g, 3, 4);
	insertEdge(g, 4, 1);

	printGraph(g);

	removeEdge(g, 1, 2);
	removeEdge(g, 3, 4);
	removeEdge(g, 2, 3);
	
	printGraph(g);

	PQueue* queue = CreatePQ(1000);
	Edge e = { 0, };
	e.src = 1;
	e.dest = 2;
	e.weight = 10;
	e.isEdge = true;
	insertPNode(queue, e, e.weight);
	e.weight = 20;
	e.src = 2;
	e.dest = 3;
	insertPNode(queue, e, e.weight);
	e.weight = 3;
	e.src = 3;
	e.dest = 4;
	insertPNode(queue, e, e.weight);
	e.weight = 4;
	e.src = 4;
	e.dest = 1;
	insertPNode(queue, e, e.weight);
	e.weight = 100;
	e.src = 4;
	e.dest = 1;
	insertPNode(queue, e, e.weight);
	e.weight = 6;
	e.src = 4;
	e.dest = 1;
	insertPNode(queue, e, e.weight);
	printPQueue(queue);
	popPNode(queue);
	printf("\n");
	printPQueue(queue);
	queue;
	return 0;
}