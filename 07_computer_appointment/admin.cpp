using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "identity.h"
#include "admin.h"
#include "globalFile.h"

Admin::Admin()
{

}

Admin::Admin(string name, string passwd)
{
    // 初始化管理员信息
    this->m_Name = name;
    this->m_Passwd = passwd;

    // 初始化容器 获取所有文件中 学生、老师信息
    this->initVector();

    // 初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
    {
        vCom.push_back(com);
    }
    ifs.close();
    cout << "机房数量为：" << vCom.size() << endl;
}

void Admin::operateMenu()
{
    cout << "欢迎管理员 "<< this->m_Name << " 登录！" << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         1.添加账号          |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         2.查看账号          |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         3.查看机房          |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         4.清空预约          |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         0.注销登录          |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << "请输入您的选择：" << endl;
}

void Admin::addAccount()
{
    cout << "请输入添加的账号类型" << endl;
    cout << "1.学生账号" << endl;
    cout << "2.教师账号" << endl;

    string fileName; // 操作文件名
    string tip; // 提示id号
    string errorTip;

    ofstream ofs; // 文件操作对象

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
        errorTip = "学号重复，请重新输入" ;
    }
    else
    {
        fileName = TEACHER_FILE;
        tip = "请输入职工号：";
        errorTip = "职工号重复，请重新输入";
    }
   
    ofs.open(fileName, ios::out | ios::app); // 追加 输出

    int id;
    string name;
    string passwd;

    cout << tip << endl;

    while (true)
    {
        cin >> id;
        bool ret = this->checkRepeat(id, select);

        if (ret) // 有重复
        {
            cout << errorTip << endl;
        }
        else
        {
            break;
        }
    }

    cout << "请输入姓名：" << endl;
    cin >> name;
    cout << "请输入密码" << endl;
    cin >>passwd;
    
    ofs << id << " " << name << " " << passwd << endl;
    cout << "添加成功" << endl;
    ofs.close();

    this->initVector(); // 调用初始化容器接口，重新获取文件中的数据

    cout << "按任意键继续" << endl;
    getchar();
    getchar();
    system("clear");
}

void printStudent(Student &s)
{
    cout << "学号：" << s.m_id << "\t" << "姓名：" << s.m_Name << endl;
}

void printTeacher(Teacher &t)
{
    cout << "职工号：" << t.m_EmpId << "\t" << "姓名：" << t.m_Name << endl;
}

void Admin::showAccount()
{
    cout << "请选择查看内容：" << endl;
    cout << "1.查看所有学生" << endl;
    cout << "2.查看所有教师" << endl;

    int select;
    cin >> select;

    if (select == 1)
    {
        cout << "查看学生信息如下：" << endl;
        for_each(vStu.begin(), vStu.end(), printStudent); 
    }
    else
    {
        cout << "查看学生信息如下：" << endl;
        for_each(vTeach.begin(), vTeach.end(), printTeacher);
    }

    cout << "按任意键继续" << endl;
    getchar();
    getchar();
    system("clear");
}

void Admin::showRoom()
{
    cout << "机房信息如下：" << endl;
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
    {
        cout << "机房编号：" << it->m_ComId << "\t" << "机房容量：" << it->m_MaxNum << endl;
    }

    cout << "按任意键继续" << endl;
    getchar();
    getchar();
    system("clear");
}

void Admin::clearOrder()
{
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "清空成功！" << endl;
    cout << "按任意键继续" << endl;
    getchar();
    getchar();
    system("clear");
}

void Admin::initVector()
{
    // 确保容器是清空状态
    vStu.clear();
    vTeach.clear();

    // 读取学生信息
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    
    Student s;
    while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_Passwd)
    {
        vStu.push_back(s);
    }
    // cout << "当前的学生数量为：" << vStu.size() << endl;
    ifs.close();

    // 读取老师信息
    ifs.open(TEACHER_FILE, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    
    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Passwd)
    {
        vTeach.push_back(t);
    }
    // cout << "当前的老师数量为：" << vTeach.size() << endl;
    ifs.close();

    return;
}

bool Admin::checkRepeat(int id, int type)
{
    if (type == 1) // 检测学生
    {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
        {
            if (id == it->m_id)
            {
                return true; // 学生重复
            }
        }
    }
    else // 检测老师
    {
        for (vector<Teacher>::iterator it = vTeach.begin() ; it != vTeach.end(); it++)
        {
            if (id == it->m_EmpId)
            {
                return true; // 老师重复
            }
        }
    }
    return false; // 无重复
}