#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <queue>
#include <stack>
namespace RedBlackTree {
	typedef int KeyType;
	typedef void* DataPtr;
	typedef enum { LEFT, RIGHT }Direction;
	typedef enum { BLACK, RED }Color;

	/*
	노드 선언
	*/
	typedef struct _Node {
		KeyType key;
		DataPtr dataPtr;
		_Node *left;
		_Node *right;
		_Node *parent;
		Color color;
	}Node, *pNode;

	/*
	트리 선언
	*/
	typedef struct _Tree{
		pNode root;
	}Tree,*pTree;

	pNode createNode(KeyType key,DataPtr data);
	void appendNode(Tree& tree, pNode childNode);
	void rebuildAfterAppend(Tree& tree, pNode childNode);
	void removeNode(Tree& tree, KeyType data, void (*destructor) (DataPtr dataPtr));
	void rotateLeft(Tree& tree, pNode parent);
	void rotateRight(Tree& tree, pNode parent);
	void destroyTree(Tree& tree, void (*destructor) (DataPtr dataPtr));
	DataPtr searchNode(Tree& tree, KeyType key);
	
	void init();
	
	void printBST(Node* root);
	void tcase1();
	void tcase2();
	void tcase3();
	void tcase4();
	void tcase5();
	int main();
}