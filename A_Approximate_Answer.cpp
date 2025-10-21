#include <bits/stdc++.h>
using namespace std;
int main()
{

    int x, y, k;
    cin >> x >> y >> k;
    abs(x);
    abs(y);
    abs(k);
    if(x-y<=k){
        cout<<"Yes";
    }else{
        cout<<"No";  
    }
    return 0;
}