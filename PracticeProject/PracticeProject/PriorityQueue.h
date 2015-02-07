#include "Graph.h"
#pragma once
#define DATA Edge

struct PNode{
	int priority;
	DATA edge;
};
struct PQueue{
	PNode* array;
	int nodeCount;
};

PQueue* CreatePQ(int size){
	PQueue* q = new PQueue;
	q->array = new PNode[size];
	q->nodeCount = 1;
	q->array[0].priority = -1;	//dummy
	return q;
}

void insertPNode(PQueue* queue,DATA edge, int priority)
{
	int index = queue->nodeCount;
	queue->array[index].priority = priority;
	queue->array[index].edge = edge;
	//�������� ��ġ����.
	//�� ����
	while (index != 1){
		if (queue->array[index / 2].priority > queue->array[index].priority){
			//swap
			PNode temp = { 0, };
			temp = queue->array[index / 2];
			queue->array[index / 2] = queue->array[index];
			queue->array[index] = temp;
			index = index / 2;
		}
		else{
			break;
		}
	}
		//����
	queue->nodeCount++;
}

PNode popPNode(PQueue* queue){
	if (queue->nodeCount == 1)
		return queue->array[0];
	PNode result = queue->array[1];
	PNode* narr = queue->array;

	int index = 1;
	narr[index] = narr[queue->nodeCount - 1];
	//�� ����
	int swapindex;
	PNode temp;
	while (index < queue->nodeCount){
		if ((index * 2 >= queue->nodeCount))
			break;
		else if ((index * 2 == queue->nodeCount - 1)){
			swapindex = index * 2;
		}else {
			if (narr[index * 2].priority < narr[index * 2 + 1].priority){
				swapindex = index * 2;
			}
			else{
				swapindex = index * 2 + 1;
			}
		}
		//����
		temp = narr[swapindex];
		narr[swapindex] = narr[index];
		narr[index] = temp;
		//�����ε��� ����
		index = swapindex;
	}

	//��ȯ
	queue->nodeCount--;
	return result;
}

void printPQueue(PQueue* queue){
	for (int i = 1; i < queue->nodeCount; i++){
		printf("Node[%d] weight: %d, src: %d, dest: %d\n", i, queue->array[i].edge.weight, queue->array[i].edge.src, queue->array[i].edge.dest);
	}
}