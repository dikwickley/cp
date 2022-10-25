
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

int hammingDistance(vector<int> n1, vector<int> n2)
{
	int n = n1.size();
	int count = 0;
	for(int i=0;i<n;i++){
		if(n1[i]!=n2[i]) count++;
	}

 
    return count;
}
 
void solve() {
    int n;
    cin>>n;
    vector<int>a(n), b(n);

    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i++) cin>>b[i];


    int ones=0;
	bool flag = true;

	for(int i=0;i<n;i++){
		if(a[i]!=b[i]) flag = false;
		if(a[i]==1) ones ++;
		if(b[i]==1) ones --;
	}

	if(flag){
		cout<<0<<endl; return;
	}


	int hamming_distance = hammingDistance(a,b);

	if(hamming_distance > abs(ones)){
		cout<<abs(ones)+1<<endl; return;kkkkkkkkkkkkkkkhhffffffbp;
	}

	cout<<abs(ones)<<endl;oooo
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