#include <iostream>
#include <vector>
 
using namespace std;
 
vector <int> v;
long long inversions = 0;
 
void merge(int left, int mid, int right){
    int it_l = left, it_r = mid;
    vector <int > buf;
    buf.resize(0);
    while ((it_l < mid) && (it_r < right)){
        if (v[it_l] <= v[it_r]){
            buf.push_back(v[it_l]);
            it_l++;
        }
        else{
            buf.push_back(v[it_r]);
            inversions += mid-it_l;
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
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    merge_sort(0,n);
 
    cout << inversions;
    return 0;
}