#include <iostream>
#include <string>
#include <ios>
#include <limits>

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

string reverseString(string str)
{
    // Write your code here.
    string temp = "";
    vector<string> a;
    int n=str.size();
    
    for(int i=0;i<n;i++){
        if(str[i]==' '){

            if(temp != "")
                a.push_back(temp);

            temp = "";
        } else temp += str[i];
    }

    if(temp != "")
        a.push_back(temp);

    reverse(a.begin(), a.end());

    temp = "";

    for(int i=0;i<a.size()-1;i++){
        temp += a[i] + " ";
    }

    temp += a[a.size()-1];




    return temp;


}

int main()
{
    int t;
    cin >> t;

    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

    while(t--)
    {
        string str;

        getline(cin, str);
        
        if(str[str.size()-1] == 13)
            str.erase(str.size()-1);

        cout << reverseString(str) << '\n';
    }
}