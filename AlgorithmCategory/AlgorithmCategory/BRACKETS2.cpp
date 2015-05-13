#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
/**
https://algospot.com/judge/problem/read/BRACKETS2
*/
typedef struct _Stack{
	char stack[10005];
	int top = -1;
}Stack, *pStack;
void push(Stack& stack, int value){
	stack.stack[++stack.top] = value;
}
char pop(Stack& stack){
	if (stack.top == -1){
		return NULL;
	}
	return stack.stack[stack.top--];
}
void clear(Stack& stack){
	memset(&stack.stack, 0, 10005);
}
int findPair(Stack& stack, int value){
	char element = 0;
	int result = 0;
	switch (value){
	case ')':

		while (1){
			element = pop(stack);
			if (element == '('){
				result = 1;
				break;
			}
			else if (element == '{'){
				break;
			}
			else if (element == '['){
				break;
			}
			else{
				break;
			}
		}
		break;
	case '}':

		while (1){
			element = pop(stack);
			if (element == '('){
				break;
			}
			else if (element == '{'){
				result = 1;
				break;
			}
			else if (element == '['){
				break;
			}
			else{
				break;
			}
		}
		break;
	case ']':

		while (1){
			element = pop(stack);
			if (element == '('){
				break;
			}
			else if (element == '{'){
				break;
			}
			else if (element == '['){
				result = 1;
				break;
			}
			else{
				break;
			}
		}
		break;
	}
	return result;
}

int main(){
	Stack stack;
	int count = 0;
	char inputStr[10005] = { 0, };
	scanf("%d", &count);
	for (int i = 0; i < count; i++){
		memset(stack.stack, 0, sizeof(stack));
		stack.top = -1;
		scanf("%s", inputStr);
		int index = 0;
		char charactor = NULL;
		int flag = 1;
		while ((charactor = inputStr[index++]) != NULL && flag!=0){
			switch (charactor){
			case ')':
				if (findPair(stack, ')') == 0){
					flag = 0;
				}
				break;
			case '}':
				if (findPair(stack, '}') == 0){
					flag = 0;
				}
				break;
			case ']':
				if (findPair(stack, ']') == 0){
					flag = 0;
				}
				break;
			default:
				push(stack, charactor);
			}
		}
		if (flag == 1&& stack.top==-1){
			printf("YES\n");
		}
		else{
			printf("NO\n");

		}
	}
	return 0;
}