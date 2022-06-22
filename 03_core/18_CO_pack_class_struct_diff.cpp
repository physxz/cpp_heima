/*
 * @Author: 赵小鑫
 * @Date: 2022-05-10 06:48:26
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-10 16:30:11
 * @FilePath: /18_CO_pack_class_struct_diff.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

class C1 {
    int m_A; // 默认权限是私有
    void printC1() {
        cout << m_A << endl;
    }
};

struct C2 {
    int m_A; // 默认权限是公共
    void printC2() {
        cout << m_A << endl;
    }
};

int main() {
    // struct默认权限是公共
    // class默认权限是私有
    C1 c1; // 实例化对象
    // c1.m_A = 100; // 错误，class默认私有
    // c1.printC1();
    C2 c2;
    c2.m_A = 100; // 正确，struct默认公共
    c2.printC2();
    return 0;
}