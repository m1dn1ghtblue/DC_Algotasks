#include <iostream>
#include <vector>
#define int32 __int32
using namespace std;
 
vector <int32> v;
 
int partition(int left, int right){
    int32 key = v[(left+right)/2];
    int l = left, r = right;
    while (l <= r){
        while (v[l] < key) l++;
        while (v[r] > key) r--;
        if(l >= r) break;
        swap(v[l], v[r]);
        l++;
        r--;
    }
 
    return r;
}
 
void qsort (int left, int right, int k){
    if (left >= right) return;
 
    int q = partition(left, right);
 
    if (q >= k) qsort(left, q, k);
    else qsort(q+1, right, k);
}
 
int main(){
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
 
    int n, k;
    cin >> n >> k;
    v.resize(2);
    int32 A, B, C;
    cin >> A >> B >> C >> v[0] >> v[1];
    for (int i = 2; i < n; i++){
        v.push_back(A*v[i-2] + B*v[i-1] + C);
    }
 
    qsort(0, n-1, k-1);
    cout << v[k-1];
 
    return 0;
}