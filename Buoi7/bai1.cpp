#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai1" // Edit here
using namespace std;

const int N = 1000006;
int n;
pair<int, int> a[N];
int ans = 0;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

void Input() {
    cin >> n;
    loop(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n, cmp);
}

void Process() {
    int last = -1;
    loop(i, 1, n) {
        if(last < a[i].first) {
            ans = ans + 1;
            last = a[i].second;
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