#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

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



void rec(vector<int> a, int i, int n, vector<int> set, vector<vector<int>> &ans){

    if(i==n){
        if(set.size()>0)
            ans.push_back(set);
    } else {

        rec(a,i+1,n,set,ans);

        set.push_back(a[i]);

        rec(a,i+1,n,set,ans);
    }

    if(ans.size() == (1<<n) - 1) return;

}

vector<vector<int>> FindAllSubsets(int n, vector<int> &arr){
    // Write your code here

    vector<vector<int>> ans;

    rec(arr, 0, n, {}, ans);

    return ans;

}

class Runner{
    int t;
    vector<int> N;
    vector<vector<int>> arr;

public:
    void takeInput(){
        cin >> t;
        N.resize(t);
        arr.resize(t);
        for (int i = 0; i < t; i++){
            cin >> N[i];
            arr[i].resize(N[i]);
            for (int j = 0; j < N[i]; j++){
                cin >> arr[i][j];
            }
        }
    }

    void execute(){
        vector<int> cpyN = N;
        vector<vector<int>> cpyArr = arr;
        for (int i = 0; i < t; i++){
            vector<vector<int>> ans = FindAllSubsets(cpyN[i], cpyArr[i]);
        }
        vector<int>().swap(cpyN);
        vector<vector<int>>().swap(cpyArr);
    }

    void executeAndPrintOutput(){
        for (int i = 0; i < t; i++){
            vector<vector<int>> ans = FindAllSubsets(N[i], arr[i]);
            for(int x=0; x<ans.size(); x++){
                sort(ans[x].begin(),ans[x].end());
            }
            sort(ans.begin(),ans.end());
            for(auto u: ans){
                for(auto x : u){
                    cout << x << " ";
                }
                cout << endl;
            }
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
   // freopen("testcases/Large/in/input12.txt", "r", stdin);
   // freopen("testcases/Large/out/output12.txt", "w", stdout);
#endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}