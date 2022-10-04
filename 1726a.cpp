
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
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    int max_index = max_element(a.begin(), a.end()) - a.begin();
    int min_index = min_element(a.begin(), a.end()) - a.begin();




    if(a[max_index] == a[n-1]){
    	cout<<a[max_index] - a[min_index]<<endl;
    	return;
    }

    if(a[min_index] == a[0]){
    	cout<<a[max_index] - a[min_index]<<endl;
    	return;
    }

    for(int i=1;i<n-1;i++){
    	if((a[i-1]==a[max_index] && a[i]==min_index) || (a[i]==a[max_index] && a[i-1]==min_index) ){
    		cout<<a[max_index] - a[min_index]<<endl;
    		return;
    	}
    	if((a[i-1]==a[min_index] && a[i]==max_index) || (a[i]==a[min_index] && a[i-1]==min_index) ){
    		cout<<a[max_index] - a[min_index]<<endl;
    		return;
    	}
    }

    if(abs(max_index-min_index)==1){
    	cout<<a[max_index] - a[min_index]<<endl;
    	return;
    } else {

    	int x = a[max_index] - a[0];
	    int y = a[n-1] - a[min_index];

	    cout<<max(x,y)<<endl;

	    return;
    	
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