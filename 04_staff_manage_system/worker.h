#pragma once
#include <iostream>
#include <string>
using namespace std;

// 职工抽象类(不需要实现，不需要写对应worker.cpp源文件，具体实现由子类完成)
class Worker
{
public:
    // 行为(方法)
    // 纯虚函数(空实现)
    virtual void showInfo() = 0; // 显示个人信息
    virtual string getDeptName() = 0; // 获取岗位名称

    // 属性
    int m_Id; // 职工编号
    string m_name; // 职工姓名
    int m_DeptId; // 部门编号
};