#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        string s, x;
        cin >> s >> x;

        size_t pos = s.find(x); 
       
        while (pos != string::npos)
        {

          s.replace(pos, x.size(), "#");
          pos = s.find(x, pos + 1);
        }
        
        cout << s << endl;
    }

    return 0;
}