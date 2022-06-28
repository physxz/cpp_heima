#pragma once
#include <iostream>
#include "worker.h"
using namespace std;
// 普通员工文件

class Employee: public Worker
{
public:
    Employee(int id, string name, int dId); // 构造函数
    // 只做声明(也要重写)(virtual关键字可删可不删)
    virtual void showInfo(); // 显示个人信息
    virtual string getDeptName(); // 获取岗位名称
};