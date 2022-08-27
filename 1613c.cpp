
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
//debugger start
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...)  cerr<<"l "<<__LINE__<<": "<< "[" << #x << "] = ["; _print(x)
// #define debugf(s, x...) cerr<<"l "<<__LINE__<<": "<<s<<" : "<< "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//debugger end


bool check_health(vector<long long>a, long long h, long long t){
    int n = a.size();

    for(int i=0;i<n-1;i++){
        // h -= min(a[i+1]-a[i], t);
        if(a[i+1]-a[i] < t) h -= a[i+1]-a[i];
        else h -= t;
        if(h<=0) return true;
    }
    h-=t;
    if(h<=0) return true;
    else return false;


}
 
void solve() {
    int n;
    long long h;
    cin>>n>>h;

    vector<long long>a(n);


    for(int i=0;i<n;i++) cin>>a[i];


    bool temp = check_health(a,h, 908);
    debug(temp);

    
    long long l = 1;
    long long r = h;
    long long ans = -1;
    
    while(l<=r){

        long long mid = (l+r)/2;

        bool check = check_health(a,h,mid);

        if(check) ans = mid;

        if(check) r = mid;
        else l = mid+1;

        if((l+r)/2 == mid) {r = mid-1;}
    
    }
    
    cout<<ans<<endl;
    
    

    
}
 
int main() { io
    #ifndef ONLINE_JUDGE
        freopen("error.err", "w", stderr);
    #endif
    int t=1; 
    cin>>t; 
    while (t--) {
        solve();
    }
    return 0;
}