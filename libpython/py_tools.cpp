//
//  py_tools.cpp
//  PyTest
//
//  Created by zhangdw on 16-1-13.
//
//

#include "py_tools.h"
#include "Python.h"

std::string libpy::getModuleName(const std::string &py_file)
{
    auto target = py_file.find(".py");
    if (target!=std::string::npos){
        return py_file.substr(0, target);
    }
    else{
        return py_file;
    }
}