#include <bits/stdc++.h> 
using namespace std;

long long merge(vector<int> &a, int start, int mid, int end){
    vector<int> left, right;
    for(int i=start; i<=mid;i++) left.push_back(a[i]);
    for(int i=mid+1; i<=end;i++) right.push_back(a[i]);

    long long total = 0;

    int n = left.size();
    int m = right.size();

    int l = 0;
    int r = 0;
    int c = start;

    while(l<n && r<m){
        if(left[l]<=right[r]){
            a[c] = left[l];
            c++;l++;
        } else {
            a[c] = right[r];
            c++;r++;
            total += (n-l);
        }
    }

    while(l < n){
        a[c] = left[l];
        c++;l++;
    }

    while(r < m){
        a[c] = right[r];
        c++;r++;
    }

    return total;
}

long long merge_sort(vector<int> &a, int start, int end){
    if(start >= end) return 0;
    
    int mid = start + (end - start) / 2;

    long long total = 0;

    total+=merge_sort(a,start,mid);
    total+=merge_sort(a,mid+1,end);

    total+=merge(a,start,mid,end);

    return total;
}


long long getInversions(long long *arr, int n){
    vector<int> a(n);
    for(int i=0;i<n;i++) {a[i]=arr[i];}
    
    return merge_sort(a,0,n-1);
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