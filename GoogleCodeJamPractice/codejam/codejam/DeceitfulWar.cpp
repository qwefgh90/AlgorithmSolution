#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//https://code.google.com/codejam/contest/dashboard?c=2974486#s=p3&a=3

//속여서 이기는 법 Deceitful War (least upper bound 구하기 문제) 
//1)A의 블록과 B의 블록을 오름차순으로 정렬한다.(양방향 큐 정렬)
//2)A에서 하나를 뽑아서 B의 의 가장 작은 값보다 작다면 A의 가장 큰값에 근사한 값으로 바꾼뒤(속여서) 큰 값을 소비하도록 한다.
//3)B의 가장 작은 값보다 크다면 가장 큰값으로 바꿔서(속여서) B가 이기지 못하도록 한다.
//
//우선순위 큐 배열 2개

//일반 War 게임
//1)B를 오름차순으로 정렬
//2)A에서 하나를 뽑아서 제시하면 B에서 이 값보다 큰 값이 있다면 뽑고
//3)없다면 가장 작은 값을 준다.
//
//우선순위 큐 배열 1개

//
#define QSIZE 2000
struct queue{
	double data[QSIZE];
	int length = 0;

	queue(){
		length = 0;
		for (int i = 0; i < QSIZE; i++){
			data[i] = 0;
		}
	}

	void push(double v){
		if (length == 0){
			data[0] = v;
			length++;
			return;
		}
		for (int i = 0; i < length; i++){
			if (data[i] <= v){
			}
			else{
				double temp[QSIZE];
				memcpy(temp, data + i, sizeof(double)* (length - i));
				data[i] = v;
				memcpy(data + i + 1, temp, sizeof(double) * (length - i));
				length++;
				break;
			}
			if (i == length - 1){
				data[length] = v;
				length++;
				break;
			}
		}
	}
	//이분 탐색
	//같거나 큰값
	int find(int start, int end, double target){
		if (target < minPeek()) //크면서 가장작은 값 반환
			return 0;
		if (target > maxPeek())	//존재하지 않음
			return -1;

		int sindex = start + (end - start) / 2;

		//큰값 중 가장 작은값
		//예 1 2 4 중에서 start와 end 둘다 2인 경우 또는 4인 경우 나눠서 처리해야함
		if (start == end){
			if (target > data[start]){
				return start + 1;
			}
			else{
				return start;
			}
		}

		//큰값 중 가장 작은값
		//예) 1 2 4  에서 end가 2 start가 4를 가르치는 경우 start를 반환해야 한다.
		if (end < start){
			return start;
		}

		//같은값
		if (target == data[sindex]){
			return sindex;
		}

		else if (target > data[sindex]){

			//같으면 큰값중 가장 작은값
			/*if (sindex + 1 == end)
				return start;*/
			return find(sindex + 1, end, target);

		}
		else if (target < data[sindex]){

			//같으면 큰값중 가장 작은값
			/*if (start == sindex - 1)
				return start+1;*/
			return find(start, sindex-1, target);
		}
	}

	double minPeek(){
		return data[0];
	}

	double maxPeek(){
		return data[length - 1];
	}
	
	double pop(){
		if (length == 0){
			return -1;
		}
		if (length == 1){
			length--;
			return data[0];
		}

		double temp[QSIZE];
		double result = data[0];
		memcpy(temp, data + 1, sizeof(double)*(length - 1));
		memcpy(data, temp, sizeof(double)*(length - 1));
		length--;
		return result;
	}

	void remove(int index){
		if (index >= length)
			return;

		double temp[QSIZE];
		memcpy(temp, data + index + 1, sizeof(double)*(length - index - 1));
		memcpy(data + index, temp, sizeof(double)*(length - index - 1));
		length--;
	}
};

