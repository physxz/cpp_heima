/*
 * @Author: 赵小鑫
 * @Date: 2022-05-10 16:29:58
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-10 17:05:25
 * @FilePath: /19_CO_pack_private.cpp
 * @Description: 
 */

#include <iostream>
#include <string>
using namespace std;

class Person {
public: // 提供一个公共接口
    void setName(string name) { // 写名字
        m_Name = name;
    }
    string getName() { // 读名字
        return m_Name;
    }

    int getAge() { // 获取年龄
        return m_Age;
    }

    void setAge(int age) { // 写年龄，范围0-150
        if (age < 0 || age > 150) {
            m_Age = 0;
            cout << "年龄超出范围" << endl;
        }
        else
            m_Age = age;
    }

    void setLover(string lover) { // 写情人
        m_Lover = lover;
    }
    
private:
    string m_Name; // 姓名 可读可写
    int m_Age; // 年龄 可读可(范围)写
    string m_Lover; // 情人 只写
};

int main() {
    Person p;
    p.setName("张三");
    cout << "姓名为：" << p.getName() << endl;
    p.setAge(1000);
    p.setAge(18);
    cout << "年龄为：" << p.getAge() << endl;
    p.setLover("李四");
    return 0;
}