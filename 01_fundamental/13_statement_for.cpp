/*
 * @Author: 赵小鑫
 * @Date: 2022-05-05 23:21:24
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-05 23:35:05
 * @FilePath: /13_statement_for.cpp
 * @Description: 乘法口诀表(列×行，列数<=行数)
 */
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++)
            cout << j << "*" << i << "=" << i*j << " ";
        cout << endl;
    }
    return 0;
}