#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    queue<string> qe;
    while (t--)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 0)
        {
            string name;
            cin >> name;
            qe.push(name);
        }
        else
        {
            if (qe.empty())
            {
                cout << "Invalid" << endl;
            }else{
                cout<<qe.front()<<endl;
                qe.pop();
            }
        }
    }

    return 0;
}