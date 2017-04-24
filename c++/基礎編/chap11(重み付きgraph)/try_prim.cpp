#include "taichitary.h"
#define V_MAX 100
#define INFTY 5000
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int M[V_MAX][V_MAX];
int d[V_MAX];
int p[V_MAX];
int color[V_MAX]; //いったところ用に保持しておく
int n;

void Prim(){

    for(int i=0; i<n; i++){
        d[i] = INFTY;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0;
    p[1] = -1;

    while(1){

        int mincost = INFTY; //一番小さい経路を選びたい
        int u; //最短経路の場所

        //ここで新しく伸ばす頂点を決める
        for(int j=0; j<n; j++){
            if(d[j] < mincost && color[j] != BLACK){
                mincost = d[j];
                u = j;
            }
        }

        if(mincost == INFTY) break;

        color[u] = BLACK;

        //伸びているところをしらべて(for), そこから更新する辺を決める
        for(int v=0; v<n; v++){
            if(color[v] != BLACK && M[u][v] != INFTY){
                if(M[u][v] < d[v]){
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }

    }


}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int tmp;
            cin >> tmp;
            if(tmp != -1) M[i][j] = tmp;
            else M[i][j] = INFTY;
        }
    }

    Prim();

    int sum = 0;

    for(int k=0; k<n; k++){
        if(p[k] != -1) {
            sum += M[k][p[k]];
        }
    }

    cout << sum << endl;

}