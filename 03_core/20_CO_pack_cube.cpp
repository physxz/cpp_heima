/*
 * @Author: 赵小鑫
 * @Date: 2022-05-10 17:12:31
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-10 20:27:15
 * @FilePath: /20_CO_pack_case1.cpp
 * @Description: 
 */

#include <iostream>
using namespace std;

class Cube {

public:
    void setL(int l) { // 设置长
        m_L = l;
    }
    int getL() { // 获取长
        return m_L;
    }
    void setW(int w) {
        m_W = w;
    }
    int getW() {
        return m_W;
    }
    void setH(int h) {
        m_H = h;
    }
    int getH() {
        return m_H;
    }
    // 获取面积
    int calculateS() {
        return 2*m_L*m_W + 2*m_L*m_H + 2*m_W*m_H;
    }
    // 获取体积
    int calculateV() {
        return m_L*m_W*m_H;
    }
    //利用成员函数判断两个立方体是否相等
    bool isSameByClass(Cube &c) {
        if (m_L == c.getL() && m_W == c.getW() &&
            m_H == c.getW())
        return true;
    else
        return false;
    }

private:
    int m_L;
    int m_W;
    int m_H;
};

// 利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2) { // 传入引用数据，不产生拷贝
    if (c1.getL() == c2.getL() && 
        c1.getW() == c2.getW() &&
        c1.getH() == c2.getW())
        return true;
    else
        return false;
}

int main() {
    Cube c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);
    cout << "面积：" << c1.calculateS() << endl;
    cout << "体积：" << c1.calculateV() << endl;
    Cube c2;
    c2.setL(11);
    c2.setW(10);
    c2.setH(10);

    // 利用全局函数判断
    if (isSame(c1,c2))
        cout << "两个立方体相等" << endl;
    else
        cout << "两个立方体不相等" << endl;

    // 利用成员函数判断
    if (c1.isSameByClass(c2))
        cout << "两个立方体不相等" << endl; 
    else
        cout << "两个立方体不相等" << endl;   
    return 0;
}