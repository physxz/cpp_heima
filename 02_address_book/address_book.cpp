/*
 * @Author: 赵小鑫
 * @Date: 2022-05-07 14:48:32
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-07 23:21:13
 * @FilePath: /02_address_book/address_book.cpp
 * @Description: 
 */

#include <iostream>
#include <string>
using namespace std;
#define MAX 1000 // 通讯录能容纳的最大人数

// 联系人结构体
struct Person {
    string m_Name; // 姓名
    int m_Sex; // 性别: 1男 2女
    int m_Age; // 年龄
    string m_Phone; // 电话
    string m_Addr; // 地址
};

// 通讯录结构体
struct AddressBooks {
    Person personArray[MAX]; // 通讯录中保存的联系人数组
    int m_size; // 通讯录中人员个数
};

// 显示菜单
void showMenu() {
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}

// 1.添加联系人
void addPerson(AddressBooks *abs) {
    if (abs->m_size == MAX) {
        cout << "通讯录已满，无法添加！" << endl;
    } else {
        cout << "请输入姓名：" << endl;
        string name;
        cin >> name;
        abs->personArray[abs->m_size].m_Name = name;

        cout << "请输入性别：" << endl;
        cout << "1 --- 男：" << endl;
        cout << "2 --- 女：" << endl;
        int sex;
        while (cin >> sex) {
            if (sex == 1 || sex == 2) {
                abs->personArray[abs->m_size].m_Sex = sex;
                break;
            }
            else
                cout << "输入错误，请重新输入1-2" << endl;
        }

        cout << "请输入年龄：" << endl;
        int age;
        cin >> age;
        abs->personArray[abs->m_size].m_Age = age;

        cout << "请输入电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_size].m_Phone = phone;

        cout << "请输入住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_size].m_Addr = address;

        abs->m_size++; // 更新通讯录人数

        cout << "添加联系人成功" << endl;
        cin.get(); cin.get(); // 暂停输入，等待用户输入，换行符可能输入到第1次，所以需要2次
        system("clear"); // 清空屏幕，回到主函数再次显示菜单
    }
}

// 2.显示联系人
void showPerson(AddressBooks *abs) {
    if (abs->m_size == 0) 
        cout << "当前记录为空" << endl;
    else {
        for (int i = 0; i < abs->m_size; i++) {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t"
                 << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男":"女") << "\t"
                 << "年龄：" << abs->personArray[i].m_Age << "\t"
                 << "电话：" << abs->personArray[i].m_Phone << "\t"
                 << "住址：" << abs->personArray[i].m_Addr << endl;
        }
    }
    cin.get(); cin.get();
    system("clear");
}

// 检测联系人是否存在
int isExist(AddressBooks *abs, string name) {
    for (int i = 0; i < abs->m_size; i++) {
        if (name == abs->personArray[i].m_Name) // 确有此人
            return i; // 返回此人在结构体数组中的下标
    }
    return -1; // 查无此人
}

// 3.删除指定联系人
void deletePerson(AddressBooks *abs) {
    cout << "请输入要删除的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    // 要删除某人，将其后所有人都向前移一位；然后人员个数减1
    if (ret != -1) { // 确有此人
        for (int i = ret; i < abs->m_size; i++)
            abs->personArray[i] = abs->personArray[i+1]; /// 数据前移
        abs->m_size--; // 更新通讯录中的人员数
        cout << "删除联系人成功" << endl;
    }
    else
        cout << "查无此人" << endl;
}

// 4.查找联系人
void findPerson(AddressBooks *abs) {
    cout << "请输入您要查找的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1) { // 确有此人
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t"
             << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t"
             << "年龄：" << abs->personArray[ret].m_Age << "\t"
             << "电话：" << abs->personArray[ret].m_Phone << "\t"
             << "地址：" << abs->personArray[ret].m_Addr << "\t" << endl;
    } else // 查无此人
        cout << "查无此人" << endl;
}

// 5.修改联系人
void modifyPerson(AddressBooks *abs) {
    cout << "请输入您要修改的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1) { // 确有此人
        cout << "请输入姓名：" << endl;
        string name;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;
        while (cin >> sex) {
            if (sex == 1 || sex == 2) {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "输入错误，请重新输入1-2" << endl;
        }
        cout << "请输入年龄：" << endl;
        int age;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        cout << "请输入电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;
        
        cout << "请输入地址：" << endl;
        string address;
        cin >> address;
        abs->personArray->m_Addr = address;

        cout << "修改联系人成功" << endl;
        cin.get(); cin.get(); // 暂停输入，等待用户输入，换行符可能输入到第1次，所以需要2次
        system("clear"); // 清空屏幕，回到主函数再次显示菜单
    } else
        cout << "查无此人" << endl;
}

// 6.清空联系人
void cleanPerson(AddressBooks *abs) {
    cout << "确定要清空通讯录吗(yes/no)？" << endl;
    string answer;
    while (cin >> answer) {
        if (answer == "yes") {
            abs->m_size = 0; // 将当前记录联系人数重置为0,做逻辑清空操作
            cout << "通讯录已清空" << endl;
        } else if (answer == "no")
            break;
        else
            cout << "输入错误，请重新输入(yes/no)" << endl;
    }
    cin.get(); cin.get(); // 暂停输入，等待用户输入，换行符可能输入到第1次，所以需要2次
    system("clear"); // 清空屏幕，回到主函数再次显示菜单
}
int main() {
    // 创建通讯录结构体变量
    AddressBooks abs;
    abs.m_size = 0;
    // string name;

    int select = 0;
    while (true) {
        showMenu();
        cin >> select;
        switch (select) {
            case 1: addPerson(&abs); break;
            case 2: showPerson(&abs); break;
            case 3: {
                    // cout << "请输入您要删除的联系人：" << endl;
                    // string name;
                    // cin >> name;
                    // if (isExist(&abs, name) == -1)
                    //     cout << "查无此人" << endl;
                    // else
                    //     cout << "确有其人" << endl;
                    deletePerson(&abs);
                    break;
            }
            case 4: findPerson(&abs); break;
            case 5: modifyPerson(&abs); break;
            case 6: cleanPerson(&abs); break;
            case 0: cout << "欢迎下次使用" << endl; return 0; break;
            default: cout << "输入错误，请输入数字0-6" << endl; break;
        }
    }
}