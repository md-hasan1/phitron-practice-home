#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N + 1);
        for (int i = 1; i <= N; i++) cin >> A[i];

        vector<pair<int,int>> arr;
        for (int i = 1; i <= N; i++) arr.push_back({A[i], i});
        sort(arr.begin(), arr.end());

        vector<int> sortedIdx(N);
        for (int i = 0; i < N; i++) sortedIdx[i] = arr[i].second;

        vector<int> P(N + 1);
        for (int i = 0; i < N; i++) {
            int from = sortedIdx[i];
            int to = sortedIdx[(i + 1) % N];
            P[from] = to;
        }

        int score = 0;
        for (int i = 1; i <= N; i++) {
            if (A[P[i]] <= A[i]) score++;
        }

        cout << score << "\n";
        for (int i = 1; i <= N; i++) cout << P[i] << " ";
        cout << "\n";
    }
    return 0;
}
