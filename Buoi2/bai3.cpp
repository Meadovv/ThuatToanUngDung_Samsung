#include <bits/stdc++.h>
using namespace std;

float oldPrice[] = {1728, 1786, 2074, 2612, 2919, 3015};
float newPrice[] = {1728, 2074, 2612, 3111, 3457};

float oldCalculation(float x) {
    if(x <= 50) 
        return x * oldPrice[0];
    if(x <= 100) 
        return 50 * oldPrice[0] + (x - 50) * oldPrice[1];
    if(x <= 200)
        return 50 * oldPrice[0] + 50 * oldPrice[1] + (x - 100) * oldPrice[2];
    if(x <= 300)
        return 50 * oldPrice[0] + 50 * oldPrice[1] + 100 * oldPrice[2] + (x - 200) * oldPrice[3];
    if(x <= 400)
        return 50 * oldPrice[0] + 50 * oldPrice[1] + 100 * oldPrice[2] + 100 * oldPrice[3] + (x - 300) * oldPrice[4];
    
    return 50 * oldPrice[0] + 50 * oldPrice[1] + 100 * oldPrice[2] + 100 * oldPrice[3] + 100 * oldPrice[4] + (x - 400) * oldPrice[5];
}

float newCalculation(float x) {
    if(x <= 100) 
        return x * newPrice[0];
    if(x <= 200) 
        return 100 * newPrice[0] + (x - 100) * newPrice[1];
    if(x <= 400)
        return 100 * newPrice[0] + 100 * newPrice[1] + (x - 200) * newPrice[2];
    if(x <= 700)
        return 100 * newPrice[0] + 100 * newPrice[1] + 200 * newPrice[2] + (x - 400) * newPrice[3];
    
    return 100 * newPrice[0] + 100 * newPrice[1] + 200 * newPrice[2] + 300 * newPrice[3] + (x - 700) * newPrice[4];
}


int main() {
    float x;
    cin >> x;
    cout << fixed << setprecision(2) << (newCalculation(x) - oldCalculation(x)) * 1.1;
    return 0;
}