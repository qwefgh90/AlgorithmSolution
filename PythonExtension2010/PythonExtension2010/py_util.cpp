#include "py_util.h"
#ifndef PY_UTIL
#define PY_UTIL
//파이썬 확장 Capsule 소멸자
void changext_destructorEmpty(PyObject* self)
{
	const char* namePtr = PyCapsule_GetName(self);
	printf("capsule destructor: %s\n",namePtr);
}
//파이썬 확장 Capsule 소멸자
void changext_destructorCapsuleName(PyObject* self)
{
	const char* namePtr = PyCapsule_GetName(self);
	printf("capsule destructor: %s\n",namePtr);
	if(NULL != namePtr) {
		delete namePtr;
	}
}
//파이썬 확장 참조 카운팅 감소
void changext_xdecref(void* self)
{
	if(NULL != self)
	{
		Py_XDECREF((PyObject*)self);
		printf("xdecref pyobject\n");
	}
}
#endif