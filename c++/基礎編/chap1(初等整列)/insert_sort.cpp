#include "../../taichitary.h"

void insertionSort(int n, int *a){
    for(int i=0; i<n; i++){
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
}

int main(){

    int n, a[110];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    insertionSort(n, a);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    cout << endl;
}