#include "taichitary.h"

struct Node{
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL; //Node型のポインタ型の初期化をする *root->root 根のポインタ, *NIL->NIL なにもないことをしめすポインタ

void insert(int num){
    //ポインタで保持する
    Node *y = NIL; //親用のポインタ
    Node *x = root; //探索用のポインタ

    Node *z;

    //メモリ分を動的に確保する
    z = (Node *)malloc(sizeof(Node));
    z->key = num;
    z->left = NIL;
    z->right = NIL;

    while(x != NIL){
        y = x;
        if(z->key < x->key) x = x->left; //rootだったらNILどうでチェックが入る
        else x = x->right;
    }

    z->parent = y;
    if(y == NIL) root = z;
    else{
        if(z->key < y->key) y->left = z;
        else y->right = z;
    }
}

void inorder(Node *u){
    if(u == NIL) return;
    inorder(u->left);
    cout << u->key;
    inorder(u->right);

}

void print(Node *u){
    inorder(u);
    cout << endl;
}

int main(){

    int num, n;
    string command;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> command;

        if(command == "insert"){
            cin >> num;
            insert(num);
        }
        else if(command == "print")
            print(root);
    }
}