#include <iostream>
#include "point.h"
#include "circle.h"
using namespace std;

void isInCircle(Circle &c, Point &p) { // 引用方式传递
    int dd = ( p.getX() - c.getCenter().getX() ) * 
             ( p.getX() - c.getCenter().getX() ) + 
             ( p.getY() - c.getCenter().getY() ) *
             ( p.getY() - c.getCenter().getY() ) ; // 点到圆心距离的平方
    int rr = c.getR()*c.getR(); // 半径的平方
    if (rr < dd)
        cout << "点在圆外" << endl;
    else if (rr > dd)
        cout << "点在圆内" << endl;
    else
        cout << "点在圆上" << endl;
}

int main() {
    // 创建点
    Point p;
    p.setX(0);
    p.setY(10);
    // 创建圆心
    Point center;
    center.setX(0);
    center.setY(0);
    // 创建圆
    Circle c;
    c.setCenter(center);
    c.setR(10);
    // 调用函数判断关系
    isInCircle(c,p);
    return 0;
}