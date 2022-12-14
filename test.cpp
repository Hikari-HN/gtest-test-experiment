/*
 * @Author: Hikari_HN lizihao_@nudt.edu.cn
 * @Date: 2022-08-03 17:01:53
 * @LastEditors: Hikari_HN lizihao_@nudt.edu.cn
 * @LastEditTime: 2022-08-14 22:28:20
 * @FilePath: /gtest-test-experiment/test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Hikari_HN lizihao_@nudt.edu.cn, All Rights Reserved.
 */

#include <iostream>
#include "SuperString.cc"
#include "test_helper.cpp"
#include <gtest/gtest.h>

TEST(Test, BasicCASE)
{
    SuperString s1 = SuperString();
    SuperString s2 = SuperString::Const("I am a string!");
    SuperString s3 = SuperString(s2);
    EXPECT_EQ(s1.isEmpty(), true);
    EXPECT_EQ(s2.isNotEmpty(), true);
    std::cout << s2 << std::endl;
}

TEST(Test, compareToCASE)
{
    SuperString s1 = SuperString::Const("aa");
    SuperString s2 = SuperString::Const("aaa");
    SuperString s3 = SuperString::Const("ab");
    SuperString s4 = SuperString(s1);
    EXPECT_EQ(s1.compareTo(s2), -1);
    EXPECT_EQ(s2.compareTo(s1), 1);
    EXPECT_EQ(s1.compareTo(s3), -1);
    EXPECT_EQ(s3.compareTo(s1), 1);
    EXPECT_EQ(s4.compareTo(s1), 0);
}

TEST(Test, indexCASE)
{
    SuperString s1 = SuperString::Const("aabcccc");
    SuperString s2 = SuperString::Const("ab");
    SuperString s3 = SuperString();
    SuperString s4 = SuperString::Const("x");
    SuperString s5 = SuperString::Const("");
    EXPECT_EQ(s1.indexOf(s2).ok(), 1);
    EXPECT_EQ(s1.indexOf(s4).isErr(), 1);
    EXPECT_EQ(s1.indexOf(s5).ok(), 0);
    EXPECT_EQ(s3.indexOf(s1).isErr(), 1);
    EXPECT_EQ(s1.lastIndexOf(s2).ok(), 1);
    EXPECT_EQ(s1.lastIndexOf(s4).isErr(), 1);
    EXPECT_EQ(s3.lastIndexOf(s1).isErr(), 1);
    EXPECT_EQ(s3.codeUnitAt(1).isErr(), 1);
}

TEST(Test, substringCASE)
{
    SuperString s1 = SuperString::Const("abc");
    SuperString s2 = SuperString();
    EXPECT_EQ(s1.substring(1, 2).ok(), SuperString::Const("b"));
    EXPECT_EQ(s2.substring(1, 2).isErr(), 1);
    EXPECT_EQ(s1.substr(0, 2), SuperString::Const("ab"));
    EXPECT_ANY_THROW(s2.substr(0, 2));
    EXPECT_EQ(s1.substr(0), SuperString::Const("abc"));
    EXPECT_ANY_THROW(s2.substr(0));
}

TEST(Test, printCASE)
{
    SuperString s1 = SuperString::Const("abc");
    SuperString s2 = SuperString();
    s1.print(std::cout);
    s1.print(std::cout, 1, 2);
    s2.print(std::cout);
    s2.print(std::cout, 1, 2);
}

TEST(Test, trimCASE)
{
    SuperString s1 = SuperString::Const(" aaa");
    SuperString s2 = SuperString::Const("aaa ");
    SuperString s3 = SuperString::Const("aaa");
    SuperString s4 = SuperString::Const(" aaa ");
    SuperString s5 = SuperString();
    EXPECT_EQ(s1.trim(), s3);
    EXPECT_EQ(s2.trim(), s3);
    EXPECT_EQ(s3.trim(), s3);
    EXPECT_EQ(s4.trim(), s3);
    EXPECT_EQ(s1.trimLeft(), s3);
    EXPECT_EQ(s2.trimLeft(), s2);
    EXPECT_EQ(s3.trimLeft(), s3);
    EXPECT_EQ(s4.trimLeft(), s2);
    EXPECT_EQ(s1.trimRight(), s1);
    EXPECT_EQ(s2.trimRight(), s3);
    EXPECT_EQ(s3.trimRight(), s3);
    EXPECT_EQ(s4.trimRight(), s1);
    EXPECT_EQ(s5.trim(), s5);
    EXPECT_EQ(s5.trimLeft(), s5);
    EXPECT_EQ(s5.trimRight(), s5);
}

