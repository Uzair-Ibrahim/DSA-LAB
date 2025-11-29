#include <iostream>
using namespace std;

class Graph {
    int V;
    int adjList[10][10];
    int listSize[10];
    int adjMatrix[10][10]; 
    public:
    Graph(int vertices) {
        V = vertices;
        for (int i = 1; i <= V; i++) {
            listSize[i] = 0;
            for (int j = 1; j <= V; j++)
                adjMatrix[i][j] = 0;
        }
    }
    void addEdge(int u, int v) {
        adjList[u][listSize[u]++] = v;
        adjList[v][listSize[v]++] = u;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    void displayAdjList() {
        cout << "Adjacency List:\n";
        for (int i = 1; i <= V; i++) {
            cout << i << ": ";
            for (int j = 0; j < listSize[i]; j++)
                cout << adjList[i][j] << " ";
            cout << "\n";
        }
    }
    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }
    void BFS(int start) {
        bool visited[10];
        for(int i=1;i<=V;i++) visited[i]=false;
        int q[50], front = 0, rear = 0;
        visited[start] = true;
        q[rear++] = start;
        cout << "\nBFS starting from " << start << ": ";
        while (front < rear) {
            int node = q[front++];
            cout << node << " ";
            for (int i = 0; i < listSize[node]; i++) {
                int neigh = adjList[node][i];
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q[rear++] = neigh;
                }
            }
        }

        cout << "\n";
    }
    void DFSUtil(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";
        for (int i = 0; i < listSize[node]; i++) {
            int neigh = adjList[node][i];
            if (!visited[neigh])
                DFSUtil(neigh, visited);
        }
    }
    void DFS(int start) {
        bool visited[10];
        for(int i=1;i<=V;i++) visited[i]=false;
        cout << "\nDFS starting from " << start << ": ";
        DFSUtil(start, visited);
        cout << "\n";
    }
};

int main() {
    Graph g(5);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.displayAdjList();
    g.displayAdjMatrix();
    g.BFS(1);
    g.DFS(1);
    return 0;
}
