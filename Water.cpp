    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int testCases;
        cin >> testCases;
        
        while (testCases--) {
            int numPeople;
            cin >> numPeople;
            vector<int> heights(numPeople);
            
            for (int i = 0; i < numPeople; i++) {
                cin >> heights[i];
            }

            int tallestHeight = -1, secondTallestHeight = -1;
            int tallestIndex = -1, secondTallestIndex = -1;
            
            for (int i = 0; i < numPeople; i++) {
                if (heights[i] > tallestHeight) {
                    secondTallestHeight = tallestHeight;
                    secondTallestIndex = tallestIndex;
                    tallestHeight = heights[i];
                    tallestIndex = i;
                } else if (heights[i] > secondTallestHeight) {
                    secondTallestHeight = heights[i];
                    secondTallestIndex = i;
                }
            }

            if (tallestIndex < secondTallestIndex) {
                cout << tallestIndex << " " << secondTallestIndex << endl;
            } else {
                cout << secondTallestIndex << " " << tallestIndex << endl;
            }
        }
        
        return 0;
    }
