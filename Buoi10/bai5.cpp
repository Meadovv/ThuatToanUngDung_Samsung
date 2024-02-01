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
int num[N]; // thứ tự thăm u
int low[N]; // thứ tự thăm nhỏ nhất mà từ u có thể đến được trong nhánh DFS của u, ban đầu low[u] = num[u]
int visitTime = 0;
stack<int> vertex;
int isDelete[N];
int numStronglyConnectedComponent = 0;

void Input() {
    cin >> n >> m;
    while(m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void Tarjan(int u) {
    vertex.push(u);
    num[u] = low[u] = visitTime++;
    for(auto v: adj[u]) {
        if(isDelete[v]) continue;
        if(num[v]) low[u] = min(low[u], num[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == num[u]) {
        numStronglyConnectedComponent++;
        int v;
        do {
            v = vertex.top();
            vertex.pop();
            isDelete[v] = true;
        } while (v != u);
    }
}

void Process() {
    loop(i, 1, n)
    if(!num[i]) Tarjan(i);
}

void Output() {
    cout << numStronglyConnectedComponent;
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