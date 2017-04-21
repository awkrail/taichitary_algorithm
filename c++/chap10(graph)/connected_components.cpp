#include "taichitary.h"
#define V_MAX 100000

vector<int> v[V_MAX];
int check[V_MAX];

bool dfs(int s, int t){

    for(int i=0; i<v[s].size(); i++){
        int to = v[s][i];
        if(check[to]) continue;
        check[to] = 1;
        if(to == t) return true;
        dfs(to, t); //ここがおかしい気がする
    }
    return false;
}

int main(){

    int n, m;
    cin >> n >> m;
    int to, from;

    for(int i=0; i<m; i++){
        cin >> from >> to;
        v[from].pb(to);
        v[to].pb(from);
        //無向リンクなので両方向に貼る
    }

    int ques;
    cin >> ques;
    vector<bool> flgs;

    for(int j=0; j<ques; j++){
        int s, t;
        cin >> s >> t;
        for(int k=0; k<V_MAX; k++) check[k] = 0;
        check[s] = 1; //始点に戻ってこないようにする
        bool flg = dfs(s, t);
        flgs.pb(flg);
    }

    vector<bool>::iterator ite;
    for(ite = flgs.begin(); ite != flgs.end(); ite++){
        if(*ite) cout << "yes" << endl;
        else cout << "no" << endl;
    }

}