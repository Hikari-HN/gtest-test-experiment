/*
 * @Author: Hikari_HN lizihao_@nudt.edu.cn
 * @Date: 2022-08-03 17:01:53
 * @LastEditors: Hikari_HN lizihao_@nudt.edu.cn
 * @LastEditTime: 2022-08-03 17:20:36
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
    // SuperString s2 = SuperString::Const("abc");
    std::cout << s1.substring(1, 2).ok() << std::endl;
    std::cout << s1.substr(0, 2) << std::endl;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
