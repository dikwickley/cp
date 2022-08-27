
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
  
void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);

    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;


    sort(a.rbegin(), a.rend());


	int count = 1;

	int last_begin = a[0].first;

	for(int i=1;i<n;i++){
		if(a[i].second <= last_begin){
			count++;
			last_begin = a[i].first;
					
		}
	}

	cout<<count<<endl;


}
 
int main() { io

    int t=1; 
    // cin>>t; 
    while (t--) {
        solve();
    }
    return 0;
}