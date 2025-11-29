#include <iostream>
using namespace std;

const int INF = 1000000;
const int N = 6;

void initGraph(int g[N][N]) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            g[i][j] = INF;

    g[0][1]=4; g[1][0]=4;
    g[0][2]=9; g[2][0]=9;
    g[1][3]=8; g[3][1]=8;
    g[2][3]=6; g[3][2]=6;
    g[3][4]=4; g[4][3]=4;
    g[4][5]=3; g[5][4]=3;
    g[2][5]=14; g[5][2]=14;
}

int extractMin(int dist[N], int vis[N]) {
    int mn = INF, idx = -1;
    for(int i=0;i<N;i++)
        if(!vis[i] && dist[i] < mn) {
            mn = dist[i];
            idx = i;
        }
    return idx;
}

void dijkstra(int g[N][N], int dist[N], int parent[N], int start) {
    int vis[N];
    for(int i=0;i<N;i++){
        dist[i] = INF;
        vis[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    for(int i=0;i<N;i++){
        int u = extractMin(dist, vis);
        if(u == -1) return;
        vis[u] = 1;

        for(int v=0; v<N; v++){
            if(g[u][v] < INF) {
                if(dist[u] + g[u][v] < dist[v]) {
                    dist[v] = dist[u] + g[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

void printPath(int parent[N], int target) {
    int path[20], idx = 0;
    int x = target;

    while(x != -1) {
        path[idx++] = x;
        x = parent[x];
    }

    for(int i=idx-1; i>=0; i--) {
        if(path[i]==0) cout<<"B ";
        else if(path[i]==1) cout<<"A ";
        else if(path[i]==2) cout<<"C ";
        else if(path[i]==3) cout<<"D ";
        else if(path[i]==4) cout<<"F ";
        else if(path[i]==5) cout<<"E ";
    }
}

int main() {
    int g[N][N];
    int dist[N], parent[N];
    initGraph(g);
    dijkstra(g, dist, parent, 0);
    printPath(parent, 5);
}
