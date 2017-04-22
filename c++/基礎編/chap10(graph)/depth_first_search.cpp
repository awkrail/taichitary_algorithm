#include "../chap11(重み付きgraph)/taichitary.h"
#define V_MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int d[V_MAX], f[V_MAX];
int n, M[V_MAX][V_MAX];
int color[V_MAX], tt;
int nt[V_MAX];

int next(int u){
    for(int v=nt[u]; v < n; v++){
        nt[u] = v + 1;
        if(M[u][v]) return v;
    }

    return -1;
}

//スタックによる深さ優先探索
void dfs_visit(int r){
    for(int i=0; i<n; i++) nt[i] = 0;

    //訪れる
    stack<int> S;
    S.push(r);
    color[r] = GRAY;
    d[r] = ++tt;

    while(!S.empty()){

        int u = S.top();
        int v = next(u);

        if(v != -1){
            if(color[v] == WHITE){
                color[v] = GRAY;
                d[v] = ++tt;
                S.push(v);
            }
        }else{
            S.pop();
            color[u] = BLACK;
            f[u] = ++tt;
        }
    }
}


void dfs(){
    //初期化
    for(int i=0; i<n; i++){
        color[i] = WHITE;
        nt[i] = 0;
    }
    tt = 0;

    for(int u=0; u<n; u++){
        if(color[u] == WHITE) dfs_visit(u);
    }

    for(int i=0; i<n; i++){
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }

}


int main(){

    int u, k, v;
    cin >> n;

    for(int i=0; i<n; i++){

        cin >> u >> k;
        u--; //0に合わせる

        for(int j=0; j<k; j++){
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }

    dfs();
}