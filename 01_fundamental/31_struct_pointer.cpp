/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 23:04:59
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 23:12:29
 * @FilePath: /31_struct_pointer.cpp
 * @Description: 
 */

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    int score;
};

int main() {
    // 1. 创建学生结构体变量
    Student s = {"张三",18,100};
    // 2. 通过指针指向结构体变量
    Student *p = &s;
    // 3. 通过指针访问结构体变量中的数据
    cout << "姓名：" << p->name << " "
         << "年龄：" << p->age << " "
         << "分数：" << p->score << endl;
    return 0;
}