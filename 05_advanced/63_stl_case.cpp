#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
using namespace std;

#define PLANNING 1 // 策划部
#define ART 2 // 美术部
#define RnD 3 // 研发部

// 员工分组案例-自己写的(修改)

class Worker
{
public:
    Worker(string name, int salary)
    {
        this->m_Name = name;
        this->m_Salary = salary;
    }
    string m_Name;
    int m_Salary;
};

void createEmp(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        string name = "员工";
        name += nameSeed[i];
        int salary = rand() % 5001 + 5000; // 5000-10000

        Worker w(name, salary);

        v.push_back(w);
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &mm)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        int departId = rand() % 3 + 1;
        mm.insert(make_pair(departId, *it));
    }
}

void showWorkerByGroup(multimap<int, Worker> &mm)
{
    cout << "策划部有 " << mm.count(PLANNING) << " 名员工" << endl;
    multimap<int, Worker>::iterator pos = mm.find(PLANNING);
    for (int i = 0; i < mm.count(PLANNING); i++)
    {
        cout << "姓名：" << pos->second.m_Name << "\t" << "工资：" << pos->second.m_Salary << endl;
        pos++;
    }

    cout << "美术部有 " << mm.count(ART) << " 名员工" << endl;
    pos = mm.find(ART);
    for (int i = 0; i < mm.count(ART); i++)
    {
        cout << "姓名：" << pos->second.m_Name << "\t" << "工资：" << pos->second.m_Salary << endl;
        pos++;
    }
    
    cout << "研发部有 " << mm.count(RnD) << " 名员工" << endl;
    pos = mm.find(RnD);
    for (int i = 0; i < mm.count(RnD); i++)
    {
        cout << "姓名：" << pos->second.m_Name << "\t" << "工资：" << pos->second.m_Salary << endl;
        pos++;
    }
}

int main()
{
    // 随机数种子
    srand( (unsigned int) time(nullptr) );

    vector<Worker> v;

    // 1.创建10名员工
    createEmp(v);
    
    // 2.随机分组 并插到multimap中
    multimap<int, Worker> mm;
    setGroup(v, mm);
    
    // 3.分部门显示员工信息
    showWorkerByGroup(mm);

    return 0;
}