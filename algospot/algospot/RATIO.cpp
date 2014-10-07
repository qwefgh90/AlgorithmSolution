#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>

//fail code
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
		int mintargetval = 2000000001;

		//search addition value
		while (1){
			int targetval = (startoff + endoff) / 2;
			double tempPercentDouble = (((winCount + targetval) / (gamePlayCount + targetval)) * 100);
			int tempPercent = (int)tempPercentDouble;
			printf("percent %d, temppercent %d, targetval %d start %d end %d\n",percent, tempPercent,targetval,startoff,endoff);
			if (tempPercent == percent + 1){
				if (mintargetval > targetval){
					mintargetval = targetval;
				}
				endoff = targetval;
			}else if (tempPercent < percent + 1){
				startoff = targetval+1;
			}
			else if (tempPercent > percent + 1){
				endoff = targetval;
			}
			if (startoff == endoff){	//can't found
				//printf("not found\n");
				//minWinCount = -1;
				break;
			}
		}
		for (int i = mintargetval; mintargetval != 2000000001; i--){
			double tempPercentDouble = (((winCount + i) / (gamePlayCount + i)) * 100);
			int tempPercent = (int)tempPercentDouble;
			if (tempPercent == percent)
				break;
			if (minWinCount >= i){
				minWinCount = i;
			}
		}
		if (mintargetval == 2000000001)	// can't found addition value
			minWinCount = -1;
		printf("%d\n", minWinCount);
	}
	return 0;
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
int icontinueWinCount = (int)continueWinCount;	//continewWinCount �� �� �������� ���� (0.00000000010001) (�Ǽ� ����������� ���� �߻�)


//���� �ظ� �������� �ٽ� �������Ͽ� ������ �´��� Ȯ�� (if -> continewWinCount �� �� �������� ���)
if ((int)(((winCount + ((double)icontinueWinCount)) / (gameCount + ((double)icontinueWinCount))) * 100) == ipercent + 1){
printf("%d\n", icontinueWinCount);
}
//(else -> continewWinCount ���� �������� �ʴ� ���)
else{
printf("%d\n", icontinueWinCount + 1);
}
}
}
}

return 0;
}
*/