
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
using namespace std;

const int mod = 1e9 + 7;
 
// //debugger start
// void __print(int x) {cerr << x;}
// void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
// void __print(unsigned x) {cerr << x;}
// void __print(unsigned long x) {cerr << x;}
// void __print(unsigned long long x) {cerr << x;}
// void __print(float x) {cerr << x;}
// void __print(double x) {cerr << x;}
// void __print(long double x) {cerr << x;}
// void __print(char x) {cerr << '\'' << x << '\'';}
// void __print(const char *x) {cerr << '\"' << x << '\"';}
// void __print(const string &x) {cerr << '\"' << x << '\"';}
// void __print(bool x) {cerr << (x ? "true" : "false");}
 
// template<typename T, typename V>
// void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
// template<typename T>
// void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
// void _print() {cerr << "]\n";}
// template <typename T, typename... V>
// void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
// #ifndef ONLINE_JUDGE
// #define debug(x...)  cerr<<"l "<<__LINE__<<": "<< "[" << #x << "] = ["; _print(x)
// // #define debugf(s, x...) cerr<<"l "<<__LINE__<<": "<<s<<" : "<< "[" << #x << "] = ["; _print(x)
// #else
// #define debug(x...)
// #endif
// //debugger end

int pwr(int base, int power){
	int res = 1;

    while(power){
    	if(power&1) res *= base; res %= mod;
    	base *= base;
    	base %= mod;
    	power >>=1;
    }

    return res;
}

int locker(int n){

	if(n==1) return 1;
	if(n==2) return 2;

	if(n%3==0){
		return pwr(3,n/3)%mod;
	}

	if(n%3==1){
		return (pwr(3, (n-4)/3)*4)%mod;
	}

	return (pwr(3, (n-2)/3)*2)%mod;
	
	
}
 
void solve() {
    int n;
    cin>>n;
    cout<<locker(n)<<endl;
}
 
int32_t main() { io
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