#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define ii pair<int,int>
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 1003;
int n, m, a[N][N], q;

void Input() {
    cin >> n >> m;
    loop(i, 1, n) {
        loop(j, 1, m) {
            cin >> a[i][j];
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    cin >> q;
    loop(i, 1, q) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        cout << a[x][y] - a[u-1][y] - a[x][v-1] + a[u-1][v-1] << '\n';
    }
}

void Process() {

}

void Output() {

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