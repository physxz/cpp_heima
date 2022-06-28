#include "employee.h"
// employee.h文件的实现

Employee::Employee(int id, string name, int dId) // 构造函数初始化实现
{
    // this可以加也可以不加(形参名一样的话必须加this，如果不一样，可以加也可以不加)
    this->m_Id = id;
    this->m_name = name;
    this->m_DeptId = dId;
}

void Employee::showInfo()
{
    cout << "职工编号：" << this->m_Id << "\t"
         << "职工姓名：" << this->m_name << "\t"
         << "岗位：" << this->getDeptName() << "\t" // 多态，一个函数(接口)有多种形态
         << "岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName()
{
    return string("员工");
}