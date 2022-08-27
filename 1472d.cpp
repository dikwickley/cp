
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
    vector<long long> a(n), o,e;

    for(int i=0;i<n;i++) {
    	cin>>a[i];
    	if(a[i]&1) o.push_back(a[i]);
    	else e.push_back(a[i]);
    }

    
    sort(o.begin(), o.end());
    sort(e.begin(), e.end());

    debug(o);
    debug(e);

    unsigned long long alice=0, bob=0;

    while(o.size()>0 || e.size()>0){

    	if(e.size()>0){
	    	if(o.size()>0){
	    		if(e.back()>o.back()){
	    			alice += e.back();
	    			e.pop_back();
	    		} else {
	    			o.pop_back();
	    		}
	    	} else {
	    		alice += e.back();
	    		e.pop_back();
	    	}

    	} else 
    		if(o.size()>0)
    			o.pop_back();

    	if(o.size()>0){
    		if(e.size()>0){
	    		if(o.back()>e.back()){
	    			bob += o.back();
	    			o.pop_back();
	    		} else {
	    			e.pop_back();
	    		}
	    	}
	    	else {
	    		bob += o.back();
	    		o.pop_back();
	    	}
    	} else
    		if(e.size()>0)
    	 		e.pop_back();


    }

    debug(alice, bob);
    if(alice==bob){cout<<"Tie"<<endl; return;}
    if(alice>bob){cout<<"Alice"<<endl; return;}
    if(alice<bob){cout<<"Bob"<<endl; return;}


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