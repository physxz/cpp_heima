#pragma once
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define FILENAME "empFile.txt"
using namespace std;

// .h头文件只做声明，不做实现(类内声明类外实现)
class WorkerManager
{
public:
    // 成员函数
    WorkerManager(); // 构造函数
    
    void showMenu(); // 展示菜单

    void addEmp(); // 添加职工

    void save(); // 保存职工到文件

    void exitSystem(); // 退出系统

    ~WorkerManager(); // 析构函数

    // 成员属性
    int m_EmpNum; // 记录文件中的人数
    Worker ** m_EmpArray; // 员工数组的指针
    
    bool m_FileIsEmpty; // 判断文件是否为空
};
