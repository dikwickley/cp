#include<iostream>

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

int hamming_distance(int a, int b){
    int ans = 0;
    while(a || b){
        ans += (a&1) ^ (b&1);
        a = a>>1;
        b = b>>1;
    }

    return ans;
}

long long int sumOfHammingDistance(int *arr, int n) {

   // Write your code here.
    long long int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans += hamming_distance(arr[i],arr[j]);
        }
    }
    return ans;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin>>n;
        int a[n];

        for(int i=0;i<n;i++){
        	cin>>a[i];
        }
        cout<< sumOfHammingDistance (a,n);
        cout << "\n";
    }
    return 0;

}