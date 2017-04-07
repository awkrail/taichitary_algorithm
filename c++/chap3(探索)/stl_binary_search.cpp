#include "taichitary.h"

int A[int(1e7)], n;

int main(){

    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> A[i];
    }

    int q, k, sum = 0;
    cin >> q;
    for(int j=0; j<q; j++){
        cin >> k;
        if(*lower_bound(A, A+n, k) == k) sum++;
    }

    cout << sum << endl;


}