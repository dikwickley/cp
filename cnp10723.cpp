#include <iostream>
#include <vector>

using namespace std;

long long findKthGlowingBulb(vector<int> &labels, long long k) {
	// Write your code here.
}

class Runner {
    int t;
    vector<long long> inputK;
    vector<vector<int>> inputLabels;

public:
    void takeInput() {
        cin >> t; 
        for (int i = 0; i < t; i++) {
            int n;
            long long k;
            cin >> n >> k;
            vector<int> labels(n);
            for(int j = 0; j < n; j++) {
                cin >> labels[j];
            }
            inputLabels.push_back(labels);
            inputK.push_back(k);
        }
    }

    void execute() {
        vector<vector<int>> inputLabelsCpy = inputLabels;
        vector<long long> inputKCpy = inputK;

        for(int i = 0; i < t; i++) {
            long long result = findKthGlowingBulb(inputLabelsCpy[i], inputKCpy[i]);
        }
    }

    void executeAndPrintOutput() {
        for(int i = 0; i < t; i++) {
            long long result = findKthGlowingBulb(inputLabels[i], inputK[i]);
            cout << result << '\n';
        }
    }
};

int main() {
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}