
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

double c(vector<int> x, vector<int> t, double m){
	double total_time = 0;

	for(int i=0;i<x.size();i++){
		total_time += abs(x[i]-m) + t[i];
	}

	return total_time;
}
 
void solve() {
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> t(n);

    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>t[i];

  	

  	double l = 1;
  	double r = 100000000;
  	
  	while(l+0.0000001<r){


  		debug(l,r);
  	
  	    int mid = (l+r)/2;
  	    if( (c(x,t, mid-0.0000001)<=c(x,t,mid)) && (c(x,t,mid)<=c(x,t,mid+0.0000001))){
  	    	r = mid;
  	    }
      	else {
      		l = mid;
      	}
  	}
  	debug(l,r);
  	cout<<l<<endl;

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