#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 1000006;
int numNode, numEdge;
vector<int> dist, d, adj[N];
int visited[N];

void Input() {
    cin >> numNode >> numEdge;
    dist.resize(numNode + 1, 0);
    d.resize(numNode + 1, 0);
    loop(i, 1, numNode) cin >> d[i];
    loop(i, 1, numEdge) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

void DFS(int u) {
    visited[u] = true;
    dist[u] = d[u];
    for(auto v: adj[u]) {
        if(!visited[v]) DFS(v);
        dist[u] = max(dist[u], d[u] + dist[v]);
    }
}

void Process() {
    loop(i, 1, numNode) {
        if(!visited[i]) DFS(i);
    }
}

void Output() {        
    for(auto v: dist) cout << v << " ";
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