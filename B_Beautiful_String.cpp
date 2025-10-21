#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}


bool isNonDecreasing(string s, vector<int> &idx) {
    string p = "";
    for (int i : idx) p += s[i];
    for (int i = 1; i < (int)p.size(); i++) {
        if (p[i] < p[i - 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool found = false;

        
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> p;
            string x = "";
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    p.push_back(i);  
                else
                    x += s[i];        
            }

            if (isNonDecreasing(s, p) && isPalindrome(x)) {
                cout << p.size() << "\n";
                for (int i = 0; i < (int)p.size(); i++) {
                    cout << p[i] + 1 << (i + 1 == (int)p.size() ? '\n' : ' ');
                }
                found = true;
                break;
            }
        }

        if (!found) cout << -1 << "\n";
    }

    return 0;
}
