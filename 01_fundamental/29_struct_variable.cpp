/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 22:27:07
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 22:47:00
 * @FilePath: /29_struct_variable.cpp
 * @Description: 
 * 
 */

#include <iostream>
#include <string>
using namespace std;

// 1. 创建学生数据类型，属性包括(姓名，年龄，分数)
struct Student {
        // 成员列表
        string name; // 姓名
        int age; // 年龄
        int score; // 分数
    } s3; // 顺便创建结构体变量

int main() {
    // 2. 通过学生类型创建具体学生
    // 2.1 struct Student s1;
    // 结构体变量创建时可以省略struct关键字，建议使用前2种
    struct Student s1;
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;
    cout << "姓名：" << s1.name << endl;
    cout << "年龄：" << s1.age << endl;
    cout << "分数：" << s1.score << endl;
    // 2.2 struct Student s2 = {...}
    struct Student s2 = {"李四", 19, 80};
    cout << "姓名：" << s2.name << endl;
    cout << "年龄：" << s2.age << endl;
    cout << "分数：" << s2.score << endl;
    // 2.3 在定义结构体时顺便创建结构体变量
    s3.name = "王五";
    s3.age = 20;
    s3.score = 60;
    cout << "姓名：" << s3.name << endl;
    cout << "年龄：" << s3.age << endl;
    cout << "分数：" << s3.score << endl;
    return 0;
}