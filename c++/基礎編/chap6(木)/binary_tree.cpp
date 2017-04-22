#include "taichitary.h"
#define MAX 10000
#define NIL -1

struct Node{
    int parent,left,right;
};

Node T[MAX];
int D[MAX], H[MAX];

void setDepth(int u, int d){
    if(u == NIL) return;
    D[u] = d;
    setDepth(T[u].left, d+1);
    setDepth(T[u].right, d+1);
}

int setHeight(int u){
    int h1 = h2 = 0;
    if(T[u].left != NIL) h1 = setHeight(T[u].left) + 1;
    if(T[u].right != NIL) h2 = setHeight(T[u].right) + 1;

    return H[u] = (h1 > h2 ? h1 : h2);
}

int main(){

    int v,l,r, root=0;
    int n;
    cin >> n;

    for(int i=0; i<n; i++) T[i].parent = NIL;

    for(int j=0; j<n; j++){
        cin >> v >> l >> r;
        T[v].left = l;
        T[v].right = r;
        if(T[v].left != NIL) T[l].parent = v;
        if(T[v].right != NIL) T[r].parent = v;
    }

    int root;
    for(int k=0; k<n; k++){
        if(T[k].parent == NIL) root = k;
    }

    setDepth(root, 0);


}