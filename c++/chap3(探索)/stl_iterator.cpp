#include "taichitary.h"

void print(vector<int> v){
    vector<int>::iterator ite;
    for(ite = v.begin(); ite != v.end(); ite++){
        cout << *ite << endl;
    }

    cout << endl;
}

int main(){

    int N = 4;
    vector<int> v;

    for(int i=0; i<N; i++){
        v.push_back(i);
    }

    print(v);

    vector<int>::iterator ite = v.begin();
    *ite = 3; //イテレータによりvectorの最初の要素を3に変える
    ite++; //移動
    (*ite)++; //次の要素(たぶん1)を+=1する

    print(v);


}