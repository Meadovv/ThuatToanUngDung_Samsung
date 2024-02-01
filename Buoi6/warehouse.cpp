#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "warehouse" // Edit here
using namespace std;

const int N = 1003;
int numStation, maxDistance, maxTime;
int amount[N], pickTime[N], dp[N][N];
int ans = INT_MIN;

// dp[i][k] là tổng lượng hàng max lấy được khi đến trạm i (có lấy hàng ở trạm i) và có tổng thời gian lấy hàng là k
// dp[i][k] = max(dp[j][k - ti]) + ai với i - j < maxDistance

void Input() {
    cin >> numStation >> maxTime >> maxDistance;
    loop(i, 1, numStation) cin >> amount[i];
    loop(i, 1, numStation) cin >> pickTime[i];
}

void Process() {

    dp[1][pickTime[1]] = amount[1];

    loop(curStation, 1, numStation) {
        loop(curTime, 0, maxTime) {
            if(curTime - pickTime[curStation] >= 0) {
                loop(preStation, max(1, curStation - maxDistance), curStation - 1) {
                    dp[curStation][curTime] = max(dp[curStation][curTime], dp[preStation][curTime - pickTime[curStation]] + amount[curStation]);
                }
            }
            ans = max(ans, dp[curStation][curTime]);
        }
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