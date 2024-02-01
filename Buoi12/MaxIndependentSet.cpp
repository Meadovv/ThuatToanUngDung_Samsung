#include <bits/stdc++.h>
#define ii pair<int,int>
#define ll long long
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 100002;
int n;
int dp0[N]; // dp0[i] = max independent set in subtree of i, i is not chosen
int dp1[N]; // dp1[i] = max independent set in subtree of i, i is chosen
int par[N]; // par[i] = parent of i
vector<int> adj[N];
int weight[N];
vector<int> child[N]; // child[i] = list of children of i by DFS order
int ans;

void DFS(int u) {
    for(auto v: adj[u]) {
        if(v == par[u]) continue;
        par[v] = u;
        child[u].push_back(v);
        DFS(v);
    }
}

void solve(int u) {
    for(auto v: child[u]) solve(v);
    dp0[u] = 0;
    dp1[u] = weight[u];
    for(auto v: child[u]) {
        dp0[u] += max(dp0[v], dp1[v]);
        dp1[u] += dp0[v];
    }
    ans = max(ans, max(dp0[u], dp1[u]));
}

void Input() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> weight[i];
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void Process() {
    DFS(1);
    solve(1);
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