#include "taichitary.h"
#define V_MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int M[V_MAX][V_MAX];
int d[V_MAX], p[V_MAX], color[V_MAX];
int n;

void Dijkstra(){

    for(int i=0; i<n; i++){
        d[i] = INF;
        p[i] = -1;
        color[i] = WHITE;
    }

    //初期値
    d[0] = 0;
    p[0] = -1;
    color[0] = GRAY;

    while(1){

        int mincost = INF;
        int u = -1;

        for(int i=0; i<n; i++){
            if(d[i] < mincost && color[i] != BLACK){
                mincost = d[i];
                u = i;
            }
        }

        if(u == -1) break;
        color[u] = BLACK;

        for(int v=0; v<n; v++){
            if(color[v] != BLACK && M[u][v] != INF){
                if(d[u] + M[u][v] < d[v]){
                    //いままでの状態よりも辺のコストが小さくなるとき.. 最初はINF
                    //プリム法と違い, 始点からの距離が配列dに入っていく
                    d[v] = d[u] + M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
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