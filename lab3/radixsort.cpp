#include <iostream>
#include <vector>
 
using namespace std;
 
const int ALPHABET = 'z' - 'a' + 1;
 
vector <string> v;
 
int key(string str, int k) {
    return str[k] - 'a';
}
 
vector <string> count_sort(int k) {
    vector <string> sorted;
    vector <int> count;
    count.resize(ALPHABET, 0);
    sorted = v;
 
    for (int i = 0; i < v.size(); i++)
        count[key(v[i], k)]++;
    for (int i = 1; i < ALPHABET; i++)
        count[i] += count[i-1];
 
 
    for (int i = (v.size() - 1); i >= 0; i--) {
        int current_key = key(v[i], k);
        count[current_key]--;
        sorted[count[current_key]] = v[i];
    }
 
    return sorted;
}
 
 
int main(){
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
 
    for (int i = 0; i < k; i++)
        v = count_sort(m - i - 1);
 
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }
 
    return 0;
}