/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 23:15:02
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 23:27:31
 * @FilePath: /32_struct_nest.cpp
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

struct Teacher {
    int id;
    string name;
    int age;
    Student stu; // 辅导的学生
};

int main() {
    // 创建老师
    Teacher t;
    t.id = 10000;
    t.name = "老王";
    t.age = 50;
    t.stu.name = "小王";
    t.stu.age = 20;
    t.stu.score = 60;
    cout << "老师姓名：" << t.name << " "
         << "老师编号：" << t.id << " "
         << "老师年龄：" << t.age << endl;
    cout << "老师辅导的学生姓名：" << t.stu.name << " "
         << "学生年龄：" << t.stu.age << " "
         << "学生分数：" << t.stu.score << endl;
    return 0;
}