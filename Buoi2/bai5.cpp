#include <bits/stdc++.h>
using namespace std;

vector<int> number;

int toNumber(string x) {

    int ans = 0;

    for(int i = 0; i < x.size(); ++i) {
        if(x[i] >= '0' && x[i] <= '9') {
            ans = ans * 10 + (int)(x[i] - 48);
        } else {
            return -1;
        }
    }

    return ans;
}

int main() {
    string str;
    cin >> str;
    if(str.size() != 10) {
        cout << "INCORRECT";
    } else {
        str = str + "-";
        string temp = "";
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == '-') {
                number.push_back(toNumber(temp));
                temp = "";
            } else {
                temp = temp + str[i];
            }
        }
    }

    bool isTrue = true;

    for(int i = 0; i < number.size(); ++i) {
        if(i == 0 && number[i] < 1000) isTrue = false;
        if(i == 1 && (number[i] < 0 || number[i] > 12)) isTrue = false;
        if(i == 2 && (number[i] < 0 || number[i] > 31)) isTrue = false;
    }

    if(isTrue) {
        for(auto v: number) {
            cout << v << " ";
        }
    } else {
        cout << "INCORRECT";
    }

    return 0;
}