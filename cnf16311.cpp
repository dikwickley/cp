#include <bits/stdc++.h>
#include <vector>
#include <fstream>


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


int lengthOfLongestSubstring(string a) {
    // Write your code here.
    int length = 0;

    set<char> s;
    multiset<char> ms;

    int k = 0;

    int max = 0;

    for(int i=0;i<a.length();){


        if(s.size()==3){
            char c = a[k];
            auto itr = ms.find(c);
            if(itr!=ms.end()){
                ms.erase(itr);
            }
            if(ms.count(c)==0){
                s.erase(c);
            };
            k++;
        } else {


            s.insert(a[i]);
            ms.insert(a[i]);
            i++;
        }

        if(s.size() <= 2){
            if(ms.size() > max) max = ms.size();
        }


    } 

    return max;
}


class Runner{
    int t;
    vector<string> S;
    // vector<int> N;
    // vector<vector<int>> Arr;

public:
    void takeInput(){
        cin >> t;
        S.resize(t);
        // N.resize(t);
        // Arr.resize(t);
        for (int i = 0; i < t; i++){
            cin >> S[i];
            // cin >> N[i];
            // Arr[i].resize(N[i]);
            // for(int j=0; j<N[i]; j++){
            //     cin >> Arr[i][j];
            // }
        }
    }

    void execute(){
        vector<string> cpyS = S;
        // vector<int> cpyN = N;
        // vector<vector<int>> cpyArr = Arr;
        for (int i = 0; i < t; i++){
            int ans = lengthOfLongestSubstring(cpyS[i]);
        }
        vector<string>().swap(cpyS);
        // vector<int>().swap(cpyN);
        // vector<vector<int>>().swap(cpyArr);     
    }
    void executeAndPrintOutput(){
        for (int i = 0; i < t; i++){
            int ans = lengthOfLongestSubstring(S[i]);
            cout << ans << endl;
        }
    }
};


int main()
{

#ifndef ONLINE_JUDGE
    // freopen("testcases/Large/in/input11.txt", "r", stdin);
    // freopen("testcases/Large/out/output11.txt", "w", stdout);
#endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}
