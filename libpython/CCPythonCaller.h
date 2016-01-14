//
//  CCPythonCaller.h
//  PyTest
//
//  Created by zhangdw on 16-1-13.
//
//

#ifndef __PyTest__CCPythonCaller__
#define __PyTest__CCPythonCaller__

#include "PythonFileCaller.h"

namespace libpy {

    void copy_py_stdlib_to_writeable(const std::string& src_zip, const std::string& dst_zip);

    class CCPythonCaller : public PythonFileCaller
    {
    public:
        CCPythonCaller(const std::string& py_file);
        virtual ~CCPythonCaller() override;

    private:
        void check_copy_python_stdlib();
        std::string get_writeable_stdlib_zip();

    private:
        static std::string m_py_stdlib_path;
    };
}

#endif /* defined(__PyTest__CCPythonCaller__) */
