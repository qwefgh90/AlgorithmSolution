#include "include.h"

static PyObject* changError;

PyObject* changext_add(PyObject* self, PyObject* args){
	int operand1;
	int operand2;

	if(!PyArg_ParseTuple(args,"ii",&operand1,&operand2)){
		return NULL;
	}
	
	PyObject* returnVal = Py_BuildValue("i",operand1+operand2);
	if(returnVal == NULL){
		return NULL;
	}else{
		return returnVal;
	}
}

PyObject* changext_fibonachi(PyObject* self, PyObject* args){
	int operand1;

	if(!PyArg_ParseTuple(args,"i",&operand1)){
		return NULL;
	}
	
	PyObject* returnVal = Py_BuildValue("l",fibonachi(operand1));
	if(returnVal == NULL){
		return NULL;
	}else{
		return returnVal;
	}
}

static PyMethodDef ChangExt1_MTable[] = {
	{ "add", changext_add, METH_VARARGS, "a function of adding param1 to param2" },
	{ "fibonachi", changext_fibonachi, METH_VARARGS, "a function of fibonachi" },
	{ NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC initchangext(void){
	PyObject* module = Py_InitModule("changext", ChangExt1_MTable);
	if (module == NULL)
		return;

	changError = PyErr_NewException("ChangExt1.error", NULL, NULL);
	Py_INCREF(changError);
	PyModule_AddObject(module, "error", changError);
}