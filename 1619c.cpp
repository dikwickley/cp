
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
    unsigned long long a,s;
    cin>>a>>s;

    vector<int> b;

    while(s>0){

    	int s_last = s%10;
    	s /= 10;

    	int a_last = a%10;
    	a /= 10;

    	if(s_last<a_last){
            if(s>0){
                s_last = s_last + (s%10)*10;
                if(s_last < a_last) {cout<<-1<<endl;return;}
                s/=10;    
            } else {cout<<-1<<endl;return;}
    		
    	}

        if(s_last > a_last+9) {cout<<-1<<endl;return;}

        if(s_last == a_last){
            b.push_back(0);
        }else{ 
            b.push_back(s_last-a_last);
    	}
        debug(s_last,a_last);

    }


    debug(b);

    if(a>0) {cout<<-1<<endl;return;}


    unsigned long long ans = 0;

    for(int i=b.size()-1;i>=0;i--){
    	ans = ans*10 + b[i];
    }

    cout<<ans<<endl;



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