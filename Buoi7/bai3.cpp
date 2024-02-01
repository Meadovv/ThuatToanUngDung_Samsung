#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai3" // Edit here
using namespace std;

const int N = 1006;
int n;

struct edge {
    int u, v, c;
    edge(int _u, int _v, int _c): u(_u), v(_v), c(_c) {}

    void printf() {
        cout << u << " " << v << " " << c << "\n";
    }
};

vector<edge> e;

void Input() {
    cin >> n;
    loop(i, 1, n) {
        loop(j, 1, n) {
            int c; cin >> c;
            e.push_back(edge(i, j, c));
        }
    }
}

void Process() {
    sort(e.begin(), e.end(), [](edge a, edge b) {
        return a.c < b.c;
    });
}

void Output() {
    for(auto v: e) v.printf();
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