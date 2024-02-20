#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 10004;
const long long mod = 1000000007;

int n, M, a[N];

long long dp[16];

void Input() {
    cin >> n >> M;
    loop(i, 0, n - 1) cin >> a[i];
}

void Process() {
    dp[0] = 1;
    while(n--) {
        loop(i, 0, a[0] - 1) {
            if(dp[0] == 0) 
                break;
            dp[a[i + 1]] = (dp[a[i + 1]] + dp[0]) % mod;
        }
        loop(i, 1, 10) dp[i-1] = dp[i];
    }

    cout << dp[2];
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