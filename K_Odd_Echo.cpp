#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // cout << n;

    vector<string> v; 
    for (int i = 0; i < n; i++) {
        // cout << "1";
        string s;
        cin >> s;
        v.push_back(s); 
    }

    for (int i = 0; i < n; i+=2) {
        cout << v[i]<<endl;
        
    }

    return 0;
}