#include <bits/stdc++.h>
using namespace std;

int parentArr[100005];
int rankArr[100005];

int findRoot(int node) {
    if (parentArr[node] != node) {
        parentArr[node] = findRoot(parentArr[node]); // path compression
    }
    return parentArr[node];
}

bool unionSets(int nodeA, int nodeB) {
    int rootA = findRoot(nodeA);
    int rootB = findRoot(nodeB);

    if (rootA == rootB) {
        return true; // cycle detected
    }

    // Union by rank
    if (rankArr[rootA] < rankArr[rootB]) {
        parentArr[rootA] = rootB;
    } else if (rankArr[rootA] > rankArr[rootB]) {
        parentArr[rootB] = rootA;
    } else {
        parentArr[rootB] = rootA;
        rankArr[rootA]++;
    }
    return false;
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    for (int i = 1; i <= numNodes; i++) {
        parentArr[i] = i;
        rankArr[i] = 0;
    }

    int cycleEdgeCount = 0;
    for (int i = 0; i < numEdges; i++) {
        int fromNode, toNode;
        cin >> fromNode >> toNode;
        if (unionSets(fromNode, toNode)) {
            cycleEdgeCount++;
        }
    }

    cout << cycleEdgeCount << endl;
    return 0;
}
