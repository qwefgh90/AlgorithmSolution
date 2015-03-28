#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

char table[202] = { 0, };

void makeKmpTable(char* pattern, int patternSize, char* table){
	int i = 0;	//������
	int j = -1;	//��ġ Ƚ��

	table[0] = -1;
	while (i <= patternSize){
		//while�� j�� -1�� �ɶ�����... ?
		while (j >= 0 && pattern[i] != pattern[j]){
			j = table[j];
		}

		i++;
		j++;
		
		table[i] = j;
	}
	
}

int main(){

	char pattern[200] = "ababcab";
	
	int size = strlen(pattern);
	
	makeKmpTable(pattern, size, table);
	
	printf("pattern: %s\n",pattern);

	for (int i = 0; i <= size; i++){
		printf("%d", table[i]);
	}
	printf("\n");

	return 0;

}