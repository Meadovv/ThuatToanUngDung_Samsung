#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 1003;
const long long mod = 1000000007;

int n;
long long dp[N][3];

void Input() {
    cin >> n;
    dp[1][0] = 1LL;
    dp[1][1] = 1LL;
    dp[1][2] = 1LL;
}

void Process() {
    for(int i = 2; i <= n; ++i) {
        dp[i][0] = (dp[i-1][2] + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][2] + dp[i-1][0]) % mod;
        dp[i][2] = (dp[i-1][2] + dp[i-1][1] + dp[i-1][0]) % mod;
    }
}

void Output() {
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod;
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