#include <bits/stdc++.h>
using namespace std;

void printList(list<int>& l) {
    
    cout << "L -> ";
    for (int v : l) {
        cout << v << " ";
    }
    cout << endl;

   
    cout << "R -> ";
 auto it = l.end();
while (it != l.begin()) {
    --it; 
    cout << *it << " ";
}

    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    list<int> l;

    while (Q--) {
        int X;
        long long V; 
        cin >> X >> V;

        if (X == 0) {
            l.push_front(V);
        } else if (X == 1) {
            l.push_back(V);
        } else if (X == 2) {
     if (V < 0 || V >= l.size()) {
    
} else {
    auto it = l.begin();
    for (int i = 0; i < V; ++i) {
        ++it;
    }
    l.erase(it);
}
        }

        printList(l); 
    }

    return 0;
}
