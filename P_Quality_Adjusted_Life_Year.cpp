#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        double q, y;
        cin >> q >> y;
        total += q * y;
    }
    cout << fixed << setprecision(3) << total << endl;
    return 0;
}
