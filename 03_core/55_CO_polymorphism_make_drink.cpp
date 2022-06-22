#include <iostream>
using namespace std;

class AbstractDrinking // 类似于一个模板
{
public:
    // 煮水
    virtual void Boil() = 0; // 到子类中去寻找具体实现
    // 冲泡
    virtual void Brew() = 0;
    // 倒入杯中
    virtual void PourInCup() = 0;
    // 加入辅料
    virtual void PutSomething() = 0;
    // 制作饮品
    void makeDrink() // 只留一个公共接口，只要调用这一个函数就可以实现类内容
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

// 制作咖啡
class Coffee: public AbstractDrinking
{
public:
    // 煮水
    virtual void Boil()
    {
        cout << "煮农夫山泉" << endl;
    };
    // 冲泡
    virtual void Brew()
    {
        cout << "冲泡咖啡" << endl;
    };
    // 倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    };
    // 加入辅料
    virtual void PutSomething()
    {
        cout << "倒入糖和牛奶" << endl;
    };
};

class Tea: public AbstractDrinking
{
public:
    // 煮水
    virtual void Boil()
    {
        cout << "煮矿泉水" << endl;
    };
    // 冲泡
    virtual void Brew()
    {
        cout << "冲泡茶叶" << endl;
    };
    // 倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    };
    // 加入辅料
    virtual void PutSomething()
    {
        cout << "加入枸杞" << endl;
    };
};

// 制作函数
void doWork(AbstractDrinking *abs) // AbstractDrinking * abs = new Coffee
{
    abs->makeDrink();
    delete abs;
}

void test01()
{
    // 制作咖啡
    doWork(new Coffee);
    cout << "---------------" << endl;
    // 制作茶叶
    doWork(new Tea);
}

int main() {
    test01();
    return 0;
}