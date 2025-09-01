#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        string sentence;
        getline(cin, sentence);

        stringstream ss(sentence);
        string word;
        map<string, int> freq;

        string resultWord;
        int maxCount = 0;

        while (ss >> word) {
            freq[word]++;

            if (freq[word] > maxCount) {
                maxCount = freq[word];
                resultWord = word;
            }
      
        }

        cout << resultWord << " " << maxCount << "\n";
    }

    return 0;
}
