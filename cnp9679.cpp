#include <iostream>

using namespace std;
#include <vector>

void rec(int n, int k, vector<int> &ans){
	if(n<=0){
		ans.push_back(n);
		ans.push_back(n+k);
		return;
	} 

	ans.push_back(n);

	rec(n-k,k,ans);

	ans.push_back(n+k);
}

vector<int> printSeries(int n, int k)
{
	vector<int> ans;
    rec(n,k,ans);
    ans.pop_back();
    return ans;
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcase;
	cin >> testcase;

	while (testcase--) {
		string s ;
		int n, k;
		cin >> n >> k;
		vector<int> ans = printSeries(n, k);
		for (auto output : ans) {
			cout << output << " ";
		}
		cout << "\n";
	}


	return 0;
}