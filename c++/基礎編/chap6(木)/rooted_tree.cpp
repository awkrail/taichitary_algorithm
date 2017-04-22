#include "taichitary.h"
#define TREEMAX int(1e5)+10
#define NIL -1

struct Node{
    int p,l,r;
};

int D[TREEMAX];
Node T[TREEMAX];

void print(int i){
    cout << "node" << i << ':';
    cout << "parent =" << T[i].p << "depth =" << D[i];
    if(T[i].p == NIL) cout << "root, ";
    else if(T[i].l == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[ ";

    for(int j=0, c=T[i].l; c != NIL; j++, c=T[c].r){
        if(j) cout << ", ";
        else cout << c;
    }

    cout << "]" << endl;
}


void rec(int u, int p){
    D[u] = p;
    if(T[u].r != NIL) rec(T[u].r, p);
    if(T[u].l != NIL) rec(T[u].l, p+1);
}

int main(){

    int n, k=0;
    cin >> n;
    for(int j=0; j<n; j++) T[j].p = T[j].r = T[j].l = NIL;

    int v,d,c,l;
    int tmp;
    for(int i=0; i<n; i++){
        cin >> v >> d;
        for(int j=0; j<d; j++){
            cin >> c;
            if(j==0){
                T[v].l = c;
                //l = T[v].l;
            }
            else{
                T[l].r = c;
            } //lは初期化されてないのにこんなとこで使うとおかしくなると思うのだが..→解決. 29行目でl=cをすることで,子の一番左から順に埋まっていく
            l = c; //子のノードの右側をひとつずつ埋めていく
            T[c].p = v;
        }
    }

    int r;

    for(int e=0; e<n; e++){
        if(T[e].p == NIL) r = e; //根のノードのrootを見つける
    }

    rec(r, 0);

    for(int f=0; f<n; f++) print(f);


}