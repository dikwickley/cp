#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>

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

int find_max(vector<int> start, vector<int> end){
    int m = INT_MIN;
    int n = start.size();
    for(int i=0;i<n;i++){
        m = max(m,end[i]-start[i]);
    } 

    return m;
}

vector<int> trafficLights(int n, int x, vector<int> &pos)
{
    vector<int> sta = {0};
    vector<int> end = {x};
    vector<int> ans(n);
    

    for(int i=0;i<n;i++){
        int index = upper_bound(sta.begin(), sta.end(), pos[i]) - sta.begin();
        int temp = end[index-1];

        end[index-1] = pos[i];
        sta.insert(sta.begin() + index,pos[i]);
        end.insert(end.begin() + index, temp);


        ans[i] = find_max(sta,end);
    }

    return ans;
}

class Runner
{
    int t;
    vector<vector<int> > nxArray;
    vector<vector<int> > arr ;

public:
    void takeInput()
    {
        cin >> t;
        for (int d = 0; d < t; d++)
        {

            int x, n, p ;
            cin >> x >> n;
            nxArray.push_back({x, n});

            vector<int> pos(n) ;
            for (int i = 0 ; i < n ; i++) {
                cin >> pos[i] ;
            }

            arr.push_back(pos) ;
        }
    }

    void execute()
    {
        vector<vector<int> > cpy1 = nxArray ;
        vector<vector<int> > cpy2 = arr ;
        for (int i = 0 ; i < t ; i++) {
            vector<int> res = trafficLights(cpy1[i][1], cpy1[i][0], cpy2[i]) ;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0 ; i < t ; i++) {
            vector<int> res = trafficLights(nxArray[i][1], nxArray[i][0], arr[i]) ;
            for (int i = 0 ; i < res.size() ; i++) {
                cout << res[i] << " " ;
            } cout << endl ;
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