#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int n, temp, c[N][N], route[N];
bool visited[N];
int ans = INT_MAX, curAns = 0;

void Solution() {
    ans = min(ans, curAns + c[route[n]][route[1]]);
}

void Try(int cur) {
    for(int i = 1; i <= n; ++i) {
        if(visited[i]) continue;
        if(curAns + c[route[cur -1 ]][i] > ans) continue;
        visited[i] = true;
        route[cur] = i;
        curAns = curAns + c[route[cur -1]][i];
        if(cur == n) Solution();
        else Try(cur + 1);
        visited[i] = false;
        curAns = curAns - c[route[cur -1]][i];
    }
}

int main() {

    freopen("input.txt", "r", stdin);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> temp;
            c[i][j] = temp;
        }
    }

    route[1] = 1;
    visited[1] = 1;

    Try(2);

    cout << ans;

    return 0;
}