#include <bits/stdc++.h>
using namespace std;
int main()
{

    int ss, qs;
    cin >> ss >> qs;
    stack<int> st;
    queue<int> qe;
    int flag=0;
    if (ss != qs)
    {
        cout << "NO";
        return 0;
    }

    while (ss--)
    {
        int val;
        cin >> val;
        st.push(val);
    }
    while (qs--)
    {
        int val;
        cin >> val;
        qe.push(val);
    }
    while (!st.empty())
    {
        if (st.top() != qe.front())
        {
         flag=1;
            break;
        }
        st.pop();
        qe.pop();
    }
   if(flag){
    cout<<"NO";
   }else{
    cout<<"YES";
   }

    return 0;
}