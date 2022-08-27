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

#include<bits/stdc++.h>

vector<int> relativeSorting(vector<int> &arr, vector<int> &brr, int n, int m)
{

    vector<int> temp;
    map<int,int> mp;

    for(int i=0;i<m;i++){
        mp.insert({brr[i],0});
    }

    for(int i=0;i<n;i++){
        if(mp.count(arr[i])==1){
            mp[arr[i]] += 1;
        } else temp.push_back(arr[i]);
    }   

    vector<int> ans;
    ans.reserve(n+1);
    
    for(int i=0;i<m;i++){
        if(mp[brr[i]]>0){
            ans.insert(ans.end(),mp[brr[i]],brr[i]);
        }
    }

    sort(temp.begin(), temp.end());

    for(int i=0;i<temp.size();i++){
        ans.push_back(temp[i]);
    }

    return ans;

}


int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> brr(m);

        for (int i = 0; i < m; i++)
        {
            cin >> brr[i];
        }

        vector<int> result = relativeSorting(arr, brr, n, m);

        for (int i = 0; i < n; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}
