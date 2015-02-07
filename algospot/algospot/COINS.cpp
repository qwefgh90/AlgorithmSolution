#include <stdio.h>

unsigned int getValue(unsigned int(*possibleTable)[5000], int row, int col){
	if (row < 0 || col < 0){
		return 0;
	}
	return possibleTable[row][col];
}
unsigned int possibleTable[100][5000] = { 0, };
int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		int money;
		int changeCount;
		scanf("%d %d",&money,&changeCount);
		int change[5000] = { 0, };
		for (int j = 0; j < changeCount; j++){
			scanf("%d",&change[j]);
		}
		
		//이미 정렬되있다고 가정
		//점화식 f(change_idx,col) = f(change_idx,col-change) + f(pre_change_idx,col);
		unsigned int result;
		int minimumChange = change[0];
		for (int j = 0; j < changeCount; j++){
			int changeValue = change[j];

			possibleTable[j][0] = 1;	//기본 값
			for (int col = minimumChange; col <= money; col += minimumChange){
				possibleTable[j][col] = ((getValue(possibleTable, j, col - changeValue) % 1000000007)
					+ (getValue(possibleTable, j - 1, col) % 1000000007))%1000000007;
			}
			if (j==changeCount - 1){
				result = possibleTable[changeCount - 1][money];

			}
		}
		printf("%d\n", result);
	}
	
	return 0;
}