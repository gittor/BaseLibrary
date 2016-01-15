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

#define CHECK_ARCH_RETURN_ERROR(type, img_size, err) \
if (sizeof(type)!=img_size) { \
    if (error)  \
        *error = cex::cstr("%s=%d", #type, sizeof(type)); \
    return false; \
}

bool libpy::checkArchCompatible(std::string* error /*= nullptr*/)
{
    CHECK_ARCH_RETURN_ERROR(double, SIZEOF_DOUBLE, error);
    CHECK_ARCH_RETURN_ERROR(float, SIZEOF_FLOAT, error);
    CHECK_ARCH_RETURN_ERROR(fpos_t, SIZEOF_FPOS_T, error);
    CHECK_ARCH_RETURN_ERROR(int, SIZEOF_INT, error);
    CHECK_ARCH_RETURN_ERROR(long, SIZEOF_LONG, error);
    CHECK_ARCH_RETURN_ERROR(long double, SIZEOF_LONG_DOUBLE, error);
    CHECK_ARCH_RETURN_ERROR(long long, SIZEOF_LONG_LONG, error);
    CHECK_ARCH_RETURN_ERROR(off_t, SIZEOF_OFF_T, error);
    CHECK_ARCH_RETURN_ERROR(pid_t, SIZEOF_PID_T, error);
    CHECK_ARCH_RETURN_ERROR(pthread_t, SIZEOF_PTHREAD_T, error);
    CHECK_ARCH_RETURN_ERROR(short, SIZEOF_SHORT, error);
    CHECK_ARCH_RETURN_ERROR(size_t, SIZEOF_SIZE_T, error);
    CHECK_ARCH_RETURN_ERROR(time_t, SIZEOF_TIME_T, error);
    CHECK_ARCH_RETURN_ERROR(uintptr_t, SIZEOF_UINTPTR_T, error);
    CHECK_ARCH_RETURN_ERROR(void *, SIZEOF_VOID_P, error);
    CHECK_ARCH_RETURN_ERROR(wchar_t, SIZEOF_WCHAR_T, error);
    CHECK_ARCH_RETURN_ERROR(bool, SIZEOF__BOOL, error);
    return true;
}

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