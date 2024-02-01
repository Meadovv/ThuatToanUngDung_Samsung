#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "DEFAULT" // Edit here
using namespace std;

const int N = 100006;
int a, b, d;
map<pair<int, int>, int> visited;
queue<pair<int, int>> q;
bool hasSolution = false;
int ans = INT_MAX;

void Input() {
    cin >> a >> b >> d;
}

void Process() {

    q.push(pair<int, int>(0, 0));
    visited[pair<int, int>(0, 0)] = 0;
    while(!q.empty()) {
        auto u = q.front();
        q.pop();

        if(u.first > a || u.second > b || u.first < 0 || u.second < 0) continue;

        if(u.first == d || u.second == d) {
            hasSolution = true;
            ans = min(ans, visited[u]);
        }

        // fully fill jug 2
        if(!visited[pair<int, int>(u.first, b)]) {
            visited[pair<int, int>(u.first, b)] = visited[u] + 1;
            q.push(pair<int, int>(u.first, b));
        }

        // fully fill jug 1
        if(!visited[pair<int, int>(a, u.second)]) {
            visited[pair<int, int>(a, u.second)] = visited[u] + 1;
            q.push(pair<int, int>(a, u.second));
        }

        // Pour from jug 1 to jug 2
        int jug2_Remain_Cap = b - u.second;
        if(u.first >= jug2_Remain_Cap) {
            if(!visited[pair<int, int>(u.first - jug2_Remain_Cap, b)]) {
                visited[pair<int, int>(u.first - jug2_Remain_Cap, b)] = visited[u] + 1;
                q.push(pair<int, int>(u.first - jug2_Remain_Cap, b));
            }
        } else {
            if(!visited[pair<int, int>(0, u.first + u.second)]) {
                visited[pair<int, int>(0, u.first + u.second)] = visited[u] + 1;
                q.push(pair<int, int>(0, u.first + u.second));
            }
        }

        // Pour from jug 2 to jug 1
        int jug1_Remain_Cap = a - u.first;
        if(u.second >= jug1_Remain_Cap) {
            if(!visited[pair<int, int>(a, u.second - jug1_Remain_Cap)]) {
                visited[pair<int, int>(a, u.second - jug1_Remain_Cap)] = visited[u] + 1;
                q.push(pair<int, int>(a, u.second - jug1_Remain_Cap));
            }
        } else {
            if(!visited[pair<int, int>(u.first + u.second, 0)]) {
                visited[pair<int, int>(u.first + u.second, 0)] = visited[u] + 1;
                q.push(pair<int, int>(u.first + u.second, 0));
            }
        }

        // empty jug 1
        if(!visited[pair<int, int>(0, u.second)]) {
            visited[pair<int, int>(0, u.second)] = visited[u] + 1;
            q.push(pair<int, int>(0, u.second));
        }

        // empty jug 2
        if(!visited[pair<int, int>(u.first, 0)]) {
            visited[pair<int, int>(u.first, 0)] = visited[u] + 1;
            q.push(pair<int, int>(u.first, 0));
        }
    }
}

void Output() {
    if(!hasSolution) {
        cout << -1;
    } else {
        cout << ans;
    }
}

int main() {
    // Do not put your code here
    if(!(FILE_NAME == "DEFAULT")) {
        InputFormFile(FILE_NAME);
        OutputToFile(FILE_NAME);
        FAST(0);
    }
    Input(), Process(), Output();
    return 0;
}
