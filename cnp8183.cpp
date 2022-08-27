#include<iostream>

using namespace std;

#include<vector>


#include<algorithm>

pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
	int a = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
	int b = upper_bound(arr.begin(),arr.end(),x) - arr.begin();

	if(arr[a] != x || arr[b-1] !=x) return {-1,-1};


	return {a,b-1};
}




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;

	while (tc--) {

		int N;
		cin >> N;

		vector<int> arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		int X;
		cin >> X;

		pair<int, int> sol = findFirstLastPosition(arr, N, X);
		cout << sol.first << " " << sol.second << endl;
	}

}