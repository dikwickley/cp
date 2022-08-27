#include <stdio.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <algorithm>

using namespace std;

#include<bits/stdc++.h>
int recursive(vector<vector<int>> c, int i, int a, int b, int n){

    if(i==2*n) return 0;

    if(a==n) {
        int total = 0;
        for(int j=i;j<2*n;j++) total += c[j][1];
        return total;
    }

    if(b==n) {
        int total = 0;
        for(int j=i;j<2*n;j++) total += c[j][0];
        return total;
    }
    
    return min(
        c[i][0] + recursive(c,i+1, a+1,b,n),
        c[i][1] + recursive(c,i+1, a,b+1,n)
    );
}
 

int findMinCost(int n, vector<vector<int>> &cost)
{
    return recursive(cost,0,0,0,n);
}

class Runner
{
    int t;
    vector<vector<vector<int>>>cost;

public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n;
            vector<vector<int>>tmp;
            cin >> n;
            for (int i = 0; i < 2 * n; i++)
            {
                vector<int>z;
                int x, y;
                cin >> x >> y;
                z.push_back(x);
                z.push_back(y);
                tmp.push_back(z);
            }
            cost.push_back(tmp);
        }

    }


    void execute()
    {
        vector<vector<vector<int>>> copy = cost;
        for (int i = 0; i < t; i++)
        {
            int n = copy.size() / 2;
            int result = findMinCost(n, copy[i]);
        }

    }

    void executeAndPrintOutput()
    {
        vector<vector<vector<int>>> copy = cost;
        for (int i = 0; i < t; i++)
        {
            int n = copy[i].size() / 2;
            int result = findMinCost(n, copy[i]);
            cout << result << '\n';
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