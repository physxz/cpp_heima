using namespace std;
#include "student.h"

Student::Student()
{
    
}

Student::Student(int id, string name, string passwd)
{
    this->m_id = id;
    this->m_Name = name;
    this->m_Passwd = passwd;

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
    {
        this->vCom.push_back(com);
    }

    ifs.close();
}

void Student::operateMenu()
{
    cout << "欢迎学生代表 "<< this->m_Name << " 登录！" << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         1.申请预约          |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         2.查看我的预约      |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         3.查看所有预约      |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         4.取消预约          |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|         0.注销登录          |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << "请输入您的选择：" << endl;
}

void Student::applyOrder()
{
    cout << "请选择日期：" << endl;
    cout << "1.周一" << endl;
    cout << "2.周二" << endl;
    cout << "3.周三" << endl;
    cout << "4.周四" << endl;
    cout << "5.周五" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true)
    {
        cin >> date;
        if (date >= 1 && date <= 5)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    
    cout << "请选择时段：" << endl;
    cout << "1.上午" << endl;
    cout << "2.下午" << endl;

    while (true)
    {
        cin >> interval;
        if (interval == 1 || interval == 2)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请选择机房：" << endl;
    for (int i = 0; i < vCom.size(); i++)
    {
        cout << vCom[i].m_ComId << "号机房容量为：" << vCom[i].m_MaxNum << endl;
    }

    while (true)
    {
        cin >> room;
        if (room >=1 && room <= 3)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    
    cout << "预约成功!审核中..." << endl;

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);

    ofs << "date:" << date << " "
        << "interval:" << interval << " "
        << "stuId:" << this->m_id << " "
        << "stuName:" << this->m_Name << " "
        << "roomId:" << room << " "
        << "status:" << 1 << endl;

    ofs.close();

    cout << "按任意键继续" << endl;
    getchar();
    getchar();
    system("clear");
}

void Student::showMyOrder()
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

    for (int i = 0; i < of.m_Size; i++)
    {
        // string转int，string利用.c_str()转const char *
        if ( this->m_id == atoi( of.m_orderFile[i]["stuId"].c_str() ) ) // 找到自身预约
        {
            cout << "预约信息：周 " << of.m_orderFile[i]["date"] << " ";
            cout << ( of.m_orderFile[i]["interval"] == "1" ? "上午" : "下午" ) << "，";
            cout << of.m_orderFile[i]["roomId"] << "号房" << "，";

            string status = "状态：";
            // 1审核中 2已预约 -1预约失败 0取消预约
            if (of.m_orderFile[i]["status"] == "1")
            {
                status += "审核中";
            }
            else if (of.m_orderFile[i]["status"] == "2")
            {
                status += "预约成功";
            }
            else if (of.m_orderFile[i]["status"] == "-1")
            {
                status += "预约失败";
            }
            else
            {
                status += "取消预约";
            }
            cout << status << endl;
        }
    }

    cout << "按任意键继续" << endl;
    getchar();
    getchar();
    system("clear");
}

void Student::showAllOrder()
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

    for (int i = 0; i < of.m_Size; i++)
    {
        cout << i + 1 << ".";
        cout << "预约信息：周 " << of.m_orderFile[i]["date"] << " ";
        cout << ( of.m_orderFile[i]["interval"] == "1" ? "上午" : "下午" ) << "，";
        cout << "学号：" << of.m_orderFile[i]["stuId"] << "，";
        cout << "学号：" << of.m_orderFile[i]["stuName"] << "，";
        cout << of.m_orderFile[i]["roomId"] << "号房" << "，";

        string status = "状态：";
        // 1审核中 2已预约 -1预约失败 0取消预约
        if (of.m_orderFile[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if (of.m_orderFile[i]["status"] == "2")
        {
            status += "预约成功";
        }
        else if (of.m_orderFile[i]["status"] == "-1")
        {
            status += "预约失败";
        }
        else
        {
            status += "取消预约";
        }
        cout << status << endl;
    }

    cout << "按任意键继续" << endl;
    getchar();
    getchar();
    system("clear");
}

void Student::cancleOrder()
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

    cout << "审核中或预约成功的记录可以取消，请输入要取消的记录：" << endl;

    vector<int> v;
    int index = 1;
    for (int i = 0; i < of.m_Size; i++)
    {
        if ( atoi(of.m_orderFile[i]["stuId"].c_str()) == this->m_id ) // 通过id判断是自身预约
        {
            if (of.m_orderFile[i]["status"] == "1" || of.m_orderFile[i]["status"] == "2") // 筛选状态
            {
                v.push_back(i);
                cout << index++ << ". ";
                cout << "预约信息：" << "周" << of.m_orderFile[i]["date"] << " "
                     << (of.m_orderFile[i]["interval"] == "1" ? "上午" : "下午") << "，"
                     << of.m_orderFile[i]["roomId"] << "号房，";
                string status = "状态：";
                if (of.m_orderFile[i]["status"] == "1")
                {
                    status += "审核中";
                }
                else if (of.m_orderFile[i]["status"] == "2")
                {
                    status += "预约成功";
                }
                cout << status << endl;
            }
        }
    }

    cout << "请输入取消的记录，0代表返回" << endl;
    int select = 0;

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
                of.m_orderFile[ v[select-1] ]["status"] = "0";

                of.updateOrder();

                cout << "已取消预约" << endl;
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