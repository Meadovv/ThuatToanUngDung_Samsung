#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define ii pair<int,int>
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 1000006;

class SegmentTree {
private:
    int tree[2 * N];
    int n;

    void buildTree(int nums[], int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(nums, 2 * node + 1, start, mid);
            buildTree(nums, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void updateTree(int node, int start, int end, int i, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (i <= mid) {
                updateTree(2 * node + 1, start, mid, i, val);
            } else {
                updateTree(2 * node + 2, mid + 1, end, i, val);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int queryTree(int node, int start, int end, int left, int right) {
        if (start > right || end < left) {
            return 0;
        } else if (start >= left && end <= right) {
            return tree[node];
        } else {
            int mid = (start + end) / 2;
            int leftNode = queryTree(2 * node + 1, start, mid, left, right);
            int rightNode = queryTree(2 * node + 2, mid + 1, end, left, right);
            return max(leftNode, rightNode);
        }
    }

public:
    SegmentTree() {}

    void build(int arr[], int n) {
        this->n = n;
        buildTree(arr, 0, 0, n - 1);
    }

    void update(int i, int val) {
        updateTree(0, 0, n - 1, i, val);
    }

    int query(int left, int right) {
        return queryTree(0, 0, n - 1, left, right);
    }
};

SegmentTree st;
int n, q, a[N];
string type;

void Input() {
    cin >> n;
    loop(i, 1, n) cin >> a[i];
    st.build(a, n);
}

void Process() {
    cin >> q;
    while(q--) {
        cin >> type;
        if(type == "update") {
            int x, val;
            cin >> x >> val;
            st.update(x, val);
        } else {
            int x, y;
            cin >> x >> y;
            cout << st.query(x, y) << "\n";
        }
    }
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