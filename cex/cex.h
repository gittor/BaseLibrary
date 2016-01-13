#pragma once

#include "common.h"
#include "DynamicCreation.h"
#include "Observer.h"
#include "OnFinally.h"
#include "Singleton.h"

//using namespace cex;

#include <cstdarg>
#include <cassert>

#ifndef byte
typedef unsigned char byte;
#endif

#ifndef uchar
typedef unsigned char uchar;
#endif

#ifndef uint
typedef unsigned int uint;
#endif

#ifndef ushort
typedef unsigned short ushort;
#endif

#ifndef ulong
typedef unsigned long ulong;
#endif

namespace cex
{	
	template<int buffsize>
	std::string to_str(const char* format, ...)
	{
		char temp[buffsize] = {0};
		va_list list;
		long ret;

		va_start (list, format);
		ret = vsnprintf(temp, buffsize, format, list);
		assert(ret<buffsize);
		va_end (list);
		
		return temp;
	}

	template<int buffsize>
	const char* to_cstr(const char* format, ...)
	{
		static char static_buff[buffsize] = {0};
		va_list list;
		long ret;

		va_start (list, format);
		ret = vsnprintf(static_buff, buffsize, format, list);
		assert(ret<buffsize);
		va_end (list);

		return static_buff;
	}

	#define cstr to_cstr<512>
	#define sstr to_str<512>
}