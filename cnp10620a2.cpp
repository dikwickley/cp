#include <stdio.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <algorithm>
#include <unordered_map>


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

string decode_word(string word, vector<char> a){
    string x = "";


    for(int i=0;i<word.size();i++){
        int index = find(a.begin(), a.end(), word[i]) - a.begin();
        x +=  '0' + index;
    }

    return x;
}

bool check_word(vector<string> words, string result, vector<char> a){
    int x = 0;



    for(int i=0;i<words.size();i++){

        string t = decode_word(words[i], a);
        string u = t;
        reverse(u.begin(), u.end());
        if(u!=t) return false;
        else x+= std::stoi(t);
    }
    string t = decode_word(result, a);
    string u = t;
    reverse(u.begin(), u.end());
    if(u!=t) return false;
    int y = std::stoi(t);

    debug(y);
    return x == y;
}

bool rec(vector<string> words, string result, vector<char>a, vector<char> v, int i, int n){


    if(i==n){

        // debug(a);

        if(check_word(words, result, a)){
            return true;
        } else {
            return false;
        }
    }

    bool temp = false;

    for(int j=0; j<10;j++){
        if(a[j]=='-'){
            a[j] = v[i];
            temp = temp || rec(words, result, a, v, i+1, n);
            a[j] = '-';
        }
    }

    return temp;
}

#include<bits/stdc++.h>
bool isSolvable(int m, vector < string > & words, string result) {
    

    vector<char> a(10,'-');

    unordered_set<char> s;

    for(int i=0;i<m;i++){
        for(int j=0;j<words[i].size();j++){
            s.insert(words[i][j]);
        }
    }

    for(int i=0;i<result.size();i++) s.insert(result[i]);


    vector<char> v(s.begin(), s.end());

    

    return rec(words, result, a, v, 0, v.size());
    return false;

}

class Runner
{
    int t;
    vector<string>right;
    vector<vector<string>> left;

public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
            vector<string>a(n);
            for (int i = 0; i < n; i++) cin >> a[i];
            left.push_back(a);
            string s;
            cin >> s;
            right.push_back(s);
        }

    }


    void execute()
    {
        vector<vector<string>> copy = left;
        vector<string> a = right;
        for (int i = 0; i < t; i++)
        {
            bool result = isSolvable(copy[i].size(), copy[i], a[i]);

        }

    }

    void executeAndPrintOutput()
    {
        vector<vector<string>> copy = left;
        vector<string> a = right;
        for (int i = 0; i < t; i++)
        {
            bool result = isSolvable(copy[i].size(), copy[i], a[i]);
            if (result)
            {
                cout << "true" << endl;
            }

            else
            {
                cout << "false" << endl;
            }

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