#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    

    bool found = false;
    while (n > 0) {
        int digit = n % 10;
       
        if (digit == 7) {
            found = true;
            break;
        }
        
        n /= 10;
        
    }

    if (found) cout << "Lucky" << endl;
    else cout << "Not Lucky" << endl;

    return 0;
}
