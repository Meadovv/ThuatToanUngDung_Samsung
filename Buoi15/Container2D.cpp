#include <bits/stdc++.h>
#define loopEQ(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopNE(_i, a, b) for(int _i = a; _i < b; ++_i)
#define loopREQ(_i, a, b) for(int _i = a; _i >= b; --_i)
#define loopRNE(_i, a, b) for(int _i = a; _i > b; --_i)
#define ii pair<int,int>
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

struct Truck
{
    int W, L, c;

    Truck(int _W, int _L, int _c):
        W(_W), L(_L), c(_c) {}
    
    bool operator < (const Truck &other) const {
        if(W * L == other.W * other.L) return c < other.c;
        else return W * L > other.W * other.L;
    }
};

struct Pack
{
    int w, l;
    int idx, t, x, y, o;
    Pack(int _idx, int _w, int _l):
        idx(_idx), w(_w), l(_l) {
            t = x = y = o = 0;
        }
    bool operator < (const Pack &other) const {
        return w * l > other.w * other.l;
    }

    void printf() {
        cout << idx << " " << t << " " << x << " " << y << " " << o << '\n';
    }
};



const int N = 1000006;
int n, k;
vector<Truck> trucks;
vector<Pack> packs;
int truckIndex = 0;

void Input() {
    cin >> n >> k;
    loopEQ(i, 1, k) {
        int w, l;
        cin >> w >> l;
        packs.push_back(Pack(i, w, l));
    }
    loopEQ(i, 1, k) {
        int w, l, c;
        cin >> w >> l >> c;
        trucks.push_back(Truck(w, l, c));
    }
}

bool put(Pack pack, int truckIdx) {
    return true;
}

void Process() {
    sort(trucks.begin(), trucks.end());
    sort(packs.begin(), packs.end());
    for(Pack pack: packs) {
        if(!put(pack, truckIndex)) {
            truckIndex++;
        }
        else put(pack, truckIndex);
    }
}

void Output() {
    for(Pack pack: packs) {
        pack.printf();
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