#include <iostream>
#include <vector>
 
using namespace std;
 
vector <pair <string, string> > v; //first - country  second - name
 
void merge(int left, int mid, int right){
    int it_l = left, it_r = mid;
    vector <pair <string, string> > buf;
    buf.resize(0);
    while ((it_l < mid) && (it_r < right)){
        if (v[it_l].first > v[it_r].first){
            buf.push_back(v[it_l]);
            it_l++;
        }
        else{
            buf.push_back(v[it_r]);
            it_r++;
        }
    }
    while (it_l < mid){
        buf.push_back(v[it_l]);
        it_l++;
    }
    while (it_r < right){
        buf.push_back(v[it_r]);
        it_r++;
    }
 
    for (int i = 0; i < (right-left); i++){
        v[left+i] = buf[i];
    }
}
 
void merge_sort(int left, int right){ // [left - nid) | [mid - right)
    if (left+1 < right){
        int mid = (right+left)/2;
        merge_sort(left, mid);
        merge_sort(mid, right);
        merge(left, mid, right);
    }
}
 
int main(){
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
 
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
 
    merge_sort(0,n);
    string country = "";
    for (int i = n-1; i >= 0; i--){
        if(v[i].first != country){
            country = v[i].first;
            cout << "=== " << country << " ===\n";
        }
        cout << v[i].second << endl;
    }
 
    return 0;
}