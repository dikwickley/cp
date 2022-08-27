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


void rec(vector<int> arr, int i, int k, vector<int> s, vector<vector<int>> &ans){
    

    if(i==arr.size()){
        if(k==0) {
            // debug(s);
            ans.push_back(s);
            return;
        }
        if(k<0){
            return;
        }
        return;
    }

    rec(arr, i+1, k, s, ans);
    s.push_back(arr[i]);
    rec(arr,i+1,k-arr[i],s, ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    rec(arr,0,k,{},ans);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    vector<vector<int>> subsets = findSubsetsThatSumToK(arr, n, k);
    sort(subsets.begin(), subsets.end());

    for (int i = 0; i < subsets.size(); i++)
    {
        for (int element : subsets[i])
        {
            cout << element << " ";
        }
        cout << endl;
    }
}
