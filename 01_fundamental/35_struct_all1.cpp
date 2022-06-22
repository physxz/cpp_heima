/*
 * @Author: 赵小鑫
 * @Date: 2022-05-07 11:39:20
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-07 13:44:54
 * @FilePath: /35_struct_all1.cpp
 * @Description: 毕业设计结构体，3名老师，每人带5名学生
 */

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Student {
    string sName;
    int score;
};

struct Teacher {
    string tName;
    Student sArray[5];
};

// 参数1 老师数组 参数2 老师数组长度 参数3 学生数组长度
void allocateSpace(Teacher *tArray, int tLen, int sLen) {
    string nameSed = "ABCDE";
    for (int i = 0; i < tLen; i++) {
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameSed[i];
        for (int j = 0; j < sLen; j++) {
            tArray[i].sArray[j].sName = "Student_";
            tArray[i].sArray[j].sName += nameSed[i];
            int random = rand() % 61 + 40;  // (0-59 + 1) + 40
            tArray[i].sArray[j].score = random;
        }
    }
}

void printInfo(Teacher *tArray, int tLen, int sLen) {
    for (int i = 0; i < tLen; i++) {
        cout << "老师姓名：" << tArray[i].tName << endl;
        for (int j = 0; j < sLen; j++) {
            cout << "所带学生姓名：" << tArray[i].sArray[j].sName
                 << " 分数：" << tArray[i].sArray[j].score << endl;
        }
    }
}

int main() {
    srand((unsigned int) time(NULL)); // 随机数种子
    Teacher tArray[3];
    int tLen = sizeof(tArray) / sizeof(tArray[0]);
    // sizeof返回的是字节长度 sizeof(tArray)是整个数组长度，
    // sizeof(tArray[0])是数组第一个元素(子数组)的长度，两者相除就是有几个元素(子数组)即有几名老师
    int sLen = sizeof(tArray[0])/sizeof(tArray[0].sArray[0]);
    // sizeof(tArray[0].sArray[0])是第一个(子)数组的第一个元素的长度
    // 两者相除就是第一个(子)数组含有几个元素，即有几个学生
    allocateSpace(tArray, tLen, sLen);
    printInfo(tArray, tLen, sLen);
    return 0;
}