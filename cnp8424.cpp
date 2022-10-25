
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int mod = 1e9 + 7;

vector<int> sieve(int n){
	vector<bool> p(n+1, true);
	p[1] = false;
	for(int i=2;i*i<=n;i++)
		if(p[i]==true)
			for(int j=i*i;j<=n; j+=i)
				p[j] = false;
	vector<int> primes;
	for(int i=2;i<=n;i++)
		if(p[i])
			primes.push_back(i);
	return primes;
}

//counter
int __counter = 0;
#define cnt cerr<<"l "<<__LINE__<<": "<<++__counter<<endl;
 
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

long long extendedGCD(long long a, long long b, long long &x, long long &y){
	//to solve ax+by=c (where x and y are long longegers)
	 if(b==0){
	 	x = 1; y = 0; return a;
	 }
	 long long x1, y1;
	 long long g = extendedGCD(b, a%b, x1, y1);
	 x = y1; y = x1 - (a/b)*y1; return g;
}

 
void solve() {
    long long a,b,c;
    long long x,y;

    cin>>a>>b>>c;

    long long g = extendedGCD(a,b,x,y);

    x = (x*c)/g;
    y = (y*c)/g;


	long long l = ceil(-1.0*x/(b/g));
	long long r = floor(1.0*y/(a/g));


	if(c%g!=0){
    	cout<<0<<endl; return;
    }

	if(l>r){
		cout<<0<<endl; return;
	}

	cout<<r-l+1<<endl;

    
}
 
int main() { io
    #ifndef ONLINE_JUDGE
        freopen("error.err", "w", stderr);
    #endif
    int t=1; 
    int t_count = 1;
    cin>>t; 
    while (t--) {
    	cerr<<"#tc: "<<t_count<<endl;
        solve();
        t_count++;
    }
    return 0;
}