TEST(Test, operatorCASE)
{
    SuperString s1 = SuperString::Const("a");
    SuperString s2 = SuperString::Const("b");
    SuperString s3 = SuperString::Const("ab");
    SuperString s4 = SuperString::Const("aa");
    EXPECT_EQ(s1 + s2, s3);
    EXPECT_EQ(s1 * 2, s4);
    s1 = s1;
    s1 = s3;
}

TEST(Test, const_copyCASE)
{
    SuperString s1 = SuperString::Const("a", SuperString::Encoding::ASCII);
    SuperString s2 = SuperString::Const("a", SuperString::Encoding::UTF16BE);
    SuperString s3 = SuperString::Const("a", SuperString::Encoding::UTF32);
    int a[3] = {1, 2, 3};
    SuperString::Byte b[3] = "12";
    char c[3] = "34";
    SuperString s4 = SuperString::Const(a);
    SuperString s5 = SuperString::Const(b);
    SuperString s6 = SuperString::Copy(c);
    SuperString s7 = SuperString::Copy(c, SuperString::Encoding::ASCII);
    SuperString s8 = SuperString::Copy(c, SuperString::Encoding::UTF16BE);
    SuperString s9 = SuperString::Copy(c, SuperString::Encoding::UTF32);
    SuperString s10 = SuperString::Copy(a);
    SuperString s11 = SuperString::Copy(b);
}

TEST(Test, stringsequence_violent_CASE)
{
    SuperString s1 = SuperString::Const("aaa");
    SuperString s2 = SuperString::Const("");
    EXPECT_EQ(s1.isSequenceEmpty(), false);
    EXPECT_EQ(s1.isSequenceNotEmpty(), true);
    EXPECT_EQ(s2.testrefRelease_case0(), true);
    EXPECT_EQ(s1.testfreeingCost_notnull(), true);
    EXPECT_EQ(s1.testbad_substringMatches(), false);
}

TEST(Test, constASCIIsequence_CASE)
{
    SuperString s1 = SuperString::Const("aaa", SuperString::Encoding::ASCII);
    SuperString s2 = SuperString::Const(" aaa ", SuperString::Encoding::ASCII);
    EXPECT_EQ(s1.length(), 3);
    EXPECT_EQ(s1.codeUnitAt(0).ok(), 'a');
    EXPECT_EQ(s1.codeUnitAt(5).isErr(), 1);
    EXPECT_EQ(s1.substring(1, 2).ok(), SuperString::Const("a", SuperString::Encoding::ASCII));
    EXPECT_EQ(s1.substring(1, 5).isErr(), 1);
    EXPECT_EQ(s1.substring(-1, 2).isErr(), 1);
    s1.print(std::cout);
    s1.print(std::cout, 1, 2);
    s1.print(std::cout, 1, 5);
    s1.print(std::cout, -1, 2);
    EXPECT_EQ(s2.length(), 5);
    s2.trim();
    s2.trimLeft();
    s2.trimRight();
}

TEST(Test, copyASCIIsequence_CASE)
{
    SuperString s1 = SuperString::Copy("aaa", SuperString::Encoding::ASCII);
    EXPECT_EQ(s1.length(), 3);
    EXPECT_EQ(s1.codeUnitAt(0).ok(), 'a');
    EXPECT_EQ(s1.codeUnitAt(5).isErr(), 1);
    EXPECT_EQ(s1.substring(1, 2).ok(), SuperString::Const("a", SuperString::Encoding::ASCII));
    EXPECT_EQ(s1.substring(1, 5).isErr(), 1);
    EXPECT_EQ(s1.substring(-1, 2).isErr(), 1);
    s1.print(std::cout);
    s1.print(std::cout, 1, 2);
    s1.print(std::cout, 1, 5);
    s1.print(std::cout, -1, 2);
    EXPECT_EQ(s1.trim(), s1);
    EXPECT_EQ(s1.trimLeft(), s1);
    EXPECT_EQ(s1.trimRight(), s1);
    EXPECT_EQ(s1.testCopyASCIISequence(), true);
}

