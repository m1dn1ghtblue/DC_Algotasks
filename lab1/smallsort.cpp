#include <iostream>
#include <vector>
 
using namespace std;
int main() {
 
    freopen("smallsort.in", "r", stdin);
    freopen("smallsort.out", "w", stdout);
 
 
    int n;
    cin >> n;
 
    vector <long long> v;
    v.resize(n);
    for (int i = 0; i< n; i++)
        cin >> v[i];
 
    for (int i = 1; i < n; i++){
        int k = v[i];
        for (int j = i-1; j >= 0; j--){
            if (v[j] > k){
                long long tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
            else break;
        }
    }
 
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
 
    return 0;
}