
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
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


long long total =  0;

void merge(vector<ll> &a, int start, int mid, int end){
	vector<ll> left, right;
	for(int i=start; i<=mid;i++) left.push_back(a[i]);
	for(int i=mid+1; i<=end;i++) right.push_back(a[i]);



	int n = left.size();
	int m = right.size();

	int l = 0;
	int r = 0;
	int c = start;

	long long rolling = 0;

	while(l<n && r<m){
		if(left[l]<right[r]){
			a[c] = left[l];
			rolling += a[c];
			c++;l++;
		} else {
			a[c] = right[r];
			total += rolling;
			c++;r++;
			
		}
	}

	while(l < n){
		a[c] = left[l];
		c++;l++;
	}

	while(r < m){
		a[c] = right[r];
		c++;r++;
		total += rolling;

	}

}

void merge_sort(vector<ll> &a, int start, int end){
	if(start >= end) return;
	
	int mid = start + (end - start) / 2;


	merge_sort(a,start,mid);
	merge_sort(a,mid+1,end);

	merge(a,start,mid,end);

}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);

    for(int i=0;i<n;i++) {
    	cin>>a[i];
    }

    total = 0;

    merge_sort(a,0,n-1);


    cout<<total<<endl;

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