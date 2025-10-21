#include <bits/stdc++.h>
using namespace std;

vector<long long> getSubsetSums(vector<int>& arr) {
    int n = arr.size();
    set<long long> sums;
    sums.insert(0); 

    for (int price : arr) {
        vector<long long> newSums;
        for (long long s : sums) {
            newSums.push_back(s + price);
        }
        sums.insert(newSums.begin(), newSums.end());
    }

    return vector<long long>(sums.begin(), sums.end());
}

int main() {
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    int mid = n / 2;
    vector<int> firstHalf(prices.begin(), prices.begin() + mid);
    vector<int> secondHalf(prices.begin() + mid, prices.end());

    vector<long long> sum1 = getSubsetSums(firstHalf);
    vector<long long> sum2 = getSubsetSums(secondHalf);
    sort(sum2.begin(), sum2.end());

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        set<long long> results;

        for (long long x : sum1) {
            auto lowIt = lower_bound(sum2.begin(), sum2.end(), l - x);
            auto highIt = upper_bound(sum2.begin(), sum2.end(), r - x);
            for (auto it = lowIt; it != highIt; it++) {
                results.insert(x + *it);
            }
        }

        cout << results.size() << "\n";
    }

    return 0;
}
