#include "workerManager.h"

// 类内声明类外实现(构造和析构函数的空实现科可写可不写，编译器会自动添加，但是写上方便后边初始化操作)
// 构造函数的实现(初始化)
WorkerManager::WorkerManager()
{
    // 1.文件不存在的情况
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if ( !ifs.is_open() )
    {
        // cout << "文件不存在！" << endl;
        // 初始化属性
        this->m_EmpNum = 0; // 初始化记录人数
        this->m_EmpArray = nullptr; // 初始化数组指针
        this->m_FileIsEmpty = true; // 初始化文件是否为空
        ifs.close();
        return;
    }

    // 2.文件存在但数据为空
    char ch;
    ifs >> ch; // 从文件中读取一个字符
    if ( ifs.eof() ) // 读取到的字符为EOF(文件尾)为真
    {
        // cout << "文件为空！" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = nullptr;
        ifs.close();
        return;
    }

    // 3.文件存在，并且有记录数据
    int num = this->getEmpNum();
    // cout << "职工人数为：" << num << endl;
    this->m_EmpNum = num;
    this->m_EmpArray = new Worker * [this->m_EmpNum];
    initEmp();
    // 测试代码
    // for (int i = 0; i < m_EmpNum; i++)
    // {
    //     cout << "职工编号：" << this->m_EmpArray[i]->m_Id << "\t"
    //          << "职工姓名：" << this->m_EmpArray[i]->m_name << "\t"
    //          << "部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
    // }
}

// 展示菜单
void WorkerManager::showMenu()
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

// 添加成员
void WorkerManager::addEmp()
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
        // 更新职工不为空标志
        this->m_FileIsEmpty = false; // 添加职工之后文件不为空
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

// 保存职工到文件
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

// 获取职工人数
int WorkerManager::getEmpNum() 
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++; // 记录人数
    }
    ifs.close();
    return num;
}

// 初始化职工
void WorkerManager::initEmp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker * worker = nullptr;

        // 根据不同的部门id创建不同对象
        if (dId == 1)
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else
        {
            worker = new Boss(id, name, dId);
        }

        // 存放在数组中
        this->m_EmpArray[index] = worker;
        index++;
    }
}

// 显示职工
void WorkerManager::showEmp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            // 利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }

    // 按任意键清屏
    cout << "请按任意键继续..." << endl;
    getchar(); // 暂停，按任意键后继续
    getchar(); // 暂停，按任意键后继续
    system("clear || cls");
}

// 判断职工是否存在
int WorkerManager::isExist(int id)
{
    int index = -1; // 默认不存在，就是return -1

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

// 删除职工
void WorkerManager::delEmp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        // 按照职工编号删除职工
        cout << "请输入想要删除的职工编号" << endl;
        int id = 0;
        cin >> id;

        int index = this->isExist(id);
        if (index != -1)
        {
            // 数据前移
            for (int i = index; i < this->m_EmpNum-1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            // 更新数组中记录的人员个数
            this->m_EmpNum--;
            // 数据同步更新到文件中
            this->save();
            
            cout << "删除成功！" << endl;
        }
        else
        {
            cout << "删除失败，未找到该职工" << endl;
        }
    }

    cout << "请按任意键继续..." << endl;
    getchar(); // 暂停，按任意键后继续
    getchar(); // 暂停，按任意键后继续
    system("clear || cls");
}

void WorkerManager::modEmp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入要修改职工的编号：" << endl;
        int id;
        cin >> id;

        int ret = this->isExist(id);
        if (ret != -1)
        {
            delete this->m_EmpArray[ret];
            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到：" << id << "号职工，请输入新职工编号：" << endl;
            cin >> newId;
            cout << "请输入新姓名：" << newName << endl;
            cin >> newName;
            cout << "请输入岗位：" << "\n"
                 << "1. 普通职工" << "\n"
                 << "2. 经理" << "\n"
                 << "3. 老板" << endl;
            cin >> dSelect;

            Worker * worker = nullptr;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }

            // 更改数据到数组中
            this->m_EmpArray[ret] = worker;

            cout << "修改成功！" << this->m_EmpArray[ret]->m_DeptId << endl;

            // 保存到文件中
            this->save();
        }
        else
        {
            cout << "修改失败，未找到该职工" << endl;
        }
    }

    cout << "请按任意键继续..." << endl;
    getchar(); // 暂停，按任意键后继续
    getchar(); // 暂停，按任意键后继续
    system("clear || cls");
}

