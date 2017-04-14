#include "taichitary.h"

struct Node{
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;

Node* find(Node *u, int num){
    while(u != NIL && u->key != num){
        if(num < u->key) u = u->left;
        else u = u->right;
    }

    return u;
}

void insert(int num){
    Node *x = root;
    Node *y = NIL; //親を探すためのポインタ

    Node *z;
    z = (Node *)malloc(sizeof(Node));
    z->key = num;
    z->right = NIL;
    z->left = NIL;

    while(x != NIL){
        y = x;
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent = y;

    if(y == NIL) root = z;
    else{
        if(z->key < y->key) y->left = z;
        else y->right = z;
    }
}

Node* treeMinimum(Node *x){
    while(x->left != NIL) x = x->left;
    return x;
}

Node* treeSuccessor(Node *x){
    if(x->right != NIL) return treeMinimum(x->right);
    Node *y = x->parent;
    while( y!= NIL && x == y->right){
        x = y;
        y = y->parent;
    }

    return y;
}

void _delete(Node *z){
    Node *y; //削除対象のノード
    Node *x; //yの子
    //zは削除したいキーのノード

    if(z->left == NIL || z->right == NIL) y = z;
    else y = treeSuccessor(z);

    //yの子をきめる
    if(y->left != NIL){
        x = y->left;
    }else{
        x = y->right;
    }

    if(x != NIL){
        x->parent = y->parent;
    }

    if(y->parent == NIL){
        root = x;
    }else{
        if(y == y->parent->left) y->parent->left = x;
        else y->parent->right = x;
    }

    if(y != z){
        z->key = y->key;
    }
    free(y);
}


int main(){

    int n, num;
    cin >> n;
    string s;

    for(int i=0; i<n; i++){
        cin >> s >> num;
        if(s == "insert") insert(num);
        else if(s == "find"){
            Node *t = find(root, num);
            if(t != NIL) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else if(s == "delete") _delete(find(root, num));
        //else if(s == "print") print();
    }

}