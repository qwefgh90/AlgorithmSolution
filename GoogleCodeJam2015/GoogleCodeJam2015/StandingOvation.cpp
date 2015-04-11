#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

//https://code.google.com/codejam/contest/dashboard?c=6224486#s=p0
//문자열 문제

int getNeedCount(char* levelCount, int maxLevel){
	int result = 0;
	int digitSum = 0; // 9 * 1000
	for (int i = 0; i <= maxLevel; i++){
		digitSum += (levelCount[i] - '0') ; //전체 사람의 수	//[자주하는실수]
		digitSum += -1;				//레벨 i에 1사람 만족	//실수

		//음수 라면 친구필요
		if (digitSum < 0){
			result++;
			digitSum = 0;	//초기화
		}
	}
	return result; 
}

int main(){
	FILE* f = fopen("StandingOvationLarge.txt", "r");
	FILE* w = fopen("output.txt", "w");
	int testcase;
	fscanf(f, "%d", &testcase);

	for (int j = 0; j < testcase; j++){
		int maxLevel;
		char levelCount[2000];
		fscanf(f, "%d %s", &maxLevel , levelCount);	//[실수]
		int result = getNeedCount(levelCount, maxLevel);
		fprintf(w,"Case #%d: %d\n", j + 1, result);
	}
	fclose(f);
	fclose(w);
}