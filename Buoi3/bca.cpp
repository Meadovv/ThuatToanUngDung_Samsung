#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bca" // Edit here
using namespace std;

const int N = 50;
int n, m;
vector<int> course[N]; // course[i] is an arr include teacher can teach course i
int conflict[N][N]; // conflict[i][j] = true mean course i and course j are conflict
int load[N]; // load[i] = j mean teacher i teaching j courses
int x[N]; // solution. x[i] = j mean course i is teach by teacher j
int ans = INT_MAX;



void Input() {
    cin >> m >> n;
    loop(i, 1, m) {
        int k; cin >> k;
        loop(j, 1, k) {
            int x; cin >> x;
            course[x].push_back(i);
        }
    }
    
    int nConflict; cin >> nConflict;
    loop(i, 1, nConflict) {
        int x, y;
        cin >> x >> y;
        conflict[x][y] = conflict[y][x] = 1;
    }
}

bool Check(int curCourse, int teacher) {
    loop(i, 1, curCourse - 1) {
        if(conflict[curCourse][i] && x[i] == teacher) return false;
    }
    return true;
}

void Solution() {
    int curAns = INT_MIN;
    loop(teacher, 1, m) {
        curAns = max(curAns, load[teacher]);
    }
    ans = min(ans, curAns);
}

void Try(int curCourse) {
    for(auto teacher: course[curCourse]) {
        if(!Check(curCourse, teacher)) continue;
        load[teacher] = load[teacher] + 1;
        x[curCourse] = teacher;
        if(curCourse == n) Solution();
        else {
            if(load[teacher] <= ans) Try(curCourse + 1);
        }
        load[teacher] = load[teacher] - 1;
    }
}

void Process() {
    Try(1);
}

void Output() {
    cout << ans;
}

int main() {
    // Do not put your code here
    if(!(FILE_NAME == "DEFAULT")) {InputFormFile(FILE_NAME), OutputToFile(FILE_NAME), FAST(0);}
    Input(), Process(), Output();
    return 0;
}