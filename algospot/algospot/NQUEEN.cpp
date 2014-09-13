#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define IMPOSSIBLE 0
#define POSSIBLE 1
#define ERROR -1
struct Node{
	int row;
	int col;
}*pNode;

struct Stack{
	int top;
	Node stack[12];
}*pStack;
void push(Stack &stack, Node value){
	stack.stack[++stack.top] = value;
}
Node pop(Stack& stack){
	if (stack.top == -1){
		Node node;
		node.col = -1;
		node.row = -1;
		return node;
	}
	return stack.stack[stack.top--];
}
int isPossible(Stack &stack,int row, int col){
	int result = 0;
	int rowV;
	int colV;
	for (int i = 0; i <= stack.top; i++){
		rowV = stack.stack[i].row;
		colV = stack.stack[i].col;
		if (row != rowV && col != colV){
			if (abs(col - colV) == 0){
				if (abs(row - rowV) == 0){
					return IMPOSSIBLE;
				}
			}
			else if (abs(row - rowV) == 0){
				if (abs(col - colV) == 0){
					return IMPOSSIBLE;
				}
			}
			else if ((abs(row - rowV) / abs(col - colV)) == 1){
				return IMPOSSIBLE;
			}
		}
		else{
			return IMPOSSIBLE;
		}
	}
	return POSSIBLE;
}
int count = 0;
void recursiveTest(Stack& stack,int testrow,int colcount){
	if (testrow == colcount){
		count++;
		return;
	}
	for (int i = 0; i < colcount; i++){
		if (isPossible(stack, testrow, i) == POSSIBLE){

			Node node;
			node.row = testrow;
			node.col = i;
			push(stack, node);
			recursiveTest(stack, testrow+1, colcount);
			pop(stack);
		}
		else{
		//	printf("IMPOSSIBLE");
		}
	}
}

int main(){
	int caseCount = 0;
	scanf("%d", &caseCount);
	for (int i = 0; i < caseCount; i++){
		Stack stack;
		stack.top = -1;
		for (int i = 0; i < 12; i++){
			stack.stack[i].row = -1;
			stack.stack[i].col = -1;
		}

		count = 0;
		int nCount = 0;
		scanf("%d", &nCount);
		recursiveTest(stack, 0, nCount);
		printf("%d\n", count);
	}
	return 0;
}