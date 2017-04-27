#include "../../taichitary.h"
// TODO: Segmentation fault: 11を直す

struct Node{
    int key;
    Node *prev, *next;
};

struct command{
    int key;
    string name;
};

//番兵のみ
Node *nil;

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil->prev = nil;
    nil->next = nil;
}

void insertNode(int key){
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    //ここはnil->nextがそもそも, nilの次のノードを指ししめすようになっている
    nil->next->prev = x;
    x->prev = nil;
    nil->next = x;
}

Node* searchNode(int key){
    Node *cur = nil->next; //番兵の次から見ていく
    while( cur != nil && cur->key != key){
        cur = cur->next;
    }

    return cur;
}

void deleteNode(Node *t){
    if(t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast(){
    deleteNode(nil->prev);
}

void deleteKey(int key){
    deleteNode(searchNode(key));
}

int main(){
    int n;
    command command_ary[2000010];
    init();
    string c_n;
    string _insert = "insert";
    string _delete = "delete";
    string _deleteFirst = "deleteFirst";
    string _deleteLast = "deleteLast";
    int key;


    for(int i=0; i<n; i++){
        cin >> command_ary[i].name >> command_ary[i].key;
    }

    for(int j=0; j<n; j++){
        c_n = command_ary[j].name;
        int c_k = command_ary[j].key;
        if(c_n == "insert") insertNode(c_k);
        else if(c_n == "delete") deleteKey(c_k);
        else if(c_n == "deleteFirst") deleteFirst();
        else if(c_n == "deleteLast") deleteLast();
    }

    while(nil->prev != nil){
        cout << key;
    }

    cout << "¥n";
}
