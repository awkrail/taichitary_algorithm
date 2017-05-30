#include "../../taichitary.h"

void bubble_sort(int n, int *a){
    for(int i=0; i<n; i++){
        for(int j=n-1; j>i; j--){
            if(a[j-1] > a[j]) swap(a[j-1], a[j]);
        }
    }
}


int main(){

    int n;
    int a[100];
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    bubble_sort(n, a);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    cout << endl;
}