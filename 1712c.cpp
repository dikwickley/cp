
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 

bool check_non_dec(vector<int> a, int o){

	int n = a.size();
	set<int> s;

	for(int i=0;i<n;i++){
		
		if(s.count(a[i])==0){
			if(o>0){
				o--;
				s.insert(a[i]);
				a[i] = 0;
			}
		} else {
			a[i] = 0;
		}

	}

	
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]) return false;
	}

	return true;
}
 
void solve() {
    int n;
    cin>>n;

    vector<int> ARR(n);

    for(int i=0;i<n;i++) cin>>ARR[i];


    int l = 0;
    int r = n;
    int count = -1;
    
    while(l<=r){
    
        int mid = l + (r - l)/2;
        bool c = check_non_dec(ARR,mid);
        if(c) count = mid;
        if(c) r = mid;
        else l = mid+1;
        if((l+r)/2 == mid) {r = mid-1;}
    
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