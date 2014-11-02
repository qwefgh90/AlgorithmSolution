#include "py_rbtree.h"
using namespace RedBlackTree;
/*
	create tree in C memory and make PyCapsule Object
	param: string treeName
	return: tree capsule object
*/
void rbInit()
{
	init();
}
PyObject* changext_rbCreateTree(PyObject* self, PyObject* args)
{
	PyObject* capsuleReturnObject = NULL;
	const char* pytreeName = NULL;		//참조 카운트 0 이다. 이후 가비지 컬렉팅 된다.
	char* const treeName = new char[255];
	memset(treeName, 0, sizeof(char) * 255);
	if(NULL == PyArg_ParseTuple(args,"s",&pytreeName)) {
		delete treeName; // free tree Name
		return NULL;
	}
	if(strlen(pytreeName) > 254) {
		strncpy(treeName, pytreeName, 254);
	} else {
		strcpy(treeName, pytreeName);
	}
	Tree* treePtr = new Tree();	//capsule이 컬렉팅 되기전 tree의 생명을 처리는 프로그래머의 몫
	capsuleReturnObject = PyCapsule_New(treePtr, treeName, changext_destructorCapsuleName);	//need destructor
	return capsuleReturnObject;
}
/*
	create Node
	param: int key, PyObject dataPtr
	return: node capsule object
*/
PyObject* changext_rbCreateNode(PyObject* self, PyObject* args)
{
	int key = -1;
	PyObject* dataPtr = NULL;
	PyObject* capsuleReturnObject = NULL;
	if(NULL == PyArg_ParseTuple(args, "iO", &key, &dataPtr)) {
		return NULL;
	}
	Py_XINCREF(dataPtr);	//Store dataPtr Object
	pNode newNode = createNode(key, dataPtr);	//capsule이 컬렉팅 되기전에 node의 생명을 처리는 프로그래머의 몫
	capsuleReturnObject = PyCapsule_New(newNode, "node", changext_destructorEmpty);	//don't need destructor
	return capsuleReturnObject;
}

/*
	appendNode to RedBlackTree
	param: PyObject* tree, PyObject* node
	return: None
*/
PyObject* changext_rbAppendNode(PyObject* self, PyObject* args)
{
	PyObject* pyTree = NULL;
	PyObject* pyNode = NULL;
	if(NULL == PyArg_ParseTuple(args, "OO", &pyTree, &pyNode)) {
		return NULL;
	}
	if(NULL == pyTree
		|| NULL == pyNode) {
			return NULL;
	}
	Tree* treePtr = (Tree*)PyCapsule_GetPointer(pyTree, PyCapsule_GetName(pyTree));
	
	if(NULL == treePtr) {
		return NULL;
	}

	Node* node = (Node*)PyCapsule_GetPointer(pyNode, "node");
	appendNode(*treePtr, node);
	return Py_BuildValue("s",NULL);
}

/*
	remove Node
	param: PyObject* tree, int key
	return: None
*/
PyObject* changext_rbRemoveNode(PyObject* self, PyObject* args)
{
	PyObject* pyTree = NULL;
	int key = -1;
	if(NULL == PyArg_ParseTuple(args, "Oi", &pyTree, &key)) {
		return NULL;
	}
	Tree* tree = (Tree*)PyCapsule_GetPointer(pyTree, PyCapsule_GetName(pyTree));
	removeNode(*tree, key, changext_xdecref);//now, not use dataPtr
	return Py_BuildValue("s",NULL);
}

//레드블랙트리 노드 검색
/*
	search node, using key
	param: PyObject* tree, int key
	return: DataPtr
*/
PyObject* changext_rbSearchNode(PyObject* self, PyObject* args)
{
	PyObject* pyTree = NULL;
	int key = -1;
	if(NULL == PyArg_ParseTuple(args, "Oi", &pyTree, &key)) {
		return NULL;
	}
	Tree* treePtr = (Tree*)PyCapsule_GetPointer(pyTree, PyCapsule_GetName(pyTree));
	
	if(NULL == treePtr) {
		return NULL;
	}

	PyObject* pySearchObject = (PyObject*)searchNode(*treePtr, key);
	if(NULL != pySearchObject)
		return pySearchObject;
	else
		return Py_BuildValue("s",NULL);

}
//레드블랙트리 트리 삭제
/*
	remove Tree
	param: PyObject* tree
	return: None
*/
PyObject* changext_rbDestroyTree(PyObject* self, PyObject* args)
{
	PyObject* pyTree = NULL;
	if(NULL == PyArg_ParseTuple(args, "O", &pyTree)) {
		return NULL;
	}
	Tree* treePtr = (Tree*)PyCapsule_GetPointer(pyTree, PyCapsule_GetName(pyTree));

	if(NULL == treePtr) {
		return NULL;
	}

	destroyTree(*treePtr, changext_xdecref);
	return Py_BuildValue("s",NULL);
}
/*
	print tree
	param: PyObject* tree
	return: None
*/
PyObject* changext_rbPrintTree(PyObject* self, PyObject* args)
{
	PyObject* pyTree = NULL;
	if(NULL == PyArg_ParseTuple(args, "O", &pyTree)) {
		return NULL;
	}
	Tree* treePtr = (Tree*)PyCapsule_GetPointer(pyTree, PyCapsule_GetName(pyTree));

	if(NULL == treePtr) {
		return NULL;
	}

	printBST(treePtr->root);
	return Py_BuildValue("s",NULL);
}