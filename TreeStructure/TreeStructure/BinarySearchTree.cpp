#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <queue>

namespace BinarySearchTree
{
	typedef int ElementType;
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
	int deleteNode(pNode *node, ElementType data);
	pNode searchNode(pNode node, ElementType data);
	void printBST(Node* root);
	int main(){
		pNode root = createNode(20);
		appendNode(root, createNode(30));
		appendNode(root, createNode(10));
		appendNode(root, createNode(25));
		appendNode(root, createNode(23));
		appendNode(root, createNode(27));
		appendNode(root, createNode(15));
		appendNode(root, createNode(13));
		appendNode(root, createNode(17));
		appendNode(root, createNode(5));
		appendNode(root, createNode(3));
		appendNode(root, createNode(8));
		printBST(root);
		deleteNode(&root, 5);
		printBST(root);
		return 0;
	}
	//노드 생성
	pNode createNode(ElementType data){
		pNode newNode = new Node();
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	//노드 삭제
	void destroyNode(pNode node){
		if (node != NULL)
			delete node;
	}
	//트리 삭제
	void destroyTree(pNode root){
		if (root != NULL){
			destroyTree(root->left);
			destroyTree(root->right);
			delete root;
		}
	}
	//노드 삽입
	void appendNode(pNode parent, pNode child){
		if (parent->data > child->data){
			if (parent->left == NULL)
				parent->left = child;
			else
				appendNode(parent->left, child);
		}
		else if (parent->data < child->data){
			if (parent->right == NULL)
				parent->right = child;
			else
				appendNode(parent->right, child);
		}
		else{
			//nothing
		}
	}
	//노드 탐색
	pNode searchNode(pNode node, ElementType data){
		pNode child = NULL;
		if (node == NULL){ //찾으려는 노드가 NULL일때
			return NULL;
		}
		else{
			if (node->data > data){ //찾으려는 데이터가 작을 때
				return searchNode(node->left, data);
			}
			else if (node->data < data){ //찾으려는 데이터가 작을 때
				return searchNode(node->right, data);
			}
			else{	//찾았을 때
				return node;
			}
		}
	}
	void findMaxNode(pNode &tour, pNode &parent){
		while (tour != NULL){
			if (tour->right != NULL){
				parent = tour;
				tour = tour->right;
			}
			else{
				break;
			}
		}
	}
	//노드 삭제
	int deleteNode(pNode *node, ElementType data){
		int result = 0;
		if (node != NULL){
			pNode parent = NULL;
			pNode tour = *node;
			while (tour != NULL){
				if (tour->data > data){
					parent = tour;
					tour = tour->left;
				}
				else if (tour->data < data){
					parent = tour;
					tour = tour->right;
				}
				else{
					result = 1;
					if (parent == NULL){
						*node = NULL;	//루트를 제거함
						delete tour;
					}else{
						//node 0
						if (tour->left == NULL && tour->right == NULL){
							if (parent->data > tour->data){
								parent->left = NULL;
								delete tour;
							}
							else {
								parent->right = NULL;
								delete tour;
							}
						}

						//node 1
						else if (tour->left == NULL && tour->right != NULL){
							if (parent->data > tour->data){
								parent->left = tour->right;
								delete tour;
							}
							else {
								parent->right = tour->right;
								delete tour;
							}
						}
						else if (tour->right == NULL && tour->left != NULL){
							if (parent->data > tour->data){
								parent->left = tour->left;
								delete tour;
							}
							else {
								parent->right = tour->left;
								delete tour;
							}
						}
						//node 2
						pNode innerTour = tour->left;
						pNode innerParent = tour;
						findMaxNode(innerTour, innerParent);
						if (innerTour == tour->left){
							tour->data = innerTour->data;
							tour->left = innerTour->left;
							delete innerTour;
						}
						else{
							tour->data = innerTour->data;
							innerParent->right = innerTour->left;
							delete innerTour;
						}
					}
				}
			}
		}
		return result;
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
	void printBST(Node* root){
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

					if (node != NULL){
						printf("%d ", node->data);
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
}