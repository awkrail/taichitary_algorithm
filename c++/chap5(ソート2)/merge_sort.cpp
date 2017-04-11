#include "taichitary.h"
//マクロ定義は, ;がいらない
#define MAX int(5e6)
#define SENTINEL 2e10

int cnt;
int L[MAX/2 + 2], R[MAX/2 + 2];

void merge(int *A, int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;

    for(int i = 0; i < n1; i++) L[i] = A[left+i];
    for(int i = 0; i < n2; i++) R[i] = A[mid+i];

    L[n1] = R[n2] = SENTINEL; //番兵を入れる

    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i++]; //L[i]をいれてから i+1
        }else{
            A[k] = R[j++];
        }
    }
}

void mergeSort(int *A, int n, int left, int right){
    if(left < right + 1){
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main(){

    int A[MAX], n, i;
    cnt = 0;

    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];

    mergeSort(A, n, 0, n);


}
