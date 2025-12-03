#include <iostream>
using namespace std;

#define INF 999999

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[50][50];

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;  
        }
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    int dist[50];      
    bool visited[50];  

    for (int i = 0; i < n; i++) {
        dist[i] = graph[source][i];
        visited[i] = false;
    }
    dist[source] = 0;
    visited[source] = true;

    for (int count = 1; count < n; count++) {
        int minDist = INF, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output result
    cout << "\nShortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To vertex " << i << " = " << dist[i] << endl;
    }

    return 0;
}
