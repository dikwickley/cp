
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
 
void solve() {
    int n;
    cin>>n;

    vector<int>a(n);
    vector<int>d(n);
    vector<int>p(n);
    vector<pair<float,int>> f(n);

    for(int i=0;i<n;i++){
    	cin>>a[i]>>d[i]>>p[i];
    	f[i] = {(float)(d[i]-a[i])/p[i],i};
    }

    sort(f.rbegin(), f.rend());

    debug(f);
    
    int index = f[0].second;
    int last = a[index];
    int mp = p[index];

    for(int i=1;i<n;i++){
    	index = f[i].second;

    	if(d[index] <= last){
    		last = a[index];
    		mp += p[index];
    	}
    }

    cout<<mp<<endl;
}

 
int main() { io

    int t=1; 
    // cin>>t; 
    while (t--) {
        solve();
    }
    return 0;
}