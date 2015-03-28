#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int testcase;
	scanf("%d",&testcase);

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

		if(count > 1)
			printf("Case #%d: %s\n", k+1, "Bad magician!");
		else if(count == 1)
			printf("Case #%d: %d\n", k+1, answer);
		else
			printf("Case #%d: %s\n", k+1, "Volunteer cheated!");

	}


	return 0;
}