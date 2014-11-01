#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
namespace CalculatorStack{
	enum TYPE{ OPCODE, OPERAND, ERROR, END};
	typedef struct _Token{
		int data;
		TYPE type;
	}Token, *pToken;
	typedef Token Node;
	typedef struct _Stack{
		int top;
		Node* node;
	}Stack, *pStack;
	Stack createStack(int size);
	void push(Stack& stack, int data);
	Node pop(Stack& stack);
	Node getToken(char* expression, int &expression_index);
	void printCalStack(Stack stack);
	Stack getPostfixFromExpr(Stack expr);	
	Node peek(Stack& stack);
	int getResultFromPostFix(Stack postfix);
	int main(){
		int expression_index = 0;
		char expression[255] = "2*2/4";
		
		Stack stack = createStack(100);
		Node node = getToken(expression, expression_index);
		while (node.type != ERROR && node.type != END){
			push(stack, node.data);
			node = getToken(expression, expression_index);
		}
		
		Stack postFixStack = getPostfixFromExpr(stack);	//���� ǥ��� ����
		int result = getResultFromPostFix(postFixStack);
		printf("result : %d\n", result);
		

		//printCalStack(stack);
		printCalStack(postFixStack);
		return 0;
	}
	int getResultFromPostFix(Stack postfix){
		//�ǿ����ڴ� ��������
		//�����ڴ� ���ÿ��� 2���� ������ ���
		//�������� ���ÿ� �����ִ� ���� �����
		Stack calstack = createStack(100);
		int startIdx = 0;
		while (postfix.top + 1 != startIdx){
			Node node = postfix.node[startIdx++];
			int op1;
			int op2;
			switch (node.type){
			case OPERAND:
				push(calstack, node.data);
				break;
			case OPCODE:
				op2 = pop(calstack).data;
				op1 = pop(calstack).data;
				switch (node.data){
				case '+':
					push(calstack, op1 + op2);
					break;
				case '-':
					push(calstack, op1 - op2);
					break;
				case '*':
					push(calstack, op1 * op2);
					break;
				case '/':
					push(calstack, op1 / op2);
					break;
				}
				break;
			}
		}
		return pop(calstack).data;
	}

	Stack getPostfixFromExpr(Stack expr){
		Stack tempStack = createStack(100);
		Stack resultStack = createStack(100);
		//1)������ ������ ������ ��� ���� �ӽý����� ��� �����ڸ� ����.
		//2)�������ϰ�� �ӽý��ú��� �켱������ ������� �ӽý��ÿ� �ִ´�.
		//3)�������ϰ�� �ӽý��ú��� �켱������ ������� �ӽý��ÿ� �����ڸ� �������� ��� ���ÿ� �ִ´� ���� ��ū�� �ӽý��ÿ� �ִ´�.
		//4)�ǿ������ϰ�� ������ÿ� ��´�.
		int exprStartIdx=0;
		Node tempNode;
		while (expr.top+1 != exprStartIdx){
			tempNode = expr.node[exprStartIdx++];
			if (tempNode.type == OPERAND){
				push(resultStack, tempNode.data);
			}
			else if (tempNode.type == OPCODE){
				if (tempNode.data == '+' || tempNode.data == '-' || tempNode.data == '*' || tempNode.data == '/'){
					Node topnode = peek(tempStack);
					if (topnode.type != ERROR){
						if (topnode.data == '*' || topnode.data == '/'){
							topnode = pop(tempStack);
							push(resultStack, topnode.data);
							push(tempStack, tempNode.data);
						}
						else{
							push(tempStack, tempNode.data);
						}
					}
					else{//������ ���������
						push(tempStack, tempNode.data);
					}
				}
			}
		}
	/*	exprStartIdx = 0;
		while (tempStack.top+1 != exprStartIdx){
			tempNode = tempStack.node[exprStartIdx++];
			push(resultStack, tempNode.data);
		}*/
		Node node;
		while ((node = pop(tempStack)).type != ERROR){
			push(resultStack, node.data);
		}

		return resultStack;
	}
	
	void printCalStack(Stack stack){
		Node t;
		while ((t = pop(stack)).type != ERROR){
			if (t.type == OPERAND)
				printf("%d", t.data);
			if (t.type == OPCODE)
				printf("%c", t.data);
		}
	}
	/*���� �м��� ���� ��ū�� ������*/
	Node getToken(char* expression, int &expression_index){
		Node result;
		if (expression_index == strlen(expression)){
			result.type = END;
			return result;
		}
		char charoffset = expression[expression_index++];
		char number[100] = { 0, };
		int numberIndex = 0;
		if (charoffset >= '0' && charoffset <= '9'){
			while (charoffset >= '0' && charoffset <= '9'){
				number[numberIndex++] = charoffset;
				charoffset = expression[expression_index++];
				if (charoffset < '0' || charoffset > '9')
					expression_index--;
			}
			result.type = OPERAND;
			result.data = atoi(number);
		}
		else if (charoffset == '+' ||
			charoffset == '-' ||
			charoffset == '*' ||
			charoffset == '/'){
			result.type = OPCODE;
			result.data = charoffset;
		}
		else{
			result.type = ERROR;
		}
		return result;
	}

	Stack createStack(int size){
		Stack stack;
		stack.top = -1;
		stack.node = (pToken)malloc(sizeof(Node)*size);
		memset(stack.node, 0, sizeof(Node)*size);
		stack.top = -1;
		return stack;
	}
	void push(Stack& stack, int data){
		//not full
		if (data == '+' ||
			data == '-' ||
			data == '*' ||
			data == '/'){
			stack.node[++stack.top].data = data;
			stack.node[stack.top].type = OPCODE;
		}
		else{
			stack.node[++stack.top].data = data;
			stack.node[stack.top].type = OPERAND;
		}
	}
	Node pop(Stack& stack){
		if (stack.top != -1){
			return stack.node[stack.top--];
		}
		else{
			Token t;
			t.type = ERROR;
			return t;
		}
	}
	Node peek(Stack& stack){
		if (stack.top != -1){
			return stack.node[stack.top];
		}
		else{
			Token t;
			t.type = ERROR;
			return t;
		}
	}
	void destroyStack(pStack pstack){
		if (pstack->node != NULL)
			free(pstack->node);
		pstack->top = -1;
	}
}