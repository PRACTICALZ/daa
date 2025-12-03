#include <iostream>
using namespace std;

#define INF 999999

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[50][50];

    cout << "Enter adjacency matrix (use 0 if no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF; 
        }
    }

    int selected[50] = {0};
    selected[0] = 1; 

    int edgeCount = 0;
    int totalCost = 0;

    cout << "\nEdges in MST:\n";

    while (edgeCount < n - 1) {
        int minWeight = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < minWeight) {
                        minWeight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << "  (weight = " << minWeight << ")\n";
        totalCost += minWeight;
        selected[v] = 1;
        edgeCount++;
    }

    cout << "\nTotal cost of MST = " << totalCost << endl;

    return 0;
}
