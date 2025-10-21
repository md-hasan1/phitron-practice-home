#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int from, to, weight;
    Edge(int from, int to, int weight) {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

int numNodes, numEdges;
long long distanceArr[1005];        
vector<Edge> edgeList;
bool hasNegativeCycle = false;

void bellmanFord(int sourceNode) {
    for (int i = 0; i <= numNodes; i++) {
        distanceArr[i] = LLONG_MAX;
    }
    distanceArr[sourceNode] = 0;

    for (int i = 1; i <= numNodes - 1; i++) {
        for (auto ed : edgeList) {
            if (distanceArr[ed.from] != LLONG_MAX && distanceArr[ed.from] + ed.weight < distanceArr[ed.to]) {
                distanceArr[ed.to] = distanceArr[ed.from] + ed.weight;
            }
        }
    }

    for (auto ed : edgeList) {
        if (distanceArr[ed.from] != LLONG_MAX && distanceArr[ed.from] + ed.weight < distanceArr[ed.to]) {
            hasNegativeCycle = true;
            return;
        }
    }
}

int main() {
    cin >> numNodes >> numEdges;
    for (int i = 0; i < numEdges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edgeList.push_back(Edge(from, to, weight));
    }

    int sourceNode;
    cin >> sourceNode;
    int numQueries;
    cin >> numQueries;

    bellmanFord(sourceNode);

    if (hasNegativeCycle) {
        cout << "Negative Cycle Detected\n";
        return 0;
    }

    while (numQueries--) {
        int destinationNode;
        cin >> destinationNode;
        if (distanceArr[destinationNode] == LLONG_MAX) cout << "Not Possible\n";
        else cout << distanceArr[destinationNode] << "\n";
    }
}
