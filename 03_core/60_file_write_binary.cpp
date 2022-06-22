#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

void test01()
{
    ofstream ofs("person.txt", ios::binary | ios::out); // 创建并打开
    // ofs.open("person.txt", ios::binary | ios::out); // 单独打开
    Person p = {"张三", 18};
    ofs.write( (const char *)&p, sizeof(Person) );
    ofs.close();
}

int main()
{
    test01();
    return 0;
}