#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        int first = -1, last = -1;
        for (int i = 0; i < N; i++) {
            if (S[i] == '1') {
                if (first == -1) first = i;
                last = i;
            }
        }

        if (first == -1) { 
            cout << 0 << '\n';
            continue;
        }

        int cnt = 0;
        for (int i = first; i <= last; i++) {
            if (S[i] == '0') cnt++;
        }

        cout << cnt << '\n';
    }
    return 0;
}
