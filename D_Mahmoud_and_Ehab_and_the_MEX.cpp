#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    set<int> s;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        s.insert(val);
    }

    int operations = 0;

    
    for (int i = 0; i < x; i++) {
        if (!s.count(i)) operations++;
    }
cout<<s.count(x);
    if (s.count(x)) operations++;

    cout << operations << '\n';
    return 0;
}
