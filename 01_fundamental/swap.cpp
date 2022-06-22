/*
 * @Author: 赵小鑫
 * @Date: 2022-05-06 16:28:12
 * @LastEditors: 赵小鑫
 * @LastEditTime: 2022-05-06 16:51:39
 * @FilePath: /swap.cpp
 * @Description: 
 */

#include "swap.h"

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}