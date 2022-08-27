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



int recursive(vector<pair<int,int>> a, int i, int last_end, int n){
    if(i==n) return 1;

    if(a[i].first >= last_end){
        return max( 
            1 + recursive(a, i+1, a[i].second, n),
            recursive(a,i+1,last_end, n)
        );
    } else {
        return recursive(a,i+1,last_end, n);
    }

}

int maximumActivities(vector<int> &start, vector<int> &finish) {

    int n = start.size();

    vector<pair<int,int>> a(n);

    for(int i=0;i<n;i++){
        a[i] = {start[i], finish[i]};
    }

    sort(a.begin(), a.end());

    return max(recursive(a,0,a[0].second, n),recursive(a,1,a[1].second, n));
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        vector<int> start(n);
        vector<int> finish(n);

        for (int i = 0; i < n; i++)
        {
            cin >> start[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> finish[i];
        }

        int ans = maximumActivities(start, finish);

        cout << ans << endl;
    }
     
    return 0;
}
