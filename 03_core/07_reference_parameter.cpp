/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 02:10:14
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 02:23:40
 * @FilePath: /07_reference_parameter.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

// 1. 值传递
void mySwap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "swap01 a = " << a << endl;
    cout << "swap01 b = " << b << endl;
}

// 2. 地址传递
void mySwap02(int *a, int *b) { // 指针需要解引用
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "swap02 a = " << *a << endl;
    cout << "swap02 b = " << *b << endl;
}
// 3. 引用传递
void mySwap03(int &a, int &b) { // 引用
    int temp = a;
    a = b;
    b = temp;
    cout << "swap03 a = " << a << endl;
    cout << "swap03 b = " << b << endl;
}

int main() {
    int a = 10;
    int b = 20;
    // mySwap01(a,b);
    // mySwap02(&a,&b);
    mySwap03(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}