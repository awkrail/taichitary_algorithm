#include "taichitary.h"

int factorial(int x){
    if(x == 1) return 1;
    else return x * factorial(x-1);
}

int main(){

    int n;
    cin >> n;

    int num = factorial(n);
    cout << num << endl;


}