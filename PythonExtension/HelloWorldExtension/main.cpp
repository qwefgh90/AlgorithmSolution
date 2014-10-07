#include "include.h"
static PyObject* ChangError;

PyObject*
ChangExt1_hello(PyObject* self, PyObject* args){
	int a = 0;
	int b = 0;
	int c = 0;
	int result = 0;

	if (!PyArg_ParseTuple(args, "iii", &a, &b, &c)){
		return NULL;
	}
	if (a == 0 || b == 0 || c == 0){
		PyErr_SetString(ChangError, "Input Value Zero Excetpion");
		return NULL;
	}
	result = a + b + c;
	PyObject* returnVal = Py_BuildValue("i", result);
	return returnVal;
}

//피보나치 수열 출력
PyObject *
ChangExt1_fibo(PyObject* self, PyObject* args){
	int size = 0;
	int sum = 0;
	if (PyArg_ParseTuple(args, "i", &size)==NULL){
		PyErr_SetString(ChangError, "Parse Arguments Error Exception");
		return NULL;
	}
	if (size < 1){
		PyErr_SetString(ChangError, "Parse Arguments Error Exception");
		return NULL;
	}

	int* fibo_array = (int*)malloc(size*sizeof(int));
	sum = CAlgorithm::fibo(fibo_array, size);

	PyObject* result_tuple = PyTuple_New(size);

	if (result_tuple == NULL){
		if (fibo_array != NULL)
			free(fibo_array);
		PyErr_SetString(ChangError, "Parse Arguments Error Exception");
		return NULL;
	}

	for (int i = 0; i < size; i++){
		if (0 != PyTuple_SetItem(result_tuple, i, PyInt_FromLong(fibo_array[i]))){
			if (fibo_array != NULL)
				free(fibo_array);
			PyErr_SetString(ChangError, "Parse Arguments Error Exception");
			return NULL;
		}
	}

	if (fibo_array != NULL)
		free(fibo_array);
	return Py_BuildValue("{s:I,s:O}", "sum",sum,"array",result_tuple);
}

static PyMethodDef ChangExt1_MTable[] = {
	{ "hello", ChangExt1_hello, METH_VARARGS, "hello world by changwon" },
	{ "fibo", ChangExt1_fibo, METH_VARARGS, "fibonachi by changwon" },
	{ NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC initChangExt1(void){
	PyObject* module = Py_InitModule("ChangExt1", ChangExt1_MTable);
	if (module == NULL)
		return;

	ChangError = PyErr_NewException("ChangExt1.error", NULL, NULL);
	Py_INCREF(ChangError);
	PyModule_AddObject(module, "error", ChangError);
}