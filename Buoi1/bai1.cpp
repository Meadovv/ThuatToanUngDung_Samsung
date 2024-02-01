#include <bits/stdc++.h>
using namespace std;

int main()
{

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    map<string, int> m;
    string s;
    while(cin >> s) {
        m[s]++;
    }
    for(map<string, int>::iterator p = m.begin(); p != m.end(); ++p) {
        cout << p->first << " " << p->second << "\n";
    }

    return 0;
}