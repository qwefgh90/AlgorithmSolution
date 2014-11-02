#include "py_algorithm.h"

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
