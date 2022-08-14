/*
 * @Author: Hikari_HN lizihao_@nudt.edu.cn
 * @Date: 2022-08-14 15:33:43
 * @LastEditors: Hikari_HN lizihao_@nudt.edu.cn
 * @LastEditTime: 2022-08-14 23:03:25
 * @FilePath: /gtest-test-experiment/afl/afl_test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Hikari_HN lizihao_@nudt.edu.cn, All Rights Reserved.
 */
#include <iostream>
#include <fstream>
#include "../SuperString.cc"
#include "../test_helper.cpp"
#include <gtest/gtest.h>
#include <cstring>
using namespace std;
int main(int argc, char *argv[])
{
    ifstream fin(argv[1]);
    if (!fin.good())
        return 0;
    char line[120];
    if (!fin.getline(line, 100))
        return 0;
    int time = strlen(line) % 20;
    if (time == 0)
    {
        SuperString s1 = SuperString();
        if (!fin.getline(line, 100))
            return 0;
        SuperString s2 = SuperString::Const(line);
        SuperString s3 = SuperString(s2);
        s1.isEmpty();
        s2.isEmpty();
        s2.isNotEmpty();
        s2.keepingCost();
        std::cout << s2 << std::endl;
    }
    else if (time == 1)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s2 = SuperString::Const(line);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s3 = SuperString::Const(line);
        SuperString s4 = SuperString(s1);
        s1.compareTo(s2);
        s2.compareTo(s1);
        s1.compareTo(s3);
        s3.compareTo(s1);
        s4.compareTo(s1);
    }
    else if (time == 2)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s2 = SuperString::Const(line);
        SuperString s3 = SuperString();
        if (!fin.getline(line, 100))
            return 0;
        SuperString s4 = SuperString::Const(line);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s5 = SuperString::Const(line);
        s1.indexOf(s2).ok();
        s1.indexOf(s4).isErr();
        s1.indexOf(s5).ok();
        s3.indexOf(s1).isErr();
        s1.lastIndexOf(s2).ok();
        s1.lastIndexOf(s4).isErr();
        s3.lastIndexOf(s1).isErr();
        s3.codeUnitAt(1).isErr();
    }
    else if (time == 3)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line);
        SuperString s2 = SuperString();
        s1.substring(1, 2).ok();
        s2.substring(1, 2).isErr();
        s1.substr(0, 2);
        EXPECT_ANY_THROW(s2.substr(0, 2));
        s1.substr(0);
        EXPECT_ANY_THROW(s2.substr(0));
    }
    else if (time == 4)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line);
        SuperString s2 = SuperString();
        s1.print(std::cout);
        s1.print(std::cout, 1, 2);
        s2.print(std::cout);
        s2.print(std::cout, 1, 2);
    }
    else if (time == 5)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s2 = SuperString::Const(line);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s3 = SuperString::Const(line);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s4 = SuperString::Const(line);
        SuperString s5 = SuperString();
        s1.trim();
        s2.trim();
        s3.trim();
        s4.trim();
        s1.trimLeft();
        s2.trimLeft();
        s3.trimLeft();
        s4.trimLeft();
        s1.trimRight();
        s2.trimRight();
        s3.trimRight();
        s4.trimRight();
        s5.trim();
        s5.trimLeft();
        s5.trimRight();
    }
    else if (time == 6)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s2 = SuperString::Const(line);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s3 = SuperString::Const(line);
        s1 + s2;
        s1 * 2;
        s1 = s1;
        s1 = s3;
        s1 == s1;
    }
    else if (time == 7)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line, SuperString::Encoding::ASCII);
        SuperString s2 = SuperString::Const(line, SuperString::Encoding::UTF16BE);
        SuperString s3 = SuperString::Const(line, SuperString::Encoding::UTF32);
        int a[3] = {1, 2, 3};
        SuperString::Byte b[3] = "12";
        if (!fin.getline(line, 100))
            return 0;
        SuperString s4 = SuperString::Const(a);
        SuperString s5 = SuperString::Const(b);
        SuperString s6 = SuperString::Copy(line);
        SuperString s7 = SuperString::Copy(line, SuperString::Encoding::ASCII);
        SuperString s8 = SuperString::Copy(line, SuperString::Encoding::UTF16BE);
        SuperString s9 = SuperString::Copy(line, SuperString::Encoding::UTF32);
        SuperString s10 = SuperString::Copy(a);
        SuperString s11 = SuperString::Copy(b);
    }
    else if (time == 8)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s2 = SuperString::Const(line);
        s1.isSequenceEmpty();
        s1.isSequenceNotEmpty();
        s2.testrefRelease_case0();
        s1.testfreeingCost_notnull();
        s1.testbad_substringMatches();
    }
    else if (time == 9)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line, SuperString::Encoding::ASCII);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s2 = SuperString::Const(line, SuperString::Encoding::ASCII);
        s1.length();
        s1.codeUnitAt(0).ok();
        s1.codeUnitAt(5).isErr();
        s1.substring(1, 2).ok();
        s1.substring(1, 5).isErr();
        s1.substring(-1, 2).isErr();
        s1.print(std::cout);
        s1.print(std::cout, 1, 2);
        s1.print(std::cout, 1, 5);
        s1.print(std::cout, -1, 2);
        s2.length();
        s2.trim();
        s2.trimLeft();
        s2.trimRight();
    }
    else if (time == 10)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Copy(line, SuperString::Encoding::ASCII);
        s1.length();
        s1.codeUnitAt(0).ok();
        s1.codeUnitAt(5).isErr();
        s1.substring(1, 2).ok();
        s1.substring(1, 5).isErr();
        s1.substring(-1, 2).isErr();
        s1.print(std::cout);
        s1.print(std::cout, 1, 2);
        s1.print(std::cout, 1, 5);
        s1.print(std::cout, -1, 2);
        s1.trim();
        s1.trimLeft();
        s1.trimRight();
        s1.testCopyASCIISequence();
    }
    else if (time == 11)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line, SuperString::Encoding::UTF8);
        SuperString::Byte b[10] = {0xFF, 0xF0, 0xE0, 0xC0, 0xFF};
        SuperString s2 = SuperString::Const(b, SuperString::Encoding::UTF8);
        s2.length();
        s2.codeUnitAt(0).isErr();
        s1.length();
        SuperString::Byte c[10] = {0xF0};
        SuperString s3 = SuperString::Const(c, SuperString::Encoding::UTF8);
        s3.length();
        s3.codeUnitAt(0).ok();
        SuperString::Byte d[10] = {0xE0};
        SuperString s4 = SuperString::Const(d, SuperString::Encoding::UTF8);
        s4.length();
        s4.codeUnitAt(0).ok();
        SuperString::Byte e[10] = {0xC0};
        SuperString s5 = SuperString::Const(e, SuperString::Encoding::UTF8);
        s5.length();
        s5.codeUnitAt(0).ok();
        s1.codeUnitAt(0).ok();
        s1.codeUnitAt(5).isErr();
        s1.substring(1, 2).ok();
        s1.substring(1, 5).isErr();
        s1.substring(-1, 2).isErr();
        s1.print(std::cout);
        s1.print(std::cout, 1, 2);
        s1.print(std::cout, 1, 5);
        s1.print(std::cout, -1, 2);
        s1.print(std::cout, 2, 1);
        s2.print(std::cout, 0, 0);
        s1.trim();
        s1.trimLeft();
        s1.trimRight();
    }
    else if (time == 12)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Copy(line, SuperString::Encoding::UTF8);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s2 = SuperString::Copy(line, SuperString::Encoding::UTF8);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s3 = SuperString::Copy(line, SuperString::Encoding::UTF8);
        if (!fin.getline(line, 100))
            return 0;
        SuperString s4 = SuperString::Copy(line, SuperString::Encoding::UTF8);
        SuperString::Byte b[10] = {0xFF, 0xF0, 0xE0, 0xC0, 0xFF};
        SuperString s5 = SuperString::Copy(b, SuperString::Encoding::UTF8);
        s1.length();
        s1.codeUnitAt(0).ok();
        s1.codeUnitAt(5).isErr();
        s1.substring(1, 2).ok();
        s1.substring(1, 5).isErr();
        s1.substring(-1, 2).isErr();
        s1.print(std::cout);
        s1.print(std::cout, 1, 2);
        s1.print(std::cout, 1, 5);
        s1.print(std::cout, -1, 2);
        s2.trim();
        s3.trimLeft();
        s4.trimRight();
        s1.testCopyUTF8Sequence();
    }
    else if (time == 13)
    {
        SuperString::Byte b[11];
        b[0] = b[2] = b[4] = b[6] = b[8] = 0x00;
        b[3] = b[5] = b[7] = 0x61;
        b[1] = b[9] = 0x20;
        SuperString s1 = SuperString::Const(b, SuperString::Encoding::UTF16BE);
        s1.length();
        s1.codeUnitAt(0).ok();
        s1.codeUnitAt(10).isErr();
        s1.substring(1, 2).isOk();
        s1.substring(1, 10).isErr();
        s1.substring(-1, 2).isErr();
        s1.print(std::cout);
        s1.print(std::cout, 1, 2);
        s1.print(std::cout, 1, 5);
        s1.print(std::cout, -1, 2);
        s1.trim().isEmpty();
        s1.trimLeft().isEmpty();
        s1.trimRight().isEmpty();
        s1.testUTF16BE_simple();
    }
    else if (time == 14)
    {
        SuperString::Byte b[11];
        b[0] = b[2] = b[4] = b[6] = b[8] = 0x00;
        b[3] = b[5] = b[7] = 0x61;
        b[1] = b[9] = 0x20;
        SuperString s1 = SuperString::Copy(b, SuperString::Encoding::UTF16BE);
        s1.length();
        s1.codeUnitAt(0).ok();
        s1.codeUnitAt(10).isErr();
        s1.substring(1, 2).isOk();
        s1.substring(1, 10).isErr();
        s1.substring(-1, 2).isErr();
        s1.print(std::cout);
        s1.print(std::cout, 1, 2);
        s1.print(std::cout, 1, 5);
        s1.print(std::cout, -1, 2);
        s1.trim().isEmpty();
        s1.trimLeft().isEmpty();
        s1.trimRight().isEmpty();
        s1.testCopyUTF16BESequence();
    }
    else if (time == 15)
    {
        SuperString::Byte b[16] = {};
        b[0] = 0x20;
        b[4] = 0x61;
        b[8] = 0x20;
        SuperString s1 = SuperString::Const(b, SuperString::Encoding::UTF32);
        s1.length();
        s1.codeUnitAt(0).ok();
        s1.codeUnitAt(10).isErr();
        s1.substring(1, 2).isOk();
        s1.substring(1, 10).isErr();
        s1.substring(-1, 2).isErr();
        s1.print(std::cout);
        s1.print(std::cout, 1, 2);
        s1.print(std::cout, 1, 5);
        s1.print(std::cout, -1, 2);
        s1.trim().isEmpty();
        s1.trimLeft().isEmpty();
        s1.trimRight().isEmpty();
        s1.testUTF32_simple();
    }
    else if (time == 16)
    {
        SuperString::Byte b[16] = {};
        b[0] = 0x20;
        b[4] = 0x61;
        b[8] = 0x20;
        SuperString s1 = SuperString::Copy(b, SuperString::Encoding::UTF32);
        s1.length();
        s1.codeUnitAt(0).ok();
        s1.codeUnitAt(10).isErr();
        s1.substring(1, 2).isOk();
        s1.substring(1, 10).isErr();
        s1.substring(-1, 2).isErr();
        s1.print(std::cout);
        s1.print(std::cout, 1, 2);
        s1.print(std::cout, 1, 5);
        s1.print(std::cout, -1, 2);
        s1.trim().isEmpty();
        s1.trimLeft().isEmpty();
        s1.trimRight().isEmpty();
        s1.testCopyUTF32Sequence();
    }
    else if (time == 17)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line);
        SuperString s2 = SuperString::Const(line);
        s1.testSubstringSequence_ref();
        s1.testSubstringSequence_substr();
        s2.testSubstringSequence_trim();
    }
    else if (time == 18)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line);
        s1.testConcatenationSequence_simple();
    }
    else if (time == 19)
    {
        if (!fin.getline(line, 100))
            return 0;
        SuperString s1 = SuperString::Const(line);
        s1.testMultipleSequence_simple();
    }
    return 0;
}