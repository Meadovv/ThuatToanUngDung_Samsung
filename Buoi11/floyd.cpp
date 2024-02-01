#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 10004;
const int MAX = 1000006;
int numNode, numEdge;
int matrix[N][N];

void Input() {
    cin >> numNode >> numEdge;
    loop(i, 1, numNode) {
        loop(j, 1, numNode) {
            if(i == j) matrix[i][j] = 0;
            else matrix[i][j] = MAX;
        }
    }
    loop(i, 1, numEdge) {
        int u, v, c;
        cin >> u >> v >> c;
        matrix[u][v] = c;
    }
}

void Process() {
    loop(k, 1, numNode)
        loop(i, 1, numNode)
            loop(j, 1, numNode) {
                if(matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
}

void Output() {
    loop(i, 1, numNode) {
        loop(j, 1, numNode) {
            if(matrix[i][j] < MAX) cout << matrix[i][j];
            else cout << -1;
            cout << " ";
        }
        cout << "\n";
    }
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