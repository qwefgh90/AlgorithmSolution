#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HashValue{
	int key;
	char* value;
};

int primeNum =53;
#define HASHSIZE 50000

HashValue hashTable[HASHSIZE];//문장 해싱 //

//개방 해시 테이블
void put(int key, char* value){
	HashValue val;
	val.key = key;
	val.value = value;

	int hashIndex = key;

	while(hashTable[hashIndex].value != NULL) {
		hashIndex += primeNum;
	}

	hashTable[hashIndex].key = key;		//키
	hashTable[hashIndex].value = value;	//값
}
bool findAndResult(int key, char* target){
	bool result = false;
	int hashIndex = key;

	//키가 같은 놈을 찾는다.
	while(hashTable[hashIndex].value != NULL) {

		if(hashIndex < HASHSIZE && hashTable[hashIndex].key == key){	//키가 같을 때만
			int length = strlen(target);		//target 문자열 길이
			char* val = hashTable[hashIndex].value; //hash 문자열

			for(int i = 0 ; i < length ; i++){
				if(val[i] != target[i]){	//비교
					break; 					//같지 않음
				}
				if( i == length - 1) //발견
					return true;
				
			}

		}
		hashIndex += primeNum;
	}
	return false;
}

int main(){
	//초기
	HashValue h;
	h.key = 0;
	h.value = NULL;
	for(int i = 0 ; i < 50000; i++){
		hashTable[i] = h;
	}

	char bookSentence[1000][62] = {0,};
	char userSentence[10000][62] = {0,};

	int resultCount = 0;
	int m,n;
	scanf("%d %d",&m,&n);

	for(int k = 0 ; k < m ; k ++){
		scanf("%s", bookSentence[k]);
		int length = strlen(bookSentence[k]);
		int sum = 0;
		for(int i = 0 ; i < length ; i++){
			sum += (int)bookSentence[k][i];
			//hash
			put(sum,bookSentence[i]);
		}
	}
	
	for(int k = 0 ; k < n ; k ++){
		scanf("%s", userSentence[k]);
		int length = strlen(userSentence[k]);
		int sum = 0;
		for(int i = 0 ; i < length ; i++){
			sum += (int)userSentence[k][i];
			//get and compare
			bool result = findAndResult(sum, userSentence[i]);
			if(result == true){
				resultCount ++;
			}
		}
	}
	
	printf("%d\n",resultCount);
	return 0;
}
