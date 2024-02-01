#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "gmining" // Edit here
using namespace std;

const int N = 1000006;
int n, l1, l2, a[N], dp[N], ans;
deque<int> q;

void Input() {
    cin >> n >> l1 >> l2;
    loop(i, 1, n) cin >> a[i];
}

void Process() {
    loop(i, 1, n) {
        while(!q.empty() && q.front() < i - l2) q.pop_front();
        int j = i - l1;
        if(j >= 1) {
            while(!q.empty() && dp[q.back()] < dp[j]) q.pop_back();
            q.push_back(j);
        }
        dp[i] = a[i] + (!q.empty() * dp[q.front()]);
        ans = max(ans, dp[i]);
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