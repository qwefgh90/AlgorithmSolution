#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
https://code.google.com/codejam/contest/2984486/dashboard
창 풀이법 (2진수 자리수 비교하기) (재귀 호출 문제)
1)각 자리수(2<=L=<110)의 0의 개수와 1의 개수를 샌다
2)비교대상의 0,1의 개수와 비교한다. 만약 0과 0 이 같고 1과 1이 같다면 0과 1의 개수가 같은지 판단한다.
3)다를경우 다음 자리를 비교한다.(for문)(바꿀필요가없음)
4)같은경우 바꾼 배열과 바꾸지 않은 배열을 만든후 다음 자리를 비교하기 위해 자기자신을 호출한다.(재귀 호출) 
5) 0과 1이 같고 1과 0이 같다면 스위치를 작동시킨다.(switchCount ++);
6) 4의 결과 둘다 풀이가 성공한다면 더 작은값을 반환한다.

풀이에 for문과 재귀를 섞어서 풀이가 깔끔하지 못하다.
for문을 재귀로 바꿀 수 있다.
즉 재귀 식으로 나타낸 후에 동적계획법이 가능하지 않을까? 당장은 모르겠다. 

//결과 small 케이스만 통과성공
//large 케이스는 시간이 오래걸림 (재귀한계)
*/
//#define CHANGE -1
//#define NOCHANGE 0
#define SUCCESS 2
#define IMPOSSIBLE 1

//같은 개수 반환
bool compare(char(*digit1)[50], char(*digit2)[50], int arraySize){
	for (int i = 0; i < arraySize; i++){
		for (int j = 0; j < arraySize; j++){
			int res = strcmp(digit1[i], digit2[j]);
			if (res == 0){
				break;
			}
			if (j + 1 == arraySize){
				return false;
			}
		}
	}
	return true;
}

/*
digitPos : 1자리 부터 40자리까지 가능
*/
int compareDigit(char(*digit1)[50], char(*digit2)[50], int digitPos, int arraySize, int digitLength,int& result){
	while(digitPos <= digitLength){	//모든 자리 검사
		int zeroSizeDigit1 = 0;
		int oneSizeDigit1 = 0;
		int zeroSizeDigit2 = 0;
		int oneSizeDigit2 = 0;
		for (int i = 0; i < arraySize; i++){
			if (digit1[i][digitLength - digitPos] == '0')
				zeroSizeDigit1++;
			else
				oneSizeDigit1++;
			if (digit2[i][digitLength - digitPos] == '0')
				zeroSizeDigit2++;
			else
				oneSizeDigit2++;
		}
		
		//2가지 경우로 나뉘는 경우 예) 0의 개수와 1의 개수가 같아서 바꾸거나 안바꾸는 경우
		if (zeroSizeDigit1 == zeroSizeDigit2 && oneSizeDigit1 == oneSizeDigit2 && zeroSizeDigit1 == oneSizeDigit1){
			//printf("[identical]%d\n", digitPos);
			int res1 = 0;
			int res2 = 0;
			int resCount1 = result;
			int resCount2 = result + 1;	//밑에서 1을 0으로 바꿈
			char digit1_copy[160][50];
			char digit1_copy2[160][50];
			char digit2_copy[160][50];
			memcpy(digit1_copy, digit1, sizeof(char)* 50 * 160);	//그대로 인 배열
			memcpy(digit1_copy2, digit1, sizeof(char)* 50 * 160);	//1이면 0 으로 바꾼 배열
			memcpy(digit2_copy, digit2, sizeof(char)* 50 * 160);
			for (int i= 0; i < arraySize; i++){
				if (digit1_copy2[i][digitLength - digitPos] == '0')
					digit1_copy2[i][digitLength - digitPos] = '1';
				else
					digit1_copy2[i][digitLength - digitPos] = '0';
			}
			//2가지를 다 테스트 해보고 가능한 케이스가 정답.
			res1 = compareDigit(digit1_copy, digit2, digitPos + 1, arraySize, digitLength, resCount1);
			res2 = compareDigit(digit1_copy2, digit2, digitPos + 1, arraySize, digitLength, resCount2);
			
			if (res1 == IMPOSSIBLE && res2 == IMPOSSIBLE){
				return IMPOSSIBLE;
			}
			else if (res1 == IMPOSSIBLE){
				result = resCount2;
				return SUCCESS;
			}
			else if (res2 == IMPOSSIBLE){
				result = resCount1;
				return SUCCESS;
			}
			else{
				if (resCount1 <= resCount2)//둘다 가능했을경우 더 작은 경우를 사용
					result = resCount1;
				else
					result = resCount2;
				return SUCCESS;
			}
		}
		//개수가 비대칭하게 같으면 패스
		else if (zeroSizeDigit1 == zeroSizeDigit2 && oneSizeDigit1 == oneSizeDigit2){
			
		}
		//개수가 비대칭이면서 digit0와 digit1이 크로스로 같으면
		else if (zeroSizeDigit1 == oneSizeDigit2 && oneSizeDigit1 == zeroSizeDigit2){
			//printf("[change]%d\n", digitPos);
			result++;
			for (int i = 0; i < arraySize; i++){	//나중을 위해 0과 1을 바꾼다.
				if (digit1[i][digitLength - digitPos] == '0')
					digit1[i][digitLength - digitPos] = '1';
				else
					digit1[i][digitLength - digitPos] = '0';
			}
		}
		else{
			return IMPOSSIBLE;
		}
		digitPos++;
	}
	//0과 1의 균형이 맞춰졌으면 최종 비교를 시도한다.
	if (compare(digit1, digit2, arraySize)){
		return SUCCESS;
	}
	else
		return IMPOSSIBLE;
}

