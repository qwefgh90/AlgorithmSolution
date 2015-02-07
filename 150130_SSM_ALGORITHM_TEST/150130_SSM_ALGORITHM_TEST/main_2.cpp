/*

VC, GCC���� ���

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
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

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

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}

/*

����� �����ϴ� �����̴� �Ｚ���� �ű��� ������� �����ߴٴ� �ҽ��� ��� ã�ư���� �����Ծ���. ������ ������� �湮�� �����̴� �̰��� �� �ű��� ��������� ������ �� �� �־���.
�� ����� �Ѿ��� ����(��� ���� �� 5ĭ)�� �Ʒ� �׸��� ���� ��, �Ʒ�, ����, �����ʱ����� ���̾���.



2���� �迭�� ���������� ������ ��, �� �ѹ��� �Ѿ��� �� ���� ���� ������ ������ ������ ���ϴ� ���� �����̴�.

[�Է�]
ù ��° �ٿ��� �׽�Ʈ ���̽� N�� �Է��Ѵ�.
�� ���� �ٺ��ʹ� 6*6 ����� ĭ�� 36���� ���� �־�����.
�� ���� 0���� 9������ ���̴�.

[���]
�ʷ��̰� ���� �� �ִ� ������ �ִ� ���� ����Ѵ�.
(�߿�! �׽�Ʈ ���̽� �������� #testcase��ȣ�� ��� �� ���� ���)

-����� ��-

�Է�
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

���
#testcase1
33
#testcase2
12




*/