
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

// bool rec(string s1, string s2){
// 	if(s1==s2) {
// 		return true;
// 	}

// 	if(s1.length() < 2 && s1!=s2) return false;

// 	char a1 = s1[s1.size()-1] - '0';
// 	s1.pop_back();
// 	char a2 = s1[s1.size()-1] - '0';
// 	s1.pop_back();

// 	int mi = min(a1,a2);
// 	int ma = max(a1,a2);

// 	return rec(s1 + to_string(mi),s2) || rec( s1 + to_string(ma),s2);


// }
 
void solve() {
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;

    int i=n-1,j=m-1;

    while(i>=0 && j>=1){
    	if(b[j]!=a[i]){cout<<"NO"<<endl; return;}
    	j--;i--;
    }

    while(i>=0){
    	if(b[0]==a[i]) {cout<<"YES"<<endl; return;}
    	i--;
    }

    cout<<"NO"<<endl;
        


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