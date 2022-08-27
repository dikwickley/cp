#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>

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

#include<bits/stdc++.h>

vector<int> b;
bool flag = false;

void rec(int n, vector<int> a){

	if(n==1){


		for(int i=0;i<a.size();i++){
			if(a[i]==0) a[i] = 1;
		}
		debug(a);

		if(!lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())){
			b = a;
		}
		return;
	}


	for(int i=0;i<a.size();i++){
		if(a[i]==0){
			
			if(i+n<=a.size()-1 && a[i+n]==0){

				a[i] = n;
				a[i+n] = n;
				rec(n-1,a);
				a[i] = 0;
				a[i+n] = 0;
			} 

		}
	}
	
}
vector<int> validSequence(int n) {
    // Write your code here.
    vector<int> ans(2*n-1,0);
    b.clear();
    rec(n,ans);
    return b;
}

class Runner
{
    int t;
    vector<int> arr;

public:
    void takeInput()
    {
        cin >> t;

        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
            arr.push_back(n);
        }

    }


    void execute()
    {
        vector<int> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            vector<int> ans = validSequence(arrCopy[i]);
        }

    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<int> ans = validSequence(arr[i]);
            for (int j = 0; j < ans.size(); j++) {
                cout << ans[j] << " ";
            }
            cout << endl;
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
