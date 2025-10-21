#include <bits/stdc++.h>
using namespace std;

long long distanceMatrix[105][105];
int numNodes, numEdges;

void floydWarshall() {
    for (int k = 1; k <= numNodes; k++) {
        for (int i = 1; i <= numNodes; i++) {
            for (int j = 1; j <= numNodes; j++) {
                if (distanceMatrix[i][k] != LLONG_MAX && distanceMatrix[k][j] != LLONG_MAX) {
                    if (distanceMatrix[i][j] > distanceMatrix[i][k] + distanceMatrix[k][j]) {
                        distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    cin >> numNodes >> numEdges;

 
    for (int i = 1; i <= numNodes; i++) {
        for (int j = 1; j <= numNodes; j++) {
            if (i == j) {
                distanceMatrix[i][j] = 0;
            } else {
                distanceMatrix[i][j] = LLONG_MAX;
            }
        }
    }

    for (int i = 0; i < numEdges; i++) {
        int fromNode, toNode, weight;
        cin >> fromNode >> toNode >> weight;
       
        if (weight < distanceMatrix[fromNode][toNode]) {
            distanceMatrix[fromNode][toNode] = weight;
        }
    }

    floydWarshall();

    int numQueries;
    cin >> numQueries;
    while (numQueries--) {
        int startNode, endNode;
        cin >> startNode >> endNode;
        if (distanceMatrix[startNode][endNode] == LLONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << distanceMatrix[startNode][endNode] << endl;
        }
    }

    return 0;
}
