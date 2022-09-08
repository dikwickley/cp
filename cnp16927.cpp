#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
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

long long countValues(long long x) {
    
    int count=0;

    vector<int> z;

    int i = 1;

    while(x){
        if((x&1)==0){
            z.push_back(i);
        }
        x = x>>1;
        i++;
    }


    long long ans=0;

    for(int i=0;i<z.size();i++) ans += 1<<(z[i]-1);


    return ans;
}


class Runner {
    int t;
    vector<long long> x;

   public:
    void takeInput() {
        cin >> t;
        x.resize(t);
        for (int c = 0; c < t; c++) {
            cin >> x[c];
        }
    }

    void execute() {
        for (int i = 0; i < t; i++) {
            long long ans = countValues(x[i]);
        }
    }

    void executeAndPrintOutput() {
        for (int i = 0; i < t; i++) {
            long long ans = countValues(x[i]);
            cout << ans << "\n";
        }
    }
};

int main() {
    // freopen("./Testcases/large/in/input11.txt", "r", stdin);
    // freopen("./Testcases/large/out/output11.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}