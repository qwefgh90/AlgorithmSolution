#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <queue>
#include "GlobalHeader.h"

namespace RedBlackTree{
	typedef int ElementType;
	typedef enum { LEFT, RIGHT }Direction;
	typedef enum { BLACK, RED }Color;

	/*
	��� ����
	*/
	typedef struct _Node{
		ElementType data;
		_Node *left;
		_Node *right;
		_Node *parent;
		Color color;
	}Node, *pNode;

	/*
	Ʈ�� ����
	*/
	typedef struct _Tree{
		pNode root;
	}Tree,*pTree;

	pNode createNode(ElementType data);
	void appendNode(Tree& tree, pNode childNode);
	void rebuildAfterAppend(Tree& tree, pNode childNode);
	void removeNode(Tree& tree, ElementType data);
	void rotateLeft(Tree& tree, pNode parent);
	void rotateRight(Tree& tree, pNode parent);
	
	void printBST(Node* root);
	void tcase1();
	void tcase2();
	void tcase3();
	void tcase4();
	void tcase5();

	pNode Nil = NULL;

	void rotateLeft(Tree& tree, pNode parent)
	{
		if (parent->parent != NULL && parent->right != NULL){
			pNode grandParent = parent->parent;	//initialize
			pNode rightNode = parent->right;	//right node pointer

			parent->right = rightNode->left;	//move subtree change
			if (rightNode->left != Nil)
				rightNode->left->parent = parent;	//

			rightNode->left = parent;			//change position
			parent->parent = rightNode;			//

			if (grandParent->data > parent->data){
				grandParent->left = rightNode;	//glue
			}
			else {
				grandParent->right = rightNode;	//glue
			}
			rightNode->parent = grandParent;
		}
		else if (parent->right != NULL) {	//case : root node 
			pNode rightNode = parent->right;	//right node pointer
			
			parent->right = rightNode->left;	//move subtree change

			if (rightNode->left != Nil)			//change rightNode's leftNode parent
				rightNode->left->parent = parent;

			rightNode->left = parent;			//change position to parent

			parent->parent = rightNode;			//

			tree.root = rightNode;				//glue;

			rightNode->parent = NULL;
		}
	}

	void rotateRight(Tree& tree, pNode parent)
	{
		if (parent->parent != NULL && parent->left != NULL){
			pNode grandParent = parent->parent;	//initialize
			pNode leftNode = parent->left;		//left node pointer

			parent->left = leftNode->right;		//move subtree change

			if (leftNode->right != Nil)		//parent, if not Nil
				leftNode->right->parent = parent;	

			leftNode->right = parent;			//change position
			parent->parent = leftNode;	

			if (grandParent->data > parent->data){
				grandParent->left = leftNode;	//glue
			} else {
				grandParent->right = leftNode;	//glue
			}
			leftNode->parent = grandParent;
		} 
		else if (parent->parent == NULL && parent->left != NULL) {
			pNode leftNode = parent->left;	//right node pointer

			parent->left = leftNode->right;		//move subtree change

			if (leftNode->right != Nil)			//change rightNode's leftNode parent, if not Nil
				leftNode->right->parent = parent;	//

			leftNode->right = parent;			//change position
			parent->parent = leftNode;

			tree.root = leftNode;				//glue;
			leftNode->parent = NULL;
		}
	}



	pNode createNode(ElementType data)
	{
		pNode pnode = new Node();
		pnode->data = data;
		pnode->left = NULL;
		pnode->right = NULL;

		pnode->parent = NULL;

		return pnode;
	}

