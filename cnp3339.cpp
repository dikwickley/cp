#include<iostream>
using namespace std;

int indexes(int a[], int s, int i, int x, int *output, int o){
    if(i==s) return o;

    if(a[i]==x){
        output[o] = i;
        return indexes(a,s,i+1,x,output,o+1);
    } else {
        return indexes(a,s,i+1,x,output,o);
    }

}

int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */

    return indexes(input, size, 0, x, output, 0);


}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}