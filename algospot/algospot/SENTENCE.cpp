#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


입력
M개의 문장으로 이뤄진 책이 있다. 각 문장은 길이 1이상 60이하의 문자열

입력의 첫번째 줄에는 책에 적힌 문장의 갯수 M과 메모에 적힌 문장의 개수 N이 입력된다. ( 1 <= M <= 1000, 1 <= N <= 10,000 )
그리고 그 다음 M개의 줄에는 문장이 한줄에 하나씩 입력된다. 문장은 위에 명시된 규칙대로 입력된다.
그 다음 N개의 줄에는 원표와 현환이가 적은 문장이 한줄에 한 문장씩 입력된다. 문장의 길이와 형식은 책에 적힌 것과 동일하다.

출력

N개의 문장 중에서 원표가 적은 문장의 갯수를 출력한다.

예를 들어 책에 적힌 문장이
"I am a"
"I am"
라고 하고, "I am" 이라고 할 경우 답은 1이다.


https://algospot.com/judge/problem/read/SENTENCE

해시테이블로 서브스트링을 저장하여 풀 수 있다.
*/


struct HashValue{
	int key;
	char* value;
};

int primeNum = 53;
#define HASHSIZE 100000 //문자는 최대 60000개 53000

HashValue hashTable[HASHSIZE];//문장 해싱 //

//개방 해시 테이블
void put(int key, char* value){
	HashValue val;
	val.key = key;
	val.value = value;

	int hashIndex = key;

	//자리를 찾는다
	while (hashTable[hashIndex].value != NULL) {
		hashIndex += primeNum;
	}

	hashTable[hashIndex].key = key;		//키
	hashTable[hashIndex].value = value;	//값
}
bool findAndResult(int key, char* target){
	bool result = false;
	int hashIndex = key;

	//키가 같은 놈을 찾는다.
	while (hashTable[hashIndex].value != NULL) {

		if (hashIndex < HASHSIZE && hashTable[hashIndex].key == key){	//키가 같을 때만
			int length = strlen(target);		//target 문자열 길이
			char* val = hashTable[hashIndex].value; //hash 문자열

			for (int i = 0; i < length; i++){
				if (val[i] != target[i]){	//비교
					break; 					//같지 않음
				}
				if (i == length - 1) //발견
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
	for (int i = 0; i < 50000; i++){
		hashTable[i] = h;
	}

	char bookSentence[1000][62] = { 0, };
	char userSentence[10000][62] = { 0, };

	int resultCount = 0;
	int m, n;
	scanf("%d %d", &m, &n);
	getchar();

	for (int k = 0; k < m; k++){
		//scanf("%s", );
		gets(bookSentence[k]);
		int length = strlen(bookSentence[k]);
		int sum = 0;
		for (int i = 0; i < length; i++){
			sum += (int)bookSentence[k][i];
			//hash
			put(sum, bookSentence[k]);
		}
	}

	for (int k = 0; k < n; k++){
		gets(userSentence[k]);
		int length = strlen(userSentence[k]);
		int sum = 0;
		for (int i = 0; i < length; i++){
			sum += (int)userSentence[k][i];
		}
		//get and compare
		bool result = findAndResult(sum, userSentence[k]);
		if (result == true){
			resultCount++;
		}
	}

	printf("%d\n", resultCount);
	return 0;
}

