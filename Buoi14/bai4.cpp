#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define ii pair<int,int>
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 1000006;
int ans = INT_MIN;
int n, q, a[N];

void Input() {
    cin >> n >> q;
    loop(i, 1, n) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
}

bool Check(int x) {
    bool flag = false;
    loop(i, x, n) {
        if(a[i] - a[i - x] <= q) {
            flag = true;
            break;
        }
    }

    return flag;
}

void Process() {
    int l = 1, r = n;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(Check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
}

void Output() {
    if(ans==INT_MIN) cout << "-1";
    else cout << ans;
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