/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 20:12:50
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 21:33:20
 * @FilePath: /27_pointer_func.cpp
 * @Description: 
 */
#include <iostream>
using namespace std;

void swap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "swap01 a = " << a << endl;
    cout << "swap01 b = " << b << endl;
}

void swap02(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "swap02 p1 = " << *p1 << endl;
    cout << "swap02 p2 = " << *p2 << endl;
}

int main() {
    int a = 10;
    int b = 20;
    // 1.值传递
    swap01(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // 2.地址(指针)传递
    // 如果是地址传递，可以修改实参
    swap02(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}