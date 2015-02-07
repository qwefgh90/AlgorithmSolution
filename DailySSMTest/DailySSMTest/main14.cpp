#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main(){
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);

		int width = 0;
		int height = 0;
		scanf("%d", &width);
		scanf("%d", &height);

		int result = 0;
		int resultforBonus = 0;
		int widthfor6 = width / 6;
		int heightfor6 = height / 6;
		int widthBonus = width % 6;
		int heightBonus = height % 6;
		
		//몫의 곱
		result = widthfor6 * heightfor6;
		//나머지 처리
		if (widthBonus > 0){
			resultforBonus += heightfor6;
		}
		if (heightBonus > 0){
			resultforBonus += widthfor6;
		}

		if (widthBonus > 0 && heightBonus > 0){
			resultforBonus++;
		}
		printf("%d %d\n", result,resultforBonus);

	}


	return 0;
}


/*
[ 문제 ]
SW멤버십은 환경개선의 일환으로 각 지역 리모델링 공사를 진행 중이다.
더 나은 멤버십 환경을 위해 바닥의 타일도 새로 깔려고 하는데,
타일의 크기는 6*6 밖에 없다. 타일을 그대로 사용하거나 잘라서 이용 할 수도 있는데
잘라서 사용한 타일은 반드시 버려야 한다.

사용된 온전한 타일의 수와 잘라서 사용한 타일의 수를 구하는 프로그램을 작성하라.
모든 단위는 inch이고 생략한다.

[ 입 출력 조건 ]
입력
입력의 첫 줄은 테스트 케이스의 개수 T이다.
각 테스트케이스는 방의 가로 세로 크기가 주어지며 각 수는 1000이하이다.

출력
반드시 #testcase숫자 출력 후
각 테스트케이스에 대한 온전한 타일의 수와 잘라서 사용한 타일의 수를 T줄 출력하라

[ 입출력 예 ]
2
160 240
100 120
#testcase1
1040 40
#tescase2
320 20





*/