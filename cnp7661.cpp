#include <iostream>

using namespace std;

//debugger start
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...)  cout<<"l "<<__LINE__<<": "<< "[" << #x << "] = ["; _print(x)
// #define debugf(s, x...) cout<<"l "<<__LINE__<<": "<<s<<" : "<< "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//debugger end

void print(int m[9][9]){
    cout<<"sudoku"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<m[i][j]<<" \n"[j==8];
        }
    }
}

bool check_number(int m[9][9], int x, int y, int n){

    if(m[x][y] != 0) return false;

    for(int i=0;i<9;i++){
        if(m[i][y]==n)return false;
    }

    for(int i=0;i<9;i++){
        if(m[x][i]==n)return false;
    }

    int box_x = (x/3)*3;
    int box_y = (y/3)*3;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(m[box_x+i][box_y+j]==n) return false;
        }
    }

    return true;
}

bool rec(int m[9][9], int i, int j){

    // print(m);


    if(j==9){
        i++;
        j=0;
        if(i==9){
            // print(m);
            return true;
        }

    }


    if(m[i][j]==0){
        for(int k=1;k<=9;k++){
            if(check_number(m,i,j,k)){

                m[i][j] = k;
                if(rec(m,i,j+1)){
                    return true;
                }
                m[i][j] = 0;
            }
        }        
    } else {
        if(rec(m,i,j+1)){
            return true;
        }
    }

    return false;

}


bool isItSudoku(int matrix[9][9]) {
    

    // cout<<check_number(matrix,1,2,2);

    return rec(matrix,0,0);

}


int main() {
    int t;
    cin >> t;

    while(t--){
        int matrix[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cin >> matrix[i][j];
        }
        bool ans = isItSudoku(matrix);
        if (ans) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

}
