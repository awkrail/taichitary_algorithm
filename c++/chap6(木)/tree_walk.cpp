#include "taichitary.h"
#define NIL -1

struct P{
    int p,l,r;
};

P tree[30];


void preorder(int u){
    if(u == NIL) return;
    cout << u;

    preorder(tree[u].l);
    preorder(tree[u].r);
}

void inorder(int u){
    if(u == NIL) return;

    preorder(tree[u].l);
    cout << u;
    preorder(tree[u].r);
}

void postorder(int u){
    if(u == NIL) return;

    postorder(tree[u].l);
    postorder(tree[u].r);
    cout << u;
}

int main(){

    int n;
    cin >> n;
    for(int j=0; j<30; j++) tree[j].p = tree[j].l = tree[j].r = NIL;

    int v,l,r;
    for(int i=0; i<n; i++){
        cin >> v >> l >> r;

        tree[v].l = l;
        tree[v].r = r;

        if(tree[v].l != NIL) tree[l].p = v;
        if(tree[v].r != NIL) tree[r].p = v;
    }

    int root;
    for(int k=0; k<n; k++){
        if(tree[k].p == NIL) root = k;
    }

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

}