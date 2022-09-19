
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
  string s; 
  cin >> s;
  char st = s[0];
  int n = s.size();
  char en = s[n - 1];

  map<char, vector<int>> map;
  for (int i = 0; i < n; i++) {
    map[s[i]].push_back(i);
  }
  vector<int> res;
  if (st >= en) {
  	for (auto it = map.rbegin(); it != map.rend(); it++) {
      if (it->first > st || it->first < en) continue;
      for (int p : it->second) {
        res.push_back(p);
      }
    }
    
  }
  else {
    for (auto it : map) {
      if (it.first > en || it.first < st) continue;
      for (int p : it.second) {
        res.push_back(p);
      }
    }
  }
  int ans = 0;
  for(int i = 1; i < res.size(); ++i) {
    ans += abs(s[res[i-1]] - s[res[i]]);
  }
  cout << ans << " " << res.size() << endl;
  for(auto a: res) {
    cout << a+1 << " ";
  }
  cout << endl;
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