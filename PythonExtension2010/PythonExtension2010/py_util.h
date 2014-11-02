#include "py_include.h"

//파이썬 확장 빈소멸자
void changext_destructorEmpty(PyObject* self);
//파이썬 확장 Capsule 소멸자
void changext_destructorCapsuleName(PyObject* self);
//파이썬 확장 참조 카운팅 감소
void changext_xdecref(void* self);