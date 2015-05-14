#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
/*
�ڵ����ͺ� �����м�
1.7
MxN ����� �� ���Ұ� 0�� ���, �ش� ���Ұ� ���� ��İ� ���� ��� ���Ҹ� 0���� �����ϴ�
�˰����� �ۼ��϶�.
*/

//row, col üũ ���̺� ���
void printMat(int row, int col, int(*mat)[500]);
int main(){
	int testcase;
	ifstream is("cracking_0�ϰ��_���0����ó��.txt");

	is >> testcase;

	for (int i = 0; i < testcase; i++){
		int mat[500][500] = { 0, };
		bool checkRow[500] = { 0, };
		bool checkCol[500] = { 0, };
		int row, col;
		is >> row >> col;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				int num;
				is >> num;
				mat[i][j] = num;
				if (num == 0){
					checkRow[i] = true;
					checkCol[j] = true;
				}
			}
		}
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (checkCol[j] == true){
					mat[i][j] = 0;
				}
				if (checkRow[i] == true){
					mat[i][j] = 0;
				}
			}
		}
		cout << endl;
		printMat(row, col, mat);
	}
	return 0;
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
1) row�� col�� �־����ٰ� �����ϰ� �ۼ��ص� �ǰڽ��ϱ�?
*/

