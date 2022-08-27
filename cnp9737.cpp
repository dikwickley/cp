#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

bool check_stalls(vector<int> a, int k, int d){
    int last = a[0];
    k--;
    if(k==0) return true;
    for(int i=1;i<a.size();i++){

        if(a[i]-last >= d){
            k--;
            last=a[i];
        }

        if(k==0) return true;
    }
    return false;

}



int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    

    int l = INT_MIN;
    int r = INT_MAX;
    int ans = -1;

    while(l<=r){

        int mid = (l+r)/2;
        if(check) ans = mid;

        if(!check) r = mid-1;
        else l = mid;

        if((l+r)/2 == mid) {l = mid+1;}

    }

    return ans;
}

class Runner
{
    int t;
    vector<vector<int>> arr;
    vector<int> k;

public:
    void takeInput()
    {
        cin >> t;
        arr.resize(t);
        k.resize(t);
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
            arr[c].resize(n);

            cin >> k[c];
            for (int i = 0; i < n; i++)
            {
                cin >> arr[c][i];
            }
        }
    }

    void execute()
    {
        vector<vector<int>> arrCopy = arr;
        vector<int> kCopy = k;
        for (int i = 0; i < t; i++)
        {
            int ans = aggressiveCows(arrCopy[i], kCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = aggressiveCows(arr[i], k[i]);
            cout << ans << "\n";
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