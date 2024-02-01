#include <bits/stdc++.h>
using namespace std;

float a, b, c, x1, x2;

int main() {

    cin >> a >> b >> c;

    float delta = b * b - 4 * a * c;
    
    if(delta < 0) {
        cout << "NO SOLUTION";
    } else {
        if(delta == 0) {
            cout << fixed << setprecision(2) << (-b / (2 * a));
        } else {
            float x1 = ((-b + sqrt(delta)) / (2 * a));
            float x2 = ((-b - sqrt(delta)) / (2 * a));
            cout << fixed << setprecision(2) << min(x1, x2) << " " << max(x1, x2);
        }
    }
    
    return 0;
}