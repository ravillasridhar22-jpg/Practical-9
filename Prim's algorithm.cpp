#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter the cost adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    int visited[10] = {0};
    visited[0] = 1;

    int edges = 0;
    int minCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int min = 999;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (visited[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            cout << "Graph is not connected.\n";
            return 0;
        }

        cout << u << " - " << v
             << " : " << min << endl;

        visited[v] = 1;
        minCost += min;
        edges++;
    }

    cout << "Minimum cost of MST: " << minCost << endl;

    return 0;
}
