#pragma once
#include <iostream>
using namespace std;

// 点类
class Point {
public:
    // 设置横坐标
    void setX (int x);
    // 获取横坐标
    int getX();

    void setY(int y);
    
    int getY();

private:
    int m_X;
    int m_Y;
};