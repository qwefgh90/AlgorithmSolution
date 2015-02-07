//똑똑한 왕
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory>
#define MAX 9

int main()
{
	int sunArr[200] = { 0, };
	int sunResultArr[200] = { 0, };
	//memset(sunResultArr, 0,sizeof(int)* 200);
	int sunCount;
	int powValue;

	int testCase = 0;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++){
		printf("#testcase%d\n", i + 1);
		scanf("%d", &sunCount);//자식 수
		scanf("%d", &powValue);//제곱 수
		for (int j = 0; j < sunCount; j++){
			//자식의 지능
			scanf("%d", &sunArr[j]);
		}
		int total = 0;

		//제곱 합 선택
		if (powValue % 2 == 0){	//짝수
			for (int j = 0; j < sunCount; j++){
				//sunResultArr[j] = sunArr[j];	//제곱은 1 2 3 중 하나 1 일 경우
				//if (powValue == 2)
				sunResultArr[j] = sunArr[j] * sunArr[j];
				/*else if (powValue == 3)
					sunResultArr[j] = sunArr[j] * sunArr[j] * sunArr[j];*/
				total += sunResultArr[j];
			}
		}
		else{	//홀수
			// 음수 제외
			for (int j = 0; j < sunCount; j++){
				if (sunArr[j] <= 0){
					sunResultArr[j] = 0;	// 음수 는 계산할때 무효하게 만듬
				}
				else{
					sunResultArr[j] = sunArr[j];	//제곱은 1 2 3 중 하나 1 일 경우
					/*if (powValue == 2)
						sunResultArr[j] = sunArr[j] * sunArr[j];*/
					if (powValue == 3)
						sunResultArr[j] = sunArr[j] * sunArr[j] * sunArr[j];
				}

				total += sunResultArr[j];
			}
		}
		printf("%d\n", total);

	}
	return 0;
}