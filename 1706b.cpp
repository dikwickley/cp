
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

    map<int, vector<int>> m_h;
	map<int, vector<int>> m_m;
	map<int, int> m_i;
	

	for(int i=0;i<n;i++){
		if(m_i.count(a[i])==0){
			m_h.insert({a[i],vector<int>(1,1)});
			m_i.insert({a[i],i});
			m_m.insert({a[i],{i}});
		} else {
			if((m_i[a[i]] - i)%2!=0 || m_i[a[i]] - i == 1){
				int vn = m_h[a[i]].size();
				sort(m_h[a[i]].begin(), m_h[a[i]].end());
				m_h[a[i]][vn-1]+=1;
				m_i[a[i]] = i;
			} else {
				// for(int k=0;k<m_h[a[i]].size();k++){
				// 	debug(a[i],m_m[a[i]][k]);
				// 	// if((m_m[a[i]][k] - i) % 2 != 0 || m_m[a[i]][k] - i == 1){
				// 	// 	m_h[a[i]][m_m[a[i]][k]] ++;
				// 	// }
				// }
				m_h[a[i]].push_back(1);
				m_m[a[i]].push_back(i);
				m_i[a[i]] = i;
			}
		}
		debug(m_i);
	}



	for(int i=1;i<=n;i++){
		if(m_h.count(i)!=0){
			cout<<*max_element(m_h[i].begin(), m_h[i].end())<<" ";
		} else {
			cout<<0<<" ";
		}
	}

	cout<<endl;

}
 
int main() { io
    #ifndef ONLINE_JUDGE
        freopen("error.err", "w", stderr);
    #endif
    int t=1; 
    cin>>t; 
    while (t--) {
    	debug(t);
        solve();
    }
    return 0;
}