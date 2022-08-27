#include <iostream>
#include <vector>
#include<string>

using namespace std;

#include <bits/stdc++.h>

int minSwap (int N, int M, int k, string &s, vector<char> &arr)
{

	int n = s.size();
	int ans = 0; 
	
	set<char> ar;
	for(int i=0;i<arr.size();i++) ar.insert(arr[i]);
    
    for(int i=0;i<k;i++){
    	map<char,int>f;
    	set<char> cs;
    	int count = 0;
    	for(int j=i;j<n;j+=k){
    		count ++;
    		if(ar.count(s[j])!=0){
    			if(f.count(s[j])==0) f.insert({s[j],1});
    			else f[s[j]] ++;	
    		}
    		
    	}
    	

    	int max_set = 0;

    	for (auto i = f.begin(); i != f.end(); ++i) {
		  if(i->second > max_set) max_set = i-> second;
		}


    	ans += count-max_set;
    }

    return ans;
}


class Runner
{
    int t;
    vector<int> allN;
    vector<int> allM;
    vector<int> allK;
    vector<string> allS;
    vector<vector<char> > allArr; 

public:
    void takeInput()
    {
        cin >> t;
        
        allN.resize(t);
        allM.resize(t);
        allK.resize(t);
        allS.resize(t);
        allArr.resize(t);
    
        for (int i = 0; i < t; i++)
        {
            cin >> allN[i] >> allM[i] >> allK[i] >> allS[i];
            
            allArr[i].resize(allM[i]);

            for (int j = 0; j < allM[i]; j++)
            {
                cin >> allArr[i][j];
            }
        }
    }

    void execute()
    {

        for (int i = 0; i < t; i++)
        {
            vector<char> copyArr(allArr[i]);
            string copyS=allS[i];

            minSwap(allN[i], allM[i], allK[i], copyS, copyArr);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int result;
            
            result = minSwap(allN[i], allM[i], allK[i], allS[i], allArr[i]);

            cout << result << "\n";
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}