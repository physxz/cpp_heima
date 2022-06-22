/*
 * @Author: 赵小鑫
 * @Date: 2022-05-04 23:41:02
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-04 23:58:22
 * @FilePath: /09_statement_switch.cpp
 * @Description: 给电影打分
 */

#include <iostream>
using namespace std;

int main() {
    cout << "请给电影打分" << endl;
    int score = 0;
    cin >> score;
    cout << "您输入的分数是：" << score << endl;
    switch (score) {
        case 10: cout << "经典电影" << endl; break;
        case 9: cout << "经典电影" << endl; break;
        case 8: cout << "非常好" << endl; break;
        case 7: cout << "非常好" << endl; break;
        case 6: cout << "一般" << endl; break;
        case 5: cout << "一般" << endl; break;
        default: cout << "烂片" << endl; break;
}
    return 0;
}