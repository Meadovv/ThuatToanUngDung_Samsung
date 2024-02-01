
// Given n sequence of n integers a(0), a(1),..., a(N)
// rmq(i, j) is minimum element of the sequence a(i), a(i+1),..., a(j)

// Array M[log2(n)][n] which m[i][j] is index of minimum element in sequence start at a(j) and have length is 2^(i)

// Next Step is calculate Array M
// m[i][j] = min(m[i-1][j], m[i-1][j + 2^(i-1)])
// Initiation: m[0][j] = a[j]

// k = log2(r - l + 1)
// Then rmq(r, l) = min(m[k][l], m[k][r - (1 << k) + 1])

#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai1" // Edit here
using namespace std;

const int N = 1000006;

int n, a[N], q;
int m[20][N];

void Input() {
    scanf("%d", &n);
    loop(i, 1, n) scanf("%d", &a[i]);
}

int rmq(int l, int r) {
    int k = __lg(r - l + 1);
    return min(m[k][l], m[k][r - (1 << k) + 1]);
}

void Process() {

    memset(m, -1, sizeof(m));
    loop(i, 1, n) m[0][i] = a[i];

    for(int i = 1; (1 << i) <= n; ++i) {
        for(int j = 1; j + (1 << i) - 1 <= n; ++j) {
            m[i][j] = min(m[i-1][j], m[i-1][j + (1 << (i - 1))]);
        }
    }
}

void Output() {
    int ans = 0, l, r;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &l, &r);
        ans = ans + rmq(l + 1, r + 1);
    }   

    printf("%d", ans);
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