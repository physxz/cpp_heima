using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include "globalFile.h"
#include "teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int empId, string name, string passwd)
{
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Passwd = passwd;
}

void Teacher::operateMenu()
{
    cout << "欢迎教师 "<< this->m_Name << " 登录！" << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         1.查看所有预约      |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         2.审核预约          |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         0.注销登录          |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << "请输入您的选择：" << endl;
}

void Teacher::showAllOrder()
{
    Student stu;
    stu.showAllOrder();
    // OrderFile of;
    // if (of.m_Size == 0)
    // {
    //     cout << "无预约记录" << endl;

    //     cout << "按任意键继续" << endl;
    //     getchar();
    //     getchar();
    //     system("clear");

    //     return;
    // }

    // for (int i = 0; i < of.m_Size; i++)
    // {
    //     cout << i + 1 << ".";
    //     cout << "预约信息：周 " << of.m_orderFile[i]["date"] << " ";
    //     cout << ( of.m_orderFile[i]["interval"] == "1" ? "上午" : "下午" ) << "，";
    //     cout << "学号：" << of.m_orderFile[i]["stuId"] << "，";
    //     cout << "学号：" << of.m_orderFile[i]["stuName"] << "，";
    //     cout << of.m_orderFile[i]["roomId"] << "号房" << "，";

    //     string status = "状态：";
    //     // 1审核中 2已预约 -1预约失败 0取消预约
    //     if (of.m_orderFile[i]["status"] == "1")
    //     {
    //         status += "审核中";
    //     }
    //     else if (of.m_orderFile[i]["status"] == "2")
    //     {
    //         status += "预约成功";
    //     }
    //     else if (of.m_orderFile[i]["status"] == "-1")
    //     {
    //         status += "预约失败";
    //     }
    //     else
    //     {
    //         status += "取消预约";
    //     }
    //     cout << status << endl;
    // }

    // cout << "按任意键继续" << endl;
    // getchar();
    // getchar();
    // system("clear");
}

void Teacher::checkOrder()
{
    OrderFile of;
    if (of.m_Size == 0)
    {
        cout << "无预约记录" << endl;

        cout << "按任意键继续" << endl;
        getchar();
        getchar();
        system("clear");

        return;
    }

    cout << "待审核的预约记录如下：" << endl;

    vector<int> v;
    int index = 0;
    for (int i = 0; i < of.m_Size; i++)
    {
        if (of.m_orderFile[i]["status"] == "1") // 筛选状态
        {
            v.push_back(i);
            cout << ++index << ". ";
            cout << "预约信息：周 " << of.m_orderFile[i]["date"] << " ";
            cout << ( of.m_orderFile[i]["interval"] == "1" ? "上午" : "下午" ) << "，";
            cout << "学号：" << of.m_orderFile[i]["stuId"] << "，";
            cout << "学号：" << of.m_orderFile[i]["stuName"] << "，";
            cout << of.m_orderFile[i]["roomId"] << "号房" << "，";
            
            string status = "状态：审核中";
            cout << status << endl;
        }
    }

    cout << "请输入审核的预约记录，0代表返回" << endl;
    int select = 0; // 接收用户选择的预约记录
    int choice = 0; // 接收预约结果记录

    while (true)
    {
        cin >> select;

        if (select >= 0 && select <= v.size())
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                cout << "请输入审核结果" << endl;
                cout << "1.通过" << endl;
                cout << "2.不通过" << endl;

                cin >> choice;

                if (choice == 1) // 审核通过
                {
                    of.m_orderFile[ v[select-1] ]["status"] = "2";
                }
                else // 审核不通过
                {
                    of.m_orderFile[ v[select-1] ]["status"] = "-1";
                }

                of.updateOrder();

                cout << "审核完毕" << endl;
                break;
            }
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "按任意键继续" << endl;
    getchar();
    getchar();
    system("clear");
}