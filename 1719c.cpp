
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
	// int k; cin >> k;
	vector<int> v(n+1, 0);
	vector<int> h(n+1, 0);
	vector<pair<int,int>> nh(n+1);
	vector<int> position(n+1);
	int qq; cin >> qq;

	for(int i = 0; i <n; i+=1) {
		cin >> v[i];
		position[i+1] = v[i];
	}
	if(n == 1) {
		h[v[0]]+=1;
	}
	int c = v[0] > v[1] ? v[0] : v[1];
	nh[0] = {c, h[c]};
	for(int i = 1; i < n; i+=1) {
		if(c < v[i]) {
			c = v[i];
		}
		h[c]++;
		nh[i] = {c, h[c]};
	}

	for(int i = 0; i < qq; i+=1) {
		int p; 
		cin >> p; 
		int pow = position[p];
		int r; 
		cin >> r;
		if(p > r + 1) {
			cout << 0 << endl; continue;
		}
		if(r < n) {
			if(nh[r].first != pow) {
				cout << h[pow] << endl;
			}
			else {
				cout << nh[r].second << endl;
			}
		} else {
			if(pow == n) {
				cout << ((r - (n - 1)) + h[pow]) << endl;
			}
			else {
				cout << h[pow] << endl;
			}
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