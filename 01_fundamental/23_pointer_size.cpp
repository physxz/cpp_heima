/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 17:22:57
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 17:29:50
 * @FilePath: /23_pointer_size.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p = &a;
    // 在64位操作系统下，指针占8字节，16个十六进制数，不管什么类型
    cout << "sizeof(int *) = " << sizeof(int *) << endl;
    cout << "sizeof(long *) = " << sizeof(long *) << endl;
    cout << "sizeof(float *) = " << sizeof(float *) << endl;
    cout << "sizeof(double *) = " << sizeof(double *) << endl;
    return 0;
}