#include "taichitary.h"
/**
int top, S[1000];

void push(int x){
    S[++top] = x;
}

int pop(){
    top--;
    return S[top+1];
}

int main(){
    int a, b;
    char s[100];
    top = 0;

    while( scanf("%s", s) != EOF ){
        //渡された入力が演算子ならば
        if(s[0] == '+'){
            a = pop();
            b = pop();
            push(a+b);
        }
        else if(s[0] == '-'){
            a = pop();
            b = pop();
            push(b-a);
        }
        else if(s[0] == '*'){
            a = pop();
            b = pop();
            push(a*b);
        }else{
            push(atoi(s));
        }
    }

    cout << pop() << endl;
}
 **/
#define LEN 100005

struct pp{
    char name[100];
    int t;
};

pp Q[100005];
int head, tail, n;

void enqueue(pp process){
    Q[tail] = process;
    tail = (tail + 1) % LEN;
}

pp dequeue(){
    pp process = Q[head];
    head = (head + 1) % LEN;

    return process;
}

int main(){
    int elaps = 0;
    int c;
    int q;
    pp u;
    cin >> n >> q;

    for(int i=0; i < n; i++){
        cin >> Q[i].name;
        cin >> Q[i].t;
    }
    //キューの一番はじめがhead, tailが一番後ろ
    head = 0; tail = n;

    while(head != tail){
        u = dequeue();
        if(u.t > q){
            u.t -= q; /**残り時間を計算**/
            elaps += q; /**累計時間を計算**/
            enqueue(u);
        }else{
            elaps += u.t;
            //残り時間が0(終了する場合)
            cout << u.name << endl;
            cout << elaps << endl;
        }
    }
}