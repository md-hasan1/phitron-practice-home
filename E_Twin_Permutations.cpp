#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; // number of test cases

    while (t--) {
        int n;
        cin >> n; // size of permutation

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first; // value of a[i]
            a[i].second = i;   // original index
        }

        sort(a.begin(), a.end()); // sort a by value

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[a[i].second] = i + 1; // assign smallest to smallest
        }

        for (int x : b) cout << x << " ";
        cout << endl;
    }

    return 0;
}
