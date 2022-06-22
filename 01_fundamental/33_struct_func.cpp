/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 23:29:18
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 23:40:00
 * @FilePath: /33_struct_func.cpp
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

// 值传递
void printStudent1(Student s) {
    s.age = 100;
    cout << "子函数1中 姓名：" << s.name
         << " 年龄：" << s.age
         << " 分数：" << s.score << endl;
}

// 地址传递
void printStudent2(Student *s) {
    s->age = 200;
    cout << "子函数2中 姓名：" << s->name
         << " 年龄：" << s->age
         << " 分数：" << s->score << endl;
}
int main() {
    Student s = {"张三", 20, 85};
    // printStudent1(s);
    printStudent2(&s);
    cout << "main函数中 姓名：" << s.name
         << " 年龄：" << s.age
         << " 分数：" << s.score << endl;
    return 0;
}