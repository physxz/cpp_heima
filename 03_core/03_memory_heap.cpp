/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 00:55:16
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 01:19:17
 * @FilePath: /03_memory_heap.cpp
 * @Description: 
 */
#include <iostream>
using namespace std;

int * func() {
    // 利用new关键字，可以将数据开辟到堆区
    // 这里的指针是局部变量，存放在栈区；但它保存的数据存放在堆区
    int *p = new int(10);
    // 这里10是new出来的，存储在堆区，不会被释放
    // 10的地址被func里的指针传给了main里的指针
    // func里的指针在func函数执行结束后被释放，但是无影响
    // 因为10没有被释放，main里的指针在func执行后依然保存着10的地址
    return p;
}

int main() {
    // 在堆区开辟数据
    int *p = func();
    cout << *p << endl;
    return 0;
}