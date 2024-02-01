#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
bool dd[1001];

int main() {

    freopen("input.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));

    string p1, p2, t;

    getline(cin, p1);
    getline(cin, p2);
    getline(cin, t);

    int p = 0, temp = 0;
    bool flag;
    while(p != t.size() - 1) {
        temp = p;
        flag = true;
        for(int i = 0; i < p1.size(); ++i) {
            if(t[temp] == p1[i]) {
                temp = temp + 1;
            } else {
                flag = false;
                break;
            }
        }
        if(flag) {
            dd[p] = 1;
            m[p] = temp - 1;
            p = temp;
        } else {
            p = p + 1;
        }
    }

    for(int i = 0; i < t.size(); ++i) {
        if(dd[i]) {
            for(int i = 0; i < p2.size(); ++i) {
                cout << p2[i];
            }
            i = m[i];
        } else {
            cout << t[i];
        }
    }

    return 0;
}