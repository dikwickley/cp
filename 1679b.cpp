
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

#define ull signed long long int
#define ll long long int
 
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
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    ull sum = 0;

    for(int i=0;i<n;i++) {cin>>a[i]; sum+=a[i];}

    debug(sum);

    map<ll,ll> m;

    ll flag = -1;

    while(q--){
    	int t;
    	cin>>t;

    	if(t==2){
    		ll x;
    		cin>>x;
            flag = x;
            m.clear();
            sum = n*x;
    	}

    	if(t==1){
    		ll i,x;
    		cin>>i>>x;

            if(m.count(i)==0){
                if(flag==-1)
                    sum -= a[i-1];
                else
                    sum -= flag;
                sum += x;
                m.insert({i,x});
            } else {
                sum -= m[i];
                sum += x;
                m[i] = x;
            }
            
    	}
        debug(m);

    	cout<<sum<<endl;


    }


}
 
int main() { io
    #ifndef ONLINE_JUDGE
        freopen("error.err", "w", stderr);
    #endif
    int t=1; 
    // cin>>t; 
    while (t--) {
        solve();
    }
    return 0;
}