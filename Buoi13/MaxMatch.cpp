#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

#define ii pair<int, int>

const int N = 1000006;
int numTask, numStaff;

vector<ii> adj[N];
vector<int> solution; // solution[i] = j: i is matched to j in solution

void Input() {
    cin >> numTask >> numStaff;
    loop(i, 1, numTask) {
        int taskStaffs; cin >> taskStaffs;
        loop(j, 1, taskStaffs) {
            int taskStaff; cin >> taskStaff;
            adj[i].push_back(ii(1, taskStaff + numTask));
        }
    }

    solution.resize(numTask + numStaff + 2, -1);
}

void Process() {
    for(auto v: solution) cout << v << " ";
}

void Output() {

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