#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#define ITEMCOUNT 1000
#define WEIGHT 10000
int table[ITEMCOUNT][WEIGHT] = { 0, };
struct Item{
	int weight;
	int value;
};
//http://cultist-tp.tistory.com/entry/%EB%83%85%EC%83%89Knapsack%EB%B0%B0%EB%82%AD-%EB%AC%B8%EC%A0%9C
//배낭문제
int main(){
	Item items[1000] = { 0, };
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int itemCount = 0;
		int totalWeight = 0;
		scanf("%d %d", &itemCount, &totalWeight);
		for (int i = 0; i < itemCount; i++){
			scanf("%d %d", &items[i].weight, &items[i].value);
			//여기서 maxValuePrevious는 개수가 1개인 냅색문제에서 사용하는 것이다.
			//따라서 table은 2차원 배열일 필요가 없다.
			for (int j = 1; j <= totalWeight; j++){
				int divide = j / items[i].weight;
				int selfValue = divide * items[i].value;	//하나만 넣었을 때 최고 가치
				int maxValueWithPrevious = -1;
				if (i != 0 && j - items[i].weight >= 0){
					maxValueWithPrevious = table[i - 1][j - items[i].weight] + items[i].value;
				}
				int previousMaxValue = -1;
				if (i != 0){
					previousMaxValue = table[i - 1][j];
				}
				int max = selfValue > maxValueWithPrevious ? (selfValue > previousMaxValue ? selfValue : previousMaxValue) : (maxValueWithPrevious > previousMaxValue ? maxValueWithPrevious : previousMaxValue);

				table[i][j] = max;
			}
		}
		printf("%d\n", table[itemCount - 1][totalWeight]);

	}

	return 0;
}
/*
문제지
문제	배낭채우기	문제코드	5-M-01
내용	멤버십 보석상에 도둑이 침입했다. 도둑은 배낭에 보석을 훔치려고 한다. 이때, 훔친 보석의 무게가 W를 넘어가면 배낭이 망가진다.

각 보석의 값어치와 무게가 주어질 때, 도둑은 총 무게가 W를 넘지 않으면서 보석의 총 값어치가 최대가 되도록 보석을 배낭에 담으려고 한다.
이때 배낭에 담을 수 있는 최대 값어치를 구하시오.
입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
첫 줄은 보석의 가지 수 N(1≤N≤1,000)과 배낭의 용량
W(1≤W≤10,000)가 주어진다. 둘째 줄부터 N+1줄에는 각 보석의 무게 Wi(1≤Wi≤W)와 값어치 Pi가 주어진다.
(단, 각각의 보석의 개수는 무제한으로 가정한다.)
출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
보석의 무게와 값어치가 주어질 때, 총 무게가 W를 넘지 않으면서, 보석의 총 값어치가 최대가 되는 최대값을 출력한다.
예시	입력	출력
2
2 10
5 300
2 50

2 10
2 100
5 200
#testcase1
600
#testcase2
500

*/