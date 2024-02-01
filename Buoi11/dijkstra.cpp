#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

#define ii pair<int, int>

const int N = 100005;
int numNode, numEdge, source, sink;
vector<ii> adj[N];
int dist[N];
int parent[N];

void Input() {
    cin >> numNode >> numEdge;
    loop(i, 1, numEdge) {
    	int u, v, c;
    	cin >> u >> v >> c;
    	adj[u].push_back(ii(c, v));
    }
    cin >> source >> sink;
    loop(i, 1, numNode) dist[i] = (i == source ? 0 : INT_MAX);
}

void Process() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(dist[source], source));
    while(!pq.empty()) {
        ii u = pq.top();
        pq.pop();
        if(u.first == sink) return;
        if(u.first != dist[u.second]) continue;
        for(auto v: adj[u.second]) {
            if(dist[v.second] > u.first + v.first) {
                dist[v.second] = u.first + v.first;
                parent[v.second] = u.second;
                pq.push(ii(dist[v.second], v.second));
            }
        }
    }
}

void Output() {
    cout << dist[sink];
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