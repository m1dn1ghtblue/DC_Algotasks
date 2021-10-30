#include <iostream>
#include <vector>
 
using namespace std;
int main() {
 
    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);
 
    int n;
    cin >> n;
 
    vector<pair<float, int>> v;
    v.resize(n);
 
    for (int i = 0; i < n; i++) {
        float x;
        cin >> x;
        v[i] = make_pair(x, i+1);
    }
 
    //sort
 
    for (int i = 1; i < n; i++){
        float k = v[i].first;
        for (int j = i-1; j >= 0; j--){
            if(k < v[j].first){
                pair <float,int> tmp = v[j+1];
                v[j+1] = v[j];
                v[j] = tmp;
            }
            else break;
        }
    }
 
    cout << v[0].second << " " << v[n/2].second << " " << v[n-1].second;
    return 0;
}