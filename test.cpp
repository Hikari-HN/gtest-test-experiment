/*
 * @Author: Hikari_HN lizihao_@nudt.edu.cn
 * @Date: 2022-08-03 17:01:53
 * @LastEditors: Hikari_HN lizihao_@nudt.edu.cn
 * @LastEditTime: 2022-08-03 21:07:24
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
    EXPECT_EQ(s1.indexOf(s2).ok(), 1);
    EXPECT_EQ(s3.indexOf(s1).isErr(), 1);
    EXPECT_EQ(s1.lastIndexOf(s2).ok(), 1);
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

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
