#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#define ITEMCOUNT 1000
#define WEIGHT 10000
int table[ITEMCOUNT][WEIGHT] = { 0, };
struct Item{
	int weight;
	int value;
};
//http://cultist-tp.tistory.com/entry/%EB%83%85%EC%83%89Knapsack%EB%B0%B0%EB%82%AD-%EB%AC%B8%EC%A0%9C
//�賶����
int main(){
	Item items[1000] = { 0, };
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int itemCount = 0;
		int totalWeight = 0;
		scanf("%d %d", &itemCount, &totalWeight);
		for (int i = 0; i < itemCount; i++){
			scanf("%d %d", &items[i].weight, &items[i].value);
			//���⼭ maxValuePrevious�� ������ 1���� ������������ ����ϴ� ���̴�.
			//���� table�� 2���� �迭�� �ʿ䰡 ����.
			for (int j = 1; j <= totalWeight; j++){
				int divide = j / items[i].weight;
				int selfValue = divide * items[i].value;	//�ϳ��� �־��� �� �ְ� ��ġ
				int maxValueWithPrevious = -1;
				if (i != 0 && j - items[i].weight >= 0){
					maxValueWithPrevious = table[i - 1][j - items[i].weight] + items[i].value;
				}
				int previousMaxValue = -1;
				if (i != 0){
					previousMaxValue = table[i - 1][j];
				}
				int max = selfValue > maxValueWithPrevious ? (selfValue > previousMaxValue ? selfValue : previousMaxValue) : (maxValueWithPrevious > previousMaxValue ? maxValueWithPrevious : previousMaxValue);

				table[i][j] = max;
			}
		}
		printf("%d\n", table[itemCount - 1][totalWeight]);

	}

	return 0;
}
/*
������
����	�賶ä���	�����ڵ�	5-M-01
����	����� ������ ������ ħ���ߴ�. ������ �賶�� ������ ��ġ���� �Ѵ�. �̶�, ��ģ ������ ���԰� W�� �Ѿ�� �賶�� ��������.

�� ������ ����ġ�� ���԰� �־��� ��, ������ �� ���԰� W�� ���� �����鼭 ������ �� ����ġ�� �ִ밡 �ǵ��� ������ �賶�� �������� �Ѵ�.
�̶� �賶�� ���� �� �ִ� �ִ� ����ġ�� ���Ͻÿ�.
�Է� ����	ù° ���� �׽�Ʈ���̽� T�� �Է� �޾ƾ� �Ѵ�.
ù ���� ������ ���� �� N(1��N��1,000)�� �賶�� �뷮
W(1��W��10,000)�� �־�����. ��° �ٺ��� N+1�ٿ��� �� ������ ���� Wi(1��Wi��W)�� ����ġ Pi�� �־�����.
(��, ������ ������ ������ ���������� �����Ѵ�.)
��� ����	ù° �ٿ� #testcaseN�� ���¿� ���� ��ȣ�� ����Ѵ�
������ ���Կ� ����ġ�� �־��� ��, �� ���԰� W�� ���� �����鼭, ������ �� ����ġ�� �ִ밡 �Ǵ� �ִ밪�� ����Ѵ�.
����	�Է�	���
2
2 10
5 300
2 50

2 10
2 100
5 200
#testcase1
600
#testcase2
500

*/