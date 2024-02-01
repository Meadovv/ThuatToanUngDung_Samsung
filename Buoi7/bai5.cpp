#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "bai5" // Edit here
using namespace std;

const int N = 1000006;
const int mod = 1000000007;
int n, a[N];

void Input() {
    cin >> n;
    loop(i, 1, n) cin >> a[i];
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = (inv_count + (mid - i) % mod) % mod;
        }
    }
 
    // Copy the remaining elements of left subarray
    // (if there are any) to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    // Copy the remaining elements of right subarray
    // (if there are any) to temp
    while (j <= right)
        temp[k++] = arr[j++];
 
    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

int _mergeSort(int arr[], int temp[], int l, int r) {
    int m, inv_count = 0;
    if(l < r) {
        m = (l + r) / 2;
        inv_count = (inv_count + _mergeSort(arr, temp, l, m)) % mod;
        inv_count = (inv_count + _mergeSort(arr, temp, m + 1, r)) % mod;

        inv_count = (inv_count + merge(arr, temp, l, m + 1, r)) % mod;
    }

    return inv_count;
}

int mergeSort(int arr[], int size) {
    int temp[size + 1];
    return _mergeSort(arr, temp, 1, size);
}

void Process() {

}

void Output() {
    cout << mergeSort(a, n);
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