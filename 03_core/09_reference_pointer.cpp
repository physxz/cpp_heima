/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 02:45:47
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 02:51:26
 * @FilePath: /09_reference_pointer.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

// 发现是引用，编译器将其转换为 int * const ref = &a;
void func(int &ref) {
    ref = 100;
}

int main() {
    int a = 10;
    // 编译器将其自动转换为 int * const ref = &a;
    // 指针常量，指针的指向不能变，这就是引用不可更改的原因
    int &ref = a;
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;
    
    // 编译器内部发现ref是引用，自动将其转换为 *ref = 20;
    ref = 20;
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;

    func(a);
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;
    return 0;
}