#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        set<int> st;
        for (int x : A) {
            if (x >= 1 && x <= n) {
                st.insert(x);
            }
        }

        int distinct_count = st.size();
        int need = n - distinct_count;

        if (need <= k) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
