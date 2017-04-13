#include "taichitary.h"

struct Node{
    int key;
    Node *left, *right, *parent;
};

Node *root, *NIL; //おなじところを指すらしい(初期化時のみ)

void insert(int num){
    //つまり,グローバル変数で指したときに同じものがはいるので,初insertでwhileの中を通らずに済む
    Node *x = root;
    Node *y = NIL;

    Node *z; //Node型のポインタ(新しくいれるやつ)
    z = (Node *)malloc(sizeof(Node));
    z->key = num;
    z->left = NIL;
    z->right = NIL;


    while(x != NIL){
        //挿入する部分を探す
        y = x; //親を移動
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }

    z->parent = y;
    if(y == NIL) root = z; //whileを通らない時
    else{
        if(z->key < y->key) y->left = z;
        else y->right = z;
    }
}

Node* find(int num, Node *u){

    while(u != NIL && num != u->key){
        if(u->key < num) u = u->left;
        else u = u->right;
    }

    return u;
}

int main(){

    int n;
    cin >> n;
    int num;
    string command;

    for(int i=0; i<n; i++){
        cin >> command >> num;
        if(command == "insert"){
            insert(num);
        }else if(command == "find"){
            if(find(num, root) != NIL){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            };
        }else{
            //print();
        }


    }


}