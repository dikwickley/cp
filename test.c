#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
	int i;
	for(i=1;i<=3;i++){
		printf("%u ", &argv[i]);
	}
	return 0;
}