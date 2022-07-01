#include "15_MyArray.hpp"

void printIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
    
}

void test01()
{
    MyArray<int> arr1(5); // MyArray的有参构造调用
    // MyArray<int> arr3(100); // MyArray的有参构造调用
    // arr3 = arr1; // MyArray的operator=调用

    for (int i = 0; i < 5; i++)
    {
        arr1.pushBack(i); // 利用尾插法向数组中插入数据
    }
    cout << "arr1的打印输出为：" << endl;
    printIntArray(arr1);
    cout << "arr1的容量为： " << arr1.getCapacity() << endl;
    cout << "arr1的大小为： " << arr1.getSize() << endl;

    MyArray<int> arr2(arr1); // MyArray的有参构造调用
    printIntArray(arr2);

    // 尾删
    arr2.popBack();
    cout << "arr2尾删后：" << endl;
    cout << "arr2的容量为： " << arr2.getCapacity() << endl;
    cout << "arr2的大小为： " << arr2.getSize() << endl;
}

// 测试自定义数据类型
class Person
{
public:
    Person() {}; // 有参构造会覆盖默认构造，但是开辟空间需要一个无参构造，因此需要自己写一遍无参构造才不会报错
    // 因为hpp文件中用new开辟了Person类的堆区空间，而这些new出来的对象没有参数所以调用了无参构造
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << "姓名：" << arr[i].m_Name << " "
             << "年龄：" << arr[i].m_Age << endl;
    }
}

void test02()
{
    MyArray<Person> arr(10);

    Person p1("孙悟空", 999);
    Person p2("韩信", 20);
    Person p3("妲己", 30);
    Person p4("赵云", 25);
    Person p5("安其拉", 29);

    // 将数据插入到数组中
    arr.pushBack(p1);
    arr.pushBack(p2);
    arr.pushBack(p3);
    arr.pushBack(p4);
    arr.pushBack(p5);

    // 打印数组
    printPersonArray(arr);

    // 输出容量
    cout << "arr容量为：" << arr.getCapacity() << endl;
    // 输出大小
    cout << "arr大小为：" << arr.getSize() << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}