// 查找职工
void WorkerManager::findEmp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请输入查找的方式：" << "\n"
             << "1. 按职工编号查找" << "\n"
             << "2. 按姓名查找" << endl;
        
        int select = 0;
        cin >> select;

        if (select == 1) // 按编号查找
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;
            int ret = this->isExist(id);
            if (ret != -1) // 找到职工
            {
                cout << "查找成功！该职工信息如下：" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else if (select == 2) // 按姓名查找
        {
            string name;
            cout << "请输入查找的职工姓名：" << endl;
            cin >> name;

            // 判断是否查到的标志
            bool flag = false; // 默认未找到职工

            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if ( name == this->m_EmpArray[i]->m_name )
                {
                    cout << "查找成功，职工编号为："
                         << this->m_EmpArray[i]->m_Id << "，"
                         << "该职工信息如下：" << endl;
                    // 调用显示信息接口
                    this->m_EmpArray[i]->showInfo();
                    // 将查找到的标志置为true
                    flag = true;
                }
            }
            if (flag == false)
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else
        {
            cout << "输入选项有误，请重新输入" << endl;
        }
    }

    cout << "请按任意键继续..." << endl;
    getchar(); // 暂停，按任意键后继续
    getchar(); // 暂停，按任意键后继续
    system("clear || cls");
}

void WorkerManager::sortEmp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
        cout << "请按任意键继续..." << endl;
        getchar(); // 暂停，按任意键后继续
        getchar(); // 暂停，按任意键后继续
        system("clear || cls");
    }
    else
    {
        cout << "请选择排序方式" << "\n"
             << "1. 按职工编号升序" << "\n"
             << "2. 按职工编号降序" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < this->m_EmpNum; i++)
        {
            int minOrMax = i; // 声明最小值或最大值下标

            for (int j = i+1; j < this->m_EmpNum; j++)
            {
                if (select == 1) // 升序
                {
                    if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else if (select == 2)
                {
                    if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else
                {
                    cout << "输入错误，请重新输入" << endl;
                }
            }

            // 判断一开始认定最小值或最大值是不是计算的最小值或最大值，如果不是，交换数据
            if (i != minOrMax)
            {
                Worker * temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }
        }
        cout << "排序成功，排序后的结果为：" << endl;
        this->save(); // 将排序后的结果保存到文件中
        this->showEmp();
    }
}

void WorkerManager::cleanFile()
{
    cout << "确认清空" << "\n"
         << "1. 确认" << "\n"
         << "2. 返回" << endl;

    int select = 0;
    cin >> select;

    if(select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != nullptr)
        {
            // 删除堆区的每个职工对象
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != nullptr)
                {
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = nullptr;
                }
            }

            // 删除堆区数组指针
            delete[] this->m_EmpArray;
            this->m_EmpArray = nullptr;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }
    cout << "请按任意键继续..." << endl;
    getchar(); // 暂停，按任意键后继续
    getchar(); // 暂停，按任意键后继续
    system("clear || cls");
}

// 退出系统
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    cout << "请按任意键继续..." << endl;
    getchar(); // 暂停，按任意键后继续
    getchar(); // 暂停，按任意键后继续
    exit(0);
}

// 析构函数的实现
WorkerManager::~WorkerManager()
{
    // 堆区代码手动开辟手动释放
    if (this->m_EmpArray != nullptr)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = nullptr;
    }
}