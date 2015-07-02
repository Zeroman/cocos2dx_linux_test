/// @file _debug.h
/// @brief 
/// @author Zeroman Yang <51feel@gmail.com>
/// 0.01
/// @date 2015-07-02


#pragma once

#include <iostream>
#include <sstream>

#define _d(VAL) cout_value(#VAL, VAL)
template <typename T1> void cout_value(std::string str, const T1 &value)
{
    std::cout << str << " = " << value << std::endl;
}

//其他类型转字符串
template <typename T1> bool tostring(const T1 &value, std::string &str, int precision = 8)
{
    std::ostringstream buffer;
    buffer.setf(std::ios::fixed);
    buffer.precision(precision);
    buffer << value;
    str = buffer.str();
    return !buffer.fail();
}
