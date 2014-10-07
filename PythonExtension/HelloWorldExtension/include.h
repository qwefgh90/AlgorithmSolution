#ifdef _DEBUG
#define _DEBUG_WAS_DEFINED 1
#undef _DEBUG
#endif

#include <Python.h>

#ifdef _DEBUG_WAS_DEFINED 1
#define _DEBUG 1
#endif

#include <memory.h>

#include "algorithm.h"