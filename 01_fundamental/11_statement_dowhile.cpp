/*
 * @Author: 赵小鑫
 * @Date: 2022-05-05 22:43:11
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-05 23:05:10
 * @FilePath: /11_statement_dowhile.cpp
 * @Description: 水仙花数
 */

#include <iostream>
using namespace std;

int main() {
    int num = 100;
    do {
        int n3 = num / 100;
        int n2 = num / 10 % 10;
        int n1 = num % 10;
        if (n3*n3*n3 + n2*n2*n2 + n1*n1*n1 == num)
            cout << "3位数中的水仙花数有：" << num << endl;
        num++;
    } while (num < 1000);
    return 0;
}