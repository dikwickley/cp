
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

int kicks(string p,int i,int t1,int t2, int l1, int l2){
	if(t1 > t2+l2)return 0;
	if(t2 > t1+l1)return 0;
	
	if(i%2==0){
		if(p[i]=='1') return 1+kicks(p,i+1,t1+1,t2,l1-1,l2);
		if(p[i]=='?') return min(1+kicks(p,i+1,t1,t2,l1-1,l2),1+kicks(p,i+1,t1+1,t2,l1-1,l2));
		if(p[i]=='0') return 1+kicks(p,i+1,t1,t2,l1-1,l2);
	} else {
		if(p[i]=='1') return 1+kicks(p,i+1,t1,t2+1,l1,l2-1);
		if(p[i]=='?') return min(1+kicks(p,i+1,t1,t2,l1,l2-1),1+kicks(p,i+1,t1,t2+1,l1,l2-1));
		if(p[i]=='0') return 1+kicks(p,i+1,t1,t2,l1,l2-1);
	}

	return 0;
}
 
void solve() {
    string p;
    cin>>p;

    cout<<kicks(p,0,0,0,5,5)<<endl;

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