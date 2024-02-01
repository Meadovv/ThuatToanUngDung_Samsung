#include <bits/stdc++.h>
using namespace std;

int n, a[100005], odd;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i] % 2 == 1) odd++;
    }
    cout << odd << " " << n - odd;
    return 0;
}