#include "py_include.h"
#include "py_util.h"
#include "rbtree.h"

//Nil ���� �ʱ�ȭ
void rbInit();
//�����Ʈ�� ���� ���̽� �Լ�
PyObject* changext_rbCreateTree(PyObject* self, PyObject* args);
//�����Ʈ�� ��� ���� ���̽� �Լ�
PyObject* changext_rbCreateNode(PyObject* self, PyObject* args);
//�����Ʈ�� ��� �߰�
PyObject* changext_rbAppendNode(PyObject* self, PyObject* args);
//�����Ʈ�� ��� ����
PyObject* changext_rbRemoveNode(PyObject* self, PyObject* args);
//�����Ʈ�� ��� �˻�
PyObject* changext_rbSearchNode(PyObject* self, PyObject* args);
//�����Ʈ�� Ʈ�� ����
PyObject* changext_rbDestroyTree(PyObject* self, PyObject* args);
//�����Ʈ�� ���
PyObject* changext_rbPrintTree(PyObject* self, PyObject* args);