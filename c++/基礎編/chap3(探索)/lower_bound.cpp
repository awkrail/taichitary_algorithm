#include "taichitary.h"

int main(){

    int A[14] = {1, 1, 2, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    int *pos;
    int idx;

    pos = lower_bound(A, A+14, 3); //配列は全部を指定, value=3
    idx = distance(A+1, pos); //イテレータの場所と, A(先頭)との距離 .. ここ変えてみたらどうなる?
    cout << "A[" << idx << "] =" << *pos << endl;

    pos = lower_bound(A, A+14, 2);
    idx = distance(A, pos);
    cout << "A[" << idx << "] = " << *pos << endl;

    //A(配列の変数)が配列の先頭ポインタになっているので, それをいれることができて,
    //配列の場合は,A+1,A+2...とオフセットが続くのでそう指定できる. iteratorがポインタの意味もわかってきた
}