	void rebuildAfterAppend(Tree& tree, pNode childNode)
	{
		while (childNode != tree.root && childNode->parent != tree.root && childNode->color == RED && childNode->parent->color == RED) {	//root or parent is root
			pNode parent = childNode->parent;
			pNode grandParent = childNode->parent->parent;
			if (grandParent->left == childNode->parent) {	// My Parent is left
				pNode uncle = grandParent->right;
				if (uncle->color == RED) {	//uncle is RED
					grandParent->color = RED;
					uncle->color = BLACK;
					parent->color = BLACK;

					childNode = childNode->parent->parent;
				}
				else {	//uncle is BLACK
					if (parent->right == childNode) {
						rotateLeft(tree, parent);
						parent = childNode;	//change parent position
					}

					//change color
					grandParent->color = RED;
					parent->color = BLACK;
					rotateRight(tree, grandParent);

					childNode;	//node is at new position
				}
			}
			else {	// My Parent is right
				pNode uncle = grandParent->left;
				if (uncle->color == RED) {	//uncle is RED
					grandParent->color = RED;
					uncle->color = BLACK;
					parent->color = BLACK;

					childNode = childNode->parent->parent;
				}
				else {	//uncle is BLACK
					if (parent->left == childNode) {
						rotateRight(tree, parent);
						parent = childNode;	//change parent position
					}

					//change color
					grandParent->color = RED;
					parent->color = BLACK;
					rotateLeft(tree, grandParent);

					childNode;	//node is at new position
				}
			}
		}
		tree.root->color = BLACK;

	}

	void appendNode(Tree& tree, pNode childNode)
	{
		if (tree.root == NULL){
			tree.root = childNode;
		}
		else{
			Direction direction;
			pNode parentNode = tree.root;
			pNode targetNode = tree.root;
			while (targetNode != Nil){		//Check Nil
				if (targetNode->data > childNode->data){
					parentNode = targetNode;
					targetNode = targetNode->left;
					direction = LEFT;
				}
				else if (targetNode->data < childNode->data){
					parentNode = targetNode;
					targetNode = targetNode->right;
					direction = RIGHT;
				}
				else{
					//not allow duplicate
					return;
				}
			}
			switch (direction){
			case LEFT:
				parentNode->left = childNode;
				break;
			case RIGHT:
				parentNode->right = childNode;
				break;
			}
			childNode->parent = parentNode;	//�θ� ��� ����
		}

		//For RedBlack append
		childNode->color = RED;
		childNode->left = Nil;
		childNode->right = Nil;

		//color rebuild
		rebuildAfterAppend(tree, childNode);
	}

	/*
		���������� ó��
	*/
	void rebuildAfterRemove(Tree& tree, pNode successor)
	{
		while (successor != NULL) {
			if (successor == successor->parent->left) {//���ʿ� ���� ��
				if (successor->parent->right->color == RED) {	//����
					successor->parent->color = RED;
					successor->parent->right->color = BLACK;
					rotateLeft(tree, successor->parent);	//change problem
				}
				else if (successor->parent->right == Nil//�� - ����
					|| (successor->parent->right->color == BLACK
					&& successor->parent->right->left->color == BLACK
					&& successor->parent->right->right->color == BLACK)) {
					successor->parent->right->color = RED;	//change color
					Nil->color = BLACK;	//Nil recovor
					if (successor->parent->color == BLACK) {
						successor->parent->color = BLACK;	//toss color to parent	
						successor = successor->parent;	//change successor to parent
					}
					else {
						successor->parent->color = BLACK;	//toss color to parent
						successor = NULL; // end problem
					}
				}
				else if (successor->parent->right->color == BLACK && successor->parent->right->left->color == RED) {//�� - �����
					successor->parent->right->left->color = BLACK;
					successor->parent->right->color = RED;
					rotateRight(tree, successor->parent->right); //change problem
				}
				else if (successor->parent->right->color == BLACK && successor->parent->right->right->color == RED) {//�� - ������
					successor->parent->right->color = successor->parent->color;
					successor->parent->right->right->color = BLACK;
					successor->parent->color = BLACK;
					rotateLeft(tree, successor->parent);
					successor = NULL;	//end problem
				}
			}
			else {	//�����ʿ� ���� ��
				if (successor->parent->left->color == RED) {	//����
					successor->parent->color = RED;
					successor->parent->left->color = BLACK;
					rotateRight(tree, successor->parent);	//change problem
				}
				else if (successor->parent->left == Nil//�� - ����
					|| (successor->parent->left->color == BLACK
					&& successor->parent->left->left->color == BLACK
					&& successor->parent->left->right->color == BLACK)) {////////////////stop
					successor->parent->left->color = RED;	//change color
					Nil->color = BLACK;	//Nil recovor
					if (successor->parent->color == BLACK) {
						successor->parent->color = BLACK;	//toss color to parent	
						successor = successor->parent;	//change successor to parent
					}
					else {
						successor->parent->color = BLACK;	//toss color to parent
						successor = NULL; // end problem
					}
				}
				else if (successor->parent->left->color == BLACK && successor->parent->left->right->color == RED) {//�� - �����
					successor->parent->left->right->color = BLACK;
					successor->parent->left->color = RED;
					rotateLeft(tree, successor->parent->left); //change problem
				}
				else if (successor->parent->left->color == BLACK && successor->parent->left->left->color == RED) {//�� - ������
					successor->parent->left->color = successor->parent->color;
					successor->parent->left->left->color = BLACK;
					successor->parent->color = BLACK;
					rotateRight(tree, successor->parent);
					successor = NULL;	//end problem
				}
			}
		}
		//���� - ������
		//���� - ���, ��ī ���
		//���� - ���, ���� ��ī ������
		//���� - ���, �ٱ��� ��ī ������
	}

