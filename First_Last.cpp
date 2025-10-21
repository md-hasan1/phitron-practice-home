    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        long long int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }


        map<long long, pair<long long, long long>> indx;
        for (int i = 0; i < n; i++)
        {
            long long int val = arr[i];
            

            if (indx.find(val) == indx.end())
            {
                indx[val] = {i + 1, i + 1};
            }else{
                indx[val].second=i+1;
            }
        }

            for (auto &entry : indx) {
            cout << entry.first << " " 
                << entry.second.first << " " 
                << entry.second.second << "\n";
        }
        return 0;
    }