
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
    vector<int> b(n);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    debug(a);
	debug(b);

	vector<pair<int,int>> bitmap;


	for(int i=0;i<n;i++){
		bitmap.push_back({a[i],1});
		bitmap.push_back({b[i],0});
	}


	sort(bitmap.begin(), bitmap.end());

	debug(bitmap);

	int x=bitmap.size()-1; //max 1
	int y=bitmap.size()-1; //min 1

	vector<int> d_min;
	vector<int> d_max;

	int one_count = 0;
	int zero_count = 0;

	for(int i=bitmap.size()-1;i>=0;i--){


		if(bitmap[i].second==1){
			d_max.push_back(bitmap[x].first - bitmap[i].first);
			d_min.push_back(bitmap[y].first - bitmap[i].first);
		}
		
		if(bitmap[i].second==0){
			y=i;
		}

		

		if(bitmap[i].second==1) one_count++;
		if(bitmap[i].second==0) zero_count++;

		if(one_count==zero_count){

			x=i-1;
			y=i-1;
		}



	}


	for(int i=n-1;i>=0;i--) cout<<d_min[i]<<" \n"[i==0];

	for(int i=n-1;i>=0;i--) cout<<d_max[i]<<" \n"[i==0];




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