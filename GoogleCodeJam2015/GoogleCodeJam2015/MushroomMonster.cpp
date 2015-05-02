#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE* f = fopen("MushroomMonsterSmallInput.txt", "r");
	FILE* output = fopen("output.txt", "w");

	int testcase;
	fscanf(f,"%d", &testcase);

	for (int j = 0; j < testcase; j++){
		int count;
		fscanf(f, "%d", &count);
		
		int mush[10000] = { 0, };
		
		for (int i = 0; i < count; i++){
			fscanf(f, "%d", &mush[i]);
		}
		
		//strategy 1
		int sum1 = 0;
		for (int i = 0; i < count - 1; i++){
			if (mush[i] - mush[i + 1] > 0){
				sum1 += mush[i] - mush[i + 1];
			}
		}
		//strategy 2
		int sum2 = 0;
		int maxGap = 0;
		//find maxGap
		for (int i = 0; i < count - 1; i++){
			if (mush[i] - mush[i + 1] > maxGap){
				maxGap = mush[i] - mush[i + 1];
			}
		}

		for (int i = 0; i < count - 1; i++){
			if (mush[i] >= maxGap){
				sum2 += maxGap;
			}
			else{
				sum2 += mush[i];
			}
		}
		
		
		fprintf(output,"Case #%d: %d %d\n", j+1, sum1, sum2);
	}


	fclose(f);
	fclose(output);
	return 0;

}



/*
https://code.google.com/codejam/contest/4224486/dashboard#s=p0
Problem A. Mushroom Monster
This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
Small input
7 points
Solve A-small
Large input
8 points
Solve A-large
Problem

Kaylin loves mushrooms. Put them on her plate and she'll eat them up! In this problem she's eating a plate of mushrooms, and Bartholomew is putting more pieces on her plate.

In this problem, we'll look at how many pieces of mushroom are on her plate at 10-second intervals. Bartholomew could put any non-negative integer number of mushroom pieces down at any time, and the only way they can leave the plate is by being eaten.

Figure out the minimum number of mushrooms that Kaylin could have eaten using two different methods of computation:

Assume Kaylin could eat any number of mushroom pieces at any time.
Assume that, starting with the first time we look at the plate, Kaylin eats mushrooms at a constant rate whenever there are mushrooms on her plate.
For example, if the input is 10 5 15 5:

With the first method, Kaylin must have eaten at least 15 mushroom pieces: first she eats 5, then 10 more are put on her plate, then she eats another 10. There's no way she could have eaten fewer pieces.

With the second method, Kaylin must have eaten at least 25 mushroom pieces. We can determine that she must eat mushrooms at a rate of at least 1 piece per second. She starts with 10 pieces on her plate. In the first 10 seconds, she eats 10 pieces, and 5 more are put on her plate. In the next 5 seconds, she eats 5 pieces, then her plate stays empty for 5 seconds, and then Bartholomew puts 15 more pieces on her plate. Then she eats 10 pieces in the last 10 seconds.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each will consist of one line containing a single integer N, followed by a line containing N space-separated integers mi; the number of mushrooms on Kaylin's plate at the start, and at 10-second intervals.

Output

For each test case, output one line containing "Case #x: y z", where x is the test case number (starting from 1), y is the minimum number of mushrooms Kaylin could have eaten using the first method of computation, and z is the minimum number of mushrooms Kaylin could have eaten using the second method of computation.

Limits

1 ¡Â T ¡Â 100.
Small dataset

2 ¡Â N ¡Â 10.
0 ¡Â mi ¡Â 100.
Large dataset

2 ¡Â N ¡Â 1000.
0 ¡Â mi ¡Â 10000.
Sample


Input

Output

4
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9

Case #1: 15 25
Case #2: 0 0
Case #3: 81 567
Case #4: 181 244



*/