#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

#define MAX 100000
#define HASHMAX 200000
#define DIVIDEVAL 150000
#define HASHJUMPVALUE  59

typedef struct _Node{
	int x;
	int y;
	_Node* dir[8]; //8����



	_Node(){
		x = 0;
		y = 0;
		for (int i = 0; i < 8; i++){
			dir[i] = NULL;
		}
	}
}Node;

Node* deleteBuffer[MAX] = { NULL, };
int bufidx = 0;

Node* hashMap[HASHMAX] = { NULL, };
//�䱸 ����
//���� ��ũ�� ����Ʈ
//�ؽø��� ���� ���� �˻�
void insertHash(int x, int y, Node* value){
	int key = (x + y) % DIVIDEVAL;
	if (hashMap[key] == NULL)
	{
		hashMap[key] = value;
	}
	else{
		//���� ������ �ڸ��� ã�´�
		int tempKey = key + HASHJUMPVALUE; //�Ҽ��� ���ϴ� ���
		while (hashMap[tempKey] != NULL){
			tempKey += HASHJUMPVALUE;
		}
		hashMap[tempKey] = value;
	}
}
Node* searchHash(int x, int y){
	int key = (x + y) % DIVIDEVAL;
	Node* result = NULL;
	Node* localNodePtr = hashMap[key];
	while (localNodePtr != NULL){
		int hashX = localNodePtr->x;
		int hashY = localNodePtr->y;
		if (x == hashX && hashY == y){
			result = localNodePtr;
			break;
		}
		key += HASHJUMPVALUE;
		localNodePtr = hashMap[key];
	}
	return result;
}

int main(){
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int result = 0;
		int count;
		scanf("%d", &count);
		int x = 100000;
		int y = 100000;
		char charArr[MAX] = { 0, };
		scanf("%s", charArr);

		//���� ���
		Node* prevNode = new Node();
		deleteBuffer[bufidx++] = prevNode;
		prevNode->x = x;
		prevNode->y = y;
		Node* hash_value = prevNode;
		insertHash(x, y, hash_value);

		//���� �о�� �� ����Ʈ �� �ؽø� ����
		for (int j = 0; j < count; j++) {
			char dir = charArr[j];
			char rdir = 0;;//������ ����
			switch (dir){
			case '0':
			{
						rdir = '4';
						y--;
			}
				break;
			case '1':
			{
						rdir = '5';
						x++;
						y--;
			}
				break;
			case '2':
			{
						rdir ='6';
						x++;
			}
				break;
			case '3':
			{
						rdir = '7';
						x++;
						y++;
			}
				break;
			case '4':
			{
						rdir = '0';
						y++;
			}
				break;
			case '5':
			{
						rdir = '1';
						x--;
						y++;
			}
				break;
			case '6':
			{
						rdir = '2';
						x--;
			}
				break;
			case '7':
			{
						rdir = '3';
						x--;
						y--;
			}
				break;
			}

			Node* current = searchHash(x, y);
			if (current == NULL){
				//�밢�� ��ũ�� ��ġ���� ����
				Node* crossNode = NULL;
				switch (dir){
				case '1':
				{
						  crossNode = searchHash(x, y+1);
						  if (crossNode != NULL){
							  if (crossNode->dir[7] != NULL){
								  result++;
							  }
						  }
				}
					break;
				case '3':
				{
						  crossNode = searchHash(x, y - 1);
						  if (crossNode != NULL){
							  if (crossNode->dir[5] != NULL){
								  result++;
							  }
						  }
				}
					break;
				case '5':
				{
						  crossNode = searchHash(x + 1, y);
						  if (crossNode != NULL){
							  if (crossNode->dir[7] != NULL){
								  result++;
							  }
						  }
				}
					break;
				case '7':
				{
						  crossNode = searchHash(x+1, y);
						  if (crossNode != NULL){
							  if (crossNode->dir[5] != NULL){
								  result++;
							  }
						  }
				}
					break;
				}


				//���ο� ��� ����
				Node* node = new Node();
				deleteBuffer[bufidx++] = node;
				node->x = x;
				node->y = y;

				prevNode->dir[dir-'0'] = node;
				node->dir[rdir - '0'] = prevNode;

				Node* hash_value = node;
				insertHash(x, y, hash_value);

				prevNode = node;

				continue;
			}
			//ã�� ��ũ ����
			else{
				if (current->dir[rdir - '0'] == prevNode){
					//�̹� ��ũ�� �ִ°��
					prevNode = current;
				}
				else {
					//��ũ�� ���� ���
					current->dir[rdir - '0'] = prevNode;
					prevNode->dir[dir - '0'] = current;
					prevNode = current;
					result++;

					//�밢�� ��ũ�� ��ġ���� ����
					Node* crossNode = NULL;
					switch (dir){
					case '1':
					{
								crossNode = searchHash(x, y + 1);
								if (crossNode != NULL){
									if (crossNode->dir[7] != NULL){
										result++;
									}
								}
					}
						break;
					case '3':
					{
								crossNode = searchHash(x, y - 1);
								if (crossNode != NULL){
									if (crossNode->dir[5] != NULL){
										result++;
									}
								}
					}
						break;
					case '5':
					{
								crossNode = searchHash(x + 1, y);
								if (crossNode != NULL){
									if (crossNode->dir[7] != NULL){
										result++;
									}
								}
					}
						break;
					case '7':
					{
								crossNode = searchHash(x + 1, y);
								if (crossNode != NULL){
									if (crossNode->dir[5] != NULL){
										result++;
									}
								}
					}
						break;
					}
				}
			}
		}

		printf("%d\n", result);
		for (int k = 0; k < bufidx; k++){
			if (deleteBuffer[k] != NULL){
				delete deleteBuffer[k];
				deleteBuffer[k] = NULL;
			}
		}
		bufidx = 0;
		memset(deleteBuffer, NULL, sizeof(Node*)*MAX);
		memset(hashMap, NULL, sizeof(Node*)*HASHMAX);



	}

	return 0;
}


