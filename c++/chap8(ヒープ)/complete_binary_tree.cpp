#include "taichitary.h"

struct c_b{
    int key;
    int parent, left, right;
};

c_b c_b_tree[300];

int main(){

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> c_b_tree[i].key;
        c_b_tree[i].parent = i / 2;
        c_b_tree[i].left = 2*i;
        c_b_tree[i].right = 2*i + 1;
    }

    for(int j=1; j<=n; j++){

        cout << "node " << j << ": key = " << c_b_tree[j].key << ", ";
        if(c_b_tree[j].parent != 0) cout << "parent key =" << c_b_tree[c_b_tree[j].parent].key << ", ";
        if(c_b_tree[j].left <= n) cout << "left key =" << c_b_tree[c_b_tree[j].left].key << ", ";
        if(c_b_tree[j].right <= n) cout << "right key =" << c_b_tree[c_b_tree[j].right].key << ", ";
        cout << endl;
    }

    cout << endl;
}