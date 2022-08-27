
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
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//debugger end

int recurse(string S, int i, int M, int K, int len)
{
  // Base Case
  if (i == S.length()-1)
  {
    if(K!=0) return 0;
    return 1;
  }
  if(K==0){
    int diff =  (S.length()-1) - i;
    if(diff>=M) return 1;
    return 0;
  }
  if (K < 0)
  {
    return 0;
  }

  while ((i < S.length() - 1) && ((S[i] - '0') & 1) && !((S[i + 1] - '0') & 1)) {
    i++;
    len++;
  }

  int sum = 0;

  if (len >= M) {
    sum += recurse(S, i + 1, M, K - 1, 1);
  }
  
  
  sum += recurse(S, i + 1, M, K, len+1);
  return sum;
  
}
 
void solve() {
    int n, m, k;
	  cin >> n >> m >> k;
    // debug(n,m,k);
    string s;
	  cin >> s;
	  cout << recurse(s, 0, m, k-1, 0);

	  cout << endl;
}
 
int main() { io
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    int t=1; 
    cin>>t; 
    while (t--) {
        solve();
    }
    return 0;
}