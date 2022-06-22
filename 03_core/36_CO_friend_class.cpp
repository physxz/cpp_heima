#include <iostream>
using namespace std;

// 1.类外写成员函数，2.类如何访问另一个类的私有属性
//**********************类************************//
class Building; // 让编译器先认识这个类
class GoodGay
{
public:
    GoodGay(); // 声明构造函数，后边在类外实现
    void visit(); // 参观函数，访问building中的属性
    // 类内声明，类外实现函数
    Building *building; // 一个类只声明却不做定义的话只能使用指针或引用，且并不能解引用

};
class Building
{
    friend GoodGay; // GoodGay是本类的好朋友，可以访问本类中的私有成员
public:
    Building(); // 声明构造函数，后边在类外实现
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};
//***********************************************//

//********************类外写成员函数***************//
Building::Building() // 类外构造函数
{
    m_SittingRoom = "客厅"; // 类外赋初值
    m_BedRoom = "卧室";
}
GoodGay::GoodGay()
{
    // 创建建筑物对象
    building = new Building; // 在堆区创建变量(延长对象寿命)，new创建的数据会返回该数据对应的指针
}
void GoodGay::visit() // 类外成员函数
{
    cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
    cout << "好基友类正在访问：" << building->m_BedRoom << endl;
    // 直接访问私有成员会报错，需要在Building类中声明GoodGay为友元
}
//*********************************************//

void test01()
{
    GoodGay gg; //实例化对象
    // 先调用GoodGay类的构造函数，GoodGay构造函数里边要实例化一个building对象，
    // 然后要先调用Building构造函数，Building构造函数内部对成员变量赋初值
    gg.visit(); // 调用GoodGay的成员函数，访问Building的实例化对象building的初值
}

int main() {
    test01();
    return 0;
}