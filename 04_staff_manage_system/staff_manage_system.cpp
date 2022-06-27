#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
using namespace std;

int main()
{
    // 测试代码
    Worker * worker = nullptr; // 初始化为空指针，防止出现野指针
    worker = new Employee(1, "张三", 1);
    worker->showInfo();

    // WorkerManager wm; // 实例化管理者对象

    // int choice = 0; // 存储用户选择

    // while (true)
    // {
    //     wm.showMenu(); // 调用展示菜单成员函数
    //     cout << "请输入您的选择：" << endl;
    //     cin >> choice;

    //     switch (choice)
    //     {
    //         case 0: // 退出系统
    //             wm.exitSystem();
    //             break;
    //         case 1: // 增加职工
    //             break;
    //         case 2: // 显示职工
    //             break;
    //         case 3: // 删除职工
    //             break;
    //         case 4: // 修改职工
    //             break;
    //         case 5: // 查找职工
    //             break;
    //         case 6: // 排序职工
    //             break;
    //         case 7: // 清空文档
    //             break;
    //         default: // 清屏操作
    //             system("clear || cls");
    //             break;
    //     }
    // }
    return 0;
}