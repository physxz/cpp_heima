/*
 * @Author: 赵小鑫
 * @Date: 2022-05-04 15:13:57
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-07 13:06:02
 * @FilePath: /02_type_size.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

int main() {
    // 整型
    cout << "short:\t" << sizeof(short) << " 字节" << endl;
    cout << "int:\t" << sizeof(int) << " 字节" << endl;
    cout << "long:\t" << sizeof(long) << " 字节" << endl;
    cout << "long long:\t" << sizeof(long long) << " 字节" << endl;
    // 浮点型
    cout << "float:\t" << sizeof(float) << " 字节" << endl;
    cout << "double:\t" << sizeof(double) << " 字节" << endl;
    // 字符型
    cout << "char:\t" << sizeof(char) << " 字节" << endl;
    // 布尔型
    cout << "bool:\t" << sizeof(bool) << " 字节" << endl;
    return 0;
}