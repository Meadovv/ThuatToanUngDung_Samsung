#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 1000006;
stack<char> st;
string s;

void Input() {
    cin >> s;
}

void Process() {
    loop(i, 0, s.size() - 1) {
        if(s[i] == ')') {
            if(st.empty()) {
                cout << 0;
                exit(0);
            }
            if(st.top() == '(') {
                st.pop();
            } else {
                cout << 0;
                exit(0);
            }
            continue;
        }
        if(s[i] == ']') {
            if(st.empty()) {
                cout << 0;
                exit(0);
            }
            if(st.top() == '[') {
                st.pop();
            } else {
                cout << 0;
                exit(0);
            }
            continue;
        }
        if(s[i] == '}') {
            if(st.empty()) {
                cout << 0;
                exit(0);
            }
            if(st.top() == '{') {
                st.pop();
            } else {
                cout << 0;
                exit(0);
            }
            continue;
        }
        st.push(s[i]);
    }
}

void Output() {
    if(st.size()) cout << 0;
    else cout << 1;
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