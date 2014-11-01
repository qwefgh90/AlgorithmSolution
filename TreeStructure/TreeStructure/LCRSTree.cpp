#include <stdio.h>
#include "GlobalHeader.h"
namespace LCRSTree{
typedef char ElementType;
typedef struct _Node{
	ElementType data;
	_Node* leftChild;
	_Node* rightSibling;
}Node, *pNode;
pNode createNode(ElementType data);
void appendChildNode(pNode parent, pNode child);
void printTree(pNode node, int depth);
void destroyNode(pNode root);
void printNodesAtLevel(pNode, int);

int main(){
	//pNode root = createNode(88);
	//appendChildNode(root, createNode(90));
	//appendChildNode(root, createNode(80));
	//appendChildNode(root, createNode(94));
	//appendChildNode(root, createNode(74));
	//appendChildNode(root->leftChild, createNode(60));
	//appendChildNode(root->leftChild->rightSibling, createNode(55));
	//appendChildNode(root->leftChild->rightSibling, createNode(50));
	//appendChildNode(root->leftChild->rightSibling->rightSibling->rightSibling, createNode(30));
	////printTree(root, 0);
	//printNodesAtLevel(root, 0);
	//destroyNode(root);
	Node* Root = createNode('A');
	Node* B = createNode('B');
	Node* C = createNode('C');
	Node* D = createNode('D');
	Node* E = createNode('E');
	Node* F = createNode('F');
	Node* G = createNode('G');
	Node* H = createNode('H');
	Node* I = createNode('I');
	Node* J = createNode('J');
	Node* K = createNode('K');

	appendChildNode(Root, B);
	appendChildNode(B,C);
	appendChildNode(B, D);
	appendChildNode(D, E);
	appendChildNode(D, F);
	appendChildNode(Root, G);
	appendChildNode(G, H);
	appendChildNode(Root, I);
	appendChildNode(I, J);
	appendChildNode(J, K);

	//printTree(Root, 0);

	printNodesAtLevel(Root, 2);

	destroyNode(Root);

	return 0;
}

/* ��� ���� */
pNode createNode(ElementType data){
	pNode node = new Node();
	node->leftChild = NULL;
	node->rightSibling = NULL;
	node->data = data;
	return node;
}
/*
�ڽ� ��带 �߰��ϴ� �Լ�
�θ��� �ڽĿ� ���Ḯ��Ʈ�� �ڽĵ��� ������
*/
void appendChildNode(pNode parent, pNode child){
	if (parent != NULL){
		if (parent->leftChild == NULL){
			parent->leftChild = child;
		}
		else{
			pNode childValue = parent->leftChild;
			while (childValue->rightSibling != NULL){
				childValue = childValue->rightSibling;
			}
			childValue->rightSibling = child;	//������ ��忡 �߰�
		}

	}
}

/* Ʈ�� ��� */
void printTree(pNode node, int depth){
	int index = 0;
	if (node != NULL){
		for (index = 0; index < depth; index++){
			printf(" ");
		}
		printf("%c\n", node->data);
		
	}
	//����
	//�ڽ�
	if (node != NULL){
		printTree(node->leftChild, depth + 1);//�ڽ�
		printTree(node->rightSibling, depth);//����
	}
}

void printNodesAtLevel(pNode root, int depth){
	if (depth == 0){
		pNode tempValue = root;
		while (tempValue){
			printf("%c ", tempValue->data);
			tempValue = tempValue->rightSibling;
		}
	}
	else{
		pNode tempValue = root;
		while (tempValue){
			printNodesAtLevel(tempValue->leftChild, depth - 1);
			tempValue = tempValue->rightSibling;
		}
	}
}

/* Ʈ�� �Ҹ� */
void destroyNode(pNode root){
	if (root != NULL){
		destroyNode(root->rightSibling);
		destroyNode(root->leftChild);
		delete root;
	}
}
}