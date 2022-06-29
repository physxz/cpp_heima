#pragma once
#include <iostream>
#include <string>
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

    int getEmpNum(); // 统计文件中的人数

    void initEmp(); // 初始化职工

    void showEmp(); // 显示职工

    void delEmp(); // 删除职工

    int isExist(int id); // 职工编号是否存在

    void modEmp(); // 修改职工

    void exitSystem(); // 退出系统

    ~WorkerManager(); // 析构函数

    // 成员属性
    int m_EmpNum; // 记录文件中的人数
    Worker ** m_EmpArray; // 员工数组的指针
    bool m_FileIsEmpty; // 判断文件是否为空
};
