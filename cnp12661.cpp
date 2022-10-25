#include <iostream>
#include <vector>

using namespace std;


int gcd(int a, int b){
    if(b==0) return a;

    return gcd(b,a%b);
}

long long gcdSum(int n)
{

    long long sum = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            sum += gcd(i,j);
        }
    }

    return sum;
}   


class Runner
{
    int t;
    vector<int> allN;

public:
    void takeInput()
    {
        cin >> t;
        allN.resize(t);

        for (int i = 0; i < t; i++)
        {
            cin >> allN[i];
        }
    }
    
    vector<int> copyArray(vector<int> &arr)
    {

        vector<int> copyArr;

        for (int i = 0; i < arr.size(); i++)
        {
            copyArr.push_back(arr[i]);
        }
        
        return copyArr;
    }

    void execute()
    {
        vector<int> copyArr = copyArray(allN);

        for (int i = 0; i < t; i++)
        {
            gcdSum(copyArr[i]);
        }

        copyArr.clear();
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            long long answer = gcdSum(allN[i]);

            cout << answer << "\n";
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