#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, X, K;
        cin >> N >> X >> K;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        sort(A.rbegin(), A.rend()); 

        for (int i = 0; i < N && K > 0; i++) {
            if (A[i] > X) {
                A[i] = 0;
                X += 100;
                K--;
            } else break;
        }

        int higher = 0;
        for (int a : A) if (a > X) higher++;
        cout << higher + 1 << endl;
    }
    return 0;
}
