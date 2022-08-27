
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
  
void solve() {
    long long n;

    cin>>n;

    vector<long long> a(n+1);

    for(long long i=1;i<=n;i++) {cin>>a[i]; }

  	long long count = 0;

  	for(long long i=1;i<=n;i++){
  		for(long long j = a[i] - i; j <= n; j += a[i]) {
                if(j>=0)
                if(a[i] * a[j] == i + j && i < j) count++;
        }
  	}

  	cout<<count<<endl;
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