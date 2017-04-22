/** 自作ヘッダ, 関数まとめ **/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <ctime>

using namespace std;

#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
#define fi first
#define se second
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;
const double PI = acos(-1);

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

// 挿入ソート
// 引数:配列の要素数, 配列
// 配列は帰り値ではなく値を破壊的に変更する
// Down: 降順, Up: 昇順
void insertionSortDown(int *a, int N){
    for(int i=1; i<N; i++){
        //一番最初は,一番初めの要素をソート済みとする
        int v = a[i];
        int j = i - 1;

        //ソート済みの部分と比較していく. 右側から見ていく.
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

        /**
        cout << to_string(i) << "回目" << endl;
        for(int k=0; k<N; k++){
            cout << a[k] << endl;
        }
         **/
    }
}

void insertionSortUp(int *a, int N){
}

// バブルソート
// 配列は破壊的に変更する. 必要があればreturn値からint型に変更する
void bubbleSortUp(int *a, int N){
    int sw = 0;
    int flag = 1;

    while(flag == 1){
        flag = 0;

        for(int j=N-1; j>=sw; j--){
            if(a[j-1] > a[j]){
                swap(a[j-1], a[j]);
                flag = 1;
            }
        }
        sw++;
        //一回内側ループをするごとにひとつ定まっていくので.
    }
}

void selectionSortUp(int *a, int N){
    for(int i=0; i<N-1; i++){
        int minj = i;

        for(int j=i; j<N; j++){
            if(a[minj] > a[j]){
                minj = j;
            }
        }
        swap(a[minj], a[i]);
        //一回内側ですべての数についてループをして,一番小さいものの要素と交換していく
    }
}

// 線形探索 O(nq)
// 配列, 配列の要素数, 取り出したい値
bool linearSearch(int *a, int n,int key){
    int i = 0;
    a[n] = key; //一番後ろに番兵をおく

    while(a[i] != key) i++;

    //要素が番兵より前で見つかればtrueを返す
    return i != n;
}


#define V_MAX 100000
#define NIL -1

int n;
vector<int> G[V_MAX];
int color[V_MAX];

void dfs(int u, int c){

    stack<int> S;
    S.push(u);
    color[u] = c;

    while(!S.empty()){

        int l = S.top(); S.pop();

        for(int i=0; i<G[l].size(); i++){
            int v = G[l][i];
            if(color[v] == NIL){
                color[v] = c;
                S.push(v);
            }
        }
    }
}

void assignColor(){
    for(int i=0; i<n; i++) color[i] = NIL;

    int id = 1;

    for(int j=0; j<n; j++){
        if(color[j] == NIL) dfs(j, id++);
    }

}

int main(){

    int r;
    cin >> n >> r;

    for(int i=0; i<r; i++){
        int from, to;
        cin >> from >> to;
        G[from].pb(to);
        G[to].pb(from);
    }

    assignColor();

    int q;
    cin >> q;

    int s, t;

    for(int j=0; j<q; j++){
        cin >> s >> t;
        if(color[s] == color[t]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}