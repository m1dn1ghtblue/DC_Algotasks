#include <iostream>
#include <vector>
 
using namespace std;
 
vector <int> v;
 
bool isheap(int n) {
    for (int i = 0; i < n; i++) {
        if (((i * 2) + 1 < n) && (v[i] > v[(i * 2) + 1]))
            return false;
        if (((i * 2) + 2 < n) && (v[i] > v[(i * 2) + 2]))
            return false;
    }
    return true;
}
int main(){
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << (isheap(n) ? "YES" : "NO");
 
    return 0;
}