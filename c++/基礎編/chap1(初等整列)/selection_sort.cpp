#include "../../taichitary.h"

void selection_sort(int n, int *a){
    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i; j<n; j++){
            if(a[j] < a[minj]) {
                minj = j;
            }
        }
        swap(a[i], a[minj]); //最後に一回だけ
    }
}

int main(){
    int n, a[100];
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    selection_sort(n, a);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    cout << endl;
}