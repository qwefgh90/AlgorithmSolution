//�ȶ��� ��
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory>
#define MAX 9

int main()
{
	int sunArr[200] = { 0, };
	int sunResultArr[200] = { 0, };
	//memset(sunResultArr, 0,sizeof(int)* 200);
	int sunCount;
	int powValue;

	int testCase = 0;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++){
		printf("#testcase%d\n", i + 1);
		scanf("%d", &sunCount);//�ڽ� ��
		scanf("%d", &powValue);//���� ��
		for (int j = 0; j < sunCount; j++){
			//�ڽ��� ����
			scanf("%d", &sunArr[j]);
		}
		int total = 0;

		//���� �� ����
		if (powValue % 2 == 0){	//¦��
			for (int j = 0; j < sunCount; j++){
				//sunResultArr[j] = sunArr[j];	//������ 1 2 3 �� �ϳ� 1 �� ���
				//if (powValue == 2)
				sunResultArr[j] = sunArr[j] * sunArr[j];
				/*else if (powValue == 3)
					sunResultArr[j] = sunArr[j] * sunArr[j] * sunArr[j];*/
				total += sunResultArr[j];
			}
		}
		else{	//Ȧ��
			// ���� ����
			for (int j = 0; j < sunCount; j++){
				if (sunArr[j] <= 0){
					sunResultArr[j] = 0;	// ���� �� ����Ҷ� ��ȿ�ϰ� ����
				}
				else{
					sunResultArr[j] = sunArr[j];	//������ 1 2 3 �� �ϳ� 1 �� ���
					/*if (powValue == 2)
						sunResultArr[j] = sunArr[j] * sunArr[j];*/
					if (powValue == 3)
						sunResultArr[j] = sunArr[j] * sunArr[j] * sunArr[j];
				}

				total += sunResultArr[j];
			}
		}
		printf("%d\n", total);

	}
	return 0;
}