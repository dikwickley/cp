
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
   pair<int,int> s; 
   int st = 0;
   cin>>n>>s.first>>s.second;

   st = s.first*60 + s.second;

   

   vector<pair<int,int>>t(n);
   vector<int> at(n);

   for(int i=0;i<n;i++){
    	cin>>t[i].first>>t[i].second;
    	at[i] = t[i].first * 60 + t[i].second;
   }

   sort(at.begin(), at.end());
	
	debug(st);
	debug(at);

	int next = -1;

	for(int i=0;i<n;i++){
		if(at[i] >= st){next = i; break;}
	}

	debug(next);

	if(next == -1){
		int left_time = (1440 - st) + at[0];
		cout<<left_time/60<<" "<<left_time%60<<endl;
	} else {
		int left_time = at[next]-st;
		cout<<left_time/60<<" "<<left_time%60<<endl;
	}

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