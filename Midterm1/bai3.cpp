#include <bits/stdc++.h>
#define loop(_i, a, b) for (int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for (int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name ".input", "r", stdin)
#define OutputToFile(name) freopen(name ".output", "w", stdout)
#define FAST(a)                   \
    ios_base::sync_with_stdio(a); \
    cin.tie(a);                   \
    cout.tie(a);
#define FILE_NAME "bai3" // Edit here
using namespace std;

class PriorityQueue
{
private:
    int size;
    int pq[1000006];

    void max_heap(int node)
    {
        int largest;
        int left = 2 * node;
        int right = 2 * node + 1;
        if (left <= size and pq[left] > pq[node])
            largest = left;
        else
            largest = node;
        if (right <= size and pq[right] > pq[largest])
            largest = right;
        if (largest != node)
        {
            swap(pq[node], pq[largest]);
            max_heap(largest);
        }
    }

public:
    PriorityQueue()
    {
        size = 0;
    }

    void push_element(int x)
    {
        size = size + 1;
        int cur = size;
        pq[cur] = x;
        while (cur > 1 && pq[cur / 2] < pq[cur])
        {
            swap(pq[cur / 2], pq[cur]);
            cur = cur / 2;
        }
    }

    int pop_element()
    {
        int max = pq[1];
        pq[1] = pq[size];
        size = size - 1;
        max_heap(1);
        return max;
    }
};

char type[4];
int x, ans;

PriorityQueue pq = PriorityQueue();

void Input()
{

}

void Process() {
    while(true) {
        scanf("%s", &type);
        if(type[0] == '#') {
            break;
        } else {
            if(type[1] == 'U') {
                scanf("%d", &x);
                if(x == 0) {
                    pq.push_element(1);
                } else {
                    pq.push_element(-x);
                }
            } else {
                int ans = pq.pop_element();
                if(ans == 1) {
                    ans = 0;
                } else {
                    ans = ans * -1;
                }
                printf("%d\n", ans);
            }
        }
    }
}

void Output()
{

}

int main()
{
    // Do not put your code here
    if (!(FILE_NAME == "DEFAULT"))
    {
        InputFormFile(FILE_NAME);
        // OutputToFile(FILE_NAME);
    }
    FAST(0);
    Input(), Process(), Output();
    return 0;
}