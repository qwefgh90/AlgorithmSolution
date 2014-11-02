#include "py_util.h"
#ifndef PY_UTIL
#define PY_UTIL
//���̽� Ȯ�� Capsule �Ҹ���
void changext_destructorEmpty(PyObject* self)
{
	const char* namePtr = PyCapsule_GetName(self);
	printf("capsule destructor: %s\n",namePtr);
}
//���̽� Ȯ�� Capsule �Ҹ���
void changext_destructorCapsuleName(PyObject* self)
{
	const char* namePtr = PyCapsule_GetName(self);
	printf("capsule destructor: %s\n",namePtr);
	if(NULL != namePtr) {
		delete namePtr;
	}
}
//���̽� Ȯ�� ���� ī���� ����
void changext_xdecref(void* self)
{
	if(NULL != self)
	{
		Py_XDECREF((PyObject*)self);
		printf("xdecref pyobject\n");
	}
}
#endif