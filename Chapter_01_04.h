/* 执行时弹出警告"该文件包含不能在当前代码页...请将该文件..."属于正常情况,因为文档内中文注释过多 */
/* 修复警告则点击右下角的编码,选择"通过编码重新打开",选择"Unicode(UTF-8带签名)-代码页65001" */
/* 此处推荐一个子体Maple Mono Normal NL NF CN,真的很好看 */

// 对于"/**/"注释,仅做拓展说明或占位行,无需深入研究
// 以下内容基于Windows平台实现,运行软件为Visual Studio 2026,环境为32位(在上方修改为x86)

#pragma once
// 防止头文件被重复包含

#include <iostream> 
// "iostream"名为头文件
// 可放入其他头文件,如"cmath"等
#include <cmath>
// 使用cmath头文件才可以使用数学函数(sqrt等)
#include <climits>
// 使用climits头文件才可以使用整型相关函数(SHRT_MAX,LONG_MIN等)
#include <cstring>
// 使用cstring头文件才可以使用char数组相关函数(strlen等)
#include <string>
// 使用string头文件才可以使用string类相关函数
#include <vector>
#include <array>
// 使用vector,array头文件才可以使用vector,array类相关函数

void Cpp_start();
void Simon(int);
int Square(int);
void Bas01_type_cout();
void Bas02_climits();
void Bas03_Hex_dec_oct();
void Bas04_char();
void Bas05_escape();
void Bas06_float_double();
void Bas07_calculate();
void Bas08_type_trans();
void Bas09_array();
void Bas10_string();
void Bas11_cin_enter();
void Bas12_type_string();
void Bas13_structure();
void Bas14_enumeration();
void Bas15_pointer();
void Bas16_poniter_arithmetic();
void Bas17_type_combination();
void Bas18_vector_array();
void Test_code();
// 函数声明,与变量声明类似,在主函数所在文件中需要写在main函数之前