	pNode removeNodeWithTarget(Tree& tree, ElementType data, pNode& parentNode, pNode& targetNode, Direction& direction, pNode& successor)
	{
		pNode removed = NULL;
		//ã�� ��尡 ��Ʈ ����� ���
		if (targetNode == tree.root && targetNode->left == Nil && targetNode->right == Nil) {
			tree.root = NULL;
			removed = targetNode;
		} else {
			//ã�� ��尡 ��Ʈ ��尡 �ƴ� ���
			if (targetNode->left == Nil && targetNode->right == Nil) {
				//�ڽ��� ���� ���
				switch (direction) {
				case LEFT:
					parentNode->left = Nil;
					break;
				case RIGHT:
					parentNode->right = Nil;
					break;
				}
				successor = Nil;
				successor->parent = targetNode->parent;
				removed = targetNode;
			} else if (targetNode->left == Nil || targetNode->right == Nil){
				//�ڽ��� 1�� �ִ� ���
				Direction childDirection;
				if (targetNode->left != Nil){
					childDirection = LEFT;
				} else {
					childDirection = RIGHT;
				}
				if (parentNode != NULL) {	//target is not root
					switch (direction) {
					case LEFT:
						switch (childDirection) {
						case LEFT:
							parentNode->left = targetNode->left;
							targetNode->left->parent = parentNode;	//�θ� ��� ����
							successor = targetNode->left;	//�����
							break;
						case RIGHT:
							parentNode->left = targetNode->right;
							targetNode->right->parent = parentNode;	//�θ� ��� ����
							successor = targetNode->right;	//�����
							break;
						}
						break;
					case RIGHT:
						switch (childDirection){
						case LEFT:
							parentNode->right = targetNode->left;
							targetNode->left->parent = parentNode;	//�θ� ��� ����
							successor = targetNode->left;	//�����
							break;
						case RIGHT:
							parentNode->right = targetNode->right;
							targetNode->right->parent = parentNode;	//�θ� ��� ����
							successor = targetNode->right;	//�����
							break;
						}
						break;
					}
				} else {	// target is root
					switch (childDirection) {
					case LEFT:
						tree.root = targetNode->left;
						targetNode->left->parent = NULL;	//�θ� ��� ����
						successor = targetNode->left;	//�����
						break;
					case RIGHT:
						tree.root = targetNode->right;
						targetNode->right->parent = NULL;	//�θ� ��� ����
						successor = targetNode->right;	//�����
						break;
					}
				}
				removed = targetNode;
			} else {
				//�ڽ��� 2�� �ִ� ���
				if (targetNode->left->right == Nil){
					//LEFT-RIGHT�� NULL�� ���
					removed = targetNode->left;			//subtree's color problem
					successor = targetNode->left->left;	//subtree's color problem
					targetNode->data = targetNode->left->data;	// data swap
					targetNode->left->left->parent = targetNode;	//change parent
					targetNode->left = targetNode->left->left;	// change child
				}
				else{
					//LEFT-RIGHT�� NULL�� �ƴ� ���
					pNode subGrandParentNode = targetNode->left;
					pNode subParentNode = targetNode->left;
					pNode subTargetNode = targetNode->left;
					while (subTargetNode != Nil) {
						subGrandParentNode = subParentNode;
						subParentNode = subTargetNode;
						subTargetNode = subTargetNode->right;
					}
					if (subParentNode->left != Nil) {
						subGrandParentNode->right = subParentNode->left;
						subParentNode->left->parent = subGrandParentNode;
						successor = subParentNode->left;
					} else {
						subGrandParentNode->right = Nil;	//temporary
						Nil->parent = subGrandParentNode;	//temporary
						successor = Nil;
					}
					targetNode->data = subParentNode->data;	//if target's color is RED, only change data
					removed = subParentNode;
				}
			}
		}
		return removed;
	//	targetNode = NULL; //complete 
	}

