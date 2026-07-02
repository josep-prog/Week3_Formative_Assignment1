#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* fast_sum(PyObject *self, PyObject *args)
{
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O", &list))
        return NULL;

    long long sum = 0;

    Py_ssize_t size = PyList_Size(list);

    for (Py_ssize_t i = 0; i < size; i++)
    {
        PyObject *item = PyList_GetItem(list, i);
        sum += PyLong_AsLong(item);
    }

    return PyLong_FromLongLong(sum);
}

static PyMethodDef methods[] = {
    {"fast_sum", fast_sum, METH_VARARGS, "Fast sum"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "fastsum",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_fastsum(void)
{
    return PyModule_Create(&module);
}
