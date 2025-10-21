#include <bits/stdc++.h>
using namespace std;
int main()
{

    string s;
    cin >> s;
    // cout<<s<<endl;
//this is a test comment
    for (char c : s)
    {
        if (isupper(c))
        {
            cout << c;
        }
    }
    return 0;
}