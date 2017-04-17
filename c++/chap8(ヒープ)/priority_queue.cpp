#include "taichitary.h"
#define MAX 2000000
#define INFTY (1<<30)

int H, A[MAX+1];

int left(int i){
    return i*2;
}

int right(int i){
    return i*2 + 1;
}

void maxHeapify(int *a, int i, int H){
    int l = left(i);
    int r = right(i);
    int largest;
    if(l <= H && a[i] < a[l]){
        largest = l;
    }
    else largest = i;
    if(r <= H && a[largest] < a[r]){
        largest = r;
    }

    if(largest != i){
        swap(a[i], a[largest]);
        maxHeapify(a, largest, H);
    }
}

int extractMax(){
    if(H < 1) return -INFTY; //エラー値として.

    int max = A[1];
    A[1] = A[H--]; //一番小さい値を入れる
    maxHeapify(A, 1, H);

    return max;

}

void increaseKey(int i, int key){
    if(key < A[i]) return;
    A[i] = key;
    while(i > 1 && A[i/2] < A[i]){
        swap(A[i], A[i/2]);
        i = i / 2;
    }
}

void insert(int key){
    H++;
    A[H] = -INFTY;
    increaseKey(H, key);
}

int main(){

    string s;
    int k;

    while(1){
        cin >> s;
        if(s == "insert"){
            cin >> k;
            insert(k);
        }else if(s == "extract"){
            int max = extractMax();
            cout << max << endl;
        }else if(s == "end") break;
    }

}