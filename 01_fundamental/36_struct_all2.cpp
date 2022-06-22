/*
 * @Author: 赵小鑫
 * @Date: 2022-05-07 13:35:41
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-07 14:20:51
 * @FilePath: /36_struct_all2.cpp
 * @Description: 英雄结构体，5名英雄，冒泡排序
 */

#include <iostream>
#include <string>
using namespace std;

struct Hero {
    string name;
    int age;
    string sex;
};

void bubbleSort(Hero *heroArray, int len) {
    // 使用数组
    // for (int i = 0; i < len; i++) {
    //     for (int j = 0; j < len-i-1; j++) {
    //         if (heroArray[j].age > heroArray[j+1].age) {
    //             Hero temp = heroArray[j];
    //             heroArray[j] = heroArray[j+1];
    //             heroArray[j+1] = temp;
    //         }
    //     }
    // }
    // 使用指针
    for (int i = 0; i < len; i++) {
        for (auto p = heroArray; p < &heroArray[len]-i-1; p++) {
            if (p->age > (p+1)->age) {
                Hero temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
        }
    }
}

void printInfo(Hero *heroArray, int len) {
    for (auto p = heroArray; p < &heroArray[len]; p++) {
        cout << "姓名：" << p->name
             << " 年龄：" << p->age
             << " 性别：" << p->sex << endl;
    }
}

int main() {
    Hero heroArray[5] = {
        {"刘备",23,"男"},
        {"关羽",22,"男"},
        {"张飞",20,"男"},
        {"赵云",21,"男"},
        {"貂蝉",19,"女"}
    };
    int len = sizeof(heroArray) / sizeof(heroArray[0]);
    cout << "排序前：" << endl;
    printInfo(heroArray, len);
    bubbleSort(heroArray, len);
    cout << "排序后：" << endl;
    printInfo(heroArray, len);
    return 0;
}