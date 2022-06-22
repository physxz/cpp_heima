/*
 * @Author: 赵小鑫
 * @Date: 2022-05-04 22:54:58
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-04 23:41:58
 * @FilePath: /07_statement_if.cpp
 * @Description: 比较三个数的大小
 */

#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    cin >> a >> b >> c;
    if (a > b) {
        if(a > c)
            cout << "a最重" << endl;
        else if (a < c)
            cout << "c最重" << endl;
        else  // a = c
            cout << "a和c一样重" << endl;
    } else if (a < b) {
        if (b > c)
            cout << "b最重" << endl;
        else if (b < c)
            cout << "c最重" << endl;
        else  // b = c
            cout << "b和c一样重" << endl;
    } else    // a = b
        if(a > c)
            cout << "a和b一样重" << endl;
        else if (a < c)
            cout << "c最重" << endl;
        else  // a = c
            cout << "abc一样重" << endl;
    return 0;
}