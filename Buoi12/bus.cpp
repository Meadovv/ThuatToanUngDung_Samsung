#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

#define ii pair<int, int>

const int N = 5003;
const int MAX = 1000000;

ii cities[N];
vector<int> adj[N];
vector<ii> newAdj[N];
int road[N][N];
int numNode, numEdge;
int level[N];
int dist[N];

void Input() {
    scanf("%d%d", &numNode, &numEdge);
    loop(i, 1, numNode) {
        int price, maxDist;
        scanf("%d%d", &price, &maxDist);
        cities[i] = ii(price, maxDist);
    }
    loop(i, 1, numEdge) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void BFS(int root) {
    loop(i, 1, numNode) level[i] = -1;
    queue<int> q;
    level[root] = 0;
    q.push(root);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v: adj[u]) {
            if(level[v] == -1 && level[u] < cities[root].second) {
                q.push(v);
                level[v] = level[u] + 1;
                road[root][v] = cities[root].first;
            }
        }
    }
}

void prepareRoad() {
    loop(i, 1, numNode) {
        loop(j, 1, numNode) road[i][j] = MAX;
        road[i][i] = 0;
    }

    loop(i, 1, numNode) BFS(i);
}

void Process() {

    prepareRoad();

    loop(i, 1, numNode) loop(j, 1, numNode)
    if(road[i][j] != MAX && i != j) newAdj[i].push_back(ii(road[i][j], j));

    loop(i, 1, numNode) dist[i] = MAX;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[1] = 0;
    pq.push(ii(dist[1], 1));
    while(!pq.empty()) {
        ii u = pq.top();
        pq.pop();
        if(dist[u.second] != u.first) continue;
        for(auto v: newAdj[u.second]) {
            if(dist[v.second] > dist[u.second] + v.first) {
                dist[v.second] = dist[u.second] + v.first;
                pq.push(ii(dist[v.second], v.second));
            }
        }
    }
}

void Output() {
    printf("%d", dist[numNode]);
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