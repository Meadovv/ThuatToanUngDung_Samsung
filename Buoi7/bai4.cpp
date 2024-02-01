#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai4" // Edit here
using namespace std;

const int N = 1000006;
const unsigned long long mod = 1000000007;
unsigned long long a, b;

void Input() {
    cin >> a >> b;
}

unsigned long long Pow(unsigned long long n, unsigned long long k) {
    if(k == 0) return 1;
    if(k == 1) return n;
    unsigned long long temp = Pow(n, k/2) % mod;

    if(k % 2) return ((temp * temp) % mod * n) % mod;
    else return (temp * temp) % mod;
}

void Process() {

}

void Output() {
    cout << Pow(a % mod, b);
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