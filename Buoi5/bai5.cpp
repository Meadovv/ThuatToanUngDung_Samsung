#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai5" // Edit here
using namespace std;

const int N = 1000006;
int n, a[N], dp[N], ans = INT_MIN;

void Input() {
    cin >> n;
    loop(i, 1, n) cin >> a[i], dp[i] = 1;
}

void Process() {
    loop(i, 1, n) {
        loopr(j, i - 1, 1) {
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
}

void Output() {
    loop(i, 1, n) ans = max(ans, dp[i]);

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