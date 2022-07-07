#include <ctime>
#include "speechManager.h"
#include "candidate.h"
using namespace std;

int main()
{
    SpeechManager sm; // 管理类对象
    
    int choice = 0;

    while (true)
    {
        srand( (unsigned int) time(nullptr) );

        sm.showMenu();

        // 测试12名选手创建
        // for (map<int ,Candidate>::iterator it = sm.m_Candidate.begin(); it != sm.m_Candidate.end(); it++)
        // {
        //     cout << "选手编号：" << it->first << "\t" << "姓名：" << it->second.m_Name
        //          << "\t" << "分数：" << it->second.m_Score[0] << endl;
        // }

        cout << "请输入您的选择：" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1: // 开始比赛
            sm.startSpeech();
            break;
        case 2: // 查看往届比赛记录
            sm.showRecord();
            break;
        case 3: // 清空比赛记录
            sm.clearRecord();
            break;
        case 0: // 退出系统
            sm.exitSystem();
            break;
        default:
            system("clear");
            break;
        }
    }

    return 0;
}