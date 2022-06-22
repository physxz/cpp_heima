/*
 * @Author: 赵小鑫
 * @Date: 2022-05-10 06:37:36
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-10 06:47:41
 * @FilePath: /17_CO_pack_permission.cpp
 * @Description: 
 */

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string m_Name;
protected:
    string m_Car;
private:
    int m_Password;
public:
    void func() {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
};

int main() {
    Person p1; // 实例化一个具体对象
    p1.m_Name = "李四";
    // p1.m_Car = "奔驰"; // 错误，保护权限内容在类外访问不到
    // p1.m_Password = 096742; //错误，私有权限内容在类外访问不到
    p1.func();
    return 0;
}