#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> nums, int i, int sum, )

bool judge(vector<int> &nums) {
    // Write your code here.
}

class Runner
{
    int t;
    vector<vector<int>> cards;

public:
    void takeInput()
    {
        cin >> t;
        for (int i = 0; i < t; i++)
        {
            vector<int> v;
            for (int j = 0; j < 4; j++)
            {
                int a;
                cin >> a;
                v.push_back(a);
            }
            cards.push_back(v);
        }
    }

    void execute()
    {
        vector<vector<int>> cardsCpy = cards;

        for (int i = 0; i < t; i++)
        {
            int ans = judge(cardsCpy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = judge(cards[i]);

            if (ans == 1)
                cout << "True"
                     << "\n";
            else
                cout << "False"
                     << "\n";
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
//freopen("TestCases/large/in/input11.txt", "r", stdin);
//freopen("TestCases/large/out/output11.txt", "w", stdout);
#endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}
