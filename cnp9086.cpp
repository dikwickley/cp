#include <algorithm>
#include <iostream>
#include <vector>
#include<algorithm>

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

vector<int> waveFormArray(vector<int> &a, int n) {
    sort(a.rbegin(),a.rend());

    vector<int> ans(n,0);


    if(n%2==0){
        for(int i=0,j=0;i<n/2;i++,j+=2) ans[j] = a[i];
        for(int i=n/2,j=1;i<n;i++,j+=2) ans[j] = a[i];
    }
    else{
        for(int i=0,j=0;i<=n/2;i++,j+=2) ans[j] = a[i];
        for(int i=n/2+1,j=1;i<n;i++,j+=2) ans[j] = a[i];
    }

    // debug(a);
    // debug(ans);


    return ans;

}

string checkValid(vector<int> arr){
    if(arr.size()==0){
        return "False";
    }
    
    if(arr.size()==1){
        return "True";
    }
    
    if(arr[0]<arr[1]){
        return "False";
    }
    

    for(int i=2;i<arr.size();i+=2){
        if(arr[i]<arr[i-1]){
            return "False";
        }
        
        if(i!=arr.size()-1){
            if(arr[i]<arr[i+1]){
                return "False";
            }
        }
    }
    return "True";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
  

    while (t--) {
        int n;
        cin >> n;

        vector<int> elements;
        for (int i = 0; i < n; i++) {
            int ele;
            cin >> ele;
            elements.push_back(ele);
        }

        vector<int> answer = waveFormArray(elements, n);
        cout << checkValid(answer) << endl;
    }
    return 0;
}