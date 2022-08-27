#include <bits/stdc++.h>
using namespace std;



vector<int> nextGreaterElement(vector<int> a) {
    vector<int> ans;
    stack<int> s;

    for(int i=a.size()-1;i>=0;i--){

        while(!s.empty() && s.top() <= a[i])
            s.pop();

        if(s.empty()){
            ans.push_back(-1);
            s.push(a[i]);
        } else {
            ans.push_back(s.top());
            s.push(a[i]);
        }

    }

    reverse(ans.begin(), ans.end());

    return ans;

}



int main() {
    int size, temp;
    cin >> size;

    vector<int> input;

    for(int i = 0; i < size; i++) {
	cin >> temp;
        input.push_back(temp);
    }

    vector<int> output = nextGreaterElement(input);
    for(int i = 0; i < output.size(); i++) {
	    cout << output[i] << " ";
    }
}
