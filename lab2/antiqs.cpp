#include <iostream>
#include <vector>
 
using namespace std;
 
vector <int> v;
 
void gen_arr(int n){
    if (n == 1) v.push_back(1);
    else {
        gen_arr(n - 1);
        v.push_back(n);
        int mid = (n-1) / 2;
        swap(v[mid], v[n-1]);
    }
}
 
int main(){
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
 
    v.resize(0);
    int n;
    cin >> n;
    gen_arr(n);
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    return 0;
}
 
/*
 * 1  | 2
 * 2 1  | 3
 * 2 3 1  | 4
 * 2 4 1 3  | 5
 * 2 4 5 3 1  | 6
 * 2 4 6 3 1 5  | 7
 * 2 4 6 7 1 5 3  | 8
 * 2 4 6 8 1 5 3 7  |9
 * 2 4 6 8 9 5 3 7 1  | 10
 * 2 4 6 8 10 5 3 7 1 9
 */