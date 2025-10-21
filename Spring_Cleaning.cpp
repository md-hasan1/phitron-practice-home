#include <bits/stdc++.h>
using namespace std;
int main()
{

    int x, y;
    cin >> x >> y;
    int smallroom, bigRoom;
    smallroom = x * 30;
    bigRoom = y * 60;
    int total = smallroom + bigRoom;
    cout << total << endl;
    return 0;
}