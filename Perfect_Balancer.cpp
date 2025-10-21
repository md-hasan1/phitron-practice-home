#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> A(n+1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    long long total = 0;
    for (int i = 1; i <= n; i++) total += A[i];

    long long prefix = 0;
    for (int i = 1; i <= n; i++) {
        prefix += A[i];
        if (2 * prefix == total + A[i]) {
            cout << prefix << " " << i << "\n";
            return 0;
        }
    }

    cout << "UNSTABLE\n";
    return 0;
}
