/* 执行时弹出警告"该文件包含不能在当前代码页...请将该文件..."属于正常情况,因为文档内中文注释过多 */
/* 修复警告则点击右下角的编码,选择"通过编码重新打开",选择"Unicode(UTF-8带签名)-代码页65001" */
/* 此处推荐一个子体Maple Mono Normal NL NF CN,真的很好看 */

// 以下内容基于Windows平台实现,运行软件为Visual Studio 2026,环境为32位(在上方修改为x86)
// 对于"/**/"注释,仅做拓展说明或占位行,无需深入研究

#pragma once


#include <iostream>
#include <ctime>
#include <string>

void Adv01_for();
void Adv02_Operators_Comparisons();
void Adv03_while();
void Adv04_delay_typedef();
void Adv05_dowhile_rangefor();
void Adv06_LoopsTest_Input();

void testcode();
