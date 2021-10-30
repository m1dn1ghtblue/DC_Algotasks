#include <iostream>
#include <vector>
 
using namespace std;
 
vector <pair<int, int>> v; //first - priority    second - line number
 
int parent(int vertex) {
    return (vertex - 1) / 2;
}
 
int left_child(int vertex) {
    return ((vertex * 2) + 1 < v.size()) ? (vertex * 2) + 1 : -1;
}
 
int right_child(int vertex) {
    return ((vertex * 2) + 2 < v.size()) ? (vertex * 2) + 2 : -1;
}
 
void heapify(int vertex) {
    int smallest = vertex;
    if ((left_child(vertex) != -1) && (v[left_child(vertex)].first < v[smallest].first))
        smallest = left_child(vertex);
    if ((right_child(vertex) != -1) && (v[right_child(vertex)].first < v[smallest].first))
        smallest = right_child(vertex);
    if (smallest != vertex) {
        swap(v[smallest], v[vertex]);
        heapify(smallest);
    }
}
 
int extract_min() {
    if (v.empty())
        return -1;
    int top = v[0].first;
    swap(v[0], v[v.size()-1]);
    v.pop_back();
    heapify(0);
    return top;
}
 
void decrease_key(int line, int newValue) {
    int index = -1;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i].second == line) {
            index = i;
            break;
        }
    }
    v[index].first = newValue;
    int vertex = index;
    while ((vertex > 0) && (v[parent(vertex)].first > v[vertex].first)) {
        swap(v[vertex], v[parent(vertex)]);
        vertex = parent(vertex);
    }
}
 
void push(int val, int line) { //first - val   second - line
    v.push_back({val, line});
    decrease_key(line, val);
}
 
int main() {
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    string command;
    int i = 0;
    while (cin >> command) {
        i++;
        if (command == "push") {
            int x;
            cin >> x;
            push(x,i);
        } else if (command == "extract-min") {
            int res = extract_min();
            if (res != -1)
                cout << res << "\n";
            else
                cout << "*\n";
        } else if (command == "decrease-key") {
            int x, y;
            cin >> x >> y;
            decrease_key(x,y);
        }
    }
    return 0;
}