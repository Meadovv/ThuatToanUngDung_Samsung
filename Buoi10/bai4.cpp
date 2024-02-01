#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 1000006;
int n, m;
int ans = 0;
vector<int> adj[N];
queue<int> q;
int visited[N];

void Input() {
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    while(m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

bool BFS(int root) {
    bool flag = true;
    q.push(root);
    visited[root] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v: adj[u]) {
            if(visited[v] == visited[u]) flag = false;
            else if(!visited[v]) {
                q.push(v);
                visited[v] = 3 - visited[u];
            }
        }
    }

    if(flag) return 1;
    else return 0;
}

void Process() {
    loop(i, 1, n) {
        if(!visited[i]) {
            if(!BFS(i)) {
                cout << 0;
                return;
            }
        }
    }

    cout << 1;
}

void Output() {

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