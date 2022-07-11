#pragma once
#include <string>

// 身份抽象类
class Identity
{
public:
    virtual void operateMenu() = 0; // 子菜单功能，纯虚函数，子类必须重写纯虚函数
    
    string m_Name;
    string m_Passwd;
};