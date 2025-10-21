    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, q;
        cin >> n >> q;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--; 

            set<int> st;
            for (int i = l; i <= r; i++) {
                st.insert(arr[i]);
            }

            int mex = 0;
            while (st.count(mex)) mex++;

            cout << mex << "\n";
        }

        return 0;
    }
