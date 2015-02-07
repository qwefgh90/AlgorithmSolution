#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		int number;
		scanf("%d", &number);

		int n2 = number / 2;
		int cnt = 1;//자기자신
		for (int i = 1; i <= n2; i++){
			if (number % i == 0){	//약수
				cnt++;
			}
		}
		if (cnt % 2 == 1){
			printf("yes\n");
		}
		else{
			printf("no\n");

		}
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}

/*
약수의 개수의 성질에서 알아두면 유용한 것 몇가지
•	소수는 약수의 개수가 두 개 ( 1 과 자기 자신)
•	소수의 제곱은 약수의 개수가 3
•	제곱수는 약수의 개수가 홀수개
제곱수가 아닌 수의 약수의 개수는 쌍으로 존재하므로 짝수개이다.
12 의 약수
•	( 1 , 12 )
•	( 2 , 6 )
•	( 3 , 4 )
6 개로 짝수
제곱수는 제곱이 되는 수는 자신이 곱해져서 제곱수가 되므로 홀수개가 된다.
16 의 약수
•	( 1 , 16)
•	( 2 , 8 )
•	( 4 , 4 )
5 개로 홀수
문제는 어떤수를 입력으로 받아 제곱수인지를 판별하는 것이다.

[입력]
전체 Test Case개수 N이 입력의 첫 줄에 주어진다.
각 Test Case는1 에서 10000 사이의 자연수 C가 주어지며, 각 줄에 하나의 Test Case가 주어진다.

[출력]
제곱수이면 yes 아니면 no 를 출력한다.
(중요!!! 출력 전 반드시 #testcase번호 를 출력해야 한다.)
- 입출력 예 -
입력
2
4
8

출력
#testcase1
yes
#testcase2
no



*/