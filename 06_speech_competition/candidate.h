#pragma once
#include <iostream>
#include <string>
using namespace std;

class Candidate
{
public:
    string m_Name;
    double m_Score[2]; // 最多有两轮得分
};