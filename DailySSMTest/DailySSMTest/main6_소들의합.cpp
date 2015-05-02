/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <queue>
using namespace std;

typedef bool(*comptype) (int, int);
bool compare(int arg1, int arg2){
	return arg1 > arg2;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);
		long long int sum = 0;
		priority_queue < int, vector<int>, comptype> queue(compare);
		int cowCount;
		scanf("%d", &cowCount);
		for (int i = 0; i < cowCount; i++){
			int height;
			scanf("%d", &height);
			
			if (queue.size() > 0){
				if (queue.top() > height){//키가 작을경우 더함
					sum += queue.size();
				}
				else if(queue.top() <= height){	//높이가 클 경우 큐에서 제거
					queue.pop();
					while (queue.size() > 0 && queue.top() <= height){ // 키가 더 크다면 계속 제거
						queue.pop();
					}
					if (queue.size() != 0 && queue.top() > height){	//키가 작을경우 더함
						sum += queue.size();
					}
				}
				queue.push(height);	//삽입
			}
			else{
				queue.push(height);	//비었을 경우
			}
		}
		printf("%lld\n", sum);

		/*
		1
		6
		10
		3
		7
		4
		12
		2
		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}

/*
소들은 자기 앞 쪽의 소들만을 볼수 있는 경우 각 소가 다른 소들의 머리 정수리를 볼 수 있는 소(cow) 수의 총합을 구하는 문제이다.

키가 같거나 큰 소가 나올 때까지의 모든 소들의 정수리를 볼 수 있다. 더 앞쪽의 소들은 그 소에 막혀서 볼 수가 없다.

예를 들어 6 마리의 소가 있고 차례대로 키가 5 , 2 , 4 , 2 , 6 , 1 이면



• 1 번소는 2 , 3, 4 를 볼 수 있고 ... 3 마리
• 2 번소는 볼 수 있는 소가 없고
• 3 번소는 4 번 소 ... 1 마리
• 4 번소는 볼 수 있는 소가 없고
• 5 번소는 6 번소 ... 1 마리
• 6 번소는 볼 수 있는 소가 없다
이 경우 답은 3 + 1 + 1 = 5

입력
첫 번째 줄에는 반드시 테스트케이스 수를 입력한다.
두 번째 줄에는 소의 수 N(1 ≤ N ≤ 80,000 ) 이 주어진다.
다음 N 줄에는 N 개의 키 hi (1 ≤ hi ≤ 1,000,000,000 ) 가 주어진다.

출력
출력 시 #testcase숫자 를 출력한다.
가능한 소들의 총 합을 출력한다.

입출력 예

입력
1
6
10
3
7
4
12
2

출력
#testcase1
5



*/