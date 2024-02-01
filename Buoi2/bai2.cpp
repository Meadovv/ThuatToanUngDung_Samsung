#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    for(int i = 100 / n; ; ++i) {
        ans = i * n;
        if(ans >= 100 && ans <= 999) {
            cout << i * n << " ";
        }
        if(ans > 999) {
            break;
        }
    }
    return 0;
}