#pragma once
#include <iostream>
using namespace std;

// .h头文件只做声明，不做实现(类内声明类外实现)
class WorkerManager
{
public:
    WorkerManager(); // 构造函数
    
    void showMenu(); // 展示菜单

    void exitSystem(); // 退出系统

    ~WorkerManager(); // 析构函数
};
