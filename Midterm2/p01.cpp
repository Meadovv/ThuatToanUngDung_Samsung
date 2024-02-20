#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

string s;
vector<string> vt;

const long long mod = 1000000007;
long long ans = 0;

void Input() {
    cin >> s;
}

bool NotADigit(char x) {
    return !(x >= '0') && (x <= '9');
}

void Process() {
    string curString = "";
    if(NotADigit(s[0]) || NotADigit(s[s.size() - 1])) {
            cout << "NOT_CORRECT";
            return;
    }
    loop(i, 0, s.size() - 1) {
        if(NotADigit(s[i]) && NotADigit(s[i - 1])) {
            cout << "NOT_CORRECT";
            return;
        }
        if(s[i] == '+') {
            vt.push_back(curString);
            curString = "";
        } else {
            curString += s[i];
        }
    }

    vt.push_back(curString);

    for(auto v: vt) {
        long long curNumber = 0;
        long long blockAns = 1;
        v = v + '*';
        loop(i, 0, v.size() - 1) {
            if(v[i] == '*') {
                blockAns = (blockAns * curNumber) % mod;
                curNumber = 0;
            } else {
                curNumber = curNumber * 10 + (int)(v[i] - '0');
            }
        }
        ans = (ans + blockAns) % mod;
    }
}

void Output() {
    cout << ans;
}

int main() {
    // Do not put your code here
    if(!(FILE_NAME == "DEFAULT")) {
        InputFormFile(FILE_NAME);
        // OutputToFile(FILE_NAME);
        FAST(0);
    }
    Input(), Process(), Output();
    return 0;
}