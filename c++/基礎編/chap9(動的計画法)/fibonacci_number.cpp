#include "taichitary.h"

int dp[50];

int fib(int n){
    if(dp[n] != -1) return dp[n]; //dpはありえない値を入れておく

    if(n == 0) return dp[0] = 1;
    if(n == 1) return dp[1] = 1;

    return dp[n] = fib(n-1) + fib(n-2);
}


int main(){

    int n;
    cin >> n;

    for(int i=0; i<50; i++) dp[i] = -1;

    int ans = fib(n);

    cout << ans << endl;

}