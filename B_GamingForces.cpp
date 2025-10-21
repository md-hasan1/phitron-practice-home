#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; ++i)
            cin >> h[i];
        sort(h.begin(), h.end());
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            pref[i] = pref[i - 1] + h[i - 1];
        int ans = INT_MAX;

        for (int k = 0; k <= n; ++k)
        {
            int S = pref[k];
            int pairs = (S + 1) / 2;
            int singles = n - k;
            ans = min(ans, pairs + singles);
        }
        cout << ans << '\n';
    }
    return 0;
}
