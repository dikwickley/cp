
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
    vector<long long> b(n+2);

    unsigned long long total_sum = 0;

    for(int i=0;i<n+2;i++) {
    	cin>>b[i];
    	total_sum += b[i];
    }

 	sort(b.begin(), b.end());

 	debug(b);	

 	long long A = b[n+1];	//largest
 	long long B = b[n]; 	//second largest

 	//check if second largest is S;

 	unsigned long long ts = total_sum;

 	ts -= A;
 	ts -= B;

 	if(ts == B){
 		for(int i=0;i<n;i++){
 			cout<<b[i]<<" ";
 		}
 		cout<<endl;
 		return;
 	}

 	// check if largest is S;
 	ts = total_sum;

 	ts -= A;

 	for(int i=0;i<n+1;i++){
 		//assume a[i] is x;
 		ts -= b[i];

 		if(ts==A){
 			for(int j=0;j<n+1;j++){
 				if(j!=i){
 					cout<<b[j]<<" ";			
 				}
 			}
 			cout<<endl;
 			return;
 		}
 		ts += b[i];
 	}

 	cout<<-1<<endl;




	

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