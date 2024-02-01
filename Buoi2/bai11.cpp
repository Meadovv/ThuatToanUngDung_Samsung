#include <bits/stdc++.h>
using namespace std;

int n, a[10004], Max = -1001, Min = 1001, Sum = 0;

int main() {

    freopen("input.txt", "r", stdin);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
        Sum = Sum + a[i];
    }

    string query;
    int x, y;

    while (cin >> query)
    {
        if(query == "*") continue;
        if(query == "***") return 0;
        if(query == "find-max") {
            cout << Max;
        }
        if(query == "find-min") {
            cout << Min;
        }
        if(query == "sum") {
            cout << Sum;
        }
        if(query == "find-max-segment") {
            cin >> x >> y;
            int m = -1001;
            for(int i = x; i <= y; ++i) {
                m = max(m, a[i]);
            }
            cout << m;
        }
        if(query == "find-min-segment") {
            cin >> x >> y;
            int m = 1001;
            for(int i = x; i <= y; ++i) {
                m = min(m, a[i]);
            }
            cout << m;
        }
        cout << "\n";
    }
    


    return 0;
}