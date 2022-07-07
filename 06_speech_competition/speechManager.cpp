#include "speechManager.h"

SpeechManager::SpeechManager()
{
    this->initSpeech(); // 初始化属性

    this->createCandidate(); // 创建12名选手

    this->loadRecord(); // 加载往届记录
}

void SpeechManager::showMenu()
{
    cout << "********************************" << endl;
    cout << "******* 欢迎开始演讲比赛 *******" << endl;
    cout << "******** 1.开始演讲比赛 ********" << endl;
    cout << "******** 2.查看往届记录 ********" << endl;
    cout << "******** 3.清空比赛记录 ********" << endl;
    cout << "******** 0.退出比赛程序 ********" << endl;
    cout << "********************************" << endl;
}

void SpeechManager::initSpeech() // 将初始化设计成函数，然后放到构造函数中调用，这样在别的地方也可以复用初始化函数
{
    // 保证容器为空
    this->vCandidate.clear();
    this->vAfter.clear();
    this->vVictory.clear();
    this->m_Candidate.clear();
    this->m_Index = 1; // 初始化比赛轮数
    this->m_Record.clear(); // 将记录容器情况
}

void SpeechManager::createCandidate()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "选手";
        name += nameSeed[i];

        Candidate cand;
        cand.m_Name = name;
        for (int j = 0; j < 2; j++)
        {
            cand.m_Score[j] = 0;
        }

        // 12名选手编号
        this->vCandidate.push_back(i + 10001);
        // 将选手编号以及对应选手放入到map容器中
        this->m_Candidate.insert( make_pair(i+10001, cand) );
    }
}

void SpeechManager::startSpeech()
{
    // 第一轮比赛
    // 1.抽签
    this->speechDraw();

    // 2.比赛
    this->speechCompetition();

    // 3.显示晋级结果
    this->showScore();

    // 第二轮比赛
    this->m_Index++;
    // 1.抽签
    this->speechDraw();

    // 2.比赛
    this->speechCompetition();

    // 3.显示最终结果
    this->showScore();

    // 4.保存分数
    this->saveRecord();
    
    // 重置比赛，获取记录
    this->initSpeech(); // 初始化容器和属性
    this->createCandidate(); // 创建12名选手
    this->loadRecord(); // 加载往届记录

    cout << "本届比赛完毕！" << endl;

    cout << "请按任意键继续..." << endl;
    getchar();
    system("clear");
}

void SpeechManager::speechDraw()
{
    cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签..." << endl;
    cout << "------------------------------" << endl;
    cout << "抽签后演讲顺序如下" << endl;

    if (this->m_Index == 1)
    {
        random_shuffle(this->vCandidate.begin(), this->vCandidate.end());
        for (vector<int>::iterator it = this->vCandidate.begin(); it != this->vCandidate.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(this->vAfter.begin(), this->vAfter.end());
        for (vector<int>::iterator it = this->vAfter.begin(); it != this->vAfter.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;

    cout << "请按任意键继续..." << endl;
    getchar();
    getchar();
}

void SpeechManager::speechCompetition()
{
    cout << "-------------第 " << this->m_Index << " 轮比赛正式开始------------" << endl;

    // 临时容器，保存key分数和value选手编号，降序排序；分数可能重复所以用multimap
    multimap<double, int, greater<double>> groupScore;

    int num = 0; // 记录人员数，6个为一组

    vector<int> vSrc; // 比赛人员容器
    if (this->m_Index == 1)
    {
        vSrc = this->vCandidate;
    }
    else
    {
        vSrc = this->vAfter;
    }

    // 遍历所有参赛选手
    for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); it++)
    {
        num++; // 记录人员数

        // 10个评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = ( rand() % 401 + 600 ) / 10.f; // 60.0-100.0
            // cout << score << " ";
            d.push_back(score);
        }

        sort(d.begin(), d.end(), greater<double>()); // 从大到小排序

        d.pop_front(); // 去掉最高分
        d.pop_back(); // 去掉最低分

        double sum = accumulate(d.begin(), d.end(), 0.0f); // 总分
        double avg = sum / (double)d.size(); // 平均分

        // 打印平均分
        // cout << "编号：" << *it << "\t" << "姓名：" << this->m_Candidate[*it].m_Name << "\t"
        //      << "平均分" << this->m_Candidate[*it].m_Score[0] << endl;

        // 将平均分放入map容器，分配给每个人
        this->m_Candidate[*it].m_Score[this->m_Index - 1] = avg;

        // 6个人一组，用临时容器保存
        groupScore.insert(make_pair(avg, *it)); // key是得分，value是具体选手编号

        // 每6人取出前三名
        if (num % 6 == 0)
        {
            cout << "第 " << num / 6 << " 小组比赛名次如下：" << endl;
            for ( multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++ )
            {
                cout << "编号：" << it->second << "\t姓名：" << this->m_Candidate[it->second].m_Name
                     << "\t成绩：" << this->m_Candidate[it->second].m_Score[this->m_Index - 1] << endl;
            }

            // 取走前三名
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
            {
                if (this->m_Index == 1)
                {
                    this->vAfter.push_back(it->second);
                }
                else
                {
                    this->vVictory.push_back(it->second);
                }
            }

            groupScore.clear(); // 清空容器，避免第二组直接追加

            cout << endl;
        }
    }

    cout << "-------------第 " << this->m_Index << " 轮比赛完毕------------" << endl;

    cout << "请按任意键继续..." << endl;
    getchar();
}

