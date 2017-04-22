#include "taichitary.h"

int M = 10123456;
int L = 14;
char H[10123456][14];

int h1(int key){ return key % M; }
int h2(int key){ return 1 + (key % (M - 1)); }

int getChar(char ch){
    if (ch == 'A') return 1;
    else if(ch == 'C') return 2;
    else if(ch == 'G') return 3;
    else if(ch == 'T') return 4;
    return 0;
}

long long getKey(char *str){
    long long sum = 0, p=1, i;
    for(i=0; i<strlen(str); i++){
        sum += p*(getChar(str[i]));
        p *= 5; //同じ文字も位置によって変わる
    }

    return sum;
}

int insert(char *str){
    long long key, i, h;
    key = getKey(str); //キーにするために,文字列を数値としてデータにしてキーを作る
    for(i=0; ; i++){
        h = (h1(key) + i*h2(key)) % M;
        if(strcmp(H[h], str) == 0) return 1; //ハッシュに値があるかどうかを計算..同じ文字列のもの
        else if(strlen(H[h]) == 0){ //文字列の長さを計算/ハッシュに値がなければ
            strcpy(H[h], str); //文字列をコピーする/ハッシュに値を入れる
            return 0;
        }
    }
}

bool search(char *str){
    long long key, i, h;
    key = getKey(str);
    for(i=0; ; i++){
        h = (h1(key) + i*h2(key)) % M;
        if(strcmp(H[h], str) == 0) return true; //ハッシュのキー検索で見つかった場合
        else if(strlen(H[h]) == 0) return false; //いけるところ全部を見て回ってもない場合
    }
}


int main(){

    int n;
    for(int i=0; i<M; i++) H[i][0] = '\0';
    cin >> n;
    char str[20], cmd[20];

    for(int j=0; j<n; j++){
        cin >> cmd >> str;
        if(cmd[0] == 'i') insert(str);
        else if(cmd[0] == 'f'){
            if(search(str)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }

}