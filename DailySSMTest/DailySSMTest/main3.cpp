#include <stdio.h>
#include <stdlib.h>
#include <memory>

//���ڸ� �ڿ����� �ִ�.�� ���� �� �ڸ��� �������� ���� ���� ���� �Ͻ�Ʈ�� ����� �Ѵ�.
//���� ��� 153 �� 1 + 125 + 27 �� �����Ƿ� 153�� �Ͻ�Ʈ�� ���̴�.
//�Ͻ�Ʈ�� ���� ��� ����ϴ� ���α׷��� �ۼ��Ͽ���.
//
//<���漳��>
//�� ������ �Է� �޴� �׽�Ʈ���̽��� �����Ƿ�
//�־��� ���ø����� ������ ���� ����ϰ� ������� �������� �����Ͽ� ����Ѵ�.
//cout << "#testcase1" << endl;
#define MAXNUM 10

int getNumber(int x1, int x2, int x3)
{
	return x1 * 100 + x2 * 10 + x3;
}

int main()
{
	int resultCount = 0;
	int result[1000] = { 0, };
	int arr[10] = { 0, };
	for (int i = 0; i < 10; i++){
		arr[i] = i * i * i;
	}

	printf("#testcase1\n");
	for (int x = 1; x < MAXNUM; x++){
		for (int y = 0; y < MAXNUM; y++){
			for (int z = 0; z < MAXNUM; z++){
				int result = getNumber(x, y, z);
				//printf("%d\n", result);
				if (result == arr[x] + arr[y] + arr[z]){
					/*result[resultCount] = result;
					resu*/

					printf("%d\n", result);
					resultCount++;
				}
			}
		}
	}
	
	return 0;
}
