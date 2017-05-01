#include "../taichitary.h"

struct Point{
    ll x, y;
};

int main(){

    int n, q;
    cin >> n;
    Point xy[int(5e5)+5];
    vector<int> v;

    for(int i=0; i<n; i++){
        cin >> xy[i].x >> xy[i].y;
    }

    cin >> q;

    for(int i=0; i<q; i++){
        ll sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;

        for(int k=0; k<n; k++){
            if(sx <= xy[k].x && xy[k].x <= tx){
                if(sy <= xy[k].y && xy[k].y <= ty) v.pb(k);
            }
        }

        for(int j=0; j<v.size(); j++){
            cout << v[i] << endl;
        }

        v.clear();

    }



}