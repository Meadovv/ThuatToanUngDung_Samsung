#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 1003;

int n, m;
int x[N], position[N];
int graph[N][N];
int ans = 0;

void Input() {
    cin >> n;
    loop(i, 1, n) {
        cin >> x[i];
        position[x[i]] = i;
    }
    loop(i, 1, n) loop(j, 1, n) cin >> graph[i][j];
    cin >> m;
    loop(i, 1, m) {
        int x, y;
        cin >> x >> y;
        if(position[x] > position[y]) {
            cout << -1;
            exit(0);
        }
    }
}

void Process() {
    x[n + 1] = x[1];
    loop(i, 1, n) {
        ans = ans + graph[x[i]][x[i + 1]];
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