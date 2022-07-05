#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
using namespace std;

// 员工分组案例-范例

#define PLANNING 0 // 策划部
#define ART 1 // 美术部
#define RnD 2 // 研发部

class Worker
{
public:
    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];
        worker.m_Salary = rand() % 10000 + 10000; // 10000-19999
        v.push_back(worker);
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 产生随机部门编号
        int depId = rand() % 3; // 0 1 2
        // 将员工插入到分组中
        m.insert(make_pair(depId, *it)); // key为部门编号，value为具体员工
    }
}

void showWorkerByGroup(multimap<int, Worker> &m)
{
    cout << "策划部门：" << endl;
    multimap<int, Worker>::iterator pos = m.find(PLANNING);
    int count = m.count(PLANNING); // 统计策划部门具体人数
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "\t" << "工资：" << pos->second.m_Salary << endl;
    }

    cout << "-----------------------------" << endl;
    cout << "美术部门：" << endl;
    pos = m.find(ART);
    count = m.count(ART); // 统计策划部门具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "\t" << "工资：" << pos->second.m_Salary << endl;
    }

    cout << "-----------------------------" << endl;
    cout << "研发部门：" << endl;
    pos = m.find(RnD);
    count = m.count(RnD); // 统计策划部门具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "\t" << "工资：" << pos->second.m_Salary << endl;
    }
}

int main()
{
    srand( (unsigned int) time(nullptr) );
    // 1.创建员工
    vector<Worker> vWorker;
    createWorker(vWorker);

    // // 测试
    // for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    // {
    //     cout << "姓名：" << it->m_Name << "\t" << "工资：" << it->m_Salary << endl;
    // }

    // 2.员工分组
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    // 3.分组显示员工
    showWorkerByGroup(mWorker);

    return 0;
}