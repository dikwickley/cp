
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
    long long n,k,x;
    cin>>n>>k>>x;
    vector<long long>a(n);
    for(long long i=0;i<n;i++) cin>>a[i];

    sort(a.begin(), a.end());

 	
 	long long count = 1;

 	vector<long long> mh;

 	for(long long i=1;i<n;i++){
 		long long diff = a[i]-a[i-1];
 		if(diff > x) {
 			count ++;
 			debug(a[i-1],a[i],diff);

 			if(diff-1==x)mh.push_back(1);
 			else mh.push_back((diff-1)/x);
 		}
 	}

 	if(count==1) {cout<<1<<endl; return;}

 	sort(mh.begin(), mh.end());


 	debug(mh);

 	for(int i=0;i<mh.size();i++){
 		if(k-mh[i]>=0){
 			count--;
 			k-=mh[i];
 		} else break;
 	}



 	cout<<count<<endl;

 	

}
 
int main() { io
    #ifndef ONLINE_JUDGE
        freopen("error.err", "w", stderr);
    #endif
    int t=1; 
    // cin>>t; 
    while (t--) {
        solve();
    }
    return 0;
}