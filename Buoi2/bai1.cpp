#include <bits/stdc++.h>
using namespace std;

int n;
long long sum, x;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        sum += x;
    }
    cout << sum;
    return 0;
}