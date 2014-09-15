#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <queue>
typedef int ElementType;
struct Node{
	ElementType data;
	Node* leftChild;
	Node* rightChild;
	Node(){
		this->data = 0;
		this->leftChild = NULL;
		this->rightChild = NULL;
	}
	Node(ElementType data){
		this->data = data;
		this->leftChild = NULL;
		this->rightChild = NULL;
	}
}*pNode;

struct Tree{
	Node* Root;
	Tree(){
		this->Root=NULL;
	}
}*pTree;

Node* searchNode(Node* root, ElementType target){
	Node* parent = root;
	int level=0;
	while(parent!=NULL){
		if(target > parent->data){
			parent = parent->rightChild;
		}else if(target < parent->data){
			parent = parent->leftChild;
		}else{
			printf("found level : %d\n",level);
			return parent;
		}
		level ++;
	}
	return parent;
}

void insertNode(Node* *root, Node* child){
	if(*root==NULL){
		*root = child;	
		return;
	}
	Node* parent = *root;
	while(parent!=NULL && child !=NULL){
		if(parent->data <= child->data){
			if(parent->rightChild!=NULL)
				parent = parent->rightChild;
			else{
				parent->rightChild = child;
				break;//insert completion
			}
		}else if(parent->data > child->data){
			if(parent->leftChild!=NULL)
				parent = parent->leftChild;
			else{
				parent->leftChild = child;
				break;//insert completion
			}
		}
	}
}

void removeNode(Node* *root, ElementType target){
	if(*root == NULL){
		return;
	}
	Node* parent = *root;
	Node* previous = NULL;
	while(parent!=NULL){
		if(parent->data == target){
			//remove case1
			if(parent->leftChild== NULL && parent->rightChild== NULL){	//0 child node
				if(previous==NULL){
					*root =NULL;
					//free(parent);
				}else{
					if(previous->data <= target){
						previous->rightChild = NULL;
						//free(parent);
					}else{
						previous->leftChild = NULL;
						//free(parent);
					}
				}
			}else if(parent->leftChild != NULL && parent->rightChild == NULL){	// only 1 left node
				if(previous== NULL){
					*root = parent->leftChild;
					//free(parent);
				}else{
					if(previous->data <= target){
						previous->rightChild = parent->leftChild;
						//free(parent);
					}else{
						previous->leftChild = parent->leftChild;
						//free(parent);
					}
				}
			}else if(parent->rightChild !=NULL && parent->leftChild ==NULL){	//only 1 right node
				if(previous== NULL){
					*root = parent->rightChild;
					//free(parent);
				}else{
					if(previous->data <= target){
						previous->rightChild = parent->rightChild;
						//free(parent);
					}else{
						previous->leftChild = parent->rightChild;
						//free(parent);
					}
				}
			}else{	// both is not NULL
				Node* subtree = parent->leftChild;
				Node* subprevious = NULL;
				while(subtree->rightChild!=NULL){
					subprevious = subtree;
					subtree = subtree->rightChild;
				}
				if(subprevious == NULL){
					parent->data = subtree->data;
					parent->leftChild = subtree->leftChild;
					//free(subtree);
				}else{
					parent->data = subtree->data;	//swap
					subprevious -> rightChild =NULL;
					//free(subtree);
				}
			}
			return;

		}else if(parent->data <= target){
			previous = parent;
			parent = parent->rightChild;

			if(parent==NULL){
				//not exists 
				return;
			}
		}else if(parent->data > target){
			previous = parent;
			parent = parent->leftChild;

			if(parent==NULL){
				//not exists
				return;
			}
		}
	}
}

void printBST(Node* root){
	std::queue<Node*> q;
	if(root!=NULL){
		q.push(root);
		Node* node = NULL;
		int level= 0;
		while(q.size() != 0){
			int qsize = q.size();
			int endOfPrint = 1;		//flag for print ending 
			printf("%d level\n",level);
			while(qsize--){
				node = q.front();
				q.pop();

				if(node!=NULL){
					printf("%d ",node->data);
					//Don't care NULL ptr (dummy output)
					q.push(node->leftChild);
					q.push(node->rightChild);
					endOfPrint=0;
				}
				else{
					printf("* ");
					q.push(NULL);
					q.push(NULL);
				}
				
			}
			printf("\n");
			if(endOfPrint==1){	//printf end
				break;
			}
			level ++;
		}
	}
}

int main(){
	Tree tree; tree.Root = NULL;
	Node *node1 = new Node(1);
	Node *node2 = new Node(2);
	Node *node3 = new Node(3);
	Node *node4 = new Node(4);
	Node *node5 = new Node(5);
	Node *node6 = new Node(6);
	Node *node7 = new Node(7);
	Node *node8 = new Node(8);
	Node *node9 = new Node(9);
	Node *node10 = new Node(10);
	Node *node11 = new Node(11);
	Node *node12 = new Node(12);
	insertNode(&tree.Root,node4);
	insertNode(&tree.Root,node2);
	insertNode(&tree.Root,node1);
	insertNode(&tree.Root,node3);
	insertNode(&tree.Root,node10);
	insertNode(&tree.Root,node7);
	insertNode(&tree.Root,node8);
	insertNode(&tree.Root,node9);
	insertNode(&tree.Root,node5);
	insertNode(&tree.Root,node6);
	insertNode(&tree.Root,node11);
	removeNode(&tree.Root,10);
	printBST(tree.Root);
	searchNode(tree.Root,11);
	return 0;
}