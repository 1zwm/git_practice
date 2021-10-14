#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    string temp; //input string
    vector<string> ans; //answer
    for(int i = 0; i < n; i++) {
        cin >> temp;
        string str = "";
        str += temp.substr(0, 2);
        int j = 2;
        while(j < int(temp.size())) {
            if(temp[j-2] == temp[j-1]) {
                if(temp[j] == temp[j-1]) {
                    char c = temp[j];
                    while(j+1 < int(temp.size()) && temp[++j] == c);
                    if(temp[j] != c)
                        str.push_back(temp[j]);
                    c = temp[j];
                    while(j+1 < int(temp.size()) && temp[++j] == c);
                    if(temp[j] != c)
                        str.push_back(temp[j]);
                    j++;
                 }
                else if(j+1 < int(temp.length()) && temp[j] == temp[j+1]) {
                        str.push_back(temp[j]);
                        char c = temp[j];
                            j++;
                        while(j+1 < int(temp.size()) && temp[++j] == c);
                        if(temp[j] != c)
                            str.push_back(temp[j]);
                        j++;
                    }
                else {
                    str.push_back(temp[j]);
                    j++;
                }
            } else {
                str.push_back(temp[j]);
                j++;
            }
        }
        ans.emplace_back(str);
        }
        for(int i = 0; i < int(ans.size()); i++) {
            cout << ans[i] << endl;
        }
    }