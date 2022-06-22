#include "point.h"

// 设置横坐标
void Point::setX (int x) { // 声明作用域，表明是成员函数
    m_X = x;
}
// 获取横坐标
int Point::getX() {
    return m_X;
}
void Point::setY(int y) {
    m_Y = y;
}
int Point::getY() {
    return m_Y;
}