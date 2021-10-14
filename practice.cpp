/*
 * @Author: your name
 * @Date: 2021-10-14 16:11:52
 * @LastEditTime: 2021-10-14 16:37:50
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /practice/practice.cpp
 */

#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int value = 0;
    cout << "please input data ! " << endl;
    while(cin >> value) {
        sum += value;
    }
    cout << "The sum is : " << sum << endl;
    return 0;
}