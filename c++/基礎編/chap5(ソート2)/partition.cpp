#include "taichitary.h"

int partition(int *a, int p, int r){
    int last = a[r];
    int i = p-1;

    for(int j=p; j<r; j++){
        if(a[j] <= last){
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[r], a[i+1]);

    return i+1;

}

int main(){

    int n, a[100000];
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    int last = a[n-1];

    int pt = partition(a, 0, n-1); //p=1:i=p-1にして配列外参照が起きないよう. n-1は一番末尾

    for(int j=0; j<n; j++){
        if(pt == j) cout << "[" << a[j] << "]" << " ";
        else cout << a[j] << " ";
    }

    cout << endl;

}