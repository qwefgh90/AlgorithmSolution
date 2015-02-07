#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int main(){
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int n = 0;
		int k = 0;
		scanf("%d %d", &n, &k);
		int lessCount = 0;
		for (int j = 1; j <= n; j++){
			if (k % j == 0){
				lessCount++;
			}
		}
		//짝수
		if (lessCount % 2 == 0){
			printf("0\n");	//닫힘
		}
		else{
			printf("1\n");	//열림
		}

	}

	return 0;
}

/*
문제지
문제	열려있는 라커	문제코드	2-M-02
내용	일렬로 세워진 1부터 100까지 번호가 매겨진 100개의 라커가 문이 전부 열려 있다 짝수번째 라커를 하나씩 닫고 지나간 다음 다시 처음으로 돌아가 다시 끝까지 걸어가며 3배수 라커를 닫는다.(닫혀 있으면 연다) 이러한 과정을 라커를 토글 한다고 표현하고 N번째 지나 갈때는 N배수 번째 라커를 토글 한다고 할 경우 N번 지나갔을 때 K번 라커는 열려 있는가 닫혀 있는지를 판단하라
입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
한 줄에 N과 정수 K가 입력된다.(1<N<100, 1<K<100)
출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
열려있다면 1, 닫혀있다면 0이 출력된다,
예시	입력	출력
2
2 5
12 12
#testcase1
1
#testcase2
0

*/