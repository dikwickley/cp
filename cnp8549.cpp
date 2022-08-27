#include<iostream>
#include<vector>
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


#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
		const size_t len = nums.size();
        if (len < 3)
            return {};
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> s;
        
        for(int i = 0; i < len - 2; i++) {
            
            int j = i + 1;
            int k = len - 1;
            
            while (j < k) {
            
                int sum = nums[i] + nums[j] + nums[k];
                if (K == sum) {
                    s.insert({nums[i], nums[j++], nums[k--]});
                }
                else if (K > sum)
                    j++;
                else if (K < sum)
                    k--;
            }
        }
        
        vector<vector<int>> results(s.begin(), s.end());
        
        
        return results;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int K;
        cin >> K;
        vector <vector<int>> ans = findTriplets(arr, n, K);
        if (ans.size() == 0) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < (int) ans.size(); i++) {
            sort(ans[i].begin(), ans[i].end());
            cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';

        }
    }
}