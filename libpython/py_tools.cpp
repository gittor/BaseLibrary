//
//  py_tools.cpp
//  PyTest
//
//  Created by zhangdw on 16-1-13.
//
//

#include "py_tools.h"
#include "Python.h"
#include "osdefs.h"
#include "cex.h"

using namespace std;

void libpy::addDefaultSearchPath(const std::string& path)
{
    const char* py_path = getenv("PYTHONPATH");
    if (!py_path)
    {
        setenv("PYTHONPATH", path.c_str(), 0);
    }
    else
    {
        string spath = py_path;
        vector<string> ps = cex::split(spath, DELIM);
        auto target = std::find(ps.begin(), ps.end(), path);
        if (target==ps.end())
        {
            spath += DELIM;
            spath += path;
            setenv("PYTHONPATH", spath.c_str(), 1);
        }
    }
}

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