TEST(Test, constUTF8Sequence_CASE)
{
    SuperString s1 = SuperString::Const("aaa", SuperString::Encoding::UTF8);
    SuperString::Byte b[10] = {0xFF, 0xF0, 0xE0, 0xC0, 0xFF};
    SuperString s2 = SuperString::Const(b, SuperString::Encoding::UTF8);
    EXPECT_EQ(s2.length(), 0);
    EXPECT_EQ(s2.codeUnitAt(0).isErr(), 1);
    EXPECT_EQ(s1.length(), 3);
    SuperString::Byte c[10] = {0xF0};
    SuperString s3 = SuperString::Const(c, SuperString::Encoding::UTF8);
    EXPECT_EQ(s3.length(), 1);
    EXPECT_EQ(s3.codeUnitAt(0).ok(), 0);
    SuperString::Byte d[10] = {0xE0};
    SuperString s4 = SuperString::Const(d, SuperString::Encoding::UTF8);
    EXPECT_EQ(s4.length(), 1);
    EXPECT_EQ(s4.codeUnitAt(0).ok(), 0);
    SuperString::Byte e[10] = {0xC0};
    SuperString s5 = SuperString::Const(e, SuperString::Encoding::UTF8);
    EXPECT_EQ(s5.length(), 1);
    EXPECT_EQ(s5.codeUnitAt(0).ok(), 0);
    EXPECT_EQ(s1.codeUnitAt(0).ok(), 'a');
    EXPECT_EQ(s1.codeUnitAt(5).isErr(), 1);
    EXPECT_EQ(s1.substring(1, 2).ok(), SuperString::Const("a", SuperString::Encoding::UTF8));
    EXPECT_EQ(s1.substring(1, 5).isErr(), 1);
    EXPECT_EQ(s1.substring(-1, 2).isErr(), 1);
    s1.print(std::cout);
    s1.print(std::cout, 1, 2);
    s1.print(std::cout, 1, 5);
    s1.print(std::cout, -1, 2);
    s1.print(std::cout, 2, 1);
    s2.print(std::cout, 0, 0);
    EXPECT_EQ(s1.trim(), s1);
    EXPECT_EQ(s1.trimLeft(), s1);
    EXPECT_EQ(s1.trimRight(), s1);
}

TEST(Test, copyUTF8sequence_CASE)
{
    SuperString s1 = SuperString::Copy("aaa", SuperString::Encoding::UTF8);
    SuperString s2 = SuperString::Copy(" aaa ", SuperString::Encoding::UTF8);
    SuperString s3 = SuperString::Copy(" aaa", SuperString::Encoding::UTF8);
    SuperString s4 = SuperString::Copy("aaa ", SuperString::Encoding::UTF8);
    SuperString::Byte b[10] = {0xFF, 0xF0, 0xE0, 0xC0, 0xFF};
    SuperString s5 = SuperString::Copy(b, SuperString::Encoding::UTF8);
    EXPECT_EQ(s1.length(), 3);
    EXPECT_EQ(s1.codeUnitAt(0).ok(), 'a');
    EXPECT_EQ(s1.codeUnitAt(5).isErr(), 1);
    EXPECT_EQ(s1.substring(1, 2).ok(), SuperString::Const("a", SuperString::Encoding::UTF8));
    EXPECT_EQ(s1.substring(1, 5).isErr(), 1);
    EXPECT_EQ(s1.substring(-1, 2).isErr(), 1);
    s1.print(std::cout);
    s1.print(std::cout, 1, 2);
    s1.print(std::cout, 1, 5);
    s1.print(std::cout, -1, 2);
    EXPECT_EQ(s2.trim(), s1);
    EXPECT_EQ(s3.trimLeft(), s1);
    EXPECT_EQ(s4.trimRight(), s1);
    EXPECT_EQ(s1.testCopyUTF8Sequence(), true);
}

TEST(Test, constUTF16BESequence_CASE)
{
    SuperString::Byte b[11];
    b[0] = b[2] = b[4] = b[6] = b[8] = 0x00;
    b[3] = b[5] = b[7] = 0x61;
    b[1] = b[9] = 0x20;
    SuperString s1 = SuperString::Const(b, SuperString::Encoding::UTF16BE);
    EXPECT_EQ(s1.length(), 5);
    EXPECT_EQ(s1.codeUnitAt(0).ok(), 32);
    EXPECT_EQ(s1.codeUnitAt(10).isErr(), 1);
    EXPECT_EQ(s1.substring(1, 2).isOk(), 1);
    EXPECT_EQ(s1.substring(1, 10).isErr(), 1);
    EXPECT_EQ(s1.substring(-1, 2).isErr(), 1);
    s1.print(std::cout);
    s1.print(std::cout, 1, 2);
    s1.print(std::cout, 1, 5);
    s1.print(std::cout, -1, 2);
    EXPECT_EQ(s1.trim().isEmpty(), 0);
    EXPECT_EQ(s1.trimLeft().isEmpty(), 0);
    EXPECT_EQ(s1.trimRight().isEmpty(), 0);
    EXPECT_EQ(s1.testUTF16BE_simple(), true);
}

