#include "taichitary.h"
int a[60];
int n;

bool solve(int x, int i){
    //終了条件
    if(x == 0) return true; //足し算して求められたら終了
    if(i >= n) return false; //最後のところまでみたら終了

    bool res = solve(x-a[i], i+1) || solve(x, i+1); //次の配列へ

    return res;
}

int main(){

    int m;
    int b[60];
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    cin >> m;

    for(int j=0; j<m; j++){
        cin >> b[j];
    }

    for(int k=0; k<m; k++){
        bool flag = solve(b[k], 0);
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }




}