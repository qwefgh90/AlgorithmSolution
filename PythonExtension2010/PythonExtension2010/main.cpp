#include "include.h"

static PyObject* changError;
static PyMethodDef ChangExt1_MTable[] = {
	{ "add", changext_add, METH_VARARGS, "a function of adding param1 to param2" },
	{ "fibonachi", changext_fibonachi, METH_VARARGS, "a function of fibonachi" },
	{ "rbCreateTree", changext_rbCreateTree, METH_VARARGS, "a function of rbCreateTree" },
	{ "rbCreateNode", changext_rbCreateNode, METH_VARARGS, "a function of rbCreateNode" },
	{ "rbAppendNode", changext_rbAppendNode, METH_VARARGS, "a function of rbAppendNode" },
	{ "rbRemoveNode", changext_rbRemoveNode, METH_VARARGS, "a function of rbRemoveNode" },
	{ "rbSearchNode", changext_rbSearchNode, METH_VARARGS, "a function of rbSearchNode" },
	{ "rbDestroyTree", changext_rbDestroyTree, METH_VARARGS, "a function of rbDestroyTree" },
	{ "rbPrintTree", changext_rbPrintTree, METH_VARARGS, "a function of rbPrintTree" },
	{ NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC initchangext(void){
	PyObject* module = Py_InitModule("changext", ChangExt1_MTable);
	if (module == NULL)
		return;

	changError = PyErr_NewException("ChangExt1.error", NULL, NULL);
	Py_INCREF(changError);
	PyModule_AddObject(module, "error", changError);
	
	rbInit();
}
/*
	from changext import *
	tree = rbCreateTree("hello")
	rbAppendNode(tree,rbCreateNode(12,'node1'))
	rbAppendNode(tree,rbCreateNode(24,'node2'))
	rbRemoveNode(tree,24);
	rbRemoveNode(tree,12);
	rbRemoveNode(tree,24);
	rbAppendNode(tree,rbCreateNode(12,'node12'))
	rbAppendNode(tree,rbCreateNode(24,'node24'))
	rbAppendNode(tree,rbCreateNode(48,'node48'))
	rbAppendNode(tree,rbCreateNode(6,'node6'))
	rbSearchNode(tree,6)
*/