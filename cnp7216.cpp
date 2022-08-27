#include <iostream>
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

int find_largest(int*a, int n){

	int l = 0;
	int r = n-1;

	while(l<=r){
		int mid = (l+r)/2;
		if(mid+1<=n-1 && mid-1>=0 && a[mid]>a[mid+1] && a[mid]>a[mid-1]) return mid;
		else if(mid==0 && a[mid] > a[mid+1] && a[mid] > a[n-1]) return mid;
		else if(mid==n-1 && a[mid] > a[0] && a[mid] > a[mid-1]) return mid;

		if(a[mid] > a[mid+1]) r = mid-1;
		else l= mid+1;

	}

	return -1;
}

int search(int* arr, int n, int key) {

	cout<<find_largest(arr,n)<<endl;
	int c = find_largest(arr,n);

	if(c==-1){

        auto k = lower_bound(arr, arr+n, key);
        if(*k==key) return k-arr;
        else return -1;
    }

    auto fs = lower_bound(arr, arr+c,key);
    if(*fs == key) return fs-arr;
    
    auto ss = lower_bound(arr+c, arr+n,key);
    if(*ss == key) return ss-arr;
    

	return -1;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];

	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int q;
	cin >> q;

	while(q--)
	{
		int target;
		cin >> target;
		cout << search(arr, n, target) << "\n";
	}
} 