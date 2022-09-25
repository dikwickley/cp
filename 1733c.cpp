
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
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];

  vector<pair<int, int>> ops;

  if ((a[0] & 1) ^ (a[n - 1] & 1)) {
    ops.push_back({1, n});
    a[n - 1] = a[0];

    for (int i = n - 2; i >= 0; --i) {
    if ((a[i] & 1) ^ (a[n - 1] & 1) == 0) {
	      ops.push_back({i + 1, n});
	      a[i] = a[n - 1];
	    }
	  }
	  for (int i = 1; i < n - 1; ++i) {
	    if ((a[i] & 1) ^ (a[n - 1] & 1)) {
	      ops.push_back({1, i + 1});
	      a[i] = a[0];
	    }
	  }
	  cout << ops.size() << endl;
	  for(int i=0;i<ops.size();i+=1) {
	    cout << ops[i].first << " " << ops[i].second << endl;
	  }
  } else{

  	for (int i = n - 2; i >= 0; --i) {
	    if ((a[i] & 1) ^ (a[n - 1] & 1) == 0) {
	    	a[i] = a[n - 1];
	      ops.push_back({i + 1, n});
	     
	    }
	  }
	  for (int i = 1; i < n - 1; ++i) {
	    if ((a[i] & 1) ^ (a[n - 1] & 1)) {
	    	a[i] = a[0];
	      ops.push_back({1, i + 1});
	      
	    }
	  }
	  cout << ops.size() << endl;
	  for(int i=0;i<ops.size();i+=1) {
	    cout << ops[i].first << " " << ops[i].second << endl;
	  }

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