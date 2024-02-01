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
    if(str.size() != 8) {
        cout << "INCORRECT";
        return 0;
    } else {
        str = str + ":";
        string temp = "";
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == ':') {
                number.push_back(toNumber(temp));
                temp = "";
            } else {
                temp = temp + str[i];
            }
        }
    }

    bool isTrue = true;

    for(int i = 0; i < number.size(); ++i) {
        if(i == 0 && (number[i] < 0 || number[i] > 23)) isTrue = false;
        if(i == 1 && (number[i] < 0 || number[i] > 59)) isTrue = false;
        if(i == 2 && (number[i] < 0 || number[i] > 60)) isTrue = false;
    }

    if(isTrue) {
        cout << number[0] * 3600 + number[1] * 60 + number[2];
    } else {
        cout << "INCORRECT";
    }

    return 0;
}