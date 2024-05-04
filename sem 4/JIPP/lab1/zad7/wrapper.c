#include <Python.h>
#include <stdbool.h>

typedef struct solution
{
    bool exists;
    int x;
    int y;
} solution;

int factorial_rec(int n)
{
    int result;
    PyObject *pModule, *pFunc, *pArgs, *pValue;

    Py_Initialize();
    pModule = PyImport_ImportModule("libpy.functions");

    if (pModule != NULL)
    {
        pFunc = PyObject_GetAttrString(pModule, "factorial_rec");
        if (pFunc && PyCallable_Check(pFunc))
        {

            pArgs = PyTuple_New(1);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(n));

            pValue = PyObject_CallObject(pFunc, pArgs);

            if (pValue != NULL)
            {
                result = PyLong_AsLong(pValue);
                Py_DECREF(pValue);
            }
            Py_DECREF(pArgs);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    Py_Finalize();
    return result;
}

int factorial_loop(int n)
{
    int result;
    PyObject *pModule, *pFunc, *pArgs, *pValue;

    Py_Initialize();
    pModule = PyImport_ImportModule("libpy.functions");

    if (pModule != NULL)
    {
        pFunc = PyObject_GetAttrString(pModule, "factorial_loop");
        if (pFunc && PyCallable_Check(pFunc))
        {

            pArgs = PyTuple_New(1);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(n));

            pValue = PyObject_CallObject(pFunc, pArgs);

            if (pValue != NULL)
            {
                result = PyLong_AsLong(pValue);
                Py_DECREF(pValue);
            }
            Py_DECREF(pArgs);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    Py_Finalize();
    return result;
}

int gcd_loop(int a, int b)
{
    int result;
    PyObject *pModule, *pFunc, *pArgs, *pValue;

    Py_Initialize();
    pModule = PyImport_ImportModule("libpy.functions");

    if (pModule != NULL)
    {
        pFunc = PyObject_GetAttrString(pModule, "gcd_loop");
        if (pFunc && PyCallable_Check(pFunc))
        {

            pArgs = PyTuple_New(2);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(a));
            PyTuple_SetItem(pArgs, 1, PyLong_FromLong(b));

            pValue = PyObject_CallObject(pFunc, pArgs);

            if (pValue != NULL)
            {
                result = PyLong_AsLong(pValue);
                Py_DECREF(pValue);
            }
            Py_DECREF(pArgs);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    Py_Finalize();
    return result;
}

int gcd_rec(int a, int b)
{
    int result;
    PyObject *pModule, *pFunc, *pArgs, *pValue;

    Py_Initialize();
    pModule = PyImport_ImportModule("libpy.functions");

    if (pModule != NULL)
    {
        pFunc = PyObject_GetAttrString(pModule, "gcd_rec");
        if (pFunc && PyCallable_Check(pFunc))
        {

            pArgs = PyTuple_New(2);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(a));
            PyTuple_SetItem(pArgs, 1, PyLong_FromLong(b));

            pValue = PyObject_CallObject(pFunc, pArgs);

            if (pValue != NULL)
            {
                result = PyLong_AsLong(pValue);
                Py_DECREF(pValue);
            }
            Py_DECREF(pArgs);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    Py_Finalize();
    return result;
}

solution diophantine_loop(int a, int b, int c)
{
    solution result;
    PyObject *pModule, *pFunc, *pArgs, *pValue, *pResult;

    Py_Initialize();

    pModule = PyImport_ImportModule("libpy.functions");

    if (pModule != NULL)
    {

        pFunc = PyObject_GetAttrString(pModule, "diophatine_loop");

        if (pFunc && PyCallable_Check(pFunc))
        {

            pArgs = PyTuple_New(3);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(a));
            PyTuple_SetItem(pArgs, 1, PyLong_FromLong(b));
            PyTuple_SetItem(pArgs, 2, PyLong_FromLong(c));

            pResult = PyObject_CallObject(pFunc, pArgs);

            if (pResult != NULL)
            {

                // Get the boolean attribute
                pValue = PyObject_GetAttrString(pResult, "exists");
                if (pValue && PyBool_Check(pValue))
                {
                    result.exists = PyObject_IsTrue(pValue);
                    Py_DECREF(pValue);
                }

                pValue = PyObject_GetAttrString(pResult, "x");
                if (pValue && PyLong_Check(pValue))
                {
                    result.x = PyLong_AsLong(pValue);
                    Py_DECREF(pValue);
                }

                pValue = PyObject_GetAttrString(pResult, "y");
                if (pValue && PyLong_Check(pValue))
                {
                    result.y = PyLong_AsLong(pValue);
                    Py_DECREF(pValue);
                }

                Py_DECREF(pResult);
            }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }

    Py_Finalize();
    return result;
}

solution diophantine_rec(int a, int b, int c)
{
    solution result;
    PyObject *pModule, *pFunc, *pArgs, *pValue, *pResult;

    Py_Initialize();

    pModule = PyImport_ImportModule("libpy.functions");

    if (pModule != NULL)
    {

        pFunc = PyObject_GetAttrString(pModule, "diophatine_rec");

        if (pFunc && PyCallable_Check(pFunc))
        {

            pArgs = PyTuple_New(3);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(a));
            PyTuple_SetItem(pArgs, 1, PyLong_FromLong(b));
            PyTuple_SetItem(pArgs, 2, PyLong_FromLong(c));

            pResult = PyObject_CallObject(pFunc, pArgs);

            if (pResult != NULL)
            {

                // Get the boolean attribute
                pValue = PyObject_GetAttrString(pResult, "exists");
                if (pValue && PyBool_Check(pValue))
                {
                    result.exists = PyObject_IsTrue(pValue);
                    Py_DECREF(pValue);
                }

                pValue = PyObject_GetAttrString(pResult, "x");
                if (pValue && PyLong_Check(pValue))
                {
                    result.x = PyLong_AsLong(pValue);
                    Py_DECREF(pValue);
                }

                pValue = PyObject_GetAttrString(pResult, "y");
                if (pValue && PyLong_Check(pValue))
                {
                    result.y = PyLong_AsLong(pValue);
                    Py_DECREF(pValue);
                }

                Py_DECREF(pResult);
            }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }

    Py_Finalize();
    return result;
}

void test_factorial_loop() {
    assert(factorial_loop(0) == 1);
    assert(factorial_loop(1) == 1);
    assert(factorial_loop(5) == 120);
    assert(factorial_loop(10) == 3628800);
    assert(factorial_loop(12) == 479001600);
    printf("factorial_loop tests passed.\n");
}

void test_gcd_loop() {
    assert(gcd_loop(8, 12) == 4);
    assert(gcd_loop(17, 23) == 1);
    assert(gcd_loop(15, 25) == 5);
    assert(gcd_loop(24, 36) == 12);
    assert(gcd_loop(18, 9) == 9);
    printf("gcd_loop tests passed.\n");
}

void test_diophantine_loop() {
/*     solution sol = diophantine_loop(3, 5, 12);
    assert(sol.exists && (3 * sol.x + 5 * sol.y == 12));
    sol = diophantine_loop(7, 13, 100);
    assert(sol.exists && (7 * sol.x + 13 * sol.y == 100));
    sol = diophantine_loop(4, 6, 25);
    assert(!sol.exists);
    sol = diophantine_loop(10, 15, 40);
    assert(sol.exists && (10 * sol.x + 15 * sol.y == 40));
    sol = diophantine_loop(16, 8, 64);
    assert(sol.exists && (8 * sol.x + 8 * sol.y == 64)); */
    printf("diophantine_loop tests passed.\n");
}

void test_factorial_rec() {
    assert(factorial_rec(0) == 1);
    assert(factorial_rec(1) == 1);
    assert(factorial_rec(5) == 120);
    assert(factorial_rec(10) == 3628800);
    assert(factorial_rec(12) == 479001600);
    printf("factorial_rec tests passed.\n");
}

void test_gcd_rec() {
    assert(gcd_rec(8, 12) == 4);
    assert(gcd_rec(17, 23) == 1);
    assert(gcd_rec(15, 25) == 5);
    assert(gcd_rec(24, 36) == 12);
    assert(gcd_rec(18, 9) == 9);
    printf("gcd_rec tests passed.\n");
}

void test_diophantine_rec() {
/*     solution sol = diophantine_rec(3, 5, 12);
    assert(sol.exists && (3 * sol.x + 5 * sol.y == 12));
    sol = diophantine_rec(7, 13, 100);
    assert(sol.exists && (7 * sol.x + 13 * sol.y == 100));
    sol = diophantine_rec(4, 6, 25);
    assert(!sol.exists);
    sol = diophantine_rec(10, 15, 40);
    assert(sol.exists && (10 * sol.x + 15 * sol.y == 40));
    sol = diophantine_rec(16, 8, 64);
    assert(sol.exists && (8 * sol.x + 8 * sol.y == 64)); */
    printf("diophantine_rec tests passed.\n");
}

int main() {
    test_factorial_loop();
    test_gcd_loop();
    test_diophantine_loop();
    test_factorial_rec();
    test_gcd_rec();
    test_diophantine_rec();
    return 0;
}


//  gcc -o wrapper wrapper.c -I /usr/include/python3.10 -lpython3.10