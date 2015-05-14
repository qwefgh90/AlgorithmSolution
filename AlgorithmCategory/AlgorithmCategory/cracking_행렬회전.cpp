#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
/*
코딩인터뷰 완전분석
MXN 행렬을 90도 회전 시켜라. 이때 부가적인 행렬을 사용하지 않고 회전시켜라.
*/

void printMat(int row, int col, int(*mat)[500]);
void rotate(int row, int col, int(*mat)[500]);
/*
MxN이라도 정사각형으로 두고 풀면 쉽다.
*/
int main(){
	int testcase;
	ifstream is("cracking_행렬회전.txt");
	
	is >> testcase;
	
	for(int i = 0; i < testcase; i++){
		int rowCount, colCount;
		is >> rowCount >> colCount;

		int mat[500][500] = { 0, };

		for (int i = 0; i < rowCount; i++){
			for (int j = 0; j < colCount; j++){
				is >> mat[i][j];
			}
		}
		rotate(rowCount, colCount, mat);
		printMat(rowCount, colCount, mat);

	}
	return 0;
}
void rotate(int rowc, int colc, int(*mat)[500]){
	/*
	1 2
	3 4
	5 6
	7 8
	*/
	int loop = rowc > colc ? rowc : colc;
	int start = 0;
	int fixend = loop - 1;
	int end = loop - 1;
	int row = 0;
	for (start = 0, row = 0; start <= end; start++, end--, row++){
		for (int col = start; col <= end - 1; col++){
			int temp = mat[row][col];
			mat[row][col] = mat[fixend - col][row];

			mat[fixend - col][row] = mat[fixend - row][fixend - col];
			
			mat[fixend - row][fixend - col] = mat[fixend - (fixend - col)][fixend - row];
			
			mat[fixend - (fixend - col)][fixend - row] = temp;
		}
	}
}

void printMat(int row, int col, int(*mat)[500]){
	int loop = row > col ? row : col;
	for (int i = 0; i < loop; i++){
		for (int j = 0; j < loop; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

/*
면접관과 상의할 것
1) MxN을 회전시킬만큼 충분한 배열을 가지고 있습니까?
2) 입력을 받을때 M과 N을 같이 받아드립니까?

둘다 그렇다고 가정하고 풀자.

*/
