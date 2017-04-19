#include "taichitary.h"

int LCS(string x, string y){

    int m = x.size();
    int n = y.size();
    int c[1000][1000];

    for(int i=0; i<m; i++) c[i][0] = 0;
    for(int j=0; j<n; j++) c[0][j] = 0;

    for(int a=1; a<=m; a++){
        for(int b=1; b<=n; b++){
            if(x[a] == y[b]) c[a][b] = c[a-1][b-1] + 1;
            else c[a][b] = max(c[a-1][b], c[a][b-1]);
        }
    }

    return c[m][n];
}

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string x, y;
        cin >> x >> y;

        int ans = LCS(x, y);

        cout << ans << endl;
    }
}