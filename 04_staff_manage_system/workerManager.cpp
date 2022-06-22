#include "workerManager.h"

// 类内声明类外实现(构造和析构函数的空实现科可写可不写，编译器会自动添加，但是写上方便后边初始化操作)
WorkerManager::WorkerManager() // 构造函数的空实现
{

}

void WorkerManager::Show_Menu() // 展示菜单
{
    cout << "*************************************************" << endl;
    cout << "************* 欢迎使用职工管理系统！ ************" << endl;
    cout << "************* 0.退出管理程序 ********************" << endl;
    cout << "************* 1.增加职工信息 ********************" << endl;
    cout << "************* 2.显示职工信息 ********************" << endl;
    cout << "************* 3.删除离职职工 ********************" << endl;
    cout << "************* 4.修改职工信息 ********************" << endl;
    cout << "************* 5.查找职工信息 ********************" << endl;
    cout << "************* 6.按照编号排序 ********************" << endl;
    cout << "************* 7.清空所有文档 ********************" << endl;
    cout << "*************************************************" << endl;
    cout << endl;
}

void WorkerManager::Exit_System() // 退出系统
{
    cout << "欢迎下次使用" << endl;
    getchar(); // 暂停，按任意键后继续
    getchar(); // 暂停，按任意键后继续
    exit(0);
}

WorkerManager::~WorkerManager() // 析构函数的空实现
{

}