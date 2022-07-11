#pragma once
#include <string>
#include <vector>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

class Admin: public Identity
{
public:
    Admin();

    Admin(string name, string passwd);

    virtual void operateMenu(); // 父类是纯虚函数不能实例化对象，所以子菜单需要到main.cpp中创建全局函数

    void addAccount();

    void showAccount();

    void showRoom();

    void clearOrder();

    void initVector(); // 初始化容器

    bool checkRepeat(int id, int type); // 检测重复，参数1为学号或职工号，参数2为检测类型

    vector<Student> vStu;
    vector<Teacher> vTeach;

    vector<ComputerRoom> vCom;
};