/*

VC, GCC에서 사용

*/

#include <stdio.h>

int getNumber(int(*score)[6], int x, int y){
	if (x<0 || x>5 || y<0 || y>5){
		return 0;
	}
	return score[x][y];
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		int board[6][6] = { 0, };
		printf("#testcase%d\n", itr + 1);
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 6; j++){
				scanf("%d", &board[i][j]);
			}
		}
		int max = 0;
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 6; j++){
				int total = 0;
				total += getNumber(board, i - 1, j);
				total += getNumber(board, i, j - 1);
				total += getNumber(board, i, j);
				total += getNumber(board, i + 1, j);
				total += getNumber(board, i, j + 1);
				if (total>max){
					max = total;
				}
			}
		}
		printf("%d\n", max);
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}

/*

사격을 좋아하는 초현이는 삼성동에 신기한 사격장이 오픈했다는 소식을 듣고 찾아가기로 마음먹었다. 다음날 사격장을 방문한 초현이는 이곳이 왜 신기한 사격장인지 이유를 알 수 있었다.
이 사격장 총알의 범위(가운데 포함 총 5칸)는 아래 그림과 같이 위, 아래, 왼쪽, 오른쪽까지인 것이었다.



2차원 배열을 과녁판으로 정했을 때, 단 한발의 총알을 쏴 가장 많은 점수를 구간의 총합을 구하는 것이 문제이다.

[입력]
첫 번째 줄에는 테스트 케이스 N을 입력한다.
그 다음 줄부터는 6*6 행렬의 칸이 36개의 수로 주어진다.
각 수는 0에서 9사이의 수이다.

[출력]
초롱이가 얻을 수 있는 점수의 최대 합을 출력한다.
(중요! 테스트 케이스 개수마다 #testcase번호를 출력 후 정답 출력)

-입출력 예-

입력
2
3 4 1 4 9 2
9 4 5 8 9 0
8 2 1 7 0 2
8 4 2 7 2 1
4 1 1 1 1 1
1 1 1 2 1 2
1 2 1 2 1 2
2 1 2 1 2 1
3 3 3 3 3 3
1 2 1 2 1 2
2 1 2 1 2 1
1 1 1 1 1 1

출력
#testcase1
33
#testcase2
12




*/