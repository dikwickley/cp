#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<string> ninjaParty(vector<string> &arr)
{   
    int n = arr.size();
    
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(), arr[i].end());
    }

    sort(arr.begin(), arr.end());

    for(int i=0;i<n;i++){
        reverse(arr[i].begin(), arr[i].end());
    }

    return arr;


}


class Runner
{
    int t;

    vector<vector<string>> arr;
    


public:
    void takeInput()
    {

        cin >> t;
        arr.resize(t);

        for (int tc = 0; tc < t; tc++)
        {
            int n;
            cin >> n;


            arr[tc].resize(n);

            for (int i = 0; i < n; i++)
            {
                cin >> arr[tc][i];
            }
        }
    }

  
    void execute()
    {
        vector<vector<string>> arrCopy = arr;
        // vector<int> kArrCopy = kArr;

        for (int i = 0; i < t; i++)
        {
            vector<string> ans = ninjaParty(arr[i]);

        }
    }


    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<string> ans = ninjaParty(arr[i]);
           
            for(string s:ans)
            {
                cout << s << " ";
            }
            cout << endl;
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