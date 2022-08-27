#include <iostream>
#include <vector>
#include<bits/stdc++.h>

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

int calculateMinPatforms(int at[], int dt[], int n) {

    vector<int> a;

    for(int i=0;i<n;i++)a.push_back[]
    // vector<pair<int,int>> a(n);

    // for(int i=0;i<n;i++) a[i] = {at[i],dt[i]};

    // sort(a.begin(), a.end());

    // priority_queue<int, vector<int>, greater<int> > p;

    // p.push(a[0].second);
    // int count =1;

    // for(int i=1;i<n;i++){
    //     if(a[i].first <= p.top()) count++;
    //     else p.pop();

    //     p.push(a[i].second);
    // }

    // return count;


}

class Runner
{
    int t;
    vector< int >tn;
    vector<vector<int>> at,dt;

public:
    void takeInput()
    {
        cin >> t;
       
        for (int c = 0; c < t; c++)
        {
            int n;
            cin>>n;
            vector<int> tmp(n);
            for(int i=0;i<n;i++){
                cin>>tmp[i];
            }

            at.push_back(tmp);
            for(int i=0;i<n;i++){
                cin>>tmp[i];
            }

            dt.push_back(tmp);
            tn.push_back(n);
        }
    }

    void execute()
    {
        vector< int > arrCopy = tn;

        for (int i = 0; i < t; i++)
        {
            int n = tn[i];
            int arrayAt[n],arrayDt[n];
            for(int j=0;j<n;j++){
                arrayAt[j] = at[i][j];
                arrayDt[j] = dt[i][j];
            }
            
            int ans = calculateMinPatforms(arrayAt, arrayDt, tn[i]);            
        }

        arrCopy.clear();
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int n = tn[i];
            int arrayAt[n],arrayDt[n];
            for(int j=0;j<n;j++){
                arrayAt[j] = at[i][j];
                arrayDt[j] = dt[i][j];
            }
            int ans = calculateMinPatforms(arrayAt, arrayDt, tn[i]);
            cout<<ans<<endl;   
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