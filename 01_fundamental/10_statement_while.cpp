/*
 * @Author: 赵小鑫
 * @Date: 2022-05-05 00:08:30
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-05 00:25:44
 * @FilePath: /10_statement_while.cpp
 * @Description: 猜数字
 */

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    // 添加随机数种子，利用当前系统时间生成随机数，防止每次随机数都一样
    srand((unsigned int) time (NULL));
    int i = 0;
    int guess = 0;
    int num = rand()%100 + 1; // rand()%100：生成0-99区间内的随机数
    while (i < 5 && cin >> guess) {   // 先判断次数再输入
        if (guess > num)
            cout << "大了" << endl;
        else if (guess < num)
            cout << "小了" << endl;
        else {
            cout << "恭喜你答对了" << endl;
            break;    // 猜对则退出循环
        }
        i++;
    }
    return 0;
}