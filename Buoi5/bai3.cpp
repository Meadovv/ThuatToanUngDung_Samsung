
// m[i][0] la day con co tong lon nhat tu 1 toi i va khong chua ai
// m[i][1] la day con co tong lon nhat tu 1 toi i va co chua ai

// m[i][0] = max(m[i-1][0], m[i-1][1])
// m[i][1] = max(m[i-1][1] + a[i], a[i])

#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai3" // Edit here
using namespace std;

const int N = 1000006;
long long n, a[N], evenSum[N], oddSum[N], validEvenSum[N], validOddSum[N];
long long ans = INT_MIN;

void Input() {
    cin >> n;
    loop(i, 1, n) cin >> a[i];
}

void Process() {
    loop(i, 1, n) {
        if(a[i] % 2 == 0) {
            if(validEvenSum[i - 1] && evenSum[i-1] > 0) evenSum[i] = evenSum[i-1] + a[i];
            else evenSum[i] = a[i];
            validEvenSum[i] = true;

            if(validOddSum[i - 1]) oddSum[i] = oddSum[i - 1] + a[i], validOddSum[i] = true;
            else validOddSum[i] = false;
        } else {
            if(validOddSum[i - 1]) evenSum[i] = oddSum[i - 1] + a[i], validEvenSum[i] = true;
            else validEvenSum[i] = false;

            if(validEvenSum[i - 1] && evenSum[i - 1] > 0) oddSum[i] = evenSum[i - 1]  + a[i];
            else oddSum[i] = a[i];
            validOddSum[i] = true;
        }
    }
}

void Output() {
    loop(i, 1, n) ans = max(ans, evenSum[i]);

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