/*
 * @Author: 赵小鑫
 * @Date: 2022-05-10 06:15:16
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-10 06:31:06
 * @FilePath: /16_CO_pack_meaning2.cpp
 * @Description: 
 */
#include <iostream>
#include <string>
using namespace std;

class Student {
    // 类中的属性和行为统称为成员
    // 属性也成为成员属性、成员变量
    // 行为也成为成员函数、成员方法
    public:
    string m_name;
    string ID;
    void showStudent() {
        cout << "学生的姓名：" << m_name << endl;
        cout << "学生的学好：" << ID << endl;
    }
    void setName(string name) {
        m_name = name;
    }
};

int main() {
    Student s1;
    // s1.m_name = "zhao";
    s1.setName("zhangsan");
    s1.ID = "19B911030";
    s1.showStudent();
    Student s2;
    s2.m_name = "yu";
    s2.ID = "911030";
    s2.showStudent();
    return 0;
}