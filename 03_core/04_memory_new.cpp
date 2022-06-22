/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 01:23:01
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-08 01:33:25
 * @FilePath: /04_memory_new.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

// 1.new的基本语法
int * func() {
    int *p = new int(10); // new返回的是该数据类型的指针
    return p;
}

void test01() {
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    // 堆区的数据由程序员开辟管理和释放
    delete p; // 释放内存
    // cout << *p << endl; // 内存以被释放，再次访问非法，会报错或得到错误值
}

void test02(){
    int *arr = new int[10]; // 在堆区创建含有10个元素的数组
    for (int i = 0; i < 10; i++)
        arr[i] = i + 100;
    for (int i = 0; i < 10; i++)
        cout << arr[i] << endl;
    delete[] arr; // 释放数组，需要加[]
}

int main() {
    test01();
    test02();
    return 0;
}