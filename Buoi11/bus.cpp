#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

#define ii pair<int, int>

const int N = 5 * 1003;
int numNode, numEdge;
vector<ii> city;
vector<int> adj[N];
int ans = INT_MAX;

class State {
public:
    int node, cost, count;
    State(int _node, int _cost, int _count):
    node(_node), cost(_cost), count(_count) {}
};

void Input() {
    cin >> numNode >> numEdge;
    city.resize(numNode + 1);
    loop(i, 1, numNode) cin >> city[i].first >> city[i].second;
    loop(i, 1, numEdge) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void Process() {
    queue<State> q;
    q.push(State(1, city[1].first, city[1].second));
    while(!q.empty()) {
        cout << "A";
        State u = q.front();
        q.pop();
        if(u.node == numNode) {
            ans = min(ans, u.cost);
        }
        for(auto v: adj[u.node]) {
            if(v == u.node) continue;
            q.push(State(v, u.cost + city[v].first, city[v].second));
            if(!u.count) {
                q.push(State(v, u.cost, u.count - 1));
            }
        }
    }
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