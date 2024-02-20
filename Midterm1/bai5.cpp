#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai5" // Edit here
using namespace std;

const int N = 1005;
int nRow, nCol;
int a[N][N];
int f[N][N];
int Left[N], Right[N];
int best = INT_MIN;

void Input() {
    cin >> nRow >> nCol;
    loop(row, 1, nRow) loop(col, 1, nCol) {
        cin >> a[row][col];
    }
}

void Process() {
    loop(row, 1, nRow) {

        // Init
        f[row][0] = -1, f[row][nCol + 1] = -1;

        // F Calculation
        loop(col, 1, nCol)
            if(a[row][col] == 1) f[row][col] = f[row - 1][col] + 1;
            else f[row][col] = 0;

        // Left Calculation
        loop(col, 1, nCol) {
            Left[col] = col;
            while(f[row][Left[col] - 1] >= f[row][col]) Left[col] = Left[Left[col] - 1]; 
        }

        // Right Calculation
        loopr(col, nCol, 1) {
            Right[col] = col;
            while(f[row][Right[col] + 1] >= f[row][col]) Right[col] = Right[Right[col] + 1];
        }

        // Get best in row 1 -> i
        loop(col, 1, nCol) best = max(best, f[row][col] * (Right[col] - Left[col] + 1));
    }
}

void Output() {
    cout << best;
}

int main() {
    // Do not put your code here
    if(!(FILE_NAME == "DEFAULT")) {
        InputFormFile(FILE_NAME);
        //OutputToFile(FILE_NAME);
        FAST(0);
    }
    Input(), Process(), Output();
    return 0;
}