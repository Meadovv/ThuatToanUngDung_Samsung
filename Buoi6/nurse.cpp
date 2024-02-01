#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "nurse" // Edit here
using namespace std;

// count number of binary sequence which have k bit 1 consecutive and Between rows of k 1 bits, there is only one 0 bit

// dp[i][0] is the number of binary strings of length i, the last bit is 0 and satisfies it 
// dp[i][1] is the number of binary strings of length i, the last bit is 1 and satisfies it

const int N = 10006;
const int mod = 1000000007;

int n, k1, k2, dp[N][2];

void Input() {
    cin >> n >> k1 >> k2;
}

void Process() {

    dp[1][0] = 1;
    dp[0][0] = 1;
    dp[k1][1] = 1;

    loop(i, k1 + 1, n) {
        dp[i][0] = dp[i - 1][1];
        loop(j, i - k2, i - k1) {
            if(j >= 0) dp[i][1] = (dp[i][1] + dp[j][0]) % mod;
        }
    }

    cout << (dp[n][0] + dp[n][1]) % mod;
}

void Output() {

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