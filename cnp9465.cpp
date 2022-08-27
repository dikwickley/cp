#include <iostream>
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

#define ll long long

#include<bits/stdc++.h>

bool check_pens(int n, int r, int k, int c, int pen){
   ll recycled_pens = n-pen;
   ll money = r + k*recycled_pens;
   ll new_pens = money/c;

   return pen <= new_pens;

}

int recyclePens(int n, int re, int k, int c ){

   // debug(check_pens(n,re,k,c, 1));
   // debug(check_pens(n,re,k,c, 2));
   // debug(check_pens(n,re,k,c, 3));
   // debug(check_pens(n,re,k,c, 4));
   // debug(check_pens(n,re,k,c, 5));
   // debug(check_pens(n,re,k,c, 6));
   // debug(check_pens(n,re,k,c, 7));
   // debug(check_pens(n,re,k,c, 8));
   // debug(check_pens(n,re,k,c, 9));


   ll l = 0;
   ll r = n;
   ll ans = -1;
   
   while(l<=r){
   
       ll mid = (l+r)/2;
       bool check = check_pens(n,re,k,c, mid);
       if(check) ans = mid;
       if(check) l = mid;
       else r = mid-1;
       if((l+r)/2 == mid) {l = mid+1;}
   
   }

   return ans;

}

int main()
{

   int tc;
   cin>>tc;
   
   while(tc--){
      int n,r,k,c;
      cin>>n>>r>>k>>c;
      long long ans = recyclePens(n,r,k,c);
      cout<<ans<<endl;
   }

   return 0;
   
}