/*
�Ｚ�̴� ������� �����Ϸ��� �Ѵ�.
����, ���� ��ǥ���� ���� �����ִ� �ſ� ū ���̰� �ִ�. �� ����, ������ ������ ���� �ø���. ���� ���� ����� ���̿��� ���� ����ä N�� ������ ������� �׸���. ��, �Ｚ�̴� ���� ���� �ִ� ���� ������ 8���� �� �� �ϳ��θ� �̵��� �� �ִ�. (����, ����, �밢��) ������ �̵��� �Ʒ� �׸��� ������, ���ڷ� ��Ÿ�� �� �ִ�.

�Ｚ�̰� �׸� ������� �־��� �� ������ ���� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ������ ����� �׸� �󿡼� �� ������ ���ϸ�, ������ �׸� ������ �ѷ� �׿� �־�� �Ѵ�. ������ �ٸ� �������� �ѷ� �׿��� �� ������, �Ｚ�̴� �̹� �׾��� ���� �� �׸� �� �� �ִ�.

�Է�
ù° �ٿ� �׽�Ʈ���̽� T�� �־�����.
(1�� T �� 20)
���� �ٺ��� ������ �׽�Ʈ ���̽��� ���ؼ� ���� ������ Ƚ�� N�� ���� ������ ������ �־�����. ������ ������� ���̰� N�� ���ڷ� �����Ǹ� 0���� 7������ �̷���� �ִ�. (1 �� N �� 100,000)

���
������ �׽�Ʈ���̽��� �ش��ϴ� ������ ���� ����Ѵ�.


input ����
1
19
6664442220001655360

output ����
#testcase1
3


�� �Է��� ������� ����� ������ ����.

*/