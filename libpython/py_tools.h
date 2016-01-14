//
//  py_tools.h
//  PyTest
//
//  Created by zhangdw on 16-1-13.
//
//

#ifndef __PyTest__py_tools__
#define __PyTest__py_tools__

#include <string>

namespace libpy
{
    void addDefaultSearchPath(const std::string& path);
    std::string getModuleName(const std::string& py_file);
};

#endif /* defined(__PyTest__py_tools__) */
