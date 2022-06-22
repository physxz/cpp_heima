/*
 * @Author: 赵小鑫
 * @Date: 2022-05-05 23:58:25
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 00:23:00
 * @FilePath: /14_statement_break.cpp
 * @Description: 
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1.出现在switch语句中
    cout << "请选择副本难度：" << endl;
    cout << "1.普通\n2.中等\n3.困难" << endl;
    int select = 0;
    cin >> select;
    switch (select) {
        case 1: cout << "选择的难度为普通" << endl; break;
        case 2: cout << "选择的难度为中等" << endl; break;
        case 3: cout << "选择的难度为困难" << endl; break;
        default: cout << "请输入1,2,3" << endl; break;
    }
    // 2.出现在循环语句中
    for (int i = 0; i < 10; i++) {
        if (i == 5)
            break;  // 等于5时直接退出，只打印0-4
        cout << i << endl;
    }
    // 3.出现在嵌套语句中
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 5) break;  // 每一行5个*
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}