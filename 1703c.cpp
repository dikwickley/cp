
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

    vector<int> a(n);

    for(int i=0;i<n;i++) cin>>a[i];

    

	for(int i=0;i<n;i++){


		int b;
		cin>>b;
		string m;
		cin>>m;
		debug(b,m);

		for(int j=0;j<b;j++){
			if(m[j] == 'U'){
				if(a[i]-1<0)a[i]=9;
				else a[i]=a[i]-1;
			}else{
				if(a[i]+1>9)a[i]=0;
				else a[i]=a[i]+1;
			}
		}

	}



	// for(int i=0;i<b;i++){

	// 	if(m[i]=='D'){
	// 		//add
	// 		for(int j=0;j<n;j++){
	// 			if(a[j]-1 < 0) a[j] = 9;
	// 			else a[j] = a[j] - 1;
	// 		}
	// 	} else {
	// 		//subract
	// 		for(int j=0;j<n;j++){
	// 			if(a[j]+1 > 9) a[j] = 0;
	// 			else a[j] = a[j] + 1;
	// 		}
	// 	}
	// }

	for(int i=0;i<n;i++) cout<<a[i]<<" ";\
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