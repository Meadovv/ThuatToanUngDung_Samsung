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
const int mod = 1e9 + 7;
map<int, int> dd;
int n, ans = 0, x;

void Input() {
    cin >> n;
    loop(i, 1, n) {
        cin >> x;
        ans = (ans + dd[x + 1]) % mod;
        ans = (ans + dd[x - 1]) % mod;
        dd[x] += 1;
    }
}

void Process() {

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