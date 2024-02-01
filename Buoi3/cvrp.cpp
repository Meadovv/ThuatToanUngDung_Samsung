#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "cvrp" // Edit here
using namespace std;

const int N = 50;
int nClient, nTruck, truckCapacity;
int request[N]; // request[i] = x mean client i request x packages 
int c[N][N]; // c[i][j] = x mean distance client i from client j is x
int Start[N]; // Start[i] = x mean truck i is Start from x client
int Next[N]; // Next[i] = j mean Next client from client i is client j in solution
int load[N]; // load[i] = x mean truck i is current carrying x packages
bool visited[N]; // visited[i] = true mean client i is visited
int curTrip; // curTrip = n + k => solution
int ans = INT_MAX, Cmin = INT_MAX, curAns = 0;

// Solution
// 1. Generate Start array to K truck
// 2. Generate Next array mean K truck trip

void Input() {

    Next[0] = -1;

    cin >> nClient >> nTruck >> truckCapacity;
    loop(i, 1, nClient) {
        cin >> request[i];
    }

    loop(i, 0, nClient) {
        loop(j, 0, nClient) {
            cin >> c[i][j];
            if(i != j) Cmin = min(Cmin, c[i][j]);
        }
    }
}

bool CheckStart(int curTruck, int client) {
    if(visited[client] && client != 0) return false;
    return true;
}

bool CheckNext(int curTruck, int client) {
    if(visited[client] && client != 0) return false;
    if(load[curTruck] + request[client] > truckCapacity) return false;
    return true;
}

void Solution() {
    if(curTrip != nClient + nTruck) return;
    
    int curAns = 0;

    loop(truck, 1, nTruck) {
        int curPos = Start[truck];
        curAns = curAns + c[0][Start[truck]];
        while (Next[curPos] != -1)
        {
            curAns = curAns + c[curPos][Next[curPos]];
            curPos = Next[curPos];
        }
    }

    ans = min(ans, curAns);

    // loop(truck, 1, nTruck) {
    //     cout << "Xe " << truck << " : " << Start[truck] << " ";
    //     int curPos = Start[truck];
    //     while(Next[curPos] != -1) {
    //         cout << Next[curPos] << " ";
    //         curPos = Next[curPos];
    //     }
    //     cout << "\n";
    // }
    // cout << curAns << "\n";
    // cout << "-----------------------------------------\n";
}

void TryNext(int curClient, int curTruck) {
    if(curClient == 0) {
        if(curTruck == nTruck) return;
        TryNext(Start[curTruck + 1], curTruck + 1);
        return;
    }
    loop(client, 0, nClient) {
        if(!CheckNext(curTruck, client)) continue;
        visited[client] = true;
        Next[curClient] = client;
        load[curTruck] = load[curTruck] + request[client];
        curAns = curAns + c[curClient][Next[curClient]];
        curTrip = curTrip + 1;
        if(client == 0) {
            if(curTruck == nTruck) Solution();
            else if(curAns + Cmin * (nClient + nTruck - curTrip) <= ans) TryNext(Start[curTruck + 1], curTruck + 1);
        } else {
            if(curAns + Cmin * (nClient + nTruck - curTrip) <= ans) TryNext(client, curTruck);
        }
        visited[client] = false;
        load[curTruck] = load[curTruck] - request[client];
        curAns = curAns - c[curClient][Next[curClient]];
        curTrip = curTrip - 1;
    }
}

void Print() {
    loop(truck, 1, nTruck) {
        cout << Start[truck] << " ";
    }
    cout << "\n";
}

int count = 0;

void TryStart(int curTruck) {
    loop(client, Start[curTruck - 1], nClient) {
        if(!CheckStart(curTruck, client)) continue;
        visited[client] = true;
        Start[curTruck] = client;
        load[curTruck] = load[curTruck] + request[client];
        curAns = curAns + c[0][Start[curTruck]];
        curTrip = curTrip + 1;
        if(curTruck == nTruck) TryNext(Start[1], 1);
        else TryStart(curTruck + 1);
        load[curTruck] = load[curTruck] - request[client];
        curAns = curAns - c[0][Start[curTruck]];
        visited[client] = false;
        curTrip = curTrip - 1;
    }
}

void Process() {
    TryStart(1);
}

void Output() {
    cout << ans;
}

int main() {
    // Do not put your code here
    if(!(FILE_NAME == "DEFAULT")) {
        InputFormFile(FILE_NAME);
        // OutputToFile(FILE_NAME);
        FAST(0);
    }
    Input();
    Process();
    Output();
    return 0;
}