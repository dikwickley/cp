
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
 
void solve() {
    int n;
    cin>>n;

    vector<int> a(n),b(n),r(n),s(n);

    int total_bottom = 0;

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    if(n==1) {cout<<0<<endl; return;}


    total_bottom -= b[n-1];
    r[0] = a[0];
    s[0] = b[0];
    for(int i=1;i<n;i++){
    	r[i] = r[i-1] + a[i];
    	s[i] = s[i-1] + b[i];
    }


    debug(r);
   	debug(a);
   	debug(b);
   	debug(s);

   	int min_score = INT_MAX;

   	for(int i=n-1;i>=0;i--){
   		int upper_score = r[n-1] - r[i];

   		int lower_score = s[i-1];
   		if(i==0) lower_score = 0;
   		min_score = min(min_score, max(upper_score, lower_score));

   		debug(i, upper_score, lower_score);
   		debug(min_score);

   	}

   	cout<<min_score<<endl;



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