void SpeechManager::showScore()
{
    cout << "----------------第 " << this->m_Index << " 轮晋级选手信息如下：-----------------" << endl;

    vector<int> v;
    if (this->m_Index == 1)
    {
        v = vAfter;
    }
    else
    {
        v = vVictory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "编号：" << *it << "\t姓名：" << this->m_Candidate[*it].m_Name
             << "\t得分" << this->m_Candidate[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;

    cout << "请按任意键继续..." << endl;
    getchar();
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); // 用追加的方式写文件

    // 将每个人的数据写入到文件中
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        ofs << *it << "," << this->m_Candidate[*it].m_Score[1] << ",";
    }
    ofs << endl;

    ofs.close(); // 关闭文件

    cout << "记录已经保存" << endl;

    this->fileIsEmpty = false; // 有记录了，文件不为空
}

void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in); // 输入流对象，读取文件

    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        // cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // cout << "文件为空！" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    this->fileIsEmpty = false; // 文件不为空
    
    ifs.putback(ch); // 读取的单个字符放回去(指针回退)

    string data;
    int index = 0;
    while (ifs >> data)
    {
        // cout << data << endl;
        // 10010,88.4,10004,85.3,10001,84.85,

        vector<string> v; // 存放6个字符串

        int pos = -1; // 查到“，”位置的变量
        int start = 0;

        while (true)
        {
            pos = data.find(",", start);

            if (pos == -1)
            {
                break; // 没有找到
            }
            string temp = data.substr(start, pos - start);
            // cout << temp << endl;
            v.push_back(temp);
            start = pos + 1;
        }        
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    
    ifs.close();

    // for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
    // {
    //     cout << it->first << "冠军编号：" << it->second[0] << "\t分数：" << it->second[1] << endl;
    // }
}

void SpeechManager::showRecord()
{
    if (this->fileIsEmpty)
    {
        cout << "文件为空或文件不存在！" << endl;
    }

    for (int i = 0; i < this->m_Record.size(); i++)
    {
        cout << "第 " << i+1 << " 届 "
             << "冠军编号：" << this->m_Record[i][0] << "\t得分：" << this->m_Record[i][1] << "\t"
             << "亚军编号：" << this->m_Record[i][2] << "\t得分：" << this->m_Record[i][3] << "\t"
             << "季军编号：" << this->m_Record[i][4] << "\t得分：" << this->m_Record[i][5] << endl;
    }
    
    cout << "请按任意键继续..." << endl;
    getchar();
    getchar();
    system("clear");
}

void SpeechManager::clearRecord()
{
    cout << "是否确定清空文件？" << endl;
    cout << "1.是" << endl;
    cout << "2.否" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        this->initSpeech(); // 初始化容器和属性
        this->createCandidate(); // 创建12名选手
        this->loadRecord(); // 加载往届记录

        cout << "情况成功！" << endl;
    }
    cout << "请按任意键继续..." << endl;
    getchar();
    getchar();
    system("clear");
}

void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    cout << "请按任意键继续..." << endl;
    getchar();
    exit(0);
}

SpeechManager::~SpeechManager()
{
    // 无堆区数据，不用调用析构，删除掉也没问题
}