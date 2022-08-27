#include <iostream>
#include <vector>
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

#include <bits/stdc++.h>

void print_board(vector<vector<int>> a){
	cout<<"board\n";
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}

bool check(vector<vector<int>> a, int I, int J){

	for(int i=I,j=J;i>=0;i--,j--){
		if(a[i][j]==1) return false;
	}

	for(int i=I,j=J;i<a.size();i++,j--){
		if(a[i][j]==1) return false;
	}

	for(int j=J;j>=0;j--){
		if(a[I][j]==1) return false;
	}

	return true;
}

void n_queen(vector<vector<int>> a, int column, int n, vector<vector<int>> &ans){


	if(column==n){
		vector<int> temp(n*n);
		for(int i=0, c=0;i<n;i++){
			
			for(int j=0;j<n;j++){
				temp[c++] = a[i][j];
			}
		}
		ans.push_back(temp);
		return;
	}


	for(int i=0;i<n;i++){

		if(column==0 || check(a,i,column)){
			a[i][column] = 1;
			n_queen(a,column+1,n,ans);
			a[i][column] = 0;
		}
	}
}


vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> a(n, vector<int>(n,0));

    vector<vector<int>> ans(0,vector<int>());
    

    n_queen(a,0,n,ans);


    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> answer;
    answer = solveNQueens(n);

    for (auto sol : answer) {
        for (auto i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}