int main(){
	FILE* f = fopen("output.txt", "w");
	FILE* read = fopen("DeceitfulWarInput2.txt", "r");

	int testcase;
	//scanf("%d", &testcase);
	fscanf(read, "%d", &testcase);
	for (int k = 0; k < testcase; k++){
		int numCount;
		
		//scanf("%d", &numCount);
		fscanf(read, "%d", &numCount);
		queue qa;
		queue qb;
		queue temp1;
		queue temp2;
		double v = 0;
		
		for (int i = 0; i < numCount; i++){
			//scanf("%lf", &v);
			fscanf(read, "%lf", &v);
			qa.push(v);
		}

		for (int i = 0; i < numCount; i++){
			//scanf("%lf", &v);
			fscanf(read, "%lf", &v);
			qb.push(v);
		}
		memcpy(&temp1, &qa, sizeof(queue));
		memcpy(&temp2, &qb, sizeof(queue));
		
		//war game
		//
		//
		int vCount = 0;
		while (qa.length != 0){
			double v = qa.pop();
			if (qb.maxPeek() < v){
				v = qb.pop();
				vCount++;
			}
			else{
				double index = qb.find(0,qb.length-1,v);
				qb.remove(index);
			}
		}

		memcpy(&qa, &temp1, sizeof(queue));
		memcpy(&qb, &temp2, sizeof(queue));
		//Deceitful War
		//1)가장 작은값을 내게해서 지게 하거나
		//2)가장 큰값보다 작은 값을 내서 큰값을 소비하게 하는 전략
		int vCount2 = 0;
		while (qa.length != 0){
			double v = qa.pop();
			if (v < qb.minPeek()){
				v = qb.maxPeek() - 0.0000001;
			}
			else{
				v = 1.1;
			}
			if (qb.maxPeek() < v){
				v = qb.pop();
				vCount2++;
			}
			else{
				double index = qb.find(0, qb.length - 1, v);
				qb.remove(index);
			}
		}

		//fprintf(f,"Case #%d: %d %d\n", k + 1, vCount2, vCount);
		fprintf(f,"Case #%d: %d %d\n", k + 1, vCount2, vCount);
		
		
		/*v = qa.minPeek();
		v = qa.maxPeek();
		v = qb.minPeek();
		v = qb.maxPeek();

		v = qa.find(0, qa.length - 1, 0.3889999999);
		v = qb.find(0, qb.length - 1, 0.699999);
		v = qa.find(0, qa.length - 1, 0.185);
		v = qb.find(0, qb.length - 1, 0.999);
		v = qb.find(0, qb.length - 1, 0.915);
		v = qb.find(0, qb.length - 1, 0.458);
		v = qa.pop();
		v = qb.pop();
		printf("testcase\n");*/
	}
	fclose(f);
	return 0;
}

