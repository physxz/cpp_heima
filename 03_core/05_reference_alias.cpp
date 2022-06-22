/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 01:38:25
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 02:02:04
 * @FilePath: /05_reference_alias.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &b = a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}