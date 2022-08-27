
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
    vector<long long>p(n);
    vector<int> f(n);
    vector<int> b(n);

    for(int i=0;i<n;i++) cin>>p[i];
    
    for(int i=0;i<n;i++) cin>>f[i];

    for(int i=0;i<n;i++) cin>>b[i];

   

    map<int,vector<long long>> tshirt;
	
	for(int i=0;i<n;i++){
		if(tshirt.count(f[i])==0){
			tshirt.insert({f[i],{p[i]}});
		} else {
			tshirt[f[i]].push_back(p[i]);
		}

		if(tshirt.count(b[i])==0){
			tshirt.insert({b[i],{p[i]}});
		} else {
			tshirt[b[i]].push_back(p[i]);
		}
	}

	
	for(int i=1;i<=3;i++)
		sort(tshirt[i].rbegin(), tshirt[i].rend());
	

    int m;
	
	cin>>m;

	vector<int> c(m);
	vector<int> d(4,0);
	vector<int> ans(m,0);
	set<int> used;


	for(int i=0;i<m;i++){ 
		cin>>c[i];

		if(tshirt[c[i]].size()==0){
			ans[i] = -1;
		} else {
			ans[i] = -1;

			while(used.count(*tshirt[c[i]].rbegin())!=0){
				tshirt[c[i]].pop_back();
			}

			if(tshirt[c[i]].size() != 0){
				ans[i] = *tshirt[c[i]].rbegin();
				used.insert(*tshirt[c[i]].rbegin());
			}

		}

	}

	for(int i=0;i<m;i++) cout<<ans[i]<<" ";


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