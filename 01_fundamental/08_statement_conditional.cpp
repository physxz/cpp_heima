/*
 * @Author: 赵小鑫
 * @Date: 2022-05-04 23:24:49
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-04 23:41:46
 * @FilePath: /08_statement_conditional.cpp
 * @Description: 比较两三个数的大小
 */

#include <iostream>
using namespace std;

int main() {
    int a = 9;
    int b = 5;
    int c = 8;
    int result = 0;
    int fin_result = 0;
    result = (a > b ? a : b);
    // cout << result << endl;
    fin_result = (result > c ? result : c);
    cout << fin_result << endl;
    return 0;
}