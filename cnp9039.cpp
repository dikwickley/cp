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

vector<int> sortArrayByKBit(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<int> ans;

    for(int i=0;i<n;i++){
        
        if(((arr[i]>>k-1)&1) == 0){
            ans.push_back(arr[i]);  
        } 
    }

    for(int i=0;i<n;i++){
        if(((arr[i]>>k-1)&1)==1) ans.push_back(arr[i]);
    }
    return ans;
}

class Runner {
    int t;
    vector<vector<int>> inputArr1;
    vector<vector<int>> inputArr2;

public:
    void takeInput() {
        cin >> t; 
        inputArr1 = vector<vector<int>>(t);
        inputArr2 = vector<vector<int>>(t);
        for (int i = 0; i < t; i++) {
            int n , k;
            cin >> n >> k;
            inputArr1[i].push_back(n) , inputArr1[i].push_back(k);
            inputArr2[i] = vector<int>(n);
            for(int j = 0; j<n; j++){
                cin>>inputArr2[i][j];
            }
        }
    }

    void execute() {
        vector<vector<int>> inputArrCpy1 = inputArr1;
        vector<vector<int>> inputArrCpy2 = inputArr2;
        for(int i = 0; i < t; i++) {
            vector<int> result = sortArrayByKBit(inputArrCpy1[i][0] , inputArrCpy1[i][1] , inputArrCpy2[i]);
        }
    }

    void executeAndPrintOutput() {
        for(int i = 0; i < t; i++) {
            vector<int> result = sortArrayByKBit(inputArr1[i][0] , inputArr1[i][1] , inputArr2[i]);
            for(int j = 0; j<result.size(); j++){
                cout<<result[j]<<" ";
            }
            cout << '\n';
        }
    }
};

int main() {
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}