#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai6" // Edit here
using namespace std;

const int N = 1000006;
int n, c, test, a[N], ans;

bool Check(int arr[], int mid, int n, int k) {
    int pos = arr[1];
    int numE = 1;
    loop(i, 2, n) {
        if(arr[i] - pos >= mid) {
            numE = numE + 1;
            pos = arr[i];
            if(numE == k) return true;
        }
    }

    return false;
}

void Process(int arr[], int n, int k) {
    int l = 1, r = arr[n];
    ans = INT_MIN;
    while(l < r) {
        int m = (l + r) / 2;
        if(Check(arr, m, n, k)) {
            ans = max(ans, m);
            l = m + 1;
        } else {
            r = m;
        }
    }
}

void Output() {
    cout << ans << "\n";
}

void Input() {
    cin >> test;
    while(test--) {
        cin >> n >> c;
        loop(i, 1, n) cin >> a[i];
        sort(a + 1, a + 1 + n);
        Process(a, n, c);
        Output();
    }
}

int main() {
    // Do not put your code here
    if(!(FILE_NAME == "DEFAULT")) {
        InputFormFile(FILE_NAME);
        // OutputToFile(FILE_NAME);
        FAST(0);
    }
    Input();
    return 0;
}