#include <bits/stdc++.h>
using namespace std;


int main() {

    freopen("input.txt", "r", stdin);

    string str;
    while(getline(cin, str)) {
        for(int i = 0; i < str.size(); ++i) {
            str[i] = toupper(str[i]);
        }
        cout << str << "\n";
    }

    return 0;
}