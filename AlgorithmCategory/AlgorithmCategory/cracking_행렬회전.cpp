#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
/*
�ڵ����ͺ� �����м�
MXN ����� 90�� ȸ�� ���Ѷ�. �̶� �ΰ����� ����� ������� �ʰ� ȸ�����Ѷ�.
*/

void printMat(int row, int col, int(*mat)[500]);
void rotate(int row, int col, int(*mat)[500]);
/*
MxN�̶� ���簢������ �ΰ� Ǯ�� ����.
*/
int main(){
	int testcase;
	ifstream is("cracking_���ȸ��.txt");
	
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
�������� ������ ��
1) MxN�� ȸ����ų��ŭ ����� �迭�� ������ �ֽ��ϱ�?
2) �Է��� ������ M�� N�� ���� �޾Ƶ帳�ϱ�?

�Ѵ� �׷��ٰ� �����ϰ� Ǯ��.

*/
