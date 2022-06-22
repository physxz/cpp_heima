/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 15:06:10
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 15:24:14
 * @FilePath: /19_array_2d.cpp
 * @Description: 输出每个人的成绩
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    int scores[3][3] = {
        {100,100,100},
        {90,50,100},
        {60,70,80}
    };
    string names[3] = {"张三","李四","王五"};
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += scores[i][j];
        }
        cout << names[i] << "的总成绩为：" << sum << endl;
    }
    return 0;
}