#include "taichitary.h"
#define V_MAX 100

vector<int> V[V_MAX];
int M[V_MAX][V_MAX];

int main(){

    int n;
    cin >> n;
    int from, degree, tmp;

    for(int i=1; i<=n; i++){
        cin >> from >> degree;
        for(int j=0; j<degree; j++){
            cin >> tmp;
            V[from].pb(tmp);
        }
    }

    /**
     * 確認用
    for(int i=1; i<=n; i++){

        cout << i << "番目 ";

        vector<int>::iterator ite;
        for(ite = V[i].begin(); ite != V[i].end(); ite++) cout << (*ite) << " ";

        cout << endl;
    }
     **/

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            vector<int>::iterator ite;
            for(ite = V[i].begin(); ite != V[i].end(); ite++){
                if(*ite == j) M[i][j] = 1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout << M[i][j] << " ";
        cout << endl;
    }
}
