
//지뢰를 주변을 제외한 부분은 0 

//행이나 열이 2 일때

//https://code.google.com/codejam/contest/2974486/dashboard
//행이나 열이 1 일때
#include <stdio.h>
#include <stdlib.h>
#define STAR 1
#define NOTHING 0
#define START 2
bool checkTest(bool* test, int m){
	if (test[m] == true)
		return true;
	return false;
}

int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int k = 0; k < testcase; k++){
		int star[60][60];		//별을 그리기 위해
		for (int i = 0; i < 3600; i++)
			((bool*)star)[i] = NOTHING; //별 찍기 //1부터 시작

		bool possible = false;

		int R, C, M;
		scanf("%d %d %d", &R, &C, &M);

		star[R][C] = START;

		if (M == 0){
			possible = true;
		}
		else if (R == 1 && C == 1){
			
		}
		else if (R == 1){

			if (C == 2){

			}
			else if (C >= 3){
				if (M <= C - 2){
					for (int i = 1; i <= M; i++){
						star[1][i] = STAR;
					}
					possible = true;
				}
			}
		}
		else if (C == 1){

			if (R == 2){

			}
			else if (R >= 3){
				if (M <= R - 2){
					for (int i = 1; i <= M; i++){
						star[i][1] = STAR;
					}
					possible = true;
				}
			}
		}
		else if (R == 2 && C == 2){
			
		}
		else if (R == 2){
			if (M % 2 == 0 && M <= C*2 - 4){
				for (int i = 1; i <= C - 2; i++){
					star[1][i] = STAR;
					star[2][i] = STAR;
				}
				possible = true;
			}
		}
		else if (C == 2){
			if (M % 2 == 0 && M <= R * 2 - 4){
				for (int i = 1; i <= R - 2; i++){
					star[i][1] = STAR;
					star[i][2] = STAR;
				}
				possible = true;
			}
		}
		else{
			int innerRow = R - 2;
			int innerCol = C - 2;
			
			if (M <= innerRow*innerCol){
				for (int i = 1; i <= innerRow; i++){
					for (int j = 1; j < innerCol; j++){
						star[i][j] = STAR;
					}
				}
			}
			else{
				int i = 1;
				int j = 1;
				int starSize = 0;
				for (i = 1; i <= R-2 && possible == false; i++){
					for (j = 1; j <= C; j++){
						if (j == C - 1){
							star[i][j] = true;
							j = C;
						}
						star[i][j] = true;
						starSize = ((i - 1)*R) + j;
						if (M == starSize){
							possible = true;
							break;
						}
					}
				}
				

				for (i = 1; i <= C - 2; i++){
					star[R - 1][i] = true;
					star[R][i] = true;

					starSize += 2;
					if (starSize == M){
						possible = true;
					}
				}


			}
			
		}
		printf("Case #%d:\n", k+1);
		if (possible){
			//print stars 
			for (int i = 1; i <=  R; i++){
				for (int j = 1; j <= C; j++){
					switch (star[i][j]){
					case STAR:
						printf("*");
						break;
					case START:
						printf("c");
						break;
					case NOTHING:
						printf(".");
						break;
					}
				}
				printf("\n");
			}
		}
		else{
			printf("Impossible\n");
		}

	}


	return 0;
}



/*
Minesweeper is a computer game that became popular in the 1980s, and is still included in some versions of the Microsoft Windows operating system. This problem has a similar idea, but it does not assume you have played Minesweeper.

In this problem, you are playing a game on a grid of identical cells. The content of each cell is initially hidden. There are M mines hidden in M different cells of the grid. No other cells contain mines. You may click on any cell to reveal it. If the revealed cell contains a mine, then the game is over, and you lose. Otherwise, the revealed cell will contain a digit between 0 and 8, inclusive, which corresponds to the number of neighboring cells that contain mines. Two cells are neighbors if they share a corner or an edge. Additionally, if the revealed cell contains a 0, then all of the neighbors of the revealed cell are automatically revealed as well, recursively. When all the cells that don't contain mines have been revealed, the game ends, and you win.

For example, an initial configuration of the board may look like this ('*' denotes a mine, and 'c' is the first clicked cell):

*..*...**.
....*.....
..c..*....
........*.
..........
There are no mines adjacent to the clicked cell, so when it is revealed, it becomes a 0, and its 8 adjacent cells are revealed as well. This process continues, resulting in the following board:
*..*...**.
1112*.....
00012*....
00001111*.
00000001..
At this point, there are still un-revealed cells that do not contain mines (denoted by '.' characters), so the player has to click again in order to continue the game.
You want to win the game as quickly as possible. There is nothing quicker than winning in one click. Given the size of the board (R x C) and the number of hidden mines M, is it possible (however unlikely) to win in one click? You may choose where you click. If it is possible, then print any valid mine configuration and the coordinates of your click, following the specifications in the Output section. Otherwise, print "Impossible".

Input

The first line of the input gives the number of test cases, T. T lines follow. Each line contains three space-separated integers: R, C, and M.

Output

For each test case, output a line containing "Case #x:", where x is the test case number (starting from 1). On the following R lines, output the board configuration with C characters per line, using '.' to represent an empty cell, '*' to represent a cell that contains a mine, and 'c' to represent the clicked cell.

If there is no possible configuration, then instead of the grid, output a line with "Impossible" instead. If there are multiple possible configurations, output any one of them.

Limits

0 ≤ M < R * C.
Small dataset

1 ≤ T ≤ 230.
1 ≤ R, C ≤ 5.
Large dataset

1 ≤ T ≤ 140.
1 ≤ R, C ≤ 50.
Sample


Input

Output

5
5 5 23
3 1 1
2 2 1
4 7 3
10 10 82

Case #1:
Impossible
Case #2:
c
.
*
Case #3:
Impossible
Case #4:
......*
.c....*
.......
..*....
Case #5:
**********
**********
**********
****....**
***.....**
***.c...**
***....***
**********
**********
**********


*/