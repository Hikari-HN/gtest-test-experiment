/*
 * @Author: Hikari_HN lizihao_@nudt.edu.cn
 * @Date: 2022-08-14 15:33:43
 * @LastEditors: Hikari_HN lizihao_@nudt.edu.cn
 * @LastEditTime: 2022-08-14 16:29:34
 * @FilePath: /gtest-test-experiment/afl/afl_test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Hikari_HN lizihao_@nudt.edu.cn, All Rights Reserved.
 */
#include <iostream>
#include <fstream>
#include "../SuperString.cc"
#include "../test_helper.cpp"
using namespace std;
int main(int argc, char* argv[])
{
    ifstream fin(argv[1]);
    if (fin.good())
    {
        char line[120];
        while (fin.getline(line,100))
        {
            SuperString s = SuperString::Const(line);
            cout << s.length() << endl;
        }
    }
    else
    {
        cout << "file not found" << endl;
    }
    return 0;
}