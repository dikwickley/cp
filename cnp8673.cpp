#include <iostream>
#include <vector>

using namespace std;

//debugger start
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...)  cout<<"l "<<__LINE__<<": "<< "[" << #x << "] = ["; _print(x)
// #define debugf(s, x...) cout<<"l "<<__LINE__<<": "<<s<<" : "<< "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//debugger end

int requiredCandies(vector < int > &a) {
    int n = a.size();

    

    vector<int> c(n,1);

    if(n==1) return 1;


    c[0] += a[0]>a[1]?1:0;
    c[n-1] += a[n-1]>a[n-2]?1:0;

    

    for(int i=1;i<=n-2;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]){
            c[i] = max(c[i-1],c[i+1])+1;
            continue;
        } 

        if(a[i]>a[i-1]) c[i] = c[i-1]+1;
        if(a[i]>a[i+1]) c[i] = c[i+1]+1;
        
    }

    

    c[0] = a[0]>a[1]?c[1]+1:c[0];
    c[n-1] = a[n-1]>a[n-2]?c[n-2]+1:c[n-1];

    for(int i=n-2;i>=0;i--){
        if(a[i]>a[i-1]&&a[i]>a[i+1]){
            c[i] = max(c[i-1],c[i+1])+1;
            continue;
        } 

        if(a[i]>a[i-1]) c[i] = c[i-1]+1;
        if(a[i]>a[i+1]) c[i] = c[i+1]+1;
        
    }


    debug(c);


    int ans=0;

    for(int i=0;i<n;i++) ans += c[i];


    return ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
           cin >> arr[i];
        }



        cout << requiredCandies(arr) <<endl;
    }
}