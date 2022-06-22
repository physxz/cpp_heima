/*
 * @Author: 赵小鑫
 * @Date: 2022-05-08 06:49:42
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-10 06:13:58
 * @FilePath: /15_CO_pack_meaning1.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;
const double PI = 3.14;

// 设计一个圆类，求圆的周长
// 圆周长 = 2*PI*半径

class Circle {
    // 访问权限
    public:  // 公共权限
    // 属性
    int m_r; // 半径
    // 行为
    double calculatePerimeter() { // 获取圆的周长，是一种行为，一般行为用函数，属性用变量
        return 2*PI*m_r;
    }
};

int main() {
    // 通过圆类创建具体的圆，就是创建一个具体的对象
    // 这一过程就叫做实例化
    Circle c1;
    // 给圆对象的属性进行赋值
    c1.m_r = 10;
    cout << "圆的周长为：" << c1.calculatePerimeter() << endl;
    return 0;
}