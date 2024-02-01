#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

#define ii pair<int, int>

const int N = 1003;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int numRow, numCol, sx, sy;
int Map[N][N];
map<ii, int> visited;

queue<ii> q;


void Input() {
    cin >> numRow >> numCol >> sx >> sy;
    loop(i, 1, numRow) loop(j, 1, numCol) cin >> Map[i][j];
}

void Process() {
    visited[ii(sx, sy)] = 1;
    q.push(ii(sx, sy));
    while (!q.empty())
    {
        ii u = q.front();
        if(u.first == 1 || u.first == numRow || u.second == 1 || u.second == numCol) {
            cout << visited[u] << " ";
            exit(0);
        }
        q.pop();
        loop(i, 0, 3) {
            if(!visited[ii(u.first + dx[i], u.second + dy[i])] && !Map[u.first + dx[i]][u.second + dy[i]]) {
                visited[ii(u.first + dx[i], u.second + dy[i])] = visited[u] + 1;
                q.push(ii(u.first + dx[i], u.second + dy[i]));
            }
        }
    }
}

void Output() {
    cout << -1;
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