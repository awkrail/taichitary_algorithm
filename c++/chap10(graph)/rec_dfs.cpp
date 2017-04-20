#include "taichitary.h"
#define V_MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int m[V_MAX][V_MAX];
int n;
int d[V_MAX], f[V_MAX];
int color[V_MAX];
int t=0;

void dfs(int u){

    d[u] = ++t;
    color[u] = GRAY;

    //いけるところを探索する
    for(int i=0; i<n; i++){
        if(m[u][i] == 0) continue;
        if(color[i] == WHITE){
            dfs(i);
        }
    }

    color[u] = BLACK;
    f[u] = ++t;
}

int main(){

    cin >> n;
    int from, deg;

    for(int i=0; i<n; i++){
        cin >> from >> deg;
        from--;
        for(int j=0; j<deg; j++){
            int tmp;
            cin >> tmp;
            tmp--;

            m[from][tmp] = 1;
        }
    }

    dfs(0);

    for(int i=0; i<n; i++){
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }

}