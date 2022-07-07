#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <numeric>
#include <fstream>
#include "candidate.h"
using namespace std;

// 设计演讲管理类

class SpeechManager
{
public:
    SpeechManager(); // 构造函数

    void showMenu(); // 显示菜单

    void initSpeech(); // 初始化属性

    void createCandidate(); // 创建12名选手

    void startSpeech(); // 开始比赛 比赛流程控制

    void speechDraw(); // 抽签

    void speechCompetition(); // 比赛

    void showScore(); // 显示晋级结果

    void saveRecord(); // 保存比赛记录

    void loadRecord(); // 读取记录分数

    void showRecord(); // 显示往届得分

    void clearRecord(); // 情况系统

    void exitSystem(); // 退出系统

    ~SpeechManager(); // 析构函数

    vector<int> vCandidate; // 比赛选手容器 12人
    vector<int> vAfter; // 第一轮晋级容器 6人
    vector<int> vVictory; // 胜利前三名容器 3人

    map<int, Candidate> m_Candidate; // 存放编号以及对应的具体选手容器

    int m_Index; // 记录比赛轮数

    bool fileIsEmpty; // 文件为空标志

    map<int, vector<string>> m_Record; // 往届记录
};