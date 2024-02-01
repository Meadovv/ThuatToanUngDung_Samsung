#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai2" // Edit here
using namespace std;

const int N = 20;
const int M = 10;

int load[M];
int course[N];
int a[N][N];
int nCourse, nPeriod;
int credit[N];
int curLoad = 0;
int best = INT_MAX;

void Input() {
    cin >> nCourse >> nPeriod;
    loop(i, 1, nCourse) cin >> credit[i];
    loop(i, 1, nCourse) loop(j, 1, nCourse) cin >> a[i][j];
}

bool Check(int period, int curCourse) {
    loop(i, 1, nCourse) {
        if(a[i][curCourse] && course[i] == period) return false;
    }
    return true;
}

void Solution () {
    int curAns = INT_MIN;
    loop(period, 1, nPeriod) {
        curAns = max(curAns, load[period]);
    }
    best = min(best, curAns);
}

void Try(int curCourse) {
    loop(period, 1, nPeriod) {
        if(Check(period, curCourse)) {
            course[curCourse] = period;
            load[period] = load[period] + credit[curCourse];
            if(curCourse == nCourse) Solution();
            else {
                if(load[period] <= best) Try(curCourse + 1);
            }
            load[period] = load[period] - credit[curCourse];
        }
    }
}

void Process() {
    Try(1);
}

void Output() {
    cout << best;
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