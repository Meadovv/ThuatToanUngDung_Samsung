#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai4" // Edit here
using namespace std;

const int N = 20;

int nCity, m;
int dist[N][N];
int ans = 0;
int x[N];
int cur = 0;
bool visited[N];
int minDist = INT_MAX;

void Input() {
    cin >> nCity >> m;
    loop(i, 1, nCity) loop(j, 1, nCity) {
        cin >> dist[i][j];
        if(dist[i][j] == 0) continue;
        minDist = min(minDist, dist[i][j]);
    }
    memset(visited, 0, sizeof(visited));
    x[1] = 1;
}

bool Check (int curCity, int cur, int cityOrder) {
    if(cur + dist[x[cityOrder - 1]][curCity] > m) return false;
    return !visited[curCity];
}

void Solution (int cur) {
    if(cur <= m) {
        ans = ans + 1;
        // loop(i, 1, nCity) {
        //     cout << x[i] << " ";
        // }
        // cout << "1 => " << cur << "\n";
    }
}

void Try (int cityOrder) {
    loop(curCity, 2, nCity) {
        if(Check(curCity, cur, cityOrder)) {
            visited[curCity] = true;
            x[cityOrder] = curCity;
            cur = cur + dist[x[cityOrder - 1]][curCity];
            if(cityOrder == nCity) Solution(cur + dist[curCity][1]);
            else {
                if((nCity + 1 - cityOrder) * minDist <= m) Try(cityOrder + 1);
            }
            visited[curCity] = false;
            cur = cur - dist[x[cityOrder - 1]][curCity];
        }
    }
}

void Process() {
    Try(2);
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