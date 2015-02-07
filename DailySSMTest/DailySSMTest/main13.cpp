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
	_Node* dir[8]; //8방향



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
//요구 사항
//다중 링크드 리스트
//해시맵을 통한 빠른 검색
void insertHash(int x, int y, Node* value){
	int key = (x + y) % DIVIDEVAL;
	if (hashMap[key] == NULL)
	{
		hashMap[key] = value;
	}
	else{
		//삽입 가능한 자리를 찾는다
		int tempKey = key + HASHJUMPVALUE; //소수를 더하는 방식
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

		//시작 노드
		Node* prevNode = new Node();
		deleteBuffer[bufidx++] = prevNode;
		prevNode->x = x;
		prevNode->y = y;
		Node* hash_value = prevNode;
		insertHash(x, y, hash_value);

		//문자 읽어온 후 리스트 및 해시맵 구성
		for (int j = 0; j < count; j++) {
			char dir = charArr[j];
			char rdir = 0;;//역방향 숫자
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
				//대각선 링크와 겹치는지 조사
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


				//새로운 노드 생성
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
			//찾은 링크 존재
			else{
				if (current->dir[rdir - '0'] == prevNode){
					//이미 링크가 있는경우
					prevNode = current;
				}
				else {
					//링크가 없는 경우
					current->dir[rdir - '0'] = prevNode;
					prevNode->dir[dir - '0'] = current;
					prevNode = current;
					result++;

					//대각선 링크와 겹치는지 조사
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
삼성이는 농경지를 설계하려고 한다.
먼저, 정수 좌표마다 점이 찍혀있는 매우 큰 종이가 있다. 그 다음, 종이의 원점에 펜을 올린다. 이제 펜을 절대로 종이에서 떼지 않은채 N번 움직여 농경지를 그린다. 또, 삼성이는 펜을 현재 있는 점과 인접한 8개의 점 중 하나로만 이동할 수 있다. (가로, 세로, 대각선) 가능한 이동은 아래 그림과 같으며, 숫자로 나타낼 수 있다.

삼성이가 그린 농경지가 주어질 때 나누어 지는 구역의 수를 구하는 프로그램을 작성하시오. 구역은 농경지 그림 상에서 빈 공간을 말하며, 펜으로 그린 선으로 둘러 쌓여 있어야 한다. 구역은 다른 구역으로 둘러 쌓여질 수 있으며, 삼성이는 이미 그었던 선을 또 그릴 수 도 있다.

입력
첫째 줄에 테스트케이스 T가 주어진다.
(1≤ T ≤ 20)
다음 줄부터 각각의 테스트 케이스에 대해서 펜을 움직인 횟수 N과 펜을 움직인 순서가 주어진다. 순서는 공백없이 길이가 N인 숫자로 구성되며 0부터 7까지로 이루어져 있다. (1 ≤ N ≤ 100,000)

출력
각각의 테스트케이스에 해당하는 구역의 수를 출력한다.


input 예시
1
19
6664442220001655360

output 예시
#testcase1
3


위 입력의 농경지의 모습은 다음과 같다.

*/