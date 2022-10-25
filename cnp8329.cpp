
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int mod = 1e9 + 7;

vector<bool> primes(2*100001, true);

void sieve(){
	int n = primes.size();
	primes[1] = false;
	for(int i=2;i*i<=n;i++)
		if(primes[i]==true)
			for(int j=i*i;j<=n; j+=i)
				primes[j] = false;


	// for(int i=2;i<=n;i++)
	// 	if(p[i])
	// 		primes.push_back(i);
	// return primes;
}
 
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

    vector<int> a;

    for(int i=2;i<=n;i++){
		if(primes[i]){
			a.push_back(i);
		}
	}
	debug(a);
	int count = 0;
	for(int i=1;i<a.size();i++){
		int num = a[i]+a[i-1]+1;
		debug(num,a[i-1],a[i]);
		if(num>n) break;
		if(primes[num]){
			count++;
		}
	}

	cout<<count<<endl;
	

    
}
 
int main() { io
    #ifndef ONLINE_JUDGE
        freopen("error.err", "w", stderr);
    #endif
    int t=1; 
    // cin>>t; 
	sieve();
    while (t--) {
        solve();
    }
    return 0;
}