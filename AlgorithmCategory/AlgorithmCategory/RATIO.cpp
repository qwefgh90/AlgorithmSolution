#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
/*
https://algospot.com/judge/problem/read/RATIO
*/
int main(){
	int testCase = 0;
	scanf("%d", &testCase);

	while (testCase--){
		double gamePlayCount = 0;
		double winCount = 0;
		int minWinCount = 2000000000;

		scanf("%lf %lf", &gamePlayCount, &winCount);
		int percent = (int)((winCount / gamePlayCount) * 100);
		int startoff = 0;
		int endoff = 2000000000;

		if (percent == 99 || percent == 100){
			printf("-1\n");
			continue;
		}

		while (1){
			int targetval = (startoff + endoff) / 2;
			int tempPercent = (int)(((winCount + targetval) / (gamePlayCount + targetval)) * 100);
		//	printf("temppercent %d\n", tempPercent);
			if (percent + 1 == tempPercent){
				for (int i = targetval;; i--){
					int realPercent = int(((winCount + i) / (gamePlayCount + i)) * 100);
					if (realPercent < tempPercent)
						break;
					minWinCount = i;
				}
				break;
			}else if (tempPercent < percent + 1){
				startoff = targetval+1;
			}else if(tempPercent >= percent+2){
				endoff = targetval;
			}
			if (startoff == endoff){	//can't found
				//printf("not found\n");
				minWinCount = -1;
				break;
			}
		}
		printf("%d\n", minWinCount);
	}
}
/*
int main(){
	int testCase = 0;
	scanf("%d", &testCase);
	
	while (testCase--){
		double gamePlayCount = 0;
		double winCount = 0;

		scanf("%lf %lf", &gamePlayCount, &winCount);
		double winPercent = (winCount / gamePlayCount) * 100 + 1;
		double continueWinCount = 0;

		if (winPercent < 100) printf("%d\n", (int)ceil((winPercent *  gamePlayCount - 100 * winCount) / (100 - winPercent)));
		else printf("-1\n");
	}
	return 0;
}*/
/*
( wincount + n ) / ( gamecount + n ) = targetPercent(0~1)

if percent == 100
printf -1;
*/
/*
//THIS IS FAIL CODE
int main(){
int testCase = 0;
scanf("%d", &testCase);
while (testCase--){
double gameCount = 0;
double winCount = 0;
double percent = 0;
scanf("%lf %lf", &gameCount, &winCount);
percent = (winCount / gameCount) * 100;
//	printf("percetn %f \n", percent);
if (percent >= 100 || gameCount<1 || winCount <0){
//	printf("is greater than 100");
printf("-1\n");
}
else{
int ipercent = (int)percent;
double continueWinCount = 0;
if (ipercent == 99){
continueWinCount = 2000000001;
}
else{
continueWinCount = ((((double)(ipercent + 1) / 100.0) * gameCount) - winCount) / (1 - ((double)(ipercent + 1) / 100.0));
}
//printf("continuewinCount %f \n", continueWinCount);
if (continueWinCount > 2000000000){

printf("-1\n");
}
else{
int icontinueWinCount = (int)continueWinCount;	//continewWinCount 가 딱 떨어지지 않음 (0.00000000010001) (실수 연산과정에서 오차 발생)


//구한 해를 바탕으로 다시 연산을하여 정답이 맞는지 확인 (if -> continewWinCount 가 딱 떨어지는 경우)
if ((int)(((winCount + ((double)icontinueWinCount)) / (gameCount + ((double)icontinueWinCount))) * 100) == ipercent + 1){
printf("%d\n", icontinueWinCount);
}
//(else -> continewWinCount 값이 떨어지지 않는 경우)
else{
printf("%d\n", icontinueWinCount + 1);
}
}
}
}

return 0;
}
*/