#include <iostream>
using namespace std;

#define MAX 50

int adj[MAX][MAX];
int deg[MAX];
int visited[MAX];

void DFS(int u) {
    visited[u] = 1;
    cout << u << " ";

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v])
            DFS(v);
    }
}

int main() {
    int n = 5;

    adj[0][deg[0]++] = 1; adj[1][deg[1]++] = 0;
    adj[0][deg[0]++] = 2; adj[2][deg[2]++] = 0;
    adj[1][deg[1]++] = 3; adj[3][deg[3]++] = 1;
    adj[2][deg[2]++] = 3; adj[3][deg[3]++] = 2;
    adj[3][deg[3]++] = 4; adj[4][deg[4]++] = 3;

    cout << "DFS Traversal ";
    DFS(0);
    return 0;
}

