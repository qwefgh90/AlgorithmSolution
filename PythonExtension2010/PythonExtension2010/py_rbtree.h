#include "py_include.h"
#include "py_util.h"
#include "rbtree.h"

//Nil 변수 초기화
void rbInit();
//레드블랙트리 생성 파이썬 함수
PyObject* changext_rbCreateTree(PyObject* self, PyObject* args);
//레드블랙트리 노드 생성 파이썬 함수
PyObject* changext_rbCreateNode(PyObject* self, PyObject* args);
//레드블랙트리 노드 추가
PyObject* changext_rbAppendNode(PyObject* self, PyObject* args);
//레드블랙트리 노드 삭제
PyObject* changext_rbRemoveNode(PyObject* self, PyObject* args);
//레드블랙트리 노드 검색
PyObject* changext_rbSearchNode(PyObject* self, PyObject* args);
//레드블랙트리 트리 삭제
PyObject* changext_rbDestroyTree(PyObject* self, PyObject* args);
//레드블랙트리 출력
PyObject* changext_rbPrintTree(PyObject* self, PyObject* args);