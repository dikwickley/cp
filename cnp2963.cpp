
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
	cout<<"crossword"<<endl;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
		cout<<a[i][j]<<" ";
	cout<<endl;
	}
}

bool check_word(vector<string>a, string word, int x, int y, int flag){

	vector<string> temp = a;
	if(flag==2){
		for(int i=0;i<word.size();i++){
			if(temp[x][y]=='-'){
				temp[x][y] = word[i];
				x++;
			} else {
				return false;
			}
		}
		if(a[x][y]=='-')return false;
	}

	if(flag==1){
		for(int i=0;i<word.size();i++){
			if(temp[x][y]=='-'){
				temp[x][y] = word[i];
				y++;
			} else {
				return false;
			}
		}
		if(a[x][y]=='-')return false;
	}
	// a=temp;
	return true;
}

// flag 1 is for horizontal flag 2 is for vertical
bool place_word(vector<string>&a, string word, int x, int y, int flag){

	vector<string> temp = a;
	if(flag==2){
		for(int i=0;i<word.size();i++){
			if(temp[x][y]=='-' && x<10){
				temp[x][y] = word[i];
				x++;
			} else {
				return false;
			}
		}
		if(a[x][y]=='-')return false;
	}

	if(flag==1){
		for(int i=0;i<word.size();i++){
			if(temp[x][y]=='-' && y<10){
				temp[x][y] = word[i];
				y++;
			} else {
				return false;
			}
		}
		if(a[x][y]=='-')return false;
	}
	a=temp;
	return true;
}

void rec(vector<string> a, vector<string> words, int I){
	// cout<<I<<endl;
	// cout<<words[I]<<endl;
	// print(a);
	


	if(I==words.size()){
		print(a);
		return;
	}

	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(a[i][j]=='-'){

				vector<string> temp = a;

				if(check_word(temp,words[I],i,j,1)){
					place_word(temp,words[I],i,j,1);
					rec(temp,words,I+1);
				}

				temp = a;

				if(check_word(temp,words[I],i,j,2)){
					place_word(temp,words[I],i,j,2);
					rec(temp,words,I+1);
				}

				temp = a;

				rec(temp,words,I+1);
			}
		}
	}


}
 
void solve() {
    vector<string> a(10);

    for(int i=0;i<10;i++) cin>>a[i];

    string wl;
	cin>>wl;

	

	vector<string> words;
	string word = "";

	for(int i=0,j=0;i<wl.length();i++){
		if(wl[i]!=';'){
			word += wl[i];
		}else {
			words.push_back(word);
			word = "";
		}
	}
	words.push_back(word);

	// print(a);

	// cout<<place_word(a,words[0],9,0,1)<<endl;

	// print(a);

	rec(a,words,0);
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