#include <cstdlib>
#include <string>
#include <fstream>
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

int xorSum(vector<int> &arr1, vector<int> &arr2)
{
    int xor_one = 0;

    for(int i=0;i<arr1.size();i++) xor_one = xor_one ^ arr1[i];

    int ans = 0;

    for(int i=0;i<arr2.size();i++) {
        ans ^= (arr2[i]&xor_one);
    }

    return ans;
}

class Runner {
    int t;
    vector < vector < int > > arr;
    vector < vector < int > > arr1;
    
    public:
        void takeInput() {

            cin >> t;

            arr.resize(t);
            arr1.resize(t);

            for (int c = 0; c < t; c++) {

                int n, m;

                cin >> n >> m;

                arr[c].resize(n);
                arr1[c].resize(m);

                for (int i = 0; i < n; i++) {

                    int x;
                    cin >> x;
                    arr[c][i] = x;

                }

                for (int i = 0; i < m; i++) {

                    cin >> arr1[c][i];

                }

            }
        }

    void execute() {

        vector < vector < int > > arrcopy = arr;
        vector < vector < int > > arr1copy = arr1;


        for (int i = 0; i < t; i++) {

            int ans = xorSum(arrcopy[i], arr1copy[i]);

        }

    }

    void executeAndPrintOutput() {

        for (int i = 0; i < t; i++) {

            int ans = xorSum(arr[i], arr1[i]);

            cout << ans;
            
            cout<<"\n";

        }
    }
};

int main() {
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}