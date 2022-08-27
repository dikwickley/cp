
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


void print(vector<string> a){

	cout<<"matrix"<<endl;

	for(int i=0;i<a.size();i++){
    	cout<<a[i]<<endl;
    }
}
 
void solve() {
    int n,m;

    cin>>n>>m;

    vector<string> a(n);


    int total_ones = 0;
    for(int i=0;i<n;i++){
    	cin>>a[i];

    	for(int j=0;j<m;j++){
    		if(a[i][j]=='1') total_ones ++;
    	}
    }


    debug(total_ones);

    if(total_ones==n*m){
    	cout<<(n*m)-2<<endl;
    	return;
    }


    if(total_ones==0){
    	cout<<0<<endl;
    	return;
    }

    bool single_zeroes = false;
    bool diagonal_zeroes = false;
    bool double_zeroes = false;

    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){

    		if(a[i][j]=='0') single_zeroes = true;

    		if(i-1>=0){
    			if(a[i][j]=='0' && a[i-1][j]=='0') double_zeroes = true;	
    		}
    		if(i+1<=n-1){
    			if(a[i][j]=='0' && a[i+1][j]=='0') double_zeroes = true;
    		}

    		if(j-1>=0){
	    		if(a[i][j]=='0' && a[i][j-1]=='0') double_zeroes = true;
    		}

    		if(j+1<=m-1){
	    		if(a[i][j]=='0' && a[i][j+1]=='0') double_zeroes = true;
    		}

    	}
    }



    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(i-1>=0 && j-1>=0)
    		if(a[i][j]=='0' && a[i-1][j-1]=='0') diagonal_zeroes = true;
    		if(i+1<n && j-1>=0)
    		if(a[i][j]=='0' && a[i+1][j-1]=='0') diagonal_zeroes = true;
    		if(i-1>=0 && j+1<n)
    		if(a[i][j]=='0' && a[i-1][j+1]=='0') diagonal_zeroes = true;
    		if(i+1<n && j+1<n)
    		if(a[i][j]=='0' && a[i+1][j+1]=='0') diagonal_zeroes = true;
    	}
    }

    debug(single_zeroes);
    debug(diagonal_zeroes);
    debug(double_zeroes);

    if(double_zeroes || diagonal_zeroes){
    	cout<<total_ones<<endl;
    	return;
    }



    if(single_zeroes){
    	cout<<total_ones-1<<endl;
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
    	// cout<<"test_case"<<t<<endl;
        solve();
    }
    return 0;
}