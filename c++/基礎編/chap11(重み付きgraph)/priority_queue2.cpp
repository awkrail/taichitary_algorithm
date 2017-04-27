#include "taichitary.h"
#define MAX 100000
#define WHITE 0
#define BLACK 1

int n;
vector<pair<int, int> > adj[MAX];

void Dijkstra(){

    priority_queue<pair<int, int> > PQ;
    int color[MAX];
    int d[MAX];

    for(int i=0; i<n; i++){
        color[i] = WHITE;
        d[i] = INF;
    }

    d[0] = 0;
    PQ.push(make_pair(0, 0));

    while(!PQ.empty()){

        pair<int, int> f = PQ.top();
        PQ.pop();
        int u = f.second;

        color[u] = BLACK;

        if(d[u] < f.first*(-1)) continue;

        for(int j=0; j < adj[u].size(); j++){
            int v = adj[u][j].first;
            if(color[v] == BLACK) continue;
            if(d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                PQ.push(mp(d[v]*(-1), v));
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
        int u, k;
        cin >> u >> k;
        for(int j=0; j<k; j++){
            int c, v;
            cin >> v >> c;
            adj[u].pb(mp(v, c));
        }
    }

    Dijkstra();

}