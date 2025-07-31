#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> my_list;
    while (1)
    {
        int t;
        cin >> t;
        // cout<<t;
        if(t==-1){
            break ;
        }
        my_list.push_back(t);
    }
//   cout<<  my_list.size()
   my_list.sort();
    my_list.unique();
    for (int element : my_list)
    {
        cout << element<<" ";
    }

    return 0;
}