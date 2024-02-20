#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define ii pair<int,int>
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 2000006;
const long long mod = 1e9 + 7;
long long a[N], n, ans = 0;
int b[N];
vector<long long> st;

void Input() {
    cin >> n;
    loop(i, 1, n) cin >> a[i];
    loop(i, 1, n - 1) cin >> b[i];
    b[0] = 1;
}

void Process() {
    loop(i, 1, n) {
        if(b[i - 1] == 2) {
            long long last = st.back();
            st.pop_back();
            last = (1LL * last * a[i]) % mod;
            st.push_back(last);
        } else st.push_back((b[i - 1] == 1 ? 1LL * a[i] : 1LL * a[i] * -1));
    }
}

void Output() {
    for(auto v: st) ans = (ans + v) % mod;
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