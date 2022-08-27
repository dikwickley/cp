#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> kLargest(int arr[], int n, int k) {
    priority_queue<int> max_heap;
    vector<int> ans;

    for(int i=0;i<n;i++) max_heap.push(arr[i]);

    while(k--) {ans.push_back(max_heap.top()); max_heap.pop();}

    return ans;

    
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kLargest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}