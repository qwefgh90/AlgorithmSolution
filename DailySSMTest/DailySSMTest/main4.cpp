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
		sumTable[start] = coinArr[start];//결과 값
		return coinArr[start];
	}
	else if (count - start == 2){
		sumTable[start] = coinArr[start] + coinArr[start + 1];//결과 값
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
		sumTable[start] = temp;//결과 값
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
			scanf("%d", &coinArr[j]);//동전
		}
		for (int j = 0; j < coinCount; j++){
			coinTwoSum[j] = coinArr[j] + coinArr[j + 1];//마지막 동전의 2개짜리 합은 뒤에 부분이 '0' 이므로 문제 없음
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




//삼성이가 길을 걷고 있는데, 산 신령이 나타나서 길에 돈을 쭉 놓으면서
//“삼성아 돈을 마음껏 주워가라.단, 연속해서 3 개의 돈을 줍지는 못한다” 라고 했다.
//불쌍한 삼성이가 가장 많은 돈을 줍도록 여러분이 삼성이를 도와주는 프로그램을 작성하는 것이 문제이다.
//아래와 같은 경우에 가장 많은 돈 38 원을 주울 수 있다.
//
//1	2	3	4	5	6	7	8
//5	7	10	1	2	10	11	6
//
//입력형식
//가장 먼저 테스트 케이스 입력 후 차례대로 입력 받는다.
//첫 번째 라인은 수의 개수를 입력하고 다음 줄에 수 들이 입력된다.수 는 양의 정수이고 합해서 30000 을 초과 하지 않고 수의 개수는 100 개를 넘지 않는다.
//
//출력 형식
//반드시 #testcase숫자 출력 후
//가장 많이 주울 수 있는 돈의 액수를 출력한다.
//
//입출력 예
//입력
//1
//8
//5 7 10 1 2 10 11 6
//
//출력
//#testcase1
//38
