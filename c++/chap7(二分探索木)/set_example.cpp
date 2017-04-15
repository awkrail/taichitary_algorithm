#include "taichitary.h"

void print(set<int> S){
    set<int>::iterator ite;
    for(ite = S.begin(); ite != S.end(); ite++) cout << *ite;
}

int main(){

    set<int> S;

    S.insert(8);
    S.insert(1);
    S.insert(7);
    S.insert(4);
    S.insert(8);
    S.insert(4);

    print(S);
    cout << endl;

    S.erase(7);
    print(S);
    cout << endl;

    S.insert(2);
    print(S);
    cout << endl;

    if(S.find(10) == S.end()) cout << "not found" << endl;

}