#include "rbtree.h"

namespace RedBlackTree{

	pNode Nil = NULL;
	
	void init()
	{
		Nil = createNode(0, NULL);
		Nil->color = BLACK;
	}

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

			if (grandParent->key > parent->key){
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

			if (grandParent->key > parent->key){
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



	pNode createNode(KeyType key,DataPtr dataPtr)
	{
		pNode pnode = new Node();
		pnode->key = key;
		pnode->left = NULL;
		pnode->right = NULL;

		pnode->parent = NULL;
		
		pnode->dataPtr = dataPtr;

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
				if (targetNode->key > childNode->key){
					parentNode = targetNode;
					targetNode = targetNode->left;
					direction = LEFT;
				}
				else if (targetNode->key < childNode->key){
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
			childNode->parent = parentNode;	//부모 노드 조정
		}

		//For RedBlack append
		childNode->color = RED;
		childNode->left = Nil;
		childNode->right = Nil;

		//color rebuild
		rebuildAfterAppend(tree, childNode);
	}

	/*
		이중흑색노드 처리
	*/
	void rebuildAfterRemove(Tree& tree, pNode successor)
	{
		while (successor != NULL) {
			if (successor == successor->parent->left) {//왼쪽에 있을 때
				if (successor->parent->right->color == RED) {	//레드
					successor->parent->color = RED;
					successor->parent->right->color = BLACK;
					rotateLeft(tree, successor->parent);	//change problem
				}
				else if (successor->parent->right == Nil//블랙 - 블랙블랙
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
				else if (successor->parent->right->color == BLACK && successor->parent->right->left->color == RED) {//블랙 - 레드블랙
					successor->parent->right->left->color = BLACK;
					successor->parent->right->color = RED;
					rotateRight(tree, successor->parent->right); //change problem
				}
				else if (successor->parent->right->color == BLACK && successor->parent->right->right->color == RED) {//블랙 - 블랙레드
					successor->parent->right->color = successor->parent->color;
					successor->parent->right->right->color = BLACK;
					successor->parent->color = BLACK;
					rotateLeft(tree, successor->parent);
					successor = NULL;	//end problem
				}
			}
			else {	//오른쪽에 있을 때
				if (successor->parent->left->color == RED) {	//레드
					successor->parent->color = RED;
					successor->parent->left->color = BLACK;
					rotateRight(tree, successor->parent);	//change problem
				}
				else if (successor->parent->left == Nil//블랙 - 블랙블랙
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
				else if (successor->parent->left->color == BLACK && successor->parent->left->right->color == RED) {//블랙 - 레드블랙
					successor->parent->left->right->color = BLACK;
					successor->parent->left->color = RED;
					rotateLeft(tree, successor->parent->left); //change problem
				}
				else if (successor->parent->left->color == BLACK && successor->parent->left->left->color == RED) {//블랙 - 블랙레드
					successor->parent->left->color = successor->parent->color;
					successor->parent->left->left->color = BLACK;
					successor->parent->color = BLACK;
					rotateRight(tree, successor->parent);
					successor = NULL;	//end problem
				}
			}
		}
		//형제 - 빨간색
		//형제 - 흑색, 조카 흑색
		//형제 - 흑색, 안쪽 조카 빨간색
		//형제 - 흑색, 바깥쪽 조카 빨간색
	}

	pNode removeNodeWithTarget(Tree& tree, KeyType data, pNode& parentNode, pNode& targetNode, Direction& direction, pNode& successor)
	{
		pNode removed = NULL;
		//찾은 노드가 루트 노드인 경우
		if (targetNode == tree.root && targetNode->left == Nil && targetNode->right == Nil) {
			tree.root = NULL;
			removed = targetNode;
		} else {
			//찾은 노드가 루트 노드가 아닌 경우
			if (targetNode->left == Nil && targetNode->right == Nil) {
				//자식이 없는 경우
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
				//자식이 1개 있는 경우
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
							targetNode->left->parent = parentNode;	//부모 노드 조정
							successor = targetNode->left;	//상속자
							break;
						case RIGHT:
							parentNode->left = targetNode->right;
							targetNode->right->parent = parentNode;	//부모 노드 조정
							successor = targetNode->right;	//상속자
							break;
						}
						break;
					case RIGHT:
						switch (childDirection){
						case LEFT:
							parentNode->right = targetNode->left;
							targetNode->left->parent = parentNode;	//부모 노드 조정
							successor = targetNode->left;	//상속자
							break;
						case RIGHT:
							parentNode->right = targetNode->right;
							targetNode->right->parent = parentNode;	//부모 노드 조정
							successor = targetNode->right;	//상속자
							break;
						}
						break;
					}
				} else {	// target is root
					switch (childDirection) {
					case LEFT:
						tree.root = targetNode->left;
						targetNode->left->parent = NULL;	//부모 노드 조정
						successor = targetNode->left;	//상속자
						break;
					case RIGHT:
						tree.root = targetNode->right;
						targetNode->right->parent = NULL;	//부모 노드 조정
						successor = targetNode->right;	//상속자
						break;
					}
				}
				removed = targetNode;
			} else {
				//자식이 2개 있는 경우
				if (targetNode->left->right == Nil){
					//LEFT-RIGHT가 NULL인 경우
					removed = targetNode->left;			//subtree's color problem
					successor = targetNode->left->left;	//subtree's color problem
					targetNode->key = targetNode->left->key;	// data swap
					targetNode->left->left->parent = targetNode;	//change parent
					targetNode->left = targetNode->left->left;	// change child
				}
				else{
					//LEFT-RIGHT가 NULL이 아닌 경우
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
					targetNode->key = subParentNode->key;	//if target's color is RED, only change data
					removed = subParentNode;
				}
			}
		}
		return removed;
	//	targetNode = NULL; //complete 
	}

	void removeNode(Tree& tree, KeyType key, void (*destructor) (DataPtr dataPtr))
	{
		Direction direction;
		//DataPtr returnValue = NULL;
		pNode parentNode = NULL;
		pNode targetNode = tree.root;
		pNode successor = NULL;
		while (targetNode != Nil && tree.root != NULL){
			if (targetNode->key > key){
				parentNode = targetNode;
				targetNode = targetNode->left;
				direction = LEFT;
			} else if (targetNode->key < key){
				parentNode = targetNode;
				targetNode = targetNode->right;
				direction = RIGHT;
			} else {
				pNode removed = removeNodeWithTarget(tree, key, parentNode, targetNode, direction, successor);
				if (removed->color == BLACK && successor != NULL) {	// 삭제한 노드가 검은색인 경우 처리
					if (successor->color == RED) {	// 상속자가 빨간색인 경우 처리
						successor->color = BLACK;
					} else {	//상속자가 검은색, 이중흑색 노드 처리
						rebuildAfterRemove(tree,successor);
					}
				}
				//returnValue = removed->dataPtr;
				if(NULL != destructor)
					destructor(removed->dataPtr);
				delete(removed);
				targetNode = Nil;
			}
		}
	}

	void destroyTree(Tree& tree, void (*destructor) (DataPtr dataPtr))
	{
		if(NULL != tree.root) {
			std::queue<pNode> queue;
			std::stack<pNode> stack;
			pNode targetNode = NULL;
			queue.push(tree.root);
			stack.push(tree.root);

			while(0 != queue.size()) {
				targetNode = queue.front();
				queue.pop();
				if(Nil != targetNode) { 
					queue.push(targetNode->left);
					queue.push(targetNode->right);	
					stack.push(targetNode->left);
					stack.push(targetNode->right);
				}
			}
			pNode topNode = NULL;

			while(0 != stack.size()) {
					topNode = stack.top();
					stack.pop();
					if(topNode != Nil) {
						if(NULL != destructor) {
							destructor(topNode->dataPtr);	//destruct data
						}
						delete topNode;	//release pointer
					}
			}
			tree.root = NULL;
		}		
	}
	
	DataPtr searchNode(Tree& tree, KeyType key)
	{
		pNode targetNode = tree.root;

		while(Nil != targetNode && NULL != targetNode) {
			if(targetNode->key > key) {
				targetNode = targetNode->left;
			} else if(targetNode->key < key) {
				targetNode = targetNode->right;
			} else {
				return targetNode->dataPtr;
			}
		}
		return NULL;
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
							printf("%c%d ", 'B', node->key);
						else
							printf("%c%d ", 'R', node->key);

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
		Nil = createNode(0, NULL);
		Nil->color = BLACK;
		tcase1();
		tcase2();
		tcase3();
		tcase4();
		tcase5();
		return 0;
	}

	/* BST 유닛 테스트*/
	/* 이중흑색이 오른쪽에 있을때 형제가 검빨 빨검 일때 처리 */
	void tcase5()
	{
		Tree tree;
		tree.root = NULL;
		appendNode(tree, createNode(16, NULL));
		appendNode(tree, createNode(32, NULL));
		appendNode(tree, createNode(8, NULL));
		appendNode(tree, createNode(4, NULL));
		appendNode(tree, createNode(64, NULL));
		appendNode(tree, createNode(52, NULL));
		appendNode(tree, createNode(48, NULL));
		appendNode(tree, createNode(2, NULL));
		removeNode(tree, 16, NULL);	// remove root
		removeNode(tree, 32, NULL);	// remove root
		removeNode(tree, 8, NULL);	// remove root
		appendNode(tree, createNode(50, NULL));
		removeNode(tree, 64, NULL);	// remove root
		printBST(tree.root);
	}

	/* BST 유닛 테스트 */
	/* 루트 삭제 후, 오른쪽 이중 흑색에서 형제는 검검검, 왼쪽 이중 흑색에서 오른쪽은 빨검, 검빨 */
	void tcase4()
	{
		Tree tree;
		tree.root = NULL;
		appendNode(tree, createNode(16, NULL));
		appendNode(tree, createNode(32, NULL));
		appendNode(tree, createNode(8, NULL));
		appendNode(tree, createNode(24, NULL));
		appendNode(tree, createNode(48, NULL));
		appendNode(tree, createNode(20, NULL));
		appendNode(tree, createNode(18, NULL));
		appendNode(tree, createNode(28, NULL));
		appendNode(tree, createNode(30, NULL));
		appendNode(tree, createNode(25, NULL));
		printBST(tree.root);
		removeNode(tree, 20, NULL);	// remove root
		printBST(tree.root);
	}

	/* BST 유닛 테스트*/
	/* 왼쪽 이중 흑색에서 형제가 빨검, 검빨 인경우 테스트 */
	void tcase3()
	{
		Tree tree;
		tree.root = NULL;
		appendNode(tree, createNode(16, NULL));
		appendNode(tree, createNode(32, NULL));
		appendNode(tree, createNode(8, NULL));
		appendNode(tree, createNode(24, NULL));
		appendNode(tree, createNode(48, NULL));
		appendNode(tree, createNode(20, NULL));
		appendNode(tree, createNode(18, NULL));
		appendNode(tree, createNode(28, NULL));
		appendNode(tree, createNode(17, NULL));
		appendNode(tree, createNode(30, NULL));
		appendNode(tree, createNode(25, NULL));
		printBST(tree.root);
		removeNode(tree, 8, NULL);	//블랙 레드 블랙 , 블랙 블랙 레드 케이스 테스트
		printBST(tree.root);
	}

	/* BST 유닛 테스트*/
	/* Nil 이중흑색 형제 빨간색 및 검검검 일 경우*/
	void tcase1()
	{
		Tree tree;
		tree.root = NULL;
		appendNode(tree, createNode(8, NULL));
		appendNode(tree, createNode(4, NULL));
		appendNode(tree, createNode(14, NULL));
		appendNode(tree, createNode(2, NULL));
		appendNode(tree, createNode(6, NULL));
		appendNode(tree, createNode(5, NULL));
		pNode node10 = createNode(10, NULL);
		appendNode(tree, node10);
		appendNode(tree, createNode(18, NULL));
		pNode node12 = createNode(127, NULL);
		appendNode(tree, node12);
		appendNode(tree, createNode(18, NULL));
		pNode node16 = createNode(16, NULL);
		appendNode(tree, node16);
		appendNode(tree, createNode(20, NULL));
		printBST(tree.root);
		removeNode(tree, 14, NULL);	//형제 레드 , 블랙 블랙 블랙 케이스 테스트
		printBST(tree.root);
	}
	/* 노드 11개 추가하는 케이스 검정 갯수 체크 */
	void tcase2()
	{
		Tree tree;
		tree.root = NULL;
		appendNode(tree, createNode(134, NULL));
		appendNode(tree, createNode(135, NULL));
		appendNode(tree, createNode(136, NULL));
		appendNode(tree, createNode(159, NULL));
		appendNode(tree, createNode(160, NULL));
		appendNode(tree, createNode(161, NULL));
		appendNode(tree, createNode(162, NULL));
		appendNode(tree, createNode(139, NULL));
		appendNode(tree, createNode(137, NULL));
		appendNode(tree, createNode(155, NULL));
		appendNode(tree, createNode(156, NULL));
		printBST(tree.root);
	}
}