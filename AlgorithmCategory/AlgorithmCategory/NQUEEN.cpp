#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#define MAX_NODE 12
/*
https://algospot.com/judge/problem/read/NQUEEN
*
/
struct Node{
	int x;
	int y;
}*pNode;
struct Stack{
	int top;
	Node node[MAX_NODE];
}*pStack;

char isLocationPossible(Stack& stack, Node & node){
	for(int i=0; i<=stack.top; i++){
		int x = stack.node[i].x;
		int y = stack.node[i].y;
		if(x== node.x || y==node.y){
			return 0;//fail
		}else if(abs(node.x-x)/abs(node.y-y) == 1&&abs(node.x-x)%abs(node.y-y) == 0){
			return 0;//fail
		}
	}
	return 1;
}

void getPossibleCount(Stack& stack, int areaSize, int currentY ,int& resultCount){
	for (int x=0; x<areaSize; x++){
		Node node;
		node.y=currentY;
		node.x=x;
		if(isLocationPossible(stack,node)){
			if(currentY==areaSize-1){
				resultCount++;//result count increase
				continue;	//next location found
			}
			//push
			stack.node[++stack.top] = node;
			//recursive
			getPossibleCount(stack,areaSize,currentY+1,resultCount);
			//pop
			stack.top--;
		}
	}
}


int main(){
	int testcase= 0;
	scanf("%d",&testcase);
	while(testcase--){
		Stack stack;
		stack.top = -1;
		memset(stack.node,0,sizeof(stack.node));
		int resultCount=0;
		int areaSize=0;
		scanf("%d",&areaSize);

		getPossibleCount(stack,areaSize,0,resultCount);
		printf("%d\n",resultCount);
	}
	return 0;
}