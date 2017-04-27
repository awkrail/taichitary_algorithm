#include "taichitary.h"
#define V_MAX 10000
#define WHITE 0
#define BLACK 1

int M[V_MAX][V_MAX];
int n;

void Dijkstra(){

    int color[V_MAX];
    int d[V_MAX];

    for(int i=0; i<n; i++){
        color[i] = WHITE;
        d[i] = INF;
    }

    d[0] = 0;

    while(1){

        int mincost = INF;
        int u;

        for(int i=0; i<n; i++){
            if(mincost > d[i] && color[i] != BLACK){
                mincost = d[i];
                u = i;
            }
        }

        if(mincost == INF) break;
        color[u] = BLACK;

        for(int j=0; j<n; j++){
            if(color[j] != BLACK && M[u][j] != INF){
                if(d[u] + M[u][j] < d[j]){
                    d[j] = d[u] + M[u][j];
                }
            }
        }
    }

    for(int v=0; v<n; v++){
        cout << (d[v] == INF ? -1 : d[v]) << endl;
    }
}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            M[i][j] = INF;
        }
    }

    for(int i=0; i<n; i++){
        int u, k;
        cin >> u >> k;
        for(int j=0; j<k; j++){
            int c, v;
            cin >> v >> c;
            M[u][v] = c;
        }
    }

    Dijkstra();

}