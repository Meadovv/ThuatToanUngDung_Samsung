#include <bits/stdc++.h>
using namespace std;

int n, k, a[100005], ans;

int main() {

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    for(int i = k; i <= n; ++i) {
        if((a[i] - a[i - k]) % 2 == 0) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}