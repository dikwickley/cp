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

int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    
    vector<int> a(n);

    for(int i=0;i<n;i++) a[i] = gas[i] - cost[i];

    int g = 0, c=0;
    
    for(int i=0;i<n;i++) g += gas[i];
    for(int i=0;i<n;i++) c += cost[i];

    if(g<c) return -1;

    // debug(a);
    if(n==1){
        if(gas[0]-cost[0] >= 0) return 0;
        else return -1;
    }

    int total = 0;
    int last = 0;
    for(int i=0;i<n;i++){
        if(total < 0 ){
            last = i;
            total = 0;
        }
        total += a[i];
    }

    if(total < 0) return -1;
    else return last;
    

}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> gas(n), cost(n);

        for(int i = 0; i < n; i++) {
            cin >> gas[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> cost[i];
        }

        cout << minimumStartingIndex(gas, cost, n) << endl;
    }
}