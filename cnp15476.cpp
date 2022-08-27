#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


#include<bits/stdc++.h>
vector<int> minLoss(int n, vector<int> &time, vector<int> &loss) {
    // Write your code here.
}

class Runner
{
    int t;
    vector<vector<int>> time;
    vector<vector<int>> loss;

public:
    void takeInput(){
        cin >> t;
        time.resize(t);
        loss.resize(t);
        for (int i = 0; i < t; i++){
            int n;
            cin>>n;
            time[i].resize(n);
            loss[i].resize(n);
            for(int j = 0; j < n; ++j) {
                cin>>time[i][j];
            }
            
            for(int j = 0; j < n; ++j) {
                cin>>loss[i][j];
            }
        }
    }
    
    void execute()
    {
        vector<vector<int>> timeCpy = time;
        vector<vector<int>> lossCpy = loss;
        for (int i = 0; i < t; i++)
        {

            vector<int> ans = minLoss(timeCpy[i].size(), timeCpy[i], lossCpy[i]);

        }
        timeCpy.clear();
        lossCpy.clear();
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {

            vector<int> ans = minLoss(time[i].size(), time[i], loss[i]);
            
            for(int j = 0; j < ans.size(); ++j) {
                cout<<ans[j]<<" ";
            }
            cout<<"\n";
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
