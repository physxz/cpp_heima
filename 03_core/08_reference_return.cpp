/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 02:24:19
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 02:37:25
 * @FilePath: /08_reference_return.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

// 1. 不要返回局部变量的引用
// int & test01() {    // 错误，无法编译
//     int a  = 10;
//     return a;
// }

// 2. 函数的调用可以作为左值
int & test02() {
    static int a = 10; // 将局部变量的生命周期拉长，
    // 静态变量存放在全局区，数据由系统在程序结束后释放
    return a;
}

int main() {
    // int &ref = test01();
    // cout << "ref = " << ref << endl;

    int &ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;
    test02() = 1000; // test02的返回值是a，所以此处等价于a = 1000;
    // 而ref2是a的引用，改变a这个原值，则ref2这个引用也会被改变
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;
    return 0;
}