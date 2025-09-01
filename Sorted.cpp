#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        set<int> st;
        for (int i = 0; i < a; i++)
        {
            int val;
            cin >> val;
            st.insert(val);
        }

        for (auto it = st.begin(); it != st.end(); it++)
        {
            cout << *it <<" ";
        };

        cout<<endl;
    }

    return 0;
}
