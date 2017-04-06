#include "taichitary.h"
//TODO: binarySearchをきく

bool linearSearch(int *a, int n,int key){
    int i = 0;
    a[n] = key; //一番後ろに番兵をおく

    while(a[i] != key) i++;

    //要素が番兵より前で見つかればtrueを返す
    return i != n;
}

int binarySearch(int *a, int n, int key){
    int left = 0;
    int right = n;
    int mid;

    while(left < right){
        //真ん中の添字の計算
        mid = (left + right) / 2;
        if(a[mid] == key){
            return 1;
        } //midを返すとキーのありかになる
        if(a[mid] < key) right = mid; //midをふくむ左側で探索する
        else if(a[mid] > key) left = mid + 1; //midよりも右側で探索する
    }

    return 0;
}


int main(){

    int n;
    //配列が大きすぎてsegfault
    cin >> n;
    int S[n];
    for(int i=0; i<n; i++){
        cin >> S[i];
    }

    int q;
    cin >> q;
    int T[q];
    for(int j=0; j<q; j++){
        cin >> T[j];
    }
    //愚直なアルゴリズム
    /**
    int cnt = 0;
    for(int a=0; a<q; a++){
        int key = T[a];
        for(int b=0; b<n; b++){
            if(S[b] == key)
            {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;
    **/

    //番兵により比較が少なくなったアルゴリズム
    /**
    int cnt;
    for(int k=0; k<q; k++){
        if(linearSearch(S, n, T[k])) cnt++;
    }
    cout << cnt << endl;
    **/

    int cnt = 0;
    for(int k=0; k<q; k++){
        if(binarySearch(S, n, T[k]) == 1) cnt++;
    }
    cout << cnt << endl;
}