/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 02:53:53
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 03:15:51
 * @FilePath: /10_reference_const.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

void showValue(const int &val) {
    // val = 1000; // const修饰，不可修改
    cout << "val = " << val << endl;
}

int main() {
    // int a = 10;
    // 引用必须引一块合法的内存空间
    // int &ref = 10; // 错误
    // 加上const之后，编译器起别名为temp: int temp = 10; const int & ref = temp;
    const int &ref = 10; // 等价于 const int * const ref = 10;
    // ref = 20; // const修饰之后变为只读，不可修改
    int a = 100;
    cout << "ref的地址：\t" << &ref << endl;
    cout << "a的地址：\t" << &a << endl;  // ref和a都是局部变量，都在栈区
    showValue(a);
    cout << "a = " << a << endl;
    return 0;
}