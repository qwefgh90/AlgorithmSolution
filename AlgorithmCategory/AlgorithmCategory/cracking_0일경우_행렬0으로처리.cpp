#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
/*
코딩인터뷰 완전분석
1.7
MxN 행렬의 한 원소가 0일 경우, 해당 원소가 속한 행렬과 열의 모든 원소를 0으로 설정하는
알고리즘을 작성하라.
*/

//row, col 체크 테이블 사용
void printMat(int row, int col, int(*mat)[500]);
int main(){
	int testcase;
	ifstream is("cracking_0일경우_행렬0으로처리.txt");

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
면접관과 상의할 것
1) row와 col이 주어진다고 가정하고 작성해도 되겠습니까?
*/

