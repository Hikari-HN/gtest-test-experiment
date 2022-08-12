/*
 * @Author: Hikari_HN lizihao_@nudt.edu.cn
 * @Date: 2022-08-03 17:01:53
 * @LastEditors: Hikari_HN lizihao_@nudt.edu.cn
 * @LastEditTime: 2022-08-12 21:32:38
 * @FilePath: /gtest-test-experiment/test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Hikari_HN lizihao_@nudt.edu.cn, All Rights Reserved.
 */

#include <iostream>
#include "SuperString.cc"
#include <gtest/gtest.h>

TEST(Test, BasicCASE)
{
    SuperString s1 = SuperString();
    SuperString s2 = SuperString::Const("I am a string!");
    SuperString s3 = SuperString(s2);
    EXPECT_EQ(s1.isEmpty(), true);
    EXPECT_EQ(s2.isNotEmpty(), true);
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
    // s2.indexOf(s1);
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

bool SuperString::isSequenceEmpty() const
{
    return this->_sequence->isEmpty();
}

bool SuperString::isSequenceNotEmpty() const
{
    return this->_sequence->isNotEmpty();
}

bool SuperString::testrefRelease_case0() const
{
    return this->_sequence->refRelease() == 0;
}

bool SuperString::testfreeingCost_notnull() const
{
    SuperString s1 = SuperString::Const("aaa");
    SubstringSequence *ss1 = new SubstringSequence(s1._sequence, 1, 2);
    this->_sequence->addReferencer(ss1);
    this->_sequence->reconstructReferencers();
    return true;
}

bool SuperString::testbad_substringMatches() const
{
    SuperString s1 = SuperString::Const("aaa");
    return this->_sequence->_substringMatches(1, s1);
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

TEST(Test, constASCIIsequence_simple_CASE)
{
    SuperString s1 = SuperString::Const("aaa", SuperString::Encoding::ASCII);
    EXPECT_EQ(s1.length(), 3);
    EXPECT_EQ(s1.codeUnitAt(0).ok(), 'a');
    EXPECT_EQ(s1.codeUnitAt(5).isErr(), 1);
    EXPECT_EQ(s1.substring(1,2).ok(), SuperString::Const("a", SuperString::Encoding::ASCII));
    EXPECT_EQ(s1.substring(1,5).isErr(), 1);
    EXPECT_EQ(s1.substring(-1,2).isErr(), 1);
    
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
