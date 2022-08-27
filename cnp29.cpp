#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *arr, int n)
{
    // vector<int> m(3,0);
    int m[3] = {0,0,0};

    for(int i=0;i<n;i++) m[arr[i]] ++;

    for(int i=0;i<n;i++){
    	if(m[0]){
    		arr[i] = 0;
    		m[0]--;
    		continue;
    	}
    	if(m[1]){
    		arr[i] = 1;
    		m[1]--;
    		continue;
    	}
    	if(m[2]){
    		arr[i] = 2;
    		m[2]--;
    		continue;
    	}

    }

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}