	void removeNode(Tree& tree, ElementType data)
	{
		Direction direction;
		pNode parentNode = NULL;
		pNode targetNode = tree.root;
		pNode successor = NULL;
		while (targetNode != Nil){
			if (targetNode->data > data){
				parentNode = targetNode;
				targetNode = targetNode->left;
				direction = LEFT;
			} else if (targetNode->data < data){
				parentNode = targetNode;
				targetNode = targetNode->right;
				direction = RIGHT;
			} else {
				pNode removed = removeNodeWithTarget(tree, data, parentNode, targetNode, direction, successor);
				if (removed->color == BLACK && successor != NULL) {	// ������ ��尡 �������� ��� ó��
					if (successor->color == RED) {	// ����ڰ� �������� ��� ó��
						successor->color = BLACK;
					} else {	//����ڰ� ������, ������� ��� ó��
						rebuildAfterRemove(tree,successor);
					}
				}
				delete(removed);
				targetNode = Nil;
			}
		}
	}

	void printBST(Node* root){
		printf("===================\n");
		std::queue<Node*> q;
		if (root != NULL){
			q.push(root);
			Node* node = NULL;
			int level = 0;
			while (q.size() != 0){
				int qsize = q.size();
				int endOfPrint = 1;		//flag for print ending 
				printf("%d level\n", level);
				while (qsize--){
					node = q.front();
					q.pop();

					if (node != NULL && node != Nil){	//not NULL && Nil
						if (node->color == BLACK)
							printf("%c%d ", 'B', node->data);
						else
							printf("%c%d ", 'R', node->data);

						//Don't care NULL ptr (dummy output)
						q.push(node->left);
						q.push(node->right);
						endOfPrint = 0;
					}
					else{
						printf("* ");
						q.push(NULL);
						q.push(NULL);
					}

				}
				printf("\n");
				if (endOfPrint == 1){	//printf end
					break;
				}
				level++;
			}
		}
	}

	int main()
	{
		Nil = createNode(0);
		Nil->color = BLACK;
		/*tcase1();
		tcase2();
		tcase3();
		tcase4();
		tcase5();*/
		return 0;
	}

