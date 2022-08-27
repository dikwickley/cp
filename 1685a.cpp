
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 


 
void solve() {
    int n;
    cin>>n;

    vector<int> b(n);
    vector<int> a(n,-1);

    for(int i=0;i<n;i++) cin>>b[i];

    if(n&1){ cout<<"NO"<<endl; return;}

    sort(b.begin(), b.end());

	
	for(int i=0;i<=(n-1)/2;i+=1){
		a[i*2] = b[i];
	}

	for(int i=(n-1)/2 + 1, j=1; i<n;i++, j+=2){
		a[j] = b[i];
	}




	debug(a);

	if(a[0] < a[1]){
		if(a[0] > a[n-1]) {cout<<"NO"<<endl; return;}
	}

	if(a[0] > a[1]){
		if(a[0] < a[n-1]) {cout<<"NO"<<endl; return;}
	}

	if(a[0] == a[1] || a[0] == a[n-1]) {cout<<"NO"<<endl; return;}

	for(int i=1;i<n-1;i++){
		if(a[i]<a[i-1]){
			if(a[i]>a[i+1]) {cout<<"NO"<<endl; return;}
		}
		if(a[i]>a[i-1]){
			if(a[i]<a[i+1]) {cout<<"NO"<<endl; return;}
		}
		if(a[i]==a[i+1] || a[i]==a[i-1]) {cout<<"NO"<<endl; return;}
	}

	cout<<"YES"<<endl;

	for(int i=0;i<n;i++) cout<<a[i]<<" ";

	cout<<endl;


}
 
int main() { io
    #ifndef ONLINE_JUDGE
        freopen("error.err", "w", stderr);
    #endif
    int t=1; 
    cin>>t; 
    while (t--) {
        solve();
    }
    return 0;
}