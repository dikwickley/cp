#include <iostream>
#include <vector>

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

#include <set>
#include <map>

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{

    vector<pair<int,int>> ans;
    multiset<int> s;
    int count = 0;
    for(int i=0;i<n;i++){
        if(s.count(target-arr[i])>0){
            s.erase(s.find(target-arr[i]));
            ans.push_back({target-arr[i],arr[i]});   
            count ++;
        } else {
            s.insert(arr[i]);
        }
        debug(s);
        
    }

    if(count==0) return {{-1,-1}};
    return ans;

}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("error.err", "w", stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
    	int n,target;
    	cin>>n>>target;
    	vector<int> v(n);
    	for(int i=0;i<n;i++)
    	{
    		cin>>v[i];
    	}
    	
    	vector<pair<int,int>> ans=twoSum(v,target,n);
    	for(auto i:ans)
    	{
    		if(i.first<i.second)
    			cout<<i.first<<" "<<i.second<<"\n";
    		else
    			cout<<i.second<<" "<<i.first<<"\n";
    	}
    	
    }
}