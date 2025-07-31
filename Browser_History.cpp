#include <bits/stdc++.h>
using namespace std;


int main()
{
    list<string> my_list;

    while (1)
    {
        string val;
        cin >> val;
        if (val == "end")
        {
            break;
        }
        my_list.push_back(val);
    }


    int test;
    cin >> test;
    auto it = my_list.begin();
    while (test--)
    {
        string text;
        cin >> text;
        if (text == "visit")
        {
            string target;
            cin >> target;

            auto found = find(my_list.begin(), my_list.end(), target);
            if (found != my_list.end())
            {
                it=found;
                cout << *it << endl;
            }
            else
            {
                cout << "Not Available" <<endl;
            }
        }
        else if (text == "prev")
        {
            if (it != my_list.begin())
            {
                --it;
                cout << *it <<endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (text == "next")
        {
            auto nextIt = it;
            ++nextIt;
            if (nextIt != my_list.end())
            {
                ++it;
                cout << *it <<endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}