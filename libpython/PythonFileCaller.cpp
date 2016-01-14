//
//  PythonFileCaller.cpp
//  PyTest
//
//  Created by zhangdw on 16-1-13.
//
//

#include "PythonFileCaller.h"
#include "py_tools.h"
#include "cex.h"

using namespace libpy;

PythonFileCaller::PythonFileCaller(const std::string& py_file)
{
    m_module_name = libpy::getModuleName(py_file);
    m_env_inited = false;
}

PythonFileCaller::~PythonFileCaller()
{
    uninitEnv();
}

void PythonFileCaller::addSearchPath(const std::string& path)
{
    const char* cmd = cex::cstr("sys.path.append(\"%s\")", path.c_str());
    PyRun_SimpleString( cmd );
}

PyObject* PythonFileCaller::call(const std::string &func_name, PyObject* pArgument)
{
    do
    {
        initEnv();

        PyObject* pModule = PyImport_ImportModule( m_module_name.c_str() );
        Break_If(!pModule);

        PyObject* pFunc = PyObject_GetAttrString(pModule, func_name.c_str());
        Break_If(!pFunc);

        PyObject* pRet = PyEval_CallObject(pFunc, pArgument);
        return pRet;

    } while (0);

    return nullptr;
}

std::string PythonFileCaller::getErrorStr()
{
    std::string ret;
    do
    {
        PyObject *exception, *v, *tb;

        PyErr_Fetch(&exception, &v, &tb);
        if (!exception)
            break;

        PyErr_NormalizeException(&exception, &v, &tb);
        if (!exception)
            break;

        PyObject* err_msg = v->ob_type->tp_str(v);

        const char* err = PyString_AsString(err_msg);
        if (!err)
            break;

        ret = err;

    } while (0);

    return ret;
}

void PythonFileCaller::initEnv()
{
    Return_If(m_env_inited);
    m_env_inited = true;

    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("reload(sys)");
    PyRun_SimpleString("sys.setdefaultencoding( \"utf-8\" )");
}

void PythonFileCaller::uninitEnv()
{
    Return_If(!m_env_inited);
    Py_Finalize();
}

