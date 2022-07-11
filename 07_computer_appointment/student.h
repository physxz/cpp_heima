#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "identity.h"
#include "globalFile.h"
#include "computerRoom.h"
#include "orderFile.h"

// 学生类
class Student: public Identity
{
public:
    Student(); // 默认构造，当你提供了有参构造之后，编译器不在提供默认构造，所以需要手动写

    Student(int id, string name, string passwd); // 有参构造(学号、姓名、密码)

    virtual void operateMenu(); // 菜单界面，重新纯虚函数

    void applyOrder(); // 申请预约

    void showMyOrder(); // 查看我的预约

    void showAllOrder(); // 查看所有预约

    void cancleOrder(); // 取消预约

    int m_id;

    vector<ComputerRoom> vCom;
};