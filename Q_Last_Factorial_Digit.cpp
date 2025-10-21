#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int fac = 1;
        for (int i = n; i >= 1; i--)
        {
            fac = fac * i;
        }
        
        cout << fac%10<<endl;
    }

    return 0;
}