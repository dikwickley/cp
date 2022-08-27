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

bool check_painter(vector<int> boards, int k, int m){
    int n = boards.size();
    int s = 0;
    for(int i=0;i<n;i++){

        if(s + boards[i] <= m){
            s = s + boards[i];
            boards[i] = 0;
        }  else {
            s = 0;
            k--;
            i--;
            if(k==0) break;
        }
        
    }

    for(int i=0;i<n;i++) if(boards[i] != 0) return false;

    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{

    int n = boards.size();
    int total = 0;
    for(int i=0;i<n;i++) total += boards[i];

    int l = 1;
    int r = total;
    int ans = -1;
    
    while(l<=r){
    
        int mid = (l+r)/2;
        bool check = check_painter(boards, k, mid);
        if(check) ans = mid;
        if(check) r = mid;
        else l = mid+1;
        if((l+r)/2 == mid) {r = mid-1;}
    
    }
    
        

    return ans;
}

class Runner
{
    int t;
    vector<vector<int>> arr;
    vector<int> kList;

public:
    void takeInput()
    {
        cin >> t;

        arr.resize(t);
        kList.resize(t);

        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
            cin >> kList[c];
            arr[c].resize(n);
            for (int i = 0; i < n; i++)
            {
                cin >> arr[c][i];
            }
        }
    }

    void execute()
    {
        vector<vector<int>> arrCopy = arr;
        vector<int>kListCopy = kList;

        for (int i = 0; i < t; i++)
        {
            int ans = findLargestMinDistance(arrCopy[i],kListCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = findLargestMinDistance(arr[i],kList[i]);

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