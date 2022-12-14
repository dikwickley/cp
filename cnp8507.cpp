
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




vector<int> sieve(int n){
	vector<bool> p(n+1, true);

	p[1] = false;

	for(int i=2;i*i<n;i++){
		if(p[i]==true){
			for(int j=i*i;j<=n; j+=i)
				p[j] = false;
		}
	}

	vector<int> primes;

	for(int i=2;i<=n;i++)
		if(p[i])
			primes.push_back(i);

	return primes;
}
 
void solve() {
    int l,r;
    cin>>l>>r;

    if(l==1) {
    	vector<int> segmented_primes = sieve(r);

    	for(int i=0;i<segmented_primes.size();i++) cout<<segmented_primes[i]<<" ";
    	cout<<endl;

    	return;
    }

    vector<int> pl =  sieve(l-1);

    vector<bool> sp(r-l+1, true);

    debug(pl);

    for(int i=0;i<pl.size();i++){
    	int  p = pl[i];

    	int first = (l/p)*p;

    	if(l%p != 0){
    		first += p;
    	}

    	debug(first);

    	if(first>r) break;

    	for(int j=first;j<=r;j+=p){
    		sp[j-l] = false;
    	}
    }

    for(int i=l;i*i<=r;i++){
    	if(sp[i-l]==true){

    		for(int j=i*i;j<=r;j+=i){
    			sp[j-l] = false;
    		}
    	}
    }

    

    for(int i=0; i<sp.size();i++){
    	if(sp[i])
    		cout<<i+l<<" ";    		
    }

    cout<<endl;
    
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