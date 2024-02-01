#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define ii pair<int,int>
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 100005;
vector<ii> adj[N];
int numNode;

int d[N], f[N], parent[N], num[N];
// d[u] is the sum of weights of path from descendant of u to u
// f[u] is the sum of weight of path from other nodes to u
// parent[u] is the parent of u
// num[u] is the number of descendant (inclusive) of u

void Input() {
    cin >> numNode;
    loop(i, 1, numNode) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(ii(c, v));
        adj[v].push_back(ii(c, u));
    }
}

void DFS1(int u) {
    for(auto v: adj[u]) {
        if(parent[v.second] == 0) {
            parent[v.second] = u;
            DFS1(v.second);
            d[u] = d[u] + d[v.second] + (num[v.second] * v.first);
            num[u] = num[u] + num[v.second];
        }
    }
}

void solvePhase1() {
    loop(i, 1, numNode) {
        f[i] = d[i] = parent[i] = 0;
        num[i] = 1;
    }
    parent[1] = 1;
    DFS1(1);
}

void DFS2(int u) {
    for(auto v: adj[u]) {
        if(parent[v.second] == 0) {
            parent[v.second] = u;
            int F = f[u] - (d[v.second] + v.first * num[v.second]);
            f[v.second] = d[v.second] + F + (numNode - num[v.second]) * v.first;
            DFS2(v.second);
        }
    }
}

void solvePhase2() {
    loop(i, 1, numNode) {
        parent[i] = 0;
    }
    f[1] = d[1];
    parent[1] = 1;
    DFS2(1);
}

void Process() {
    solvePhase1();
    solvePhase2();
}

void Output() {
    cout << *max_element(f + 1, f + 1 + numNode);
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