#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


�Է�
M���� �������� �̷��� å�� �ִ�. �� ������ ���� 1�̻� 60������ ���ڿ�

�Է��� ù��° �ٿ��� å�� ���� ������ ���� M�� �޸� ���� ������ ���� N�� �Էµȴ�. ( 1 <= M <= 1000, 1 <= N <= 10,000 )
�׸��� �� ���� M���� �ٿ��� ������ ���ٿ� �ϳ��� �Էµȴ�. ������ ���� ��õ� ��Ģ��� �Էµȴ�.
�� ���� N���� �ٿ��� ��ǥ�� ��ȯ�̰� ���� ������ ���ٿ� �� ���徿 �Էµȴ�. ������ ���̿� ������ å�� ���� �Ͱ� �����ϴ�.

���

N���� ���� �߿��� ��ǥ�� ���� ������ ������ ����Ѵ�.

���� ��� å�� ���� ������
"I am a"
"I am"
��� �ϰ�, "I am" �̶�� �� ��� ���� 1�̴�.


https://algospot.com/judge/problem/read/SENTENCE

�ؽ����̺�� ���꽺Ʈ���� �����Ͽ� Ǯ �� �ִ�.
*/


struct HashValue{
	int key;
	char* value;
};

int primeNum = 53;
#define HASHSIZE 100000 //���ڴ� �ִ� 60000�� 53000

HashValue hashTable[HASHSIZE];//���� �ؽ� //

//���� �ؽ� ���̺�
void put(int key, char* value){
	HashValue val;
	val.key = key;
	val.value = value;

	int hashIndex = key;

	//�ڸ��� ã�´�
	while (hashTable[hashIndex].value != NULL) {
		hashIndex += primeNum;
	}

	hashTable[hashIndex].key = key;		//Ű
	hashTable[hashIndex].value = value;	//��
}
bool findAndResult(int key, char* target){
	bool result = false;
	int hashIndex = key;

	//Ű�� ���� ���� ã�´�.
	while (hashTable[hashIndex].value != NULL) {

		if (hashIndex < HASHSIZE && hashTable[hashIndex].key == key){	//Ű�� ���� ����
			int length = strlen(target);		//target ���ڿ� ����
			char* val = hashTable[hashIndex].value; //hash ���ڿ�

			for (int i = 0; i < length; i++){
				if (val[i] != target[i]){	//��
					break; 					//���� ����
				}
				if (i == length - 1) //�߰�
					return true;

			}

		}
		hashIndex += primeNum;
	}
	return false;
}

int main(){
	//�ʱ�
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

