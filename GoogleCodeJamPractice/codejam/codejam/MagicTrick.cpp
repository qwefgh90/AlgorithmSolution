#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//https://code.google.com/codejam/contest/2974486/dashboard

int main(){
	int testcase;
	scanf("%d",&testcase);
	FILE* f = fopen("output.txt", "w");
	for(int k = 0 ; k < testcase ; k++){
		int userSay;
		int userSay2;
		int cards[4][4] = {0,};
		int cards2[4][4] = {0,};
		scanf("%d",&userSay);
		for(int i = 0 ; i < 4 ; i++){
			for (int j = 0 ; j < 4 ; j ++){
				scanf("%d",&cards[i][j]);
			}
		}

		int firstTry[4]={0,};
		for(int i = 0 ; i < 4 ; i ++){
			firstTry[i] = cards[userSay-1][i];
		}

		scanf("%d",&userSay2);

		for(int i = 0 ; i < 4 ; i++){
			for (int j = 0 ; j < 4 ; j ++){
				scanf("%d",&cards2[i][j]);
			}
		}

		int secondTry[4]={0,};
		for(int i = 0 ; i < 4 ; i ++){
			secondTry[i] = cards2[userSay2-1][i];
		}

		bool single=false;
		bool multi=false;

		int answer = 0;
		int count = 0;

		for(int i = 0 ; i < 4 ; i++){
			for(int j = 0 ; j < 4 ; j++){
				if(firstTry[i] == secondTry[j]){
					count ++;
					answer = firstTry[i];
				}
			}
		}
		char result[200] = { 0, };
		if(count > 1)
			sprintf(result, "Case #%d: %s\n", k + 1, "Bad magician!");
		else if(count == 1)
			sprintf(result, "Case #%d: %d\n", k + 1, answer);
		else
			sprintf(result, "Case #%d: %s\n", k + 1, "Volunteer cheated!");

		fprintf(f, result);
	}
	fclose(f);

	return 0;
}