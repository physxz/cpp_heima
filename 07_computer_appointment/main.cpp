using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"
#include "globalFile.h"
#include "orderFile.h"

// 管理员子菜单 传入的是父类指针，因为只有父类指针才能调用父子共有的重写虚函数
void adminMenu(Identity * &admin) // 类型是Identity *，&只是引用(起别名)，这样传进来的指针还是原来的指针
{
    while (true)
    {
        admin->operateMenu(); // 调用管理员子菜单

        Admin * adminAdmin = (Admin *)admin; // 将父类指针转为子类指针，调用子类里的其他接口，不然父类指针只能指向父类属性

        int select = 0;
        cin >> select;

        if (select == 1) // 添加账号
        {
            cout << "添加账号" << endl;
            adminAdmin->addAccount();
        }
        else if (select == 2) // 查看账号
        {
            cout << "查看账号" << endl;
            adminAdmin->showAccount();
        }
        else if (select == 3) // 查看机房
        {
            cout << "查看机房" << endl;
            adminAdmin->showRoom();
        }
        else if (select == 4) // 清空预约
        {
            cout << "清空预约" << endl;
            adminAdmin->clearOrder();
        }
        else // 注销
        {
            delete adminAdmin;
            cout << "注销成功" << endl;
            cout << "按任意键继续" << endl;
            getchar();
            getchar();
            system("clear");
            return;
        }
    }
}

void studentMenu(Identity * &student)
{
    while (true)
    {
        student->operateMenu();

        Student * stu = (Student *)student;

        int select = 0;
        cin >> select;

        if (select == 1) // 申请预约
        {
            stu->applyOrder();
        }
        else if (select == 2) // 查看自身预约
        {
            stu->showMyOrder();
        }
        else if (select == 3) // 查看所有预约
        {
            stu->showAllOrder();
        }
        else if (select == 4)// 取消预约
        {
            stu->cancleOrder();
        }
        else // 注销登录
        {
            delete student;
            cout << "注销成功" << endl;

            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
            system("clear");

            return;
        }
    }
}

// 教师菜单
void teacherMenu(Identity * &teacher)
{
    while (true)
    {
        teacher->operateMenu(); // 调用子菜单界面
        Teacher * teach = (Teacher*)teacher;

        int select = 0;
        cin >> select;
        if (select == 1) // 查看所有预约
        {
            teach->showAllOrder();
        }
        else if (select == 2) // 审核预约
        {
            teach->checkOrder();
        }
        else
        {
            delete teacher;
            cout << "注销成功" << endl;

            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
            system("clear");

            return;
        }
    }
}

// 全局函数 登录功能
void logIn(string fileName, int type) // 参数1 文件名 参数2 操作身份类型
{
    Identity * person = nullptr; // 父类指针，用于指向子类对象

    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    
    int id;
    string name;
    string passwd;
    
    // 判断身份
    if (type == 1) // 学生身份
    {
        cout << "请输入你的学号：" << endl;
        cin >> id;
    }
    else if (type == 2)
    {
        cout << "请输入您的职工号：" << endl;
        cin >> id;
    }
    
    cout << "请输入用户名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> passwd;

    // 身份验证 从文件中获取信息 与用户输入做对比
    if (type == 1)
    {
        int fId; // 文件中的id
        string fName;
        string fPasswd;

        while (ifs >> fId && ifs >> fName && ifs >> fPasswd)
        {
            if (id == fId && name == fName && passwd == fPasswd)
            {
                cout << "学生验证登录成功！" << endl;
                getchar();
                getchar();
                system("clear");

                person = new Student(id, name, passwd);
                
                // 进入学生子菜单
                studentMenu(person);

                return;
            }
        }
    }
    else if (type == 2)
    {
        int fId; // 文件中的id
        string fName;
        string fPasswd;

        while (ifs >> fId && ifs >> fName && ifs >> fPasswd)
        {
            if (id == fId && name == fName && passwd == fPasswd)
            {
                cout << "教师验证登录成功！" << endl;
                getchar();
                getchar();
                system("clear");

                person = new Teacher(id ,name, passwd);
                
                // 进入老师子菜单
                teacherMenu(person);

                return;
            }
        }
    }
    else
    {
        string fName;
        string fPasswd;

        while (ifs >> fName && ifs >> fPasswd)
        {
            if (name == fName && passwd == fPasswd)
            {
                cout << "管理员验证登录成功！" << endl;
                getchar();
                getchar();
                system("clear");

                person = new Admin(name, passwd);
                
                // 进入管理员子菜单
                adminMenu(person);

                return;
            }
        }
    }

    cout << "验证登录失败!" << endl;
    cout << "按任意键继续..." << endl;
    getchar();
    getchar();
    system("clear");        

    return;
}

int main()
{
    int choice = 0;

    while (true)
    {
        cout << "-----------------欢迎来到传智博客机房预约系统-------------------" << endl;
        cout << "请输入您的身份" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\t|                             |" << endl;
        cout << "\t\t|         1.学生代表          |" << endl;
        cout << "\t\t|                             |" << endl;
        cout << "\t\t|         2.老    师          |" << endl;
        cout << "\t\t|                             |" << endl;
        cout << "\t\t|         3.管 理 员          |" << endl;
        cout << "\t\t|                             |" << endl;
        cout << "\t\t|         0.退    出          |" << endl;
        cout << "\t\t|                             |" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "请输入您的选择：" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1: // 学生身份
            logIn(STUDENT_FILE, 1);
            break;
        case 2: // 老师身份
            logIn(TEACHER_FILE, 2);
            break;
        case 3: // 管理员身份
            logIn(ADMIN_FILE, 3);
            break;
        case 0: // 退出系统
            cout << "欢迎下次使用机房预约系统！" << endl;
            cout << "按任意键继续..." << endl;
            getchar(); getchar();
            exit(0);
            break;
        default:
            cout << "输入有误，请重新选择！" << endl;
            cout << "按任意键继续..." << endl;
            getchar();
            getchar();
            system("clear");
            break;
        }
    }
    
    cout << "按任意键继续..." << endl;
    getchar();
    getchar();

    return 0;
}