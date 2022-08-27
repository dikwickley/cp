#include <iostream>
using namespace std;

int r(char s[], int i, int sum){
    sum = sum*10 + (s[i]-'0');
    if(s[i+1] == '\0'){
        return sum;
    }
    return r(s,i+1, sum);    
}

int stringToNumber(char input[]) {
    // Write your code here
    return r(input, 0, 0);
    
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
