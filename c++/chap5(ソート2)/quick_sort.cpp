#include "taichitary.h"

struct Card{
    char w;
    int num;
};

int partition(Card *a, int p, int r){
    int x = a[r].num;
    int i = p-1;
    for(int j=p; j<r; j++){
        if(a[j].num <= x){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[r],a[i+1]);

    return i+1;
}

void quickSort(Card *A, int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main(){

    int n;
    cin >> n;
    Card a[int(1e5)+5];
    for(int i=0; i<n; i++) cin >> a[i].w >> a[i].num;

    quickSort(a, 0, n-1); //nかもしれない..

    for(int j=0; j<n; j++) cout << a[j].w << a[j].num;

    cout << endl;


}