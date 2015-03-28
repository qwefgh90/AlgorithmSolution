#include <stdio.h>
int min(int v1, int v2){
	if (v1 >= v2)
		return v2;
	else
		return v1;

}
int max(int v1, int v2){
	if (v1 >= v2)
		return v1;
	else
		return v2;

}


int getValue(int v1, int v2){
	int minValue = min(v1, v2);//최소값
	int maxValue = max(v1, v2);//최대값
	int temp = maxValue - minValue;

	while (minValue != temp){
		int minv = min(temp, minValue);//계산
		int maxv = max(temp, minValue);

		minValue = minv;//대입
		maxValue = maxv;

		temp = maxValue - minValue;
	}

	return minValue;
}

int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int v1;
		int v2;
		scanf("%d %d", &v1, &v2);
		int result = getValue(v1, v2);
		if (result == 1)
			printf("yes\n");	//서로소
		else
			printf("no\n");
	}

	return 0;
}



/*

두 수가 서로 소(relatively prime)
두 수의 공약수가 1 만이 존재하는 수 즉 최대 공약수가 1 인 수
서로 소인 예를 들면
4 와 9 , 5 와 8 , 8 과 9 ...
[입력]
입력의 첫 줄은 전체 Test Case 개수 N이다.
각 Case 두 수가 입력으로 주어진다. 두 수는 1000 이하의 자연수이다.
[출력]
서로 소이면 yes 아니면 no 를 출력한다.
(중요!!! 출력 전 반드시 #testcase번호 를 출력해야 한다.)

- 입출력 예 -
입력
3
4 9
4 7
6 8

출력
#testcase1
yes
#testcase2
yes
#testcase3
no

*/