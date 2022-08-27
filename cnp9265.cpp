#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;


using namespace std;

    void rec(vector<int> arr, vector<int> a, int B, vector<vector<int>> &ans){
        if(B==0){
            ans.push_back(a);
            return;
        }

        if(B<0) return;

        for(int i=0;i<arr.size();i++){
            vector<int> temp = a;
            if(a.size()==0){
                temp.push_back(arr[i]);
                rec(arr, temp, B-arr[i], ans);
            } else if(a[a.size()-1] <= arr[i] ){
                temp.push_back(arr[i]);
                rec(arr, temp, B-arr[i], ans);
            }
        }


    }

    vector<vector<int>> combSum(vector<int>& ARR, int B)
    {

        vector<vector<int>> ans;

        rec(ARR, {}, B, ans);

        return ans;    
    }



class Runner
{
    int t;

    vector<vector<int> > arr;
    vector<int> B;

public:

    void takeInput() 
    {

        cin >> t;
        B.resize(t);
        for(int c = 0; c < t; c++)
        {
            int n;
            cin>>n>>B[c];
            vector<int> temp(n);
            for(int i=0;i<n;i++)
                cin>>temp[i];
            arr.push_back(temp);

        }
        
    }
    

    void execute()
    {
        for (int i = 0; i < t; i++)
        {   
            vector<int> copy=arr[i];
            vector<vector<int>> res=combSum(copy,B[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            
            vector<vector<int>> res=combSum(arr[i],B[i]);
            for(auto i:res)
            {
                for(auto j:i)
                    cout<<j<<" ";
                cout<<"\n";
            }

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