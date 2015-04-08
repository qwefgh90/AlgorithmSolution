#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
https://code.google.com/codejam/contest/2984486/dashboard
â Ǯ�̹� (2���� �ڸ��� ���ϱ�) (��� ȣ�� ����)
1)�� �ڸ���(2<=L=<110)�� 0�� ������ 1�� ������ ����
2)�񱳴���� 0,1�� ������ ���Ѵ�. ���� 0�� 0 �� ���� 1�� 1�� ���ٸ� 0�� 1�� ������ ������ �Ǵ��Ѵ�.
3)�ٸ���� ���� �ڸ��� ���Ѵ�.(for��)(�ٲ��ʿ䰡����)
4)������� �ٲ� �迭�� �ٲ��� ���� �迭�� ������ ���� �ڸ��� ���ϱ� ���� �ڱ��ڽ��� ȣ���Ѵ�.(��� ȣ��) 
5) 0�� 1�� ���� 1�� 0�� ���ٸ� ����ġ�� �۵���Ų��.(switchCount ++);
6) 4�� ��� �Ѵ� Ǯ�̰� �����Ѵٸ� �� �������� ��ȯ�Ѵ�.

Ǯ�̿� for���� ��͸� ��� Ǯ�̰� ������� ���ϴ�.
for���� ��ͷ� �ٲ� �� �ִ�.
�� ��� ������ ��Ÿ�� �Ŀ� ������ȹ���� �������� ������? ������ �𸣰ڴ�. 

//��� small ���̽��� �������
//large ���̽��� �ð��� �����ɸ� (����Ѱ�)
*/
//#define CHANGE -1
//#define NOCHANGE 0
#define SUCCESS 2
#define IMPOSSIBLE 1

//���� ���� ��ȯ
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
digitPos : 1�ڸ� ���� 40�ڸ����� ����
*/
int compareDigit(char(*digit1)[50], char(*digit2)[50], int digitPos, int arraySize, int digitLength,int& result){
	while(digitPos <= digitLength){	//��� �ڸ� �˻�
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
		
		//2���� ���� ������ ��� ��) 0�� ������ 1�� ������ ���Ƽ� �ٲٰų� �ȹٲٴ� ���
		if (zeroSizeDigit1 == zeroSizeDigit2 && oneSizeDigit1 == oneSizeDigit2 && zeroSizeDigit1 == oneSizeDigit1){
			//printf("[identical]%d\n", digitPos);
			int res1 = 0;
			int res2 = 0;
			int resCount1 = result;
			int resCount2 = result + 1;	//�ؿ��� 1�� 0���� �ٲ�
			char digit1_copy[160][50];
			char digit1_copy2[160][50];
			char digit2_copy[160][50];
			memcpy(digit1_copy, digit1, sizeof(char)* 50 * 160);	//�״�� �� �迭
			memcpy(digit1_copy2, digit1, sizeof(char)* 50 * 160);	//1�̸� 0 ���� �ٲ� �迭
			memcpy(digit2_copy, digit2, sizeof(char)* 50 * 160);
			for (int i= 0; i < arraySize; i++){
				if (digit1_copy2[i][digitLength - digitPos] == '0')
					digit1_copy2[i][digitLength - digitPos] = '1';
				else
					digit1_copy2[i][digitLength - digitPos] = '0';
			}
			//2������ �� �׽�Ʈ �غ��� ������ ���̽��� ����.
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
				if (resCount1 <= resCount2)//�Ѵ� ����������� �� ���� ��츦 ���
					result = resCount1;
				else
					result = resCount2;
				return SUCCESS;
			}
		}
		//������ ���Ī�ϰ� ������ �н�
		else if (zeroSizeDigit1 == zeroSizeDigit2 && oneSizeDigit1 == oneSizeDigit2){
			
		}
		//������ ���Ī�̸鼭 digit0�� digit1�� ũ�ν��� ������
		else if (zeroSizeDigit1 == oneSizeDigit2 && oneSizeDigit1 == zeroSizeDigit2){
			//printf("[change]%d\n", digitPos);
			result++;
			for (int i = 0; i < arraySize; i++){	//������ ���� 0�� 1�� �ٲ۴�.
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
	//0�� 1�� ������ ���������� ���� �񱳸� �õ��Ѵ�.
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
		char digit1[160][50];	//10�� �� ���Ҵ�
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

1 �� T �� 100.
No two outlets will be producing the same electric flow, initially.
No two devices will require the same electric flow.
Small dataset

1 �� N �� 10.
2 �� L �� 10.

Large dataset

1 �� N �� 150.
10 �� L �� 40.

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