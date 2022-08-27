#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;



int shoppingOptions(vector<int>& pants, vector<int>& shirts, vector<int>& shoes, vector<int>& skirts, int budget)
{

    int count = 0;
    for(int i=0;i<pants.size();i++){
        for(int j=0;j<shirts.size();j++){
            for(int k=0;k<shoes.size();k++){
                for(int l=0;l<skirts.size();l++){

                    if(pants[i] + shirts[j] + shoes[k] + skirts[l] <= budget) count++;
                }
            }
        }
    }

    return count;
}


class Runner {
    int t;

    vector < vector < int > > arrP, arrQ, arrR, arrS;

    vector<int> arrX;

public:
    void takeInput() {

        cin >> t;

        arrX.resize(t);
        arrP.resize(t);
        arrQ.resize(t);
        arrR.resize(t);
        arrS.resize(t);

        for (int c = 0; c < t; c++) {

            int p, q, r, s, x;
            cin >> p >> q >> r >> s >> x;

            arrP[c].resize(p);
            arrQ[c].resize(q);
            arrR[c].resize(r);
            arrS[c].resize(s);

            for (int i = 0; i < p; i++) {
                cin >> arrP[c][i];
            }
            for (int i = 0; i < q; i++) {
                cin >> arrQ[c][i];
            }
            for (int i = 0; i < r; i++) {
                cin >> arrR[c][i];
            }
            for (int i = 0; i < s; i++) {
                cin >> arrS[c][i];
            }

            arrX[c] = x;

        }
    }

    void execute() {

        vector < vector < int > > arrCopyP = arrP, arrCopyQ = arrQ, arrCopyR = arrR, arrCopyS = arrS;

        vector<int> arrCopyX = arrX;

        for (int i = 0; i < t; i++) {

            int ans = shoppingOptions( arrCopyP[i], arrCopyQ[i], arrCopyR[i], arrCopyS[i], arrCopyX[i] );

        }

    }

    void executeAndPrintOutput() {

        for (int i = 0; i < t; i++) {

            int ans = shoppingOptions( arrP[i], arrQ[i], arrR[i], arrS[i], arrX[i] );

            cout << ans;

            cout << "\n";
        }
    }
};

int main() {
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
