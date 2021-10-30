#include <iostream>
#include <vector>
 
using namespace std;
 
vector <int> v;
 
int left_child(int parent) {
    return ((parent * 2) + 1 < v.size()) ? (parent * 2) + 1 : -1;
}
 
int right_child(int parent) {
    return ((parent * 2) + 2 < v.size()) ? (parent * 2) + 2 : -1;
}
 
void heapify(int vertex) {
    int smallest = vertex;
    if ((left_child(vertex) != -1) && (v[left_child(vertex)] < v[smallest]))
        smallest = left_child(vertex);
    if ((right_child(vertex) != -1) && (v[right_child(vertex)] < v[smallest]))
        smallest = right_child(vertex);
    if (smallest != vertex) {
        swap(v[smallest], v[vertex]);
        heapify(smallest);
    }
}
 
void build_heap() {
    for (int i = ((int)v.size()) / 2; i >= 0; i--)
        heapify(i);
}
 
vector <int> heapsort() {
    vector <int> sorted;
    build_heap();
    while (!v.empty()) {
        sorted.push_back(v[0]);
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        heapify(0);
    }
    return sorted;
}
 
int main(){
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    v = heapsort();
 
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
 
    return 0;
}