#include <stdio.h>
#include <stdlib.h>

int factorial(int number){
	if(number == 1){
		printf("1!=1\n");
		return 1;
	}
	int decreaseNumber = number-1;

	printf("%d!=%d*%d!\n",number,number,decreaseNumber);
	return number*factorial(number-1);
}
int numCount=0;
int main(){
	scanf("%d",&numCount);
	for(int i=0; i<numCount;i++){
		int number = 0;
		scanf("%d",&number);
		int result = factorial(number);
		printf("%d\n",result);
	}
	return 0;
}