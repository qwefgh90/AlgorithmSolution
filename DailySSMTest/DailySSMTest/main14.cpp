#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main(){
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);

		int width = 0;
		int height = 0;
		scanf("%d", &width);
		scanf("%d", &height);

		int result = 0;
		int resultforBonus = 0;
		int widthfor6 = width / 6;
		int heightfor6 = height / 6;
		int widthBonus = width % 6;
		int heightBonus = height % 6;
		
		//���� ��
		result = widthfor6 * heightfor6;
		//������ ó��
		if (widthBonus > 0){
			resultforBonus += heightfor6;
		}
		if (heightBonus > 0){
			resultforBonus += widthfor6;
		}

		if (widthBonus > 0 && heightBonus > 0){
			resultforBonus++;
		}
		printf("%d %d\n", result,resultforBonus);

	}


	return 0;
}


/*
[ ���� ]
SW������� ȯ�氳���� ��ȯ���� �� ���� ���𵨸� ���縦 ���� ���̴�.
�� ���� ����� ȯ���� ���� �ٴ��� Ÿ�ϵ� ���� ����� �ϴµ�,
Ÿ���� ũ��� 6*6 �ۿ� ����. Ÿ���� �״�� ����ϰų� �߶� �̿� �� ���� �ִµ�
�߶� ����� Ÿ���� �ݵ�� ������ �Ѵ�.

���� ������ Ÿ���� ���� �߶� ����� Ÿ���� ���� ���ϴ� ���α׷��� �ۼ��϶�.
��� ������ inch�̰� �����Ѵ�.

[ �� ��� ���� ]
�Է�
�Է��� ù ���� �׽�Ʈ ���̽��� ���� T�̴�.
�� �׽�Ʈ���̽��� ���� ���� ���� ũ�Ⱑ �־����� �� ���� 1000�����̴�.

���
�ݵ�� #testcase���� ��� ��
�� �׽�Ʈ���̽��� ���� ������ Ÿ���� ���� �߶� ����� Ÿ���� ���� T�� ����϶�

[ ����� �� ]
2
160 240
100 120
#testcase1
1040 40
#tescase2
320 20





*/