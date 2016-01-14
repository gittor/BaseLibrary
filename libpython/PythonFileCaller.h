//
//  PythonFileCaller.h
//  PyTest
//
//  Created by zhangdw on 16-1-13.
//
//

#ifndef __PythonFileCaller__
#define __PythonFileCaller__

#include <string>

#include "Python.h"

namespace libpy {
    
    class PythonFileCaller
    {
    public:
        PythonFileCaller(const std::string& py_file);
        virtual ~PythonFileCaller();

        void addSearchPath(const std::string& path);

        PyObject* call(const std::string& func_name, PyObject* pArgument);
        std::string getErrorStr();
    protected:
        void initEnv();
        void uninitEnv();
        
    private:
        std::string m_module_name;
        bool m_env_inited;
    };

}


#endif /* defined(__PythonFileCaller__) */
