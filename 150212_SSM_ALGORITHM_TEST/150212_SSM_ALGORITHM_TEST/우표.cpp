#include <stdio.h>

//그리디 방식과 DP 테이블을 사용하면 풀린다.
//테이블의 모든 컬럼이 표현할 수 있는 값 중 가장 개수를 사용해야 한다. --->보장한다

void sort(int* post, int count){
	int flag = 0;
	for (int i = 0; i < count; i++){
		for (int j = 1; j < count - i; j++){
			if (post[j - 1] > post[j]){
				int t = post[j - 1];
				post[j - 1] = post[j];
				post[j] = t;//스왑
			}
			flag = 1;
		}
		if (flag == 0)
			return;
	}
}

//offset -> nextbelow를 구해옴
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
	result = post[i-1 - offset];//바닥에있는 값

	return result;
}

//테이블, maxuse, post, count
long long int getResult(int* postTable, int maxuse, int* post, int count){
	long long int  startValue = 1;
	int result = 0;
	int bonus;
	int divide;
	while (1){
		int offset = 0;
		
		int below = getBelow(startValue, post, count, offset);//바닥 값
		if (below == -1){
			return 0;	// 0을 제출하고 퇴출 (최소 1이라도 존재해야함)
		}
		divide = startValue / below;
		bonus = startValue % below;

		//if (bonus != 0 && postTable[bonus] == 0){
		//	//불가능한 값일 경우
		//	return 0;
		//}

		//최소가 아닐 수 있다?
		postTable[startValue] = postTable[bonus] + divide;

		//하나더 작은 바닥값이 더작을 지도?
		while (1){
			offset++;
			
			int below = getBelow(startValue, post, count, offset);//바닥 값
			
			if (below == -1){	// 멈춤
				break;
			}

			divide = startValue / below;
			bonus = startValue % below;

			//if (bonus != 0 && postTable[bonus] == 0){
			//	//불가능한 값일 경우
			//	return 0;
			//}

			//최소가 아닐 수 있다?
			int temp = postTable[bonus] + divide;

			if (temp < postTable[startValue]){	//더작은 바닥값이 존재하면?
				postTable[startValue] = temp;
			}
			else{	//존재하지 않으면 break;
			}

			if (offset >= 100){	//10까지 체크
				break;
			}
		}

		if (postTable[startValue] > maxuse){
			return startValue - 1;
		}

		startValue++;//다음값검사
	}


}

int postTable[100000000] = { 0, };//카운팅 테이블

int main(){
	int testcase;
	
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int maxuse;	//1~200개
		int count;	//1~200개 종류
		scanf("%d %d", &maxuse, &count);
		int post[200] = { 0, };	//우표 200개
		for (int j = 0; j < count; j++){
			scanf("%d", &post[j]);//입력	10000이하 자연수
		}
		sort(post, count);//정렬
		
		long long int result = getResult(postTable, maxuse, post, count);
		printf("%lld\n", result);
		//
	
	}
}


/*
서로 값어치가 다른 N가지 종류의 우표가 있습니다. 이 때, 같은 종류의 우표를 여러 번 사용해도 되지만, 모든 우표의 총 사용 회수가 K개 이하로 제한되어 있습니다. 이런 제한이 있을 때, 우표를 사용하여 만들어 낼 수 있는 값어치를 1부터 차례대로 만들 때, 가장 큰 값어치를 알아내려고 합니다.
예를 들어, N=2이고 각 우표의 값어치가 1, 3이라고 하고, K=5로 정하여 봅시다. 그러면 값어치가 5까지는 값어치가 1인 우표를 이용하여 만들 수 있고, 6부터 13까지는 다음과 같이 구할 수 있습니다.

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

여기서, 14는 주어진 5개의 우표를 이용하여 만들 수 없습니다.
따라서 값어치를 차례대로 만들어 나갈 때, 만들 수 있는 가장 큰 값어치는 13입니다.

우표를 사용하여 만들 수 있는 값어치를 차례대로 만들어 나갈 때, 만들 수 있는 가장 큰 값어치를 출력하세요.

제한 시간: 1초 (java: 2초)

[입력]
입력에는 여러 테스트 케이스가 포함될 수 있다. 입력의 첫째 줄에는 테스트 케이스의 수 T가 주어지고, 이후 차례로 T개의 테스트 케이스가 주어진다 (T ≤ 30)
각 테스트 케이스마다 첫 줄에 최대 사용 횟수 K와 우표의 종류 수 N가 공백으로 분리되어 주어진다. (1 ≤ N ≤ 200, 1 ≤ K ≤ 200)
두 번째 줄에 각 우표의 값어치가 공백으로 분리되어 주어진다. 각 값어치는 10,000이하의 자연수이다.

[출력]
각 테스트 케이스마다 첫 줄에 우표를 사용하여 만들 수 있는 값어치를 차례대로 만들어 나갈 때, 만들 수 있는 가장 큰 값어치를 출력한다.
(중요! 테스트 케이스 개수마다 #testcase번호를 출력 후 정답 출력)

-입출력 예-

입력
2
5 2
1 3
3 10
29 50 36 43 1 2 4 8 15 22
출력
#testcase1
13
#testcase2
56

*/