TEST(Test, copyUTF16BESequence_CASE)
{
    SuperString::Byte b[11];
    b[0] = b[2] = b[4] = b[6] = b[8] = 0x00;
    b[3] = b[5] = b[7] = 0x61;
    b[1] = b[9] = 0x20;
    SuperString s1 = SuperString::Copy(b, SuperString::Encoding::UTF16BE);
    EXPECT_EQ(s1.length(), 5);
    EXPECT_EQ(s1.codeUnitAt(0).ok(), 32);
    EXPECT_EQ(s1.codeUnitAt(10).isErr(), 1);
    EXPECT_EQ(s1.substring(1, 2).isOk(), 1);
    EXPECT_EQ(s1.substring(1, 10).isErr(), 1);
    EXPECT_EQ(s1.substring(-1, 2).isErr(), 1);
    s1.print(std::cout);
    s1.print(std::cout, 1, 2);
    s1.print(std::cout, 1, 5);
    s1.print(std::cout, -1, 2);
    EXPECT_EQ(s1.trim().isEmpty(), 0);
    EXPECT_EQ(s1.trimLeft().isEmpty(), 0);
    EXPECT_EQ(s1.trimRight().isEmpty(), 0);
    EXPECT_EQ(s1.testCopyUTF16BESequence(), true);
}

TEST(Test, constUTF32Sequence_CASE)
{
    SuperString::Byte b[16] = {};
    b[0] = 0x20;
    b[4] = 0x61;
    b[8] = 0x20;
    SuperString s1 = SuperString::Const(b, SuperString::Encoding::UTF32);
    EXPECT_EQ(s1.length(), 3);
    EXPECT_EQ(s1.codeUnitAt(0).ok(), 32);
    EXPECT_EQ(s1.codeUnitAt(10).isErr(), 1);
    EXPECT_EQ(s1.substring(1, 2).isOk(), 1);
    EXPECT_EQ(s1.substring(1, 10).isErr(), 1);
    EXPECT_EQ(s1.substring(-1, 2).isErr(), 1);
    s1.print(std::cout);
    s1.print(std::cout, 1, 2);
    s1.print(std::cout, 1, 5);
    s1.print(std::cout, -1, 2);
    EXPECT_EQ(s1.trim().isEmpty(), 0);
    EXPECT_EQ(s1.trimLeft().isEmpty(), 0);
    EXPECT_EQ(s1.trimRight().isEmpty(), 0);
    EXPECT_EQ(s1.testUTF32_simple(), true);
}

TEST(Test, copyUTF32Sequence_CASE)
{
    SuperString::Byte b[16] = {};
    b[0] = 0x20;
    b[4] = 0x61;
    b[8] = 0x20;
    SuperString s1 = SuperString::Copy(b, SuperString::Encoding::UTF32);
    EXPECT_EQ(s1.length(), 3);
    EXPECT_EQ(s1.codeUnitAt(0).ok(), 32);
    EXPECT_EQ(s1.codeUnitAt(10).isErr(), 1);
    EXPECT_EQ(s1.substring(1, 2).isOk(), 1);
    EXPECT_EQ(s1.substring(1, 10).isErr(), 1);
    EXPECT_EQ(s1.substring(-1, 2).isErr(), 1);
    s1.print(std::cout);
    s1.print(std::cout, 1, 2);
    s1.print(std::cout, 1, 5);
    s1.print(std::cout, -1, 2);
    EXPECT_EQ(s1.trim().isEmpty(), 0);
    EXPECT_EQ(s1.trimLeft().isEmpty(), 0);
    EXPECT_EQ(s1.trimRight().isEmpty(), 0);
    EXPECT_EQ(s1.testCopyUTF32Sequence(), true);
}

TEST(Test, substringSequence_violent_CASE)
{
    SuperString s1 = SuperString::Const("aaa");
    SuperString s2 = SuperString::Const(" aaa ");
    EXPECT_EQ(s1.testSubstringSequence_ref(), true);
    EXPECT_EQ(s1.testSubstringSequence_substr(), true);
    EXPECT_EQ(s2.testSubstringSequence_trim(), true);
}

TEST(Test, concatenationSequence_violent_CASE)
{
    SuperString s1 = SuperString::Const(" aaa ");
    EXPECT_EQ(s1.testConcatenationSequence_simple(), true);
}

TEST(Test, multipleSequence_violent_CASE)
{
    SuperString s1 = SuperString::Const(" aaa ");
    EXPECT_EQ(s1.testMultipleSequence_simple(), true);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}