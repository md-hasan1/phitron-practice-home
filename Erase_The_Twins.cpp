#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        stack<char> st;

        for (int i = 0; i < n; i++) { 
            char c = s[i];

            if (!st.empty() && st.top() == c) {
                st.pop(); 
            } else {
                st.push(c);
            }
        }

        cout << st.size() << "\n"; 
    }

    return 0;
}
