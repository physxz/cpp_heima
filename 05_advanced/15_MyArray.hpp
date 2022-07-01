#pragma once
#include <iostream>
#include <string>
using namespace std;

// 自己通用的数组类

template<class T>
class MyArray
{
public:
    // 有参构造，参数：容量
    MyArray(int capacity)
    {
        // cout << "MyArray的有参构造调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // 拷贝构造(防止浅拷贝)
    MyArray(const MyArray &arr)
    {
        // cout << "MyArray的拷贝构造调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // this->pAddress = arr.pAddress; // 指针不能这样拷贝，浅拷贝会导致堆区的数据重复释放
        this->pAddress = new T[arr.m_Capacity]; // 重新在堆区开辟空间，深拷贝
        for (int i = 0; i < this->m_Size; i++) // 将arr中的数据都拷贝过来
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // operator= 防止浅拷贝问题(因此重载=)
    MyArray & operator=(const MyArray &arr) // 要做连等于(a = b = c)操作，=需要返回值
    {
        // cout << "MyArray的operator=调用" << endl;
        // 先判断原来堆区是否有数据，如果有先释放
        if (this->pAddress != nullptr)
        {
            delete[] this->pAddress;
            this->pAddress = nullptr;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    // 尾插法
    void pushBack(const T &val)
    {
        // 判断容量是否等于大小
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val; // 在数组末尾插入数据
        this->m_Size++; // 更新数组大小
    }

    // 尾删法
    void popBack()
    {
        // 让用户访问不到最后一个元素，即尾删，逻辑删除
        if (this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }

    // 通过下标方式访问数组中的元素(直接下标访问不到，需要重载[]) arr[0] = 100
    T & operator[](int index) // 返回引用，引用是别名，就是直接对原数据修改，可以作为左值
    {
        return this->pAddress[index];
    }

    // 返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    // 返回数组大小
    int getSize()
    {
        return this->m_Size;
    }

    // 析构函数
    ~MyArray()
    {
        if (this->pAddress != nullptr)
        {
            // cout << "MyArray的析构函数调用" << endl;
            delete[] this->pAddress;
            this->pAddress = nullptr;
        }
    }
private:
    T * pAddress; // 指针指向堆区开辟的真实数组
    int m_Capacity; // 数组容量
    int m_Size; // 数组的大小
};