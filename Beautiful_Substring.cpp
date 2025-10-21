#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int count = 0;
    for (int i = 0; i <= n - 3; i++) {
        string sub = s.substr(i, 3);
        if (sub == "101" || sub == "010") {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
