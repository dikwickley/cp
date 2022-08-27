#include <iostream>
using namespace std;

void remove(char*s, int i, int j){
    if(s[i]=='\0'){s[j+1] = '\0'; return;}

    if(s[i] == s[j]){
        remove(s,i+1,j);
    } else {
        s[j+1]=s[i];
        remove(s, i+1,j+1);
    }
}

void removeConsecutiveDuplicates(char *input) {
    /* Don't write main().
    * Don't read input, it is passed as function argument.    
    * Change in the given string itself.
    * No need to return or print anything
    * Taking input and printing output is handled automatically.
    */
    
    remove(input,0,0);
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}