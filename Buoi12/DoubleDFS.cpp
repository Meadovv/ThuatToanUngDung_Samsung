#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

#define ii pair<int, int>

const int N = 1000006;
const int MAX = 1000000;

int d[N];
int numNode, numEdge;
vector<ii> adj[N];

void Input() {
    cin >> numNode;
    loop(i, 1, numNode - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }
}

void DFS(int u, int par) {
    for(auto v: adj[u]) {
        if(v.first == par) continue;
        d[v.first] = d[u] + v.second;
        DFS(v.first, u);
    }
}

int FindPath(int root) {
    d[root] = 0;
    DFS(root, 0);
    
    int vMax = -MAX, iMax;

    loop(i, 1, numNode) {
        if(d[i] > vMax) {
            iMax = i;
            vMax = d[i];
        }
    }

    return iMax;
}
void Process() {

}

void Output() {
    cout << d[FindPath(FindPath(1))];
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