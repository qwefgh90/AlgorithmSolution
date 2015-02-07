#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int coinArr[200] = { 0, };
int coinCount = 0;
int coinTwoSum[200] = { 0, };
int sumTable[200] = { 0, };
// O
// OO
//  OO

int maxSum(int start, int count)
{
	if (count - start <= 0){
		return 0;
	}

	if (sumTable[start] != 0){
		return sumTable[start];
	}


	if (count - start == 1){
		sumTable[start] = coinArr[start];//��� ��
		return coinArr[start];
	}
	else if (count - start == 2){
		sumTable[start] = coinArr[start] + coinArr[start + 1];//��� ��
		return coinArr[start] + coinArr[start + 1];
	}
	else if (count - start == 3){
		int temp;
		if (coinArr[start + 0] + coinArr[start + 1] > coinArr[start + 1] + coinArr[start + 2]){
			temp = coinArr[start + 0] + coinArr[start + 1];
		}
		else{
			temp = coinArr[start + 1] + coinArr[start + 2];
		}
		if (temp > coinArr[start + 0] + coinArr[start + 2]){

		}
		else {
			temp = coinArr[start + 0] + coinArr[start + 2];
		}
		sumTable[start] = temp;//��� ��
		return temp;
	}

	int maxValue = 0;
	int preValue = 0;
	// O
	preValue = coinArr[start] + maxSum(start + 2, count);
	if (maxValue < preValue)
		maxValue = preValue;
	// OO
	preValue = coinTwoSum[start] + maxSum(start + 3, count);
	if (maxValue < preValue)
		maxValue = preValue;

	//  OO
	preValue = coinTwoSum[start + 1] + maxSum(start + 4, count);
	if (maxValue < preValue)
		maxValue = preValue;

	sumTable[start] = maxValue;
	return maxValue;
}

int main()
{

	int testcase = 0;
	int max = 0;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i+1);
		memset(coinArr, 0, sizeof(int)* 200);
		coinCount = 0;
		memset(coinTwoSum, 0, sizeof(int)* 200);
		memset(sumTable, 0, sizeof(int)* 200);

		scanf("%d", &coinCount);
		for (int j = 0; j < coinCount; j++){
			scanf("%d", &coinArr[j]);//����
		}
		for (int j = 0; j < coinCount; j++){
			coinTwoSum[j] = coinArr[j] + coinArr[j + 1];//������ ������ 2��¥�� ���� �ڿ� �κ��� '0' �̹Ƿ� ���� ����
		}
		if (coinCount == 0){
			max = 0;
		}else if (coinCount == 1){
			max = coinArr[0];
		}
		else if (coinCount == 2){
			max = coinArr[0] + coinArr[1];
		}
		else if (coinCount == 3){
			int temp;
			if (coinArr[0] + coinArr[1] > coinArr[1] + coinArr[2]){
				temp = coinArr[0] + coinArr[1];
			}
			else{
				temp = coinArr[1] + coinArr[2];
			}
			if (temp > coinArr[0] + coinArr[2]){

			}
			else {
				temp = coinArr[0] + coinArr[2];
			}
			max = temp;

		}
		else if (coinCount > 3){
			int temp = 0;
			int pretemp = 0;
			//[0]  ~
			pretemp = coinArr[0] + maxSum(2, coinCount);
			if (pretemp > temp){
				temp = pretemp;
			}
			//[0] [1] ~
			pretemp = coinArr[0] + coinArr[1] + maxSum(3, coinCount);
			if (pretemp > temp){
				temp = pretemp;
			}

			//[1] ~
			pretemp = coinArr[1] + maxSum(3, coinCount);
			if (pretemp > temp){
				temp = pretemp;
			}
			//[1][2] ~
			pretemp = coinArr[1] + coinArr[2] + maxSum(4, coinCount);
			if (pretemp > temp){
				temp = pretemp;
			}
			max = temp;
		}
		printf("%d\n", max);
	}
	return 0;
}




//�Ｚ�̰� ���� �Ȱ� �ִµ�, �� �ŷ��� ��Ÿ���� �濡 ���� �� �����鼭
//���Ｚ�� ���� ������ �ֿ�����.��, �����ؼ� 3 ���� ���� ������ ���Ѵ١� ��� �ߴ�.
//�ҽ��� �Ｚ�̰� ���� ���� ���� �ݵ��� �������� �Ｚ�̸� �����ִ� ���α׷��� �ۼ��ϴ� ���� �����̴�.
//�Ʒ��� ���� ��쿡 ���� ���� �� 38 ���� �ֿ� �� �ִ�.
//
//1	2	3	4	5	6	7	8
//5	7	10	1	2	10	11	6
//
//�Է�����
//���� ���� �׽�Ʈ ���̽� �Է� �� ���ʴ�� �Է� �޴´�.
//ù ��° ������ ���� ������ �Է��ϰ� ���� �ٿ� �� ���� �Էµȴ�.�� �� ���� �����̰� ���ؼ� 30000 �� �ʰ� ���� �ʰ� ���� ������ 100 ���� ���� �ʴ´�.
//
//��� ����
//�ݵ�� #testcase���� ��� ��
//���� ���� �ֿ� �� �ִ� ���� �׼��� ����Ѵ�.
//
//����� ��
//�Է�
//1
//8
//5 7 10 1 2 10 11 6
//
//���
//#testcase1
//38
