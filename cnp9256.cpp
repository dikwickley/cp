#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

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

void rec(vector<vector<bool>> a, int i, int j, string path, vector<string> &ans){

    int n = a.size();

    // debug(path);

    if(i==n-1 && j==n-1){
        // debug(path);
        ans.push_back(path);
        return;        
    }

    if(i+1<n && a[i+1][j]!=0){
        a[i][j]=0;
        rec(a,i+1,j,path+'D',ans);
        a[i][j]=1;
    }

    if(j+1<n && a[i][j+1]!=0){
        a[i][j]=0;
        rec(a,i,j+1,path+'R',ans);
        a[i][j]=1;
    }

    if(i>0 && a[i-1][j]!=0){
        a[i][j]=0;
        rec(a,i-1,j,path+'U',ans);
        a[i][j]=1;
    }

    if(j>0 && a[i][j-1]!=0){
        a[i][j]=0;
        rec(a,i,j-1,path+'L',ans);
        a[i][j]=1;
    }

}

vector<string> findAllPaths( vector<vector<bool>> &arr)
{

    vector<string> ans = {};
    int n = arr.size();

    if(arr[0][0]==0) return ans;

    rec(arr,0,0,"",ans);
    
    return ans;
}

class Runner
{
    int t;
    vector<vector<vector<bool>>> arr;

public:
    void takeInput()
    {

        cin >> t;
        arr.resize(t);

        for (int tc = 0; tc < t; tc++)
        {
            int n;
            cin >> n;
            arr[tc].resize(n);

            for (int i = 0; i < n; i++)
            {
                arr[tc][i].resize(n);
                for (int j = 0; j < n; j++)
                {
                    bool x;
                    cin>>x;
                    arr[tc][i][j]=x;
                    
                }
            }
        }
    }

    vector<vector<vector<bool>>> getCopy()
    {
        vector<vector<vector<bool>>> arrCopy = arr;

        return arrCopy;
    }

    void execute()
    {
        vector<vector<vector<bool>>> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            vector<string> ans = findAllPaths(arrCopy[i]);
        }
    }
    

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<string> ans = findAllPaths(arr[i]);
            
            sort(ans.begin(),ans.end());
            for (string i : ans)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}