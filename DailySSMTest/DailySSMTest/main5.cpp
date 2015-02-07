#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

unsigned long long factorial[20] = { 0, };

int main()
{
	factorial[0] = 1;
	factorial[1] = 1;
	factorial[2] = 2;
	factorial[3] = 6;
	for (int i = 4; i < 20; i++) {
		factorial[i] = factorial[i-1] * i;
	}
	
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		printf("#testcase%d\n", i + 1);
		int input = 0;
		scanf("%d", &input);
		printf("%llu\n", factorial[input]);
	}

	return 0;
}

//1���� � ���� ���� n������ ������ ��� ���� ���� ���ϸ� n!�� ��Ÿ����.
//
//0!= 1
//1!= 1
//2!= 2
//n!= n * (n - 1)!
//��
//�� ���� ���ǵȴ�.
//
//���� 4!= 4��3��2��1 = 24 �̴�.
//
//n!�� �־����� �� ����� ����ϴ� ���α׷��� �ۼ��϶�.
//(Hint : ������ int�����θ� ���ѵ��� �ʴ´�)