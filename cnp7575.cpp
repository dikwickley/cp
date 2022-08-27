#include <iostream>

using namespace std;

#include <bits/stdc++.h>
int getLengthofLongestSubstring(int K, string a)
{
      // Write your code here.
    int length = 0;

    set<char> s;
    multiset<char> ms;

    int k = 0;

    int max = 0;

    for(int i=0;i<a.length();){


        if(s.size()==K+1){
            char c = a[k];
            auto itr = ms.find(c);
            if(itr!=ms.end()){
                ms.erase(itr);
            }
            if(ms.count(c)==0){
                s.erase(c);
            };
            k++;
        } else {


            s.insert(a[i]);
            ms.insert(a[i]);
            i++;
        }

        if(s.size() <= K){
            if(ms.size() > max) max = ms.size();
        }


    } 

    return max;
}


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        string s;
        cin >> k >> s;
        int longestSubstring = getLengthofLongestSubstring(k, s);
        cout << longestSubstring << endl;
    }

    return 0;
}
