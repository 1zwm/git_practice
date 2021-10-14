/*
 * @Author: your name
 * @Date: 2021-10-14 16:24:05
 * @LastEditTime: 2021-10-14 23:04:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /practice/test.cpp
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int ui;

void exgcd(ui a, ui b, ui& d, ui& x, ui& y) {
    if(b == 0) {
        d = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a%b, d, y, x);
        y -= x * (a/b);
    }
}

ui inv(ui a, ui b) {
    ui d, x, y;
    exgcd(a, b, d, x, y);
    return d == 1 ? (x+b)%b : -1;
}

ui factory(int n) {
    ui ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans % 99997867;
}

int main() {
    int N, D;
    ui ans = 0;
    cin >> N >> D;
    int building[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &building[i]);
    }
    int end = 1;
    for(int i = 0; i < N; i++) {
        while(end < N && building[i] + D >= building[end]) end++;
        if(end - i - 1 > 1) {
            ui temp = inv(factory(end - i - 3) * 2, 99997867);
            ans += factory(end - i - 1) * temp;
            ans = ans % 99997867;
        }
    }
    cout << ans;
    return 0;
}