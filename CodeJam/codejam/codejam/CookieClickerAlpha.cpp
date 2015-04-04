#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
//https://code.google.com/codejam/contest/2974486/dashboard
struct State{
	double ratio;		//생산 능력
	double factoryTime;	//공장 짓는 시간
	double finishTime; //공장 짓는 시간
};
/*
T 1~100
1 ≤ C ≤ 500.
1 ≤ F ≤ 4.
1 ≤ X ≤ 2000.
*/
State findMinimumTime(double C, double F, double X){
	State table[10000];
	table[0].ratio = 2;//초기
	table[0].factoryTime = 0;//공장짓는데 필요한 시간
	table[0].finishTime = X / table[0].ratio;
	int stateIndex = 1;	//해당 테이블의 칼럼을 공장 개수
	//공장이 증가한다
	while (1){
		table[stateIndex].ratio = table[stateIndex - 1].ratio + F;//생산능력
		table[stateIndex].factoryTime
			= table[stateIndex - 1].factoryTime
			+ C / table[stateIndex - 1].ratio;//공장짓는데 필요한 시간
		table[stateIndex].finishTime
			= X / table[stateIndex].ratio
			+ table[stateIndex].factoryTime;

		if (table[stateIndex].finishTime > table[stateIndex - 1].finishTime){
			return table[stateIndex - 1];
		}
		stateIndex++;
	}
}

int main(){
	FILE* f = fopen("output.txt", "w");
	int testcase;
	scanf("%d", &testcase);
	for (int k = 0; k < testcase; k++){
		double C;//가격
		double F;//공장의 생산량
		double X;//목표달성
		scanf("%lf %lf %lf", &C, &F, &X);
		State result = findMinimumTime(C, F, X);
		//printf("Case #%d: %.7lf\n", k + 1, result.finishTime);
		fprintf(f, "Case #%d: %.7lf\n", k + 1, result.finishTime);

	}
	fclose(f);
	return 0;
}

/*
4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0

Input

The first line of the input gives the number of test cases, T. T lines follow. Each line contains three space-separated real-valued numbers: C, F and X, whose meanings are described earlier in the problem statement.

C, F and X will each consist of at least 1 digit followed by 1 decimal point followed by from 1 to 5 digits. There will be no leading zeroes.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the minimum number of seconds it takes before you can have X delicious cookies.

We recommend outputting y to 7 decimal places, but it is not required. y will be considered correct if it is close enough to the correct number: within an absolute or relative error of 10-6. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

Limits

1 ≤ T ≤ 100.

Small dataset

1 ≤ C ≤ 500.
1 ≤ F ≤ 4.
1 ≤ X ≤ 2000.
Large dataset

1 ≤ C ≤ 10000.
1 ≤ F ≤ 100.
1 ≤ X ≤ 100000.
Sample


Input

Output

4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0

Case #1: 1.0000000
Case #2: 39.1666667
Case #3: 63.9680013
Case #4: 526.1904762


*/