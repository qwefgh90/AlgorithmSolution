#include <iostream>
//#include <fstream>
#define INT_MAX 2000000000
using namespace std;

//https://www.acmicpc.net/problem/2178

struct Item{
	int row;
	int col;
	Item(){
		row = 0;
		col = 0;
	}
};
bool isPossible(int n, int m, int(*mat)[101], int row, int col, int(*mem)[101], int myCount){
	if (row < 1 || row > n || col < 1 || col > m){
		return false;
	}
	if (mat[row][col] == 1 && mem[row][col] > myCount + 1)
		return true;
	else
		return false;
}
void insertMin(int n, int m, int(*mat)[101], int row, int col, int(*mem)[101]){
	int min = INT_MAX;
	int currentRow = row - 1;
	int currentCol = col;
	if (!(currentRow < 1 || currentRow > n || currentCol < 1 || currentCol > m)){
		min = min > mem[currentRow][currentCol] ? mem[currentRow][currentCol] : min;
	}
	currentRow = row + 1;
	currentCol = col;
	if (!(currentRow < 1 || currentRow > n || currentCol < 1 || currentCol > m)){
		min = min > mem[currentRow][currentCol] ? mem[currentRow][currentCol] : min;
	}
	currentRow = row;
	currentCol = col - 1;
	if (!(currentRow < 1 || currentRow > n || currentCol < 1 || currentCol > m)){
		min = min > mem[currentRow][currentCol] ? mem[currentRow][currentCol] : min;
	}
	currentRow = row;
	currentCol = col + 1;
	if (!(currentRow < 1 || currentRow > n || currentCol < 1 || currentCol > m)){
		min = min > mem[currentRow][currentCol] ? mem[currentRow][currentCol] : min;
	}
	mem[row][col] = min+1;
}
//������ȹ��
//��Ʈ��ŷ���� Ǯ�� �����Ƿ�
//�̷θ� �Ųٷ� Ž���ϴ� �˰���
//���� �Ųٷ� �����ʰ� ���������� BFS�� Ž���ص� ��������.>
//1)�̷θ� BFS�� Ž��
//2)�̵��Ϸ��� ������ ���� �ڽź��� ũ�� +1 �Ͽ� ������Ʈ�Ѵ�.//�̹� ������ ���� ������ �ƴҰ�� �ڹٲ� �� ����
//3)�ڽź��� ������ Ž������ �ʴ´�.
//4)ť�� �� ��� ��
int countWay(int n, int m, int(*mat)[101]){
	int mem[101][101] = { 0, };
	for (int i = 0; i < 101; i++){
		for (int j = 0; j < 101; j++){
			mem[i][j] = INT_MAX;
		}
	}
	Item queue[20000]; // ������ ���� ��Ʈ���� Ŀ�ߵ� //����� ũ������
	int index = 0;
	int popindex = 0;

	Item item;
	item.row = n;
	item.col = m;
	mem[n][m] = 1;
	queue[index++] = item;
	while (popindex < index){
		Item pop = queue[popindex++];
		int row = pop.row;
		int col = pop.col;
		if (isPossible(n, m, mat, row + 1, col, mem, mem[row][col]) == true)
		{
			item.row = row + 1;
			item.col = col;
			insertMin(n, m, mat, item.row, item.col, mem);
			queue[index++] = item;
		}
		if (isPossible(n, m, mat, row - 1, col, mem, mem[row][col]) == true)
		{
			item.row = row - 1;
			item.col = col;
			insertMin(n, m, mat, item.row, item.col, mem);
			queue[index++] = item;
		}
		if (isPossible(n, m, mat, row, col +1, mem, mem[row][col]) == true)
		{
			item.row = row;
			item.col = col + 1;
			insertMin(n, m, mat, item.row, item.col, mem);
			queue[index++] = item;
		}
		if (isPossible(n, m, mat, row, col -1, mem, mem[row][col]) == true)
		{
			item.row = row;
			item.col = col - 1;
			insertMin(n, m, mat, item.row, item.col, mem);
			queue[index++] = item;
		}
	}

	return mem[1][1];

}


//Ž���ε� ������ ������ȹ���� ������� ����
int main(){
	//ifstream in("����_�̷�ã��.txt");
	//in = cin;
	int n, m;
	cin >> n >> m;
	cin.get();

	int mat[101][101] = { 0, };
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			mat[i][j] = cin.get() - '0';
		}
		cin.get();
	}

	int count = countWay(n, m, mat);
	cout << count << endl;

	return 0;
}