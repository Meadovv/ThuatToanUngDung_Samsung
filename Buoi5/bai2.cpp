
// m[i][0] la day con co tong lon nhat tu 1 toi i va khong chua ai
// m[i][1] la day con co tong lon nhat tu 1 toi i va co chua ai

// m[i][0] = max(m[i-1][0], m[i-1][1])
// m[i][1] = max(m[i-1][1] + a[i], a[i])

#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai2" // Edit here
using namespace std;

const int N = 1000006;
int n, a[N], dp[N][2];
bool flag = false;

void Input() {
    cin >> n;
    loop(i, 1, n) cin >> a[i];
}

void Process() {
    loop(i, 1, n) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][1] + a[i], a[i]);
    }
}

void Output() {
    cout << max(dp[n][0], dp[n][1]);
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