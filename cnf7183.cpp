#include <iostream>
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


bool checkOverlappingIntervals(long* start, long* end, int n)
{
	vector<pair<long,long>> a;

    for(int i=0;i<n;i++){
        a.push_back({start[i],end[i]});
    } 

    sort(a.begin(), a.end());
    
    for(int i=1;i<n;i++){
        if(a[i-1].second > a[i].first) return true;
    }
    
    return false;
    
}



int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long *start = new long[n];
        long *end = new long[n];

        for (int i = 0; i < n; ++i)
        {
            cin >> start[i];
        }

        for (int i = 0; i < n; ++i)
        {
            cin >> end[i];
        }

        if (checkOverlappingIntervals(start, end, n))
        {
            cout << "true\n";
        }
        else
        {
            cout << "false\n";
        }

        delete start;
        delete end;
    }
}