#pragma once

#include <iostream>
#include <string>
#include <map>
#include "globalFile.h"
using namespace std;

class OrderFile
{
public:
    OrderFile(); // 构造函数

    void updateOrder(); // 更新预约记录

    int m_Size; // 记录预约条数

    // 外map的key是预约记录条数，value是第一条记录中的键值对
    // 内map的key是date等信息，value是1等信息
    map< int, map<string, string> > m_orderFile; // 记录所有预约信息的容器
};