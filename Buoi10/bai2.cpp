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
vector<int> adj[N];
queue<int> q;
bool visited[N];

void Input() {
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    loop(i, 1, n) sort(adj[i].begin(), adj[i].end());
}

void DFS(int u) {
    cout << u << " ";
    visited[u] = true;
    for(auto v: adj[u]) {
        if(!visited[v]) DFS(v);
    }
}

void Process(int root) {
    DFS(root);
}

void Output() {
    loop(i, 1, n) {
        if(!visited[i]) Process(i);
    }
}

int main() {
    // Do not put your code here
    if(!(FILE_NAME == "DEFAULT")) {
        InputFormFile(FILE_NAME);
        // OutputToFile(FILE_NAME);
        FAST(0);
    }
    Input(), Output();
    return 0;
}