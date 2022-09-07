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

// string rec(string family, int current_gen, int target_gen, long long int k){
//     if(current_gen == target_gen){
//         if(family[k-1]=='m') return "Male";
//         else return "Female";
//     }

//     string new_family = "";

//     for(int i=0;i<family.size();i++){
//         if(family[i]=='m'){
//             new_family += "mf";
//         } else {
//             new_family += "fm";
//         }
//     }

//     return rec(new_family, current_gen+1, target_gen, k);
// }

#include<bits/stdc++.h>
char last = 'm';
char rec(int n, long long int k){
    if(n==0){
        return last;
    }

    long long int K = k/2;
    
    rec(n-1,K);

    if(n!=1){
        if(K*2 == k){
            debug("left child");
            if(last=='m') last = 'm';
            else last = 'f';
        } else {
            debug("right child");
            if(last=='m') last = 'f';
            else last = 'm';
        }
    }

    debug(last);

    return last;
}

string kthChildNthGeneration(int n, long long int k)
{
    // return rec("m", 0, n, k);
    last = 'm';
    char c = rec(n,pow(2,n-1)+k -1);
    if(c=='m') return "Male";
    else return "Female"
}

class Runner
{
    int t;
    vector<pair<int, long long int>>genChild;
public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n;
            long long int k;
            cin >> n >> k;
            genChild.push_back({n, k});
        }
    }

    void execute()
    {
        vector<pair<int, long long int>> arrCopy = genChild ;
        for (int i = 0; i < t; i++)
        {
            string ans = kthChildNthGeneration(arrCopy[i].first, arrCopy[i].second);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            string ans = kthChildNthGeneration(genChild[i].first, genChild[i].second);
            cout<<ans<<"\n";
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


