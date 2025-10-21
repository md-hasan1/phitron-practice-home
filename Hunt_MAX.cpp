#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, int> freq;             
    map<int, set<int>> freq_to_vals;            
    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            int old_freq = freq[x];
            int new_freq = old_freq + 1;
            freq[x] = new_freq;

            if (old_freq > 0) {
                freq_to_vals[old_freq].erase(x);
                if (freq_to_vals[old_freq].empty()) {
                    freq_to_vals.erase(old_freq);
                }
            }
            freq_to_vals[new_freq].insert(x);
        } else if (type == 2) {
            if (freq.empty()) {
                cout << "empty\n";
            } else {
                auto it = freq_to_vals.rbegin(); 
                int max_freq = it->first;
                auto& vals = it->second;
                int val = *vals.rbegin(); 

                cout << val << "\n";

                int remove_count = max(1, freq[val] - 1);
                int new_freq = freq[val] - remove_count;

                freq_to_vals[max_freq].erase(val);
                if (freq_to_vals[max_freq].empty()) {
                    freq_to_vals.erase(max_freq);
                }

                if (new_freq == 0) {
                    freq.erase(val);
                } else {
                    freq[val] = new_freq;
                    freq_to_vals[new_freq].insert(val);
                }
            }
        }
    }

    return 0;
}