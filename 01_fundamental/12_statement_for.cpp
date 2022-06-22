/*
 * @Author: 赵小鑫
 * @Date: 2022-05-05 23:07:47
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-05 23:18:41
 * @FilePath: /12_statement_for.cpp
 * @Description: 敲桌子
 */

#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 100; i++) {
        if (i%10 == 7 || i/10 == 7 || i%7 == 0)
            cout << i << " 敲桌子" << endl;
        else
            cout << i << endl;
    }
    return 0;
}