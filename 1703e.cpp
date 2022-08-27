
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
    debug(n);
    char a[n][n];
    int c[n][n];

    for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++) c[i][j] = 0;

    for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++) cin>>a[i][j];


    // for(int i=0;i<n;i++)
    // 	for(int j=0;j<n;j++) cout<<a[i][j]<<" \n"[j==n-1];

    int r = 4 ;

	while(r--){

		// for(int i=0;i<n;i++)
  //   	for(int j=0;j<n;j++) cout<<a[i][j]<<" \n"[j==n-1];

    		// cout<<endl;
		
		char b[n][n];
		

		for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++) b[j][i] = a[i][j];
		

    	for(int i=0;i<n;i++)
    		reverse(b[i],b[i]+n);




		for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++) c[i][j] += (b[i][j] - '0');

    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++) a[i][j] = b[i][j];  


	}

     //    for(int i=0;i<n;i++)
    	// for(int j=0;j<n;j++) cout<<c[i][j]<<" \n"[j==n-1];

    	int res = 0;

    	for(int i = 0; i < (n) / 2; ++i) {
    		for(int j = 0; j < (n) / 2; ++j) {
    			res += min(c[i][j], 4-c[i][j]);
    		}
    	}
    	if(n % 2)
    	for(int i = 0; i < (n+1) / 2; ++i) {
    		res += min(c[i][((n+1) / 2) - 1], 4 - c[i][((n+1) / 2) - 1]);
    	}
    	cout << res;
    	cout<<endl;

    	// for(int i=0;i<n;i++)
    	// for(int j=0;j<n;j++) cout<<c[i][j]<<" \n"[j==n-1];

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