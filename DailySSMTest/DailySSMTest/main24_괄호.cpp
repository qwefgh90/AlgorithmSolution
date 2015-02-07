#include <stdio.h>
struct Node{
	int value;
	Node* next;
};

//가장 앞 또는 인덱스(오프셋) 뒤에 것을 가져온다.
Node* popFront(Node** node,int offset = 0){
	Node* result = *node;
	Node* prev = NULL;
	while (offset != 0){
		prev = result;
		result = result->next;
		offset--;
	}
	if (prev != NULL)
		prev->next = result->next;//리스트의 중간에서 제거할 경우
	else
		*node = result->next;//리스트의 가장 앞을 제거할 경우

	return result;
}

int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int count;
		char input[10] = { 0, };
		scanf("%d", &count);
		for (int j = 0; j < count; j++){
			scanf("%c", &input[j]);
			if (input[j] == ' ' || input[j] == '\n'){
				j--;
			}
		}
		//최소 링크드리스트
		Node minNode[10] = { 0, };
		for (int j = 0; j < 9; j++){
			minNode[j].value = j;
			minNode[j].next = &minNode[j + 1];
		}
		minNode[9].value = 9; minNode[9].next = NULL;
		
		//최대 링크드리스트//노드 초기화 
		Node maxNode[10] = { 0, };
		for (int j = 9; j > 0; j--){
			maxNode[j].value = j;
			maxNode[j].next = &maxNode[j - 1];
		}
		maxNode[0].value = 0; maxNode[0].next = NULL;
		
		//최대값 알고리즘
		//최대값 + 연속 '<' 개수
		Node* maxHead = &maxNode[9];
		for (int i = 0; i < count; i++){
			char* charPtr = &input[i];
			int offset = 0;
			//'>' 개수 
			while (*charPtr == '<' && *charPtr != '\0'){
				offset++;
				charPtr++;
			}
			Node* pop = popFront(&maxHead, offset);
			printf("%d", pop->value);

		}
		Node* pop0 = popFront(&maxHead, 0);
		printf("%d", pop0->value);
		printf("\n");
		
		//최소값 알고리즘
		//최소값 + 연속 '>' 개수
		Node* minHead = minNode;
		for (int i = 0; i < count; i++){
			char* charPtr = &input[i];
			int offset = 0;
			//'>' 개수 
			while (*charPtr == '>' && *charPtr != '\0'){
				offset++;
				charPtr++;
			}
			Node* pop = popFront(&minHead, offset);
			printf("%d",pop->value);
			
		}
		Node* pop1 = popFront(&minHead, 0);
		printf("%d", pop1->value);
		printf("\n");

	}

	return 0;
}



/*
부등호

두 종류의 부등호 기호 ‘<’와 ‘>’가 k 개 나열된 순서열 A가 있다. 우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다.

예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자.

A ⇒ < < < > < < > < >

부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 아래는 부등호 순서열 A를 만족시키는 한 예이다.

3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다.
그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다.

5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

여러분은 제시된 k 개의 부등호 순서를 만족하는 (k+1) 자리의 정수 중에서 최대값과 최소값을 찾아야 한다. 앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는  0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중에서 선택해야 하며 선택된 숫자는 모두 달라야 한다.
프로그램의 실행시간은 1초를 넘을 수 없다.

입력
첫 줄에 테스트케이스 개수 T가 주어진다.
다음 줄부터 각 테스트케이스에 대하여, 첫 줄에는 부등호 문자의 개수를 나타내는 정수가 주어진다. 그 다음 줄에는 k 개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k 의 범위는 2 <= k <= 9이다.

출력
답을 출력하기 전에 각 테스트케이스의 순서에 따라 “#testcase1”“#testcase2”... 을 출력한다. 각 테스트케이스에 대하여 제시된 부등호 관계를 만족하는 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력한다. 단 아래 예 (1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다.

입출력 예

입력
2
2
< >
9
> < < < > > > < <

출력
#testcase1
897
021
#testcase2
9567843012
1023765489


*/