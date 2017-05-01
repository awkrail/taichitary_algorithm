#include "../taichitary.h"

struct Tree{
    int location, l, r;
};

Tree T[50];
int np=0;
int t=0;
int a[50];

int make_1d_tree(int l, int r){

    if (l>=r) return -1;

    int mid = (l+r)/2;


    t = np;
    np++;
    T[t].location = mid;
    T[t].l = make_1d_tree(l, mid);
    T[t].r = make_1d_tree(mid+1, r);

    return t;
}

void find(int v, int sx, int tx){

    int x = a[T[v].location];

    if(sx <= x && x <= tx) cout << a[T[v].location] << endl;

    if(T[v].l != -1 && sx <= x) find(T[v].l, sx, tx);

    if(T[v].r != -1 && x <= tx) find(T[v].r, sx, tx);

}

void print(int u){
    if(u == -1) return;

    print(T[u].l);
    cout << u << endl;
    print(T[u].r);
}

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int r = make_1d_tree(0, n);

    cout << r << endl;

    cout << T[3].l << T[3].r << T[3].location << endl;

}