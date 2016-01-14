//
//  CCPythonCaller.cpp
//  PyTest
//
//  Created by zhangdw on 16-1-13.
//
//

#include "CCPythonCaller.h"
#include "py_tools.h"
#include "cocos2d.h"
#include "cex.h"

using namespace libpy;
USING_NS_CC;

void libpy::copy_py_stdlib_to_writeable(const std::string& src_zip, const std::string& dst_zip)
{
    Data data = FileUtils::getInstance()->getDataFromFile(src_zip);
    if (data.getSize()>0)
    {
        FILE* fp = fopen(dst_zip.c_str(), "wb");
        if (fp)
        {
            fwrite(data.getBytes(), data.getSize(), 1, fp);
            fclose(fp);
        }
    }
}

const char* libpy_zip = "libpy_lib.zip";
std::string CCPythonCaller::m_py_stdlib_path;

CCPythonCaller::CCPythonCaller(const std::string& py_file)
:PythonFileCaller(py_file)
{
    check_copy_python_stdlib();

    if (m_py_stdlib_path.empty()) {
        m_py_stdlib_path = FileUtils::getInstance()->fullPathForFilename(libpy_zip)+"/Lib";

        libpy::addDefaultSearchPath(m_py_stdlib_path);

        libpy::addDefaultSearchPath( FileUtils::getInstance()->getWritablePath() );
        libpy::addDefaultSearchPath( get_writeable_stdlib_zip() );
        libpy::addDefaultSearchPath( get_writeable_stdlib_zip()+"/Lib" );
    }
}

CCPythonCaller::~CCPythonCaller()
{

}

void CCPythonCaller::check_copy_python_stdlib()
{
    std::string fname = get_writeable_stdlib_zip();
    Return_If(FileUtils::getInstance()->isFileExist(fname));
    libpy::copy_py_stdlib_to_writeable(libpy_zip, fname);
}

std::string CCPythonCaller::get_writeable_stdlib_zip()
{
    return FileUtils::getInstance()->getWritablePath() + libpy_zip;
}

