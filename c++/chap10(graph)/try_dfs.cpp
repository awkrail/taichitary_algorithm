#include "taichitary.h"
#define V_MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int m[V_MAX][V_MAX];
int d[V_MAX], f[V_MAX];
int n, t;
int color[V_MAX];
stack<int> S;

int next(int v){
    //見つかったとき, いける部分を返す関数(見つからなかった場合は-1をかえす)
    for(int i=0; i<n; i++){
        if(m[v][i] == 1 && color[i] == WHITE) return i;
    }

    return -1;
}

void dfs(int u){

    //スタックに入れて, そこからいけるところを探す. 一番topが今いるところになる
    S.push(u);
    color[u] = GRAY;
    int v = S.top();
    int dt = next(v);

    if(dt != -1){
        S.push(dt);
        color[dt] = GRAY;
        d[dt] = ++t;
        dfs(dt);
    }else{
        f[dt] = ++t;
        color[dt] = BLACK;
        S.pop();
        dfs(dt);
    }
}

int main(){

    cin >> n;
    int from, degree;
    int tmp;

    for(int i=0; i<n; i++){
        cin >> from >> degree;
        from--;
        for(int j=0; j<degree; j++){
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