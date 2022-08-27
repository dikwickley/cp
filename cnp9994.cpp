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

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    sort(arr.begin(),arr.end());



    return {arr[k-1],arr[n-k]};
}

class Runner
{
    int t;
    vector<vector<int>> arrs;
    vector<int> ns, ks;

public:
    void takeInput()
    {
        cin >> t;
        for (int i = 0; i < t; i++)
        {
            int n, k;
            cin >> n >> k;

            vector<int> arr(n);
            for(int i = 0; i < n; i++) 
            {
                cin >> arr[i];
            }

            ns.push_back(n);
            ks.push_back(k);
            arrs.push_back(arr);
        }
    }

    void execute()
    {
        vector<vector<int>> arrsCopy = arrs;
        vector<int> nsCopy = ns;
        vector<int> ksCopy = ks;
        for (int i = 0; i < t; i++)
        {
            vector<int> result = kthSmallLarge(arrsCopy[i], nsCopy[i], ksCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<int> result = kthSmallLarge(arrs[i], ns[i], ks[i]);
            cout << result[0] << ' ' << result[1] << '\n';
        }
    }
};

int main()
{   
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}