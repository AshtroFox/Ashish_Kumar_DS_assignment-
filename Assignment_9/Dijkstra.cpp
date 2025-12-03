#include <iostream>
using namespace std;

#define MAX 50
#define INF 999999

void dijkstra(int graph[][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDist = INF, u = -1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && dist[v] < minDist)
                minDist = dist[v], u = v;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Dijkstra Shortest Paths:\n";
    for (int i = 0; i < n; i++)
        cout << src << " -> " << i << " = " << dist[i] << endl;
}

int main() {
    int n = 5;

    int graph[MAX][MAX] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 0, 4},
        {5, 2, 0, 0, 3},
        {0, 0, 4, 3, 0}
    };

    dijkstra(graph, n, 0);
    return 0;
}

