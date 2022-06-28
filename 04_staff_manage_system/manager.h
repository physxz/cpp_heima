#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

// 经理类
class Manager: public Worker
{
public:
    Manager(int id, string name, int dId); // 构造函数
    void showInfo();
    string getDeptName();
};