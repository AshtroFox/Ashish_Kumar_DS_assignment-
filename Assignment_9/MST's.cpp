#include <iostream>
using namespace std;

#define MAX 50
#define INF 999999



int parent[MAX];

void makeSet(int n) {
    for (int i = 0; i < n; i++) parent[i] = i;
}

int findSet(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int a, int b) {
    parent[findSet(a)] = findSet(b);
}



struct Edge {
    int u, v, w;
};

void kruskal(Edge edges[], int e, int n) {

    for (int i = 0; i < e-1; i++) {
        for (int j = 0; j < e-i-1; j++) {
            if (edges[j].w > edges[j+1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }

    makeSet(n);
    cout << "Kruskal MST\n";

    int count = 0;
    for (int i = 0; i < e && count < n-1; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (findSet(u) != findSet(v)) {
            cout << u << " - " << v << " ( " << edges[i].w << " )\n";
            unionSet(u, v);
            count++;
        }
    }
}



void prim(int graph[][MAX], int n) {
    int key[MAX], mst[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    key[0] = 0;
    mst[0] = -1;

    for (int i = 0; i < n-1; i++) {
        int minKey = INF, u = -1;


        for (int v = 0; v < n; v++)
            if (!visited[v] && key[v] < minKey)
                minKey = key[v], u = v;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                mst[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "\nPrim MST\n";
    for (int i = 1; i < n; i++)
        cout << mst[i] << " - " << i << " ( " << key[i] << " )\n";
}

int main() {
    int n = 4;
    int graph[MAX][MAX] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    Edge edges[] = {
        {0,1,10},{0,2,6},{0,3,5},{3,2,4},{1,3,15}
    };

    kruskal(edges, 5, n);
    prim(graph, n);

    return 0;
}

