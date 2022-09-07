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

void print(vector<vector<char>> m){
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++){
			cout<<m[i][j]<<"";
		}
		cout<<endl;
	}
}

bool check_point(vector<vector<char>> m, int k, int x, int y){

	int n = m.size();
	if(x<0 || x>n-1) return false;
	if(y<0 || y>n-1) return false;

	for(int i=x;i<=min(x+k-1,n-1);i++){
		if(m[i][y] == 'X') return false;
	}
	for(int i=x;i>=max(x-k+1,0);i--){
		if(m[i][y] == 'X') return false;
	}
	for(int i=y;i<=min(y+k-1,n-1);i++){
		if(m[x][i] == 'X') return false;
	}
	for(int i=y;i>=max(y-k+1,0);i--){
		if(m[x][i] == 'X') return false;
	}
	return true;
}
 
void solve() {
    int n,k,r,c;

    cin>>n>>k>>r>>c;

    vector<vector<char>> m(n,vector<char>(n,'.'));

    m[r-1][c-1] = 'X';

    stack<pair<int,int>> s;

    s.push({r-1,c-1});

    // cout<<check_point(m,k,3,4)<<endl;


    while(true){

    	if(s.empty()) break;
    	pair<int,int> t =  s.top();
    	s.pop();

    	int x = t.first;
    	int y = t.second;

    	debug(x,y);

    	if(check_point(m,k,x,y))
	    	m[x][y] = 'X';

    	

    	//top bottom
    	if(x-k >= 0 && check_point(m,k,x-k,y)){
    		s.push({x-k,y});
    	}
    	if(x+k <= n-1 && check_point(m,k,x+k,y)){
    		s.push({x+k,y});
    	}
    	if(y-k >= 0 && check_point(m,k,x,y-k)){
    		s.push({x,y-k});
    	}
    	if(y+k <= n-1 && check_point(m,k,x,y+k)){
    		s.push({x,y+k});
    	}
    	if(x-1 >=0 && y-1>=0 && check_point(m,k,x-1,y-1)){
    		s.push({x-1,y-1});
    	}
    	if(x-1 >=0 && y+1<=n-1 && check_point(m,k,x-1,y+1)){
    		s.push({x-1,y+1});
    	}
    	if(x+1 <=n-1 && y-1>=0 && check_point(m,k,x+1,y-1)){
    		s.push({x+1,y-1});
    	}
    	if(x+1 <=n-1 && y+1<=n-1 && check_point(m,k,x+1,y+1)){
    		s.push({x+1,y+1});
    	}
    	
    }

    for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++){
			if(check_point(m,k,i,j))
	    		m[i][j] = 'X';
		}
	}

    print(m);
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