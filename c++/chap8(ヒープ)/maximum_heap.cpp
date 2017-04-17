#include "taichitary.h"

int left(int i){ return 2*i; }
int right(int i){ return 2*i+1; }


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


void buildMaxHeap(int *a, int H){
    for(int i=H/2; i>=1; i--){
        maxHeapify(a, i, H);
    }
}

int main(){

    int H;
    cin >> H;

    int a[int(5e5)+10];
    for(int i=1; i<=H; i++) cin >> a[i];

    buildMaxHeap(a, H);

    for(int j=1; j<=H; j++) cout << a[j] << " ";

    cout << endl;

}