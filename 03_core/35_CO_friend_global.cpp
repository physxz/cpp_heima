#include <iostream>
using namespace std;

class Building
{
    // googGay全局函数是Building的好朋友，可以访问building中私有成员
    friend void goodGay(Building *building);

public:
    Building () // 默认构造函数赋初值
    {
        m_SitinngRoom = "客厅";
        m_BedRoom = "卧室";
    }
    string m_SitinngRoom;
private:
    string m_BedRoom;
};

void goodGay(Building *building)
{
    cout << "好基友全局函数 正在访问：" << building->m_SitinngRoom << endl;
    cout << "好基友全局函数 正在访问：" << building->m_BedRoom << endl; // 需要在类中friend友元声明
}

void test01() {
    Building building;
    goodGay(&building);
}

int main() {
    test01();
    return 0;
}