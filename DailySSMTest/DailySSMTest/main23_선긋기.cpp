//�������� �����غ��� ���� �κ��� ���� ��갪�� ����Ͽ� �����Ѵ�.
//��ȭ�� f(n) ={ f(n-1) * f(0) }+{ f(n-2) * f(1)} +{ f(n-3) + f(2)} + .... + {f(0) * f(n-1)}
//f(0) = 1
//f(1) = 1
//n 1~19
long long int drawTable[20] = { 0, };
#include <stdio.h>r
int main(){
	drawTable[0] = 1;
	drawTable[1] = 1;
	for (int i = 2; i < 20; i++){
		unsigned int result = 0;
		for (int j = 0; j < i; j++){
			result += drawTable[i - j - 1] * drawTable[j]; //* drawTable[i - j - 1];
		
		}
		drawTable[i] = result;
	//	printf("[%d]%d\n", i, drawTable[i]);
	}
	
	int testcase;
	
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int n;
		scanf("%d", &n);
		printf("%llu\n", drawTable[n]);
	}
	return 0;
}


/*

���߱�

1 , 2 , 3 , ... , 2*n-1 , 2*n �� ���ڸ� �ð� �������� ������ �������� ȣ ���� ��ȣ�� �ο��� �� �� ���ڿ��� �ٸ� ���ڷ� ���� ���� �� ���� ���� �ʰ� ���� �� �ִ� ���� ���� ����ϴ°� �����̴�.

���� , n �� 2 �̸� 2 ����



n �� 3 �̸� 5 ���� �̴�.



�Է�
ù�ٿ� �׽�Ʈ���̽� ���� T�� �־�����.
���� �ٺ���, �� �׽�Ʈ���̽��� ���Ͽ�, n �� �Է����� �־�����. n �� ������ 1 ���� 19 ������ �����̴�.

���

���� ����ϱ� ���� �� �׽�Ʈ���̽��� ������ ���� ��#testcase1����#testcase2��... �� ����Ѵ�. �� �׽�Ʈ���̽��� ���Ͽ� �������� ����Ѵ�.

����� ��

�Է�
1
3

���
#testcase1
5


*/