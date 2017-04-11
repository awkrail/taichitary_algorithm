#include "taichitary.h"
#define VMAX 10000

int main(){

    int n;
    cin >> n;
    int a[int(2e6)+10];
    int b[int(2e6)+10];
    int c[VMAX+1];
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i] = 0;
    }
    for(int k=0; k<VMAX; k++) c[k] = 0;

    for(int x=0; x<n; x++){
        c[a[x]]++; //添字:数値の大きさ, 要素:計数
    }

    for(int y=1; y<VMAX; y++){
        c[y] = c[y-1] + c[y]; //添字:数値の大きさ, 要素:計数の累計
    }

    for(int z=n-1; z>0; z--){
        b[c[a[z]]] = a[z];
        c[a[z]]--;
    }


    for(int j=0; j<n; j++) cout << b[j] << " ";

    cout << endl;
}