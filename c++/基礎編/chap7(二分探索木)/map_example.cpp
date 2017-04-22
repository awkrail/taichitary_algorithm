#include "taichitary.h"

void print(map<string, int> T){
    map<string, int>::iterator ite;
    for(ite = T.begin(); ite != T.end(); ite++){
        cout << (*ite).first << "-->" << (*ite).second << endl;
    }
}

int main(){

    map<string, int> T;

    T["red"] = 32;
    T["blue"] = 688;
    T["yellow"] = 122;

    T["blue"] += 312;

    print(T);

    T.insert(make_pair("zebra", 101010));
    T.insert(make_pair("white", 0));
    T.erase("yellow");

    print(T);

    pair<string, int> target = *T.find("red");
    cout << target.first << "-->" << target.second << endl;

}