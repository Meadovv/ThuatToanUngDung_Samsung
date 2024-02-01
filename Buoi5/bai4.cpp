

#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai3" // Edit here
using namespace std;

const int N = 10006;
int n, m, a[N], b[N], dp[N][N];
int trace[N][N];

void Input() {
    scanf("%d%d", &m, &n);
    loop(i, 1, m) scanf("%d", &a[i]);
    loop(j, 1, n) scanf("%d", &b[j]);
}

void Process() {
    loop(i, 1, m) loop(j, 1, n) {
        if(a[i] == b[j]) {
            dp[i][j] = dp[i-1][j-1] + 1;
            trace[i][j] = 1; // di chuyen cheo
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                trace[i][j] = 2; // di chuyen sang trai
            } else {
                dp[i][j] = dp[i][j - 1];
                trace[i][j] = 3; // di chuyen len tren
            }
        }
    }
}

void Output() {
    printf("%d\n", dp[m][n]);

    // trace
    int x = m, y = n;
    while(x != 0 && y != 0) {
        if(trace[x][y] == 1) {
            cout << a[x] << " ";
            x = x - 1;
            y = y - 1;
        } else {
            if(trace[x][y] == 2) {
                x = x - 1;
            } else {
                y = y - 1;
            }
        }
    }
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