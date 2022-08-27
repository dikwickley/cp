#include <iostream>
#include <string>

using namespace std;
#include <bits/stdc++.h>
map<int, vector<char>> m = {
	{2, {'a','b','c'}},
	{3, {'d','e','f'}},
	{4, {'g','h','i'}},
	{5, {'j','k','l'}},
	{6, {'m','n','o'}},
	{7, {'p','q','r','s'}},
	{8, {'t','u','v'}},
	{9, {'w','x','y','z'}}
};

void rec(string s, int n, int l){

	if(s.length()==l) {
		cout<<s<<endl;
		return;
	}

	int num = n%10;

	for(int i=0;i<m[num].size();i++){
		string temp = m[num][i] + s;
		rec(temp,n/10,l);
	}

}

void printKeypad(int n){
    rec("",n,ceil(log10(n)));
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

