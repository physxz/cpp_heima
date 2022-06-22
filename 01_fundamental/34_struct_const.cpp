/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 23:43:20
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 23:53:37
 * @FilePath: /34_struct_const.cpp
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

void printStudent(const Student *s) {
    // s->age = 150; // 用const修饰，一旦有修改操作就会报错，可以防止误操作
    cout << "姓名：" << s->name << " 年龄：" << s->age
         << " 分数：" << s->score << endl;
}

int main() {
    Student s = {"张三",15,70};
    printStudent(&s);
    cout << "main中张三的年龄：" << s.age << endl;
    return 0;
}