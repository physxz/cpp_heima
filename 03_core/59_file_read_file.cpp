#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test01()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    // 读取操作
    // 第1种
    // char buf[1024] = {0}; // 字符数组，每个值都是0
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }
    
    // 第2种
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }
    
    // 第3种
    string buf;
    while (getline(ifs, buf))
    {
        cout << buf << endl;
    }

    // 第4种，单字符读取，不太推荐
    char c;
    while ((c = ifs.get()) != EOF) // EOF - end of file
    {
        cout << c << endl;
    }

    ifs.close();
}

int main()
{
    test01();
    return 0;
}