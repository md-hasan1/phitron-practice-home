#include <bits/stdc++.h>
using namespace std;

int gcnd(int X, int Y) {
    for (int z = max(X, Y); z >= 5; z--) {
        if (X % z != 0 && Y % z != 0)
            return z;
    }
    return 5; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        int ans = 0;
      
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                ans = max(ans, gcnd(A[i], A[j]));
            }
        }
        cout << ans << "\n";
    }
}
