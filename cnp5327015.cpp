#include <iostream>
using namespace std;

#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    map<long long,int> m;

    for(int i=0;i<n;i++) m.insert({arr[i],i});
    sort(arr, arr+n);

    long long count = 0;

    for(int i=0;i<n;i++) {
        if(m[arr[i]] >= i){
            count += m[arr[i]] - i;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}