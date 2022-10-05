#include<bits/stdc++.h>
using namespace std;


void primeNumbersTillN(int a, int b)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[b-a+1];
    memset(prime, true, sizeof(prime));
 
    for (int p = a; p * p <= b; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if(prime[p])
            cout << p << " ";
    
    return;
}

int main(){
    int t;
    cin>>t;
    
    
    while(t--){
        int a,b;
        cin>>a>>b;
        
        primeNumbersTillN(a,b)
        cout<<endl;
    }
    
    return 0;
}