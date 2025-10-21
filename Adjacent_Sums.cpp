#include <bits/stdc++.h>
using namespace std;

int main() {


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n == 2) {
            cout << min(a[0] + a[1], abs(a[0] - a[1])) << endl;
           
        }else{
                   long long ans = 0;
        // cout<<n;
        for (int i = 1; i < n; i++) {
            ans = max(ans, abs(a[i]- a[i - 1]));
            //    cout << ans << endl;
        }
         cout << ans << endl;
        }

 
    
    
    }
    return 0;
}