	/* BST ���� �׽�Ʈ*/
	/* ��������� �����ʿ� ������ ������ �˻� ���� �϶� ó�� */
	void tcase5()
	{
		Tree tree;
		tree.root = NULL;
		appendNode(tree, createNode(16));
		appendNode(tree, createNode(32));
		appendNode(tree, createNode(8));
		appendNode(tree, createNode(4));
		appendNode(tree, createNode(64));
		appendNode(tree, createNode(52));
		appendNode(tree, createNode(48));
		appendNode(tree, createNode(2));
		removeNode(tree, 16);	// remove root
		removeNode(tree, 32);	// remove root
		removeNode(tree, 8);	// remove root
		appendNode(tree, createNode(50));
		removeNode(tree, 64);	// remove root
		printBST(tree.root);
	}

	/* BST ���� �׽�Ʈ */
	/* ��Ʈ ���� ��, ������ ���� ������� ������ �˰˰�, ���� ���� ������� �������� ����, �˻� */
	void tcase4()
	{
		Tree tree;
		tree.root = NULL;
		appendNode(tree, createNode(16));
		appendNode(tree, createNode(32));
		appendNode(tree, createNode(8));
		appendNode(tree, createNode(24));
		appendNode(tree, createNode(48));
		appendNode(tree, createNode(20));
		appendNode(tree, createNode(18));
		appendNode(tree, createNode(28));
		appendNode(tree, createNode(30));
		appendNode(tree, createNode(25));
		printBST(tree.root);
		removeNode(tree, 20);	// remove root
		printBST(tree.root);
	}

	/* BST ���� �׽�Ʈ*/
	/* ���� ���� ������� ������ ����, �˻� �ΰ�� �׽�Ʈ */
	void tcase3()
	{
		Tree tree;
		tree.root = NULL;
		appendNode(tree, createNode(16));
		appendNode(tree, createNode(32));
		appendNode(tree, createNode(8));
		appendNode(tree, createNode(24));
		appendNode(tree, createNode(48));
		appendNode(tree, createNode(20));
		appendNode(tree, createNode(18));
		appendNode(tree, createNode(28));
		appendNode(tree, createNode(17));
		appendNode(tree, createNode(30));
		appendNode(tree, createNode(25));
		printBST(tree.root);
		removeNode(tree, 8);	//�� ���� �� , �� �� ���� ���̽� �׽�Ʈ
		printBST(tree.root);
	}

	/* BST ���� �׽�Ʈ*/
	/* Nil ������� ���� ������ �� �˰˰� �� ���*/
	void tcase1()
	{
		Tree tree;
		tree.root = NULL;
		appendNode(tree, createNode(8));
		appendNode(tree, createNode(4));
		appendNode(tree, createNode(14));
		appendNode(tree, createNode(2));
		appendNode(tree, createNode(6));
		appendNode(tree, createNode(5));
		pNode node10 = createNode(10);
		appendNode(tree, node10);
		appendNode(tree, createNode(18));
		pNode node12 = createNode(127);
		appendNode(tree, node12);
		appendNode(tree, createNode(18));
		pNode node16 = createNode(16);
		appendNode(tree, node16);
		appendNode(tree, createNode(20));
		printBST(tree.root);
		removeNode(tree, 14);	//���� ���� , �� �� �� ���̽� �׽�Ʈ
		printBST(tree.root);
	}
	/* ��� 11�� �߰��ϴ� ���̽� ���� ���� üũ */
	void tcase2()
	{
		Tree tree;
		tree.root = NULL;
		appendNode(tree, createNode(134));
		appendNode(tree, createNode(135));
		appendNode(tree, createNode(136));
		appendNode(tree, createNode(159));
		appendNode(tree, createNode(160));
		appendNode(tree, createNode(161));
		appendNode(tree, createNode(162));
		appendNode(tree, createNode(139));
		appendNode(tree, createNode(137));
		appendNode(tree, createNode(155));
		appendNode(tree, createNode(156));
		printBST(tree.root);
	}
}