int main(){

	FILE* input = fopen("ChargingChaosSmallInput.txt", "r");
	FILE* output = fopen("output.txt", "w");
	int testcase;
	//scanf("%d", &testcase);
	fscanf(input, "%d", &testcase);

	for (int k = 0; k < testcase; k++){
		char digit1[160][50];	//10개 씩 더할당
		char digit2[160][50];

		int arraySize;
		int digitLength;
		//scanf("%d %d", &arraySize, &digitLength);
		fscanf(input, "%d %d", &arraySize, &digitLength);

		char enter[100];
		//fscanf(input, "%s", enter);
//;		int enter = getchar();
		for (int i = 0; i < arraySize; i++){
			//scanf("%s", digit1[i]);
			fscanf(input, "%s", digit1[i]);

		}
		for (int i = 0; i < arraySize; i++){
			//scanf("%s", digit2[i]);
			fscanf(input, "%s", digit2[i]);
		}
		int switchingCount = 0;
		int result = compareDigit(digit1, digit2, 1, arraySize, digitLength,switchingCount);
	
		if (result==IMPOSSIBLE)
			//printf("Case #%d: NOT POSSIBLE\n", k + 1);
			fprintf(output, "Case #%d: NOT POSSIBLE\n", k + 1);
		else
			//printf("Case #%d: %d\n", k + 1, switchingCount);
			fprintf(output, "Case #%d: %d\n", k + 1, switchingCount);

	}


	return 0;
}

/*
Problem A. Charging Chaos
This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
Small input
8 points
Solve A-small
Large input
17 points
Solve A-large
Problem

Shota the farmer has a problem. He has just moved into his newly built farmhouse, but it turns out that the outlets haven't been configured correctly for all of his devices. Being a modern farmer, Shota owns a large number of smartphones and laptops, and even owns a tablet for his favorite cow Wagyu to use. In total, he owns N different devices.

As these devices have different specifications and are made by a variety of companies, they each require a different electric flow to charge. Similarly, each outlet in the house outputs a specific electric flow. An electric flow can be represented by a string of 0s and 1s of length L.

Shota would like to be able to charge all N of his devices at the same time. Coincidentally, there are exactly N outlets in his new house. In order to configure the electric flow from the outlets, there is a master control panel with L switches. The ith switch flips the ith bit of the electric flow from each outlet in the house. For example, if the electric flow from the outlets is:

Outlet 0: 10
Outlet 1: 01
Outlet 2: 11
Then flipping the second switch will reconfigure the electric flow to:

Outlet 0: 11
Outlet 1: 00
Outlet 2: 10
If Shota has a smartphone that needs flow "11" to charge, a tablet that needs flow "10" to charge, and a laptop that needs flow "00" to charge, then flipping the second switch will make him very happy!

Misaki has been hired by Shota to help him solve this problem. She has measured the electric flows from the outlets in the house, and noticed that they are all different. Decide if it is possible for Shota to charge all of his devices at the same time, and if it is possible, figure out the minimum number of switches that needs to be flipped, because the switches are big and heavy and Misaki doesn't want to flip more than what she needs to.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of three lines. The first line contains two space-separated integers N and L. The second line contains N space-separated strings of length L, representing the initial electric flow from the outlets. The third line also contains N space-separated strings of length L, representing the electric flow required by Shota's devices.

Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the minimum number of switches to be flipped in order for Shota to charge all his devices. If it is impossible, y should be the string "NOT POSSIBLE" (without the quotes). Please note that our judge is not case-sensitive, but it is strict in other ways: so although "not  possible" will be judged correct, any misspelling will be judged wrong. We suggest copying/pasting the string NOT POSSIBLE into your code.

Limits

1 ≤ T ≤ 100.
No two outlets will be producing the same electric flow, initially.
No two devices will require the same electric flow.
Small dataset

1 ≤ N ≤ 10.
2 ≤ L ≤ 10.

Large dataset

1 ≤ N ≤ 150.
10 ≤ L ≤ 40.

Sample


Input

Output

3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01

Case #1: 1
Case #2: NOT POSSIBLE
Case #3: 0

Explanation

In the first example case, Misaki can flip the second switch once. The electric flow from the outlets becomes:

Outlet 0: 00
Outlet 1: 10
Outlet 2: 11
Then Shota can use the outlet 0 to charge device 1, the outlet 1 to charge device 2, outlet 2 to charge device 0. This is also a solution that requires the minimum amount number of switches to be flipped.

*/