/*
Problem D. Deceitful War
This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
Small input
14 points
Solve D-small
Large input
16 points
Solve D-large
This problem is the hardest problem to understand in this round. If you are new to Code Jam, you should probably try to solve the other problems first.

Problem

Naomi and Ken sometimes play games together. Before they play, each of them gets N identical-looking blocks of wood with masses between 0.0kg and 1.0kg (exclusive). All of the blocks have different weights. There are lots of games they could play with those blocks, but they usually play something they call War. Here is how War works:

Each player weighs each of his or her own blocks, so each player knows the weights of all of his or her own blocks, but not the weights of the other player's blocks.
They repeat the following process N times:
Naomi chooses one of her own blocks, with mass ChosenNaomi.
Naomi tells Ken the mass of the block she chose.
Ken chooses one of his own blocks, with mass ChosenKen.
They each put their block on one side of a balance scale, and the person whose block is heavier gets one point.
Both blocks are destroyed in a fire.
Naomi has realized three things about War. First, she has realized that she loses a lot. Second, she has realized that there is a unique strategy that Ken can follow to maximize his points without assuming anything about Naomi's strategy, and that Ken always uses it. Third, she has realized that she hates to lose. Naomi has decided that instead of playing War, she will play a game she calls Deceitful War. The great thing about Deceitful War is that Ken will think they're playing War!

Here is how Deceitful War works, with differences between Deceitful War and War in bold:

Each player weighs each of his or her own blocks. Naomi also weighs Ken's blocks while he isn't looking, so Naomi knows the weights of all blocks and Ken only knows the weights of his own blocks.
They repeat the following process N times:
Naomi chooses one of her own blocks, with mass ChosenNaomi.
Naomi tells Ken a number, ToldNaomi, between 0.0kg and 1.0kg exclusive. Ken, who thinks they're playing War, thinks the number Naomi just told him is ChosenNaomi.
Ken chooses one of his own blocks, with mass ChosenKen.
They each put their block on one side of a balance scale, and the person whose block is heavier gets one point.
Both blocks are destroyed in a fire.
Naomi doesn't want Ken to know that she isn't playing War; so when she is choosing which block to play, and what mass to tell Ken, she must make sure that the balance scale won't reveal that ChosenNaomi ≠ ToldNaomi. In other words, she must make decisions so that:

ChosenNaomi > ChosenKen if, and only if, ToldNaomi > ChosenKen, and
ToldNaomi is not equal to the mass of any of Ken's blocks, because he knows that isn't possible.
It might seem like Naomi won't win any extra points by being deceitful, because Ken might discover that she wasn't playing War; but Naomi knows Ken thinks both players are playing War, and she knows what he knows, and she knows Ken will always follow his unique optimal strategy for War, so she can always predict what he will play.

You'll be given the masses of the blocks Naomi and Ken started with. Naomi will play Deceitful War optimally to gain the maximum number of points. Ken will play War optimally to gain the maximum number of points assuming that both players are playing War. What will Naomi's score be? What would it have been if she had played War optimally instead?

Examples

If each player has a single block left, where Naomi has 0.5kg and Ken has 0.6kg, then Ken is guaranteed to score the point. Naomi can't say her number is ≥ 0.6kg, or Ken will know she isn't playing War when the balance scale shows his block was heavier.

If each player has two blocks left, where Naomi has [0.7kg, 0.2kg] and Ken has [0.8kg, 0.3kg], then Naomi could choose her 0.2kg block, and deceive Ken by telling him that she chose a block that was 0.6kg. Ken assumes Naomi is telling the truth (as in how the War game works) and will play his 0.8kg block to score a point. Ken was just deceived, but he will never realize it because the balance scale shows that his 0.8kg block is, like he expected, heavier than the block Naomi played. Now Naomi can play her 0.7kg block, tell Ken it is 0.7kg, and score a point. If Naomi had played War instead of Deceitful War, then Ken would have scored two points and Naomi would have scored zero.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing a single integer N, the number of blocks each player has. Next follows a line containing N space-separated real numbers: the masses of Naomi's blocks, in kg. Finally there will be a line containing N space-separated real numbers: the masses of Ken's blocks, in kg.

Each of the masses given to Ken and Naomi will be represented as a 0, followed by a decimal point, followed by 1-5 digits. Even though all the numbers in the input have 1-5 digits after the decimal point, Ken and Naomi don't know that; so Naomi can still tell Ken that she played a block with mass 0.5000001kg, and Ken has no reason not to believe her.

Output

For each test case, output one line containing "Case #x: y z", where x is the test case number (starting from 1), y is the number of points Naomi will score if she plays Deceitful War optimally, and z is the number of points Naomi will score if she plays War optimally.

Limits

1 ≤ T ≤ 50.
All the masses given to Ken and Naomi are distinct, and between 0.0 and 1.0 exclusive.
Small dataset

1 ≤ N ≤ 10.
Large dataset

1 ≤ N ≤ 1000.
Sample


Input

4
1
0.5
0.6
2
0.7 0.2
0.8 0.3
3
0.5 0.1 0.9
0.6 0.4 0.3
9
0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899
0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458



Output

Case #1: 0 0
Case #2: 1 0
Case #3: 2 1
Case #4: 8 4

*/