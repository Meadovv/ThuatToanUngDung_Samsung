#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 100005;

class Edge {
public: 
    int u, v, c;
    Edge(int _u, int _v, int _c):
    u(_u), v(_v), c(_c) {}
    bool operator < (const Edge &another) const {
        return c < another.c;
    }
};

int numNode, numEdge;
vector<Edge> edges;
int parent[N];

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return false;
    parent[v] = u;
    return true;
}

void Input() {
    cin >> numNode >> numEdge;
    loop(i, 1, numNode) parent[i] = i;
    loop(i, 1, numEdge) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
    }
}

int weight = 0;

void Process() {
    sort(edges.begin(), edges.end());
    for(auto edge: edges) {
        if(join(edge.u, edge.v)) weight += edge.c;
    }
}

void Output() {
    cout << weight;
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