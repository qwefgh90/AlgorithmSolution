#include <stdio.h>

//�׸��� ��İ� DP ���̺��� ����ϸ� Ǯ����.
//���̺��� ��� �÷��� ǥ���� �� �ִ� �� �� ���� ������ ����ؾ� �Ѵ�. --->�����Ѵ�

void sort(int* post, int count){
	int flag = 0;
	for (int i = 0; i < count; i++){
		for (int j = 1; j < count - i; j++){
			if (post[j - 1] > post[j]){
				int t = post[j - 1];
				post[j - 1] = post[j];
				post[j] = t;//����
			}
			flag = 1;
		}
		if (flag == 0)
			return;
	}
}

//offset -> nextbelow�� ���ؿ�
int getBelow(int target,int* post, int count,int offset){
	int result = -1;
	int i = 0;
	for (i = 0; i < count; i++){
		if (target < post[i]){
			break;
		}
	}
	if (i - 1 - offset < 0)
		return -1;
	result = post[i-1 - offset];//�ٴڿ��ִ� ��

	return result;
}

//���̺�, maxuse, post, count
long long int getResult(int* postTable, int maxuse, int* post, int count){
	long long int  startValue = 1;
	int result = 0;
	int bonus;
	int divide;
	while (1){
		int offset = 0;
		
		int below = getBelow(startValue, post, count, offset);//�ٴ� ��
		if (below == -1){
			return 0;	// 0�� �����ϰ� ���� (�ּ� 1�̶� �����ؾ���)
		}
		divide = startValue / below;
		bonus = startValue % below;

		//if (bonus != 0 && postTable[bonus] == 0){
		//	//�Ұ����� ���� ���
		//	return 0;
		//}

		//�ּҰ� �ƴ� �� �ִ�?
		postTable[startValue] = postTable[bonus] + divide;

		//�ϳ��� ���� �ٴڰ��� ������ ����?
		while (1){
			offset++;
			
			int below = getBelow(startValue, post, count, offset);//�ٴ� ��
			
			if (below == -1){	// ����
				break;
			}

			divide = startValue / below;
			bonus = startValue % below;

			//if (bonus != 0 && postTable[bonus] == 0){
			//	//�Ұ����� ���� ���
			//	return 0;
			//}

			//�ּҰ� �ƴ� �� �ִ�?
			int temp = postTable[bonus] + divide;

			if (temp < postTable[startValue]){	//������ �ٴڰ��� �����ϸ�?
				postTable[startValue] = temp;
			}
			else{	//�������� ������ break;
			}

			if (offset >= 100){	//10���� üũ
				break;
			}
		}

		if (postTable[startValue] > maxuse){
			return startValue - 1;
		}

		startValue++;//�������˻�
	}


}

int postTable[100000000] = { 0, };//ī���� ���̺�

int main(){
	int testcase;
	
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int maxuse;	//1~200��
		int count;	//1~200�� ����
		scanf("%d %d", &maxuse, &count);
		int post[200] = { 0, };	//��ǥ 200��
		for (int j = 0; j < count; j++){
			scanf("%d", &post[j]);//�Է�	10000���� �ڿ���
		}
		sort(post, count);//����
		
		long long int result = getResult(postTable, maxuse, post, count);
		printf("%lld\n", result);
		//
	
	}
}


/*
���� ����ġ�� �ٸ� N���� ������ ��ǥ�� �ֽ��ϴ�. �� ��, ���� ������ ��ǥ�� ���� �� ����ص� ������, ��� ��ǥ�� �� ��� ȸ���� K�� ���Ϸ� ���ѵǾ� �ֽ��ϴ�. �̷� ������ ���� ��, ��ǥ�� ����Ͽ� ����� �� �� �ִ� ����ġ�� 1���� ���ʴ�� ���� ��, ���� ū ����ġ�� �˾Ƴ����� �մϴ�.
���� ���, N=2�̰� �� ��ǥ�� ����ġ�� 1, 3�̶�� �ϰ�, K=5�� ���Ͽ� ���ô�. �׷��� ����ġ�� 5������ ����ġ�� 1�� ��ǥ�� �̿��Ͽ� ���� �� �ְ�, 6���� 13������ ������ ���� ���� �� �ֽ��ϴ�.

6 = 3+3
7 = 3+3+1
8 = 3+3+1+1
9 = 3+3+3
10 = 3+3+3+1
11 = 3+3+3+1+1
12 = 3+3+3+3
13 = 3+3+3+3+1
14 = X
15 = 3+3+3+3+3

���⼭, 14�� �־��� 5���� ��ǥ�� �̿��Ͽ� ���� �� �����ϴ�.
���� ����ġ�� ���ʴ�� ����� ���� ��, ���� �� �ִ� ���� ū ����ġ�� 13�Դϴ�.

��ǥ�� ����Ͽ� ���� �� �ִ� ����ġ�� ���ʴ�� ����� ���� ��, ���� �� �ִ� ���� ū ����ġ�� ����ϼ���.

���� �ð�: 1�� (java: 2��)

[�Է�]
�Է¿��� ���� �׽�Ʈ ���̽��� ���Ե� �� �ִ�. �Է��� ù° �ٿ��� �׽�Ʈ ���̽��� �� T�� �־�����, ���� ���ʷ� T���� �׽�Ʈ ���̽��� �־����� (T �� 30)
�� �׽�Ʈ ���̽����� ù �ٿ� �ִ� ��� Ƚ�� K�� ��ǥ�� ���� �� N�� �������� �и��Ǿ� �־�����. (1 �� N �� 200, 1 �� K �� 200)
�� ��° �ٿ� �� ��ǥ�� ����ġ�� �������� �и��Ǿ� �־�����. �� ����ġ�� 10,000������ �ڿ����̴�.

[���]
�� �׽�Ʈ ���̽����� ù �ٿ� ��ǥ�� ����Ͽ� ���� �� �ִ� ����ġ�� ���ʴ�� ����� ���� ��, ���� �� �ִ� ���� ū ����ġ�� ����Ѵ�.
(�߿�! �׽�Ʈ ���̽� �������� #testcase��ȣ�� ��� �� ���� ���)

-����� ��-

�Է�
2
5 2
1 3
3 10
29 50 36 43 1 2 4 8 15 22
���
#testcase1
13
#testcase2
56

*/