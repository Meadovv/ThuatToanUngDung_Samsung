#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai2" // Edit here
using namespace std;

const int N = 1000006;
int n, ans = 0;
pair<int, int> a[N];
int dd[N];

void Input() {
    cin >> n;
    loop(i, 1, n) cin >> a[i].first >> a[i].second;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

void Process() {
    sort(a + 1, a + 1 + n, cmp);
    loop(i, 1, n) {
        loopr(j, a[i].first - 1, 0) {
            if(!dd[j]) {
                dd[j] = 1;
                ans = ans + a[i].second;
                break;
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