#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai1" // Edit here
using namespace std;

const int N = 100006;
const int mod = 1000000007;
int n;

string expression;
long sum = 0;
long cur = 0;

void Input() {
    cin >> expression;
    expression = expression + '.';
}

void Process() {
    loop(i, 0, expression.length() - 1) {
        if(expression[i] >= '0' && expression[i] <= '9') {
            cur = (cur * 10 + (int)(expression[i] - 48));
        } else {
            if(cur == 0) {
                cout << "NOT_CORRECT";
                exit(0);
            } else {
                sum = (sum + cur) % mod;
                cur = 0;
            }
        }
    }
}

void Output() {
    cout << sum;
}

int main() {
    // Do not put your code here
    if(!(FILE_NAME == "DEFAULT")) {
        InputFormFile(FILE_NAME), 
        // OutputToFile(FILE_NAME), 
        FAST(0);
    }
    Input(), Process(), Output();
    return 0;
}