#include "workerManager.h"

// 类内声明类外实现(构造和析构函数的空实现科可写可不写，编译器会自动添加，但是写上方便后边初始化操作)
WorkerManager::WorkerManager() // 构造函数的空实现
{
    // 1.文件不存在的情况
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if ( !ifs.is_open() )
    {
        cout << "文件不存在" << endl;
        // 初始化属性
        this->m_EmpNum = 0; // 初始化记录人数
        this->m_EmpArray = nullptr; // 初始化数组指针
        this->m_FileIsEmpty = true; // 初始化文件是否为空
        ifs.close();
        return;
    }
}

void WorkerManager::showMenu() // 展示菜单
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

void WorkerManager::addEmp() // 添加成员
{
    cout << "请输入增加职工数量：" << endl;
    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        // 计算要添加的新空间大小
        int newSize = this->m_EmpNum + addNum; // 新空间人数=原来记录人数+新增人数
        
        // 开辟新空间
        Worker ** newSpace = new Worker * [newSize];
        
        // 将原来空间下数据，拷贝到新空间下
        if (this->m_EmpArray != nullptr)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 批量添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect; // 部门选择
            cout << "请输入第 " << i+1 << " 个新职工编号" << endl;
            cin >> id;
            cout << "请输入第 " << i+1 << " 个新职工姓名" << endl;
            cin >> name;
            cout << "请选择该职工的岗位" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Worker * worker = nullptr;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }

            // 将创建的职工指针保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }

        // 释放原有空间
        delete[] this->m_EmpArray;
        // 更改新空间的指向
        this->m_EmpArray = newSpace;
        // 更新新的职工人数
        this->m_EmpNum = newSize;
        // 提示添加成功
        cout << "成功添加 " << addNum << " 名职工" << endl;
        // 保存数据到文件中
        this->save();
    }
    else
    {
        cout << "输入数据有误" << endl;
    }

    // 按任意键后清屏回到上级目录
    cout << "请按任意键继续..." << endl;
    getchar(); // 暂停，按任意键后继续
    getchar(); // 暂停，按任意键后继续
    system("clear || cls");
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}

void WorkerManager::exitSystem() // 退出系统
{
    cout << "欢迎下次使用" << endl;
    cout << "请按任意键继续..." << endl;
    getchar(); // 暂停，按任意键后继续
    getchar(); // 暂停，按任意键后继续
    exit(0);
}

WorkerManager::~WorkerManager() // 析构函数的空实现
{
    // 堆区代码手动开辟手动释放
    if (this->m_EmpArray != nullptr)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = nullptr;
    }
}