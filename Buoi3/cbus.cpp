#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n, k, temp, c[N][N], route[N];
bool visited[N];
int ans = INT_MAX, curAns = 0, load = 0, Cmin = INT_MAX;

bool Check(int i) {
    if(visited[i]) return false;
    if(i <= n && load >= k) return false;
    if(i <= n && visited[i + n]) return false;
    if(i > n && !visited[i - n]) return false;

    return true;
}

void Solution() {
    ans = min(ans, curAns + c[route[2 * n]][route[0]]);
}

void Try(int cur) {
    for(int i = 1; i <= 2 * n; ++i) {
        if(!Check(i)) continue;
        route[cur] = i;
        visited[i] = true;
        curAns = curAns + c[route[cur - 1]][route[cur]];
        if(i <= n) load = load + 1;
        else load = load - 1;
        if(cur == 2 * n) Solution();
        else {
            if((curAns + (2 * n + 1 - cur) * Cmin) < ans) Try(cur + 1);
        }
        visited[i] = false;
        curAns = curAns - c[route[cur - 1]][route[cur]];
        if(i <= n) load = load - 1;
        else load = load + 1;
    }
}

int main() {

    freopen("input.txt", "r", stdin);

    cin >> n >> k;
    
    for(int i = 0; i <= 2 * n; ++i) {
        for(int j = 0; j <= 2 * n; ++j) {
            cin >> temp;
            c[i][j] = temp;
            if(i != j) Cmin = min(Cmin, temp);
        }
    }

    visited[0] = 1;
    route[0] = 0;

    Try(1);

    cout << ans;

    return 0;
}