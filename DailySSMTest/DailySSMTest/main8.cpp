#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int main() {
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int x = 0;
		int y = 0;
		int z = 0;
		scanf("%d %d %d", &x, &y, &z);
		int total = 0;
		int front = (x - 2) * 2 + (y - 2) * 2;
		int back = front;
		int middle = 4*(z-2);
		total = front + back + middle;
		printf("%d\n", total);
		
	}
	return 0;
}



/*
====
====


����	��� ��ĥ�ϱ�	�����ڵ�	1-L-03
����	ũ�Ⱑ 1*1*1 �� ����� ������ ���� A ���� B ���� C �� ������ü�� ���� �� A��B��C (2��A,B,C��120)�� ��� �Ѹ鿡 ����Ʈ�� ĥ�Ͽ���.
�Ʒ��� �׸��� 3x3x3 �� ����� �����̴�.

�� �� 2 ���� �鸸 ����Ʈ�� ĥ���� ����� ������ ���ϴ� �� �����̴�.
�Է� ����	ù° ���� �׽�Ʈ���̽� T�� �Է� �޾ƾ� �Ѵ�.
A , B , C �� ���ʴ�� �Էµȴ�. A �� ����, B �� ����, C �� �����̴�.
��� ����	ù° �ٿ� #testcaseN�� ���¿� ���� ��ȣ�� ����Ѵ�
2���� �鸸 ����Ʈ�� ĥ���� ����� ������ ù° �ٿ� ����Ѵ�.
����	�Է�	���
2
3 3 3
2 3 4
#testcase1
12
#testcase2
12

*/