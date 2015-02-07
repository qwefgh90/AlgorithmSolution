#include <stdio.h>
struct Node{
	int value;
	Node* next;
};

//���� �� �Ǵ� �ε���(������) �ڿ� ���� �����´�.
Node* popFront(Node** node,int offset = 0){
	Node* result = *node;
	Node* prev = NULL;
	while (offset != 0){
		prev = result;
		result = result->next;
		offset--;
	}
	if (prev != NULL)
		prev->next = result->next;//����Ʈ�� �߰����� ������ ���
	else
		*node = result->next;//����Ʈ�� ���� ���� ������ ���

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
		//�ּ� ��ũ�帮��Ʈ
		Node minNode[10] = { 0, };
		for (int j = 0; j < 9; j++){
			minNode[j].value = j;
			minNode[j].next = &minNode[j + 1];
		}
		minNode[9].value = 9; minNode[9].next = NULL;
		
		//�ִ� ��ũ�帮��Ʈ//��� �ʱ�ȭ 
		Node maxNode[10] = { 0, };
		for (int j = 9; j > 0; j--){
			maxNode[j].value = j;
			maxNode[j].next = &maxNode[j - 1];
		}
		maxNode[0].value = 0; maxNode[0].next = NULL;
		
		//�ִ밪 �˰���
		//�ִ밪 + ���� '<' ����
		Node* maxHead = &maxNode[9];
		for (int i = 0; i < count; i++){
			char* charPtr = &input[i];
			int offset = 0;
			//'>' ���� 
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
		
		//�ּҰ� �˰���
		//�ּҰ� + ���� '>' ����
		Node* minHead = minNode;
		for (int i = 0; i < count; i++){
			char* charPtr = &input[i];
			int offset = 0;
			//'>' ���� 
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
�ε�ȣ

�� ������ �ε�ȣ ��ȣ ��<���� ��>���� k �� ������ ������ A�� �ִ�. �츮�� �� �ε�ȣ ��ȣ �յڿ� ���� �ٸ� �� �ڸ��� ���ڸ� �־ ��� �ε�ȣ ���踦 ������Ű���� �Ѵ�.

���� ���, ���õ� �ε�ȣ ������ A�� ������ ���ٰ� ����.

A �� < < < > < < > < >

�ε�ȣ ��ȣ �յڿ� ���� �� �ִ� ���ڴ� 0���� 9������ �����̸� ���õ� ���ڴ� ��� �޶�� �Ѵ�. �Ʒ��� �ε�ȣ ������ A�� ������Ű�� �� ���̴�.

3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

�� ��Ȳ���� �ε�ȣ ��ȣ�� ������ ��, ���ڸ� ��� ���̸� �ϳ��� ���� ���� �� �ִµ� �� ���� �־��� �ε�ȣ ���踦 ������Ű�� ������� �Ѵ�.
�׷��� �־��� �ε�ȣ ���踦 �����ϴ� ������ �ϳ� �̻� �����Ѵ�. ���� ��� 3456128790 �Ӹ� �ƴ϶� 5689023174�� �Ʒ��� ���� �ε�ȣ ���� A�� ������Ų��.

5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

�������� ���õ� k ���� �ε�ȣ ������ �����ϴ� (k+1) �ڸ��� ���� �߿��� �ִ밪�� �ּҰ��� ã�ƾ� �Ѵ�. �ռ� ������ ��� �� �ε�ȣ�� �յڿ� ���� ���ڴ�  0, 1, 2, 3, 4, 5, 6, 7, 8, 9 �߿��� �����ؾ� �ϸ� ���õ� ���ڴ� ��� �޶�� �Ѵ�.
���α׷��� ����ð��� 1�ʸ� ���� �� ����.

�Է�
ù �ٿ� �׽�Ʈ���̽� ���� T�� �־�����.
���� �ٺ��� �� �׽�Ʈ���̽��� ���Ͽ�, ù �ٿ��� �ε�ȣ ������ ������ ��Ÿ���� ������ �־�����. �� ���� �ٿ��� k ���� �ε�ȣ ��ȣ�� �ϳ��� ������ �ΰ� �� �ٿ� ��� ���õȴ�. k �� ������ 2 <= k <= 9�̴�.

���
���� ����ϱ� ���� �� �׽�Ʈ���̽��� ������ ���� ��#testcase1����#testcase2��... �� ����Ѵ�. �� �׽�Ʈ���̽��� ���Ͽ� ���õ� �ε�ȣ ���踦 �����ϴ� �ڸ��� �ִ�, �ּ� ������ ù° �ٰ� ��° �ٿ� ���� ����Ѵ�. �� �Ʒ� �� (1)�� ���� ù �ڸ��� 0�� ��쵵 ������ ���ԵǾ�� �Ѵ�. ��� �Է¿� ���� �׻� �����ϸ� ��� ������ �ϳ��� ���ڿ��� �ǵ��� �ؾ� �Ѵ�.

����� ��

�Է�
2
2
< >
9
> < < < > > > < <

���
#testcase1
897
021
#testcase2
9567843012
1023765489


*/