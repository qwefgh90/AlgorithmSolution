#include <stdio.h>
#include "GlobalHeader.h"
namespace BinaryTree{
	typedef char ElementType;
	/*
	노드 선언
	*/
	typedef struct _Node{
		ElementType data;
		_Node *left;
		_Node *right;
	}Node, *pNode;

	pNode createNode(ElementType data);
	void appendNode(pNode parent, pNode child);
	void destroyTree(pNode root);
	void destroyNode(pNode node);
	void printPreOrder(pNode root);
	void printInOrder(pNode root);
	void printPostOrder(pNode root);
	int main(){
		pNode root = createNode('A');
		pNode B = createNode('B');
		pNode C = createNode('C');
		pNode D = createNode('D');
		pNode E = createNode('E');
		pNode F = createNode('F');
		pNode G = createNode('G');
		pNode H = createNode('H');
		root->left = B;
		root->right = C;
		B->left = D;
		B->right = E;
		C->left = F;
		C->right = G;
		D->left = H;
		printPreOrder(root);
		printf("\n"); 
		printInOrder(root);
		printf("\n");
		printPostOrder(root);
		return 0;
	}

	pNode createNode(ElementType data){
		pNode newNode = new Node();
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	void appendNode(pNode parent, pNode child){
		if (parent->left == NULL){
			parent->left = child;
		}
		else if (parent->right == NULL){
			parent->right = child;
		}
	}

	void destroyNode(pNode node){
		if (node != NULL)
			delete node;
	}

	void destroyTree(pNode root){
		if (root != NULL){
			destroyTree(root->left);
			destroyTree(root->right);
			delete root;
		}
	}

	void printPreOrder(pNode root){
		if (root != NULL){
			printf("%c ", root->data);
			printPreOrder(root->left);
			printPreOrder(root->right);
		}
	}
	void printInOrder(pNode root){
		if (root != NULL){
			printInOrder(root->left);
			printf("%c ", root->data);
			printInOrder(root->right);
		}
	}
	void printPostOrder(pNode root){
		if (root != NULL){
			printPostOrder(root->left);
			printPostOrder(root->right);
			printf("%c ", root->data);
		}
	}
}