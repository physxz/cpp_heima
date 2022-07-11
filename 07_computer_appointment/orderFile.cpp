#include <fstream>
#include <string>
#include "orderFile.h"

OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string date;
    string interval;
    string stuId;
    string stuName;
    string roomId;
    string status;

    this->m_Size = 0; // 记录条数

    while (ifs >> date && ifs >> interval && ifs >> stuId &&
           ifs >> stuName && ifs >> roomId && ifs >> status)
    {
        // cout << date << endl;
        // cout << interval << endl;
        // cout << stuId << endl;
        // cout << stuName << endl;
        // cout << roomId << endl;
        // cout << status << endl;
        // cout << endl;
        
        // date:1
        string key;
        string value;
        map<string, string> m;
        int pos = date.find(":"); // pos = 4
        if (pos != -1)
        {
            key = date.substr(0, pos);
            // value = date.substr( pos+1, date.size()-1 ); // size = 6, pos = 4, size-pos-1= 6-4-1
            // value = date.substr( pos+1, -1 ); // 最后一个元素
            value = date.substr( pos+1 ); // 默认截取到最后
            m.insert( make_pair(key, value) );
        }

        // cout << "key = " << key << endl;
        // cout << "value = " << value << endl;

        // interval:1
        pos = interval.find(":"); // pos = 4
        if (pos != -1)
        {
            key = interval.substr(0, pos);
            // value = date.substr( pos+1, date.size()-1 ); // size = 6, pos = 4, size-pos-1= 6-4-1
            // value = interval.substr( pos+1, -1 ); // 最后一个元素
            value = interval.substr( pos+1 ); // 默认截取到最后
            m.insert( make_pair(key, value) );
        }

        // stuId:1
        pos = stuId.find(":"); // pos = 4
        if (pos != -1)
        {
            key = stuId.substr(0, pos);
            // value = date.substr( pos+1, date.size()-1 ); // size = 6, pos = 4, size-pos-1= 6-4-1
            // value = interval.substr( pos+1, -1 ); // 最后一个元素
            value = stuId.substr( pos+1 ); // 默认截取到最后
            m.insert( make_pair(key, value) );
        }

        // stuName:张三
        pos = stuName.find(":"); // pos = 4
        if (pos != -1)
        {
            key = stuName.substr(0, pos);
            // value = date.substr( pos+1, date.size()-1 ); // size = 6, pos = 4, size-pos-1= 6-4-1
            // value = interval.substr( pos+1, -1 ); // 最后一个元素
            value = stuName.substr( pos+1 ); // 默认截取到最后
            m.insert( make_pair(key, value) );
        }

        // roomID:2
        pos = roomId.find(":"); // pos = 4
        if (pos != -1)
        {
            key = roomId.substr(0, pos);
            // value = date.substr( pos+1, date.size()-1 ); // size = 6, pos = 4, size-pos-1= 6-4-1
            // value = interval.substr( pos+1, -1 ); // 最后一个元素
            value = roomId.substr( pos+1 ); // 默认截取到最后
            m.insert( make_pair(key, value) );
        }

        // status:1
        pos = status.find(":"); // pos = 4
        if (pos != -1)
        {
            key = status.substr(0, pos);
            // value = date.substr( pos+1, date.size()-1 ); // size = 6, pos = 4, size-pos-1= 6-4-1
            // value = interval.substr( pos+1, -1 ); // 最后一个元素
            value = status.substr( pos+1 ); // 默认截取到最后
            m.insert( make_pair(key, value) );
        }

        // 将内map容器放入到外map中
        this->m_orderFile.insert( make_pair(this->m_Size, m) );
        this->m_Size++;
    }
    ifs.close();

    // 测试外map容器
    // for (map<int, map<string, string>>::iterator it = m_orderFile.begin(); it != m_orderFile.end(); it++)
    // {
    //     cout << "----第 " << it->first << " 条预约信息如下----" << endl;
    //     for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
    //     {
    //         cout << "key = " << mit->first << "\t" << "value = " << mit->second << endl;
    //     }
    // }
}

void OrderFile::updateOrder()
{
    if (this->m_Size == 0) // 预约记录0条直接return掉
    {
        return;
    }
    
    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    for (int i = 0; i < this->m_Size; i++)
    {
        ofs << "date:" << this->m_orderFile[i]["date"] << " "
            << "interval:" << this->m_orderFile[i]["interval"] << " "
            << "stuId:" << this->m_orderFile[i]["stuId"] << " "
            << "stuName:" << this->m_orderFile[i]["stuName"] << " "
            << "roomId:" << this->m_orderFile[i]["roomId"] << " "
            << "status:" << this->m_orderFile[i]["status"] << endl;
    }

    ofs.close();
}