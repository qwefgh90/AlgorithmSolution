#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
int main(){
	int inputNumber = 0;
	int capacity = 0;
	int elementsum = 0;
	char elementStr[1000] = { 0, };
	scanf("%d", &inputNumber);
	for (int index = 0; index < inputNumber; index++){
		//초기화
		elementsum = 0;
		scanf("%d", &capacity);
		rewind(stdin);
		scanf("%[^\n]s", elementStr);//라인 입력 받기 //\n이 나올때 까지 입력받음
		char* temp = NULL;
		temp = strtok(elementStr, " ");
		if (temp != NULL){
			elementsum += atoi(temp);
		}
		while (temp = strtok(NULL, " ")){
			elementsum += atoi(temp);
		}
		if (capacity >= elementsum){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}


	return 0;
}