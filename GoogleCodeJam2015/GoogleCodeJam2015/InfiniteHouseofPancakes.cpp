#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <queue>
#include <functional>
using namespace std;


//https://code.google.com/codejam/contest/dashboard?c=6224486#s=p1
//���� ���α׷��� �� �ڷᱸ�� ����
//���̽����� X special �ð� ���̺� ���� ��
//1)max ������ ���� �����´�.
//2)���� ���¿� ���� ���̽� X special ���̺��� ���� �����´�.
//3)�ּ� �ð����� �˻��Ѵ�.

#define MAX 1100 
int table[MAX][MAX];

struct CakeNode{
	int specialTime;
	int initCakeCount;
	int nodeValue;

	CakeNode(){
		specialTime = 0;
		initCakeCount = 0;
		nodeValue = 0;
	}

	bool operator > (const CakeNode& rhs) const {
		return nodeValue < rhs.nodeValue;
	}	//��������
};

//�ð� ���⵵
//O(nlogn) + O(p*logn) (�����̽� �� ���� Ƚ�� + �����̽� �ִ� ���� * ���� �� ���� Ƚ��)

int getMinTime(priority_queue<CakeNode, vector<CakeNode>, greater<CakeNode> >& max_heap){
	int bonusTime = 0;	//special ���� �߰��Ǵ� �ð�
	CakeNode topNode = max_heap.top();	//��ĳ��ũ 1�� = 1��
	int minTime = topNode.nodeValue;
	while (bonusTime < minTime){	//�ּ� �ð��� �Ѿ������
		topNode = max_heap.top();
		max_heap.pop();
		topNode.specialTime++;
		topNode.nodeValue = table[topNode.initCakeCount][topNode.specialTime];
		if (topNode.initCakeCount - 1 < topNode.specialTime){
			//���̻� ���� �� ����
			break;
		}
		max_heap.push(topNode);

		bonusTime++;
		if (bonusTime + max_heap.top().nodeValue < minTime){
			minTime = bonusTime + max_heap.top().nodeValue;
		}
	}
	return minTime;
}
//starting from 0
//���ɟ� X ������ �ð�(0�� 1��...) ���� ū ������ũ ��� ���̺�
//�ð��� ���� ���� ������ ������ũ ������ ����
void initSpecialTimeTable(int (*table)[MAX]){
	int number = 1;
	for (int number = 1; number < MAX; number++){	//���ɟ� �ʱ� ����
		for (int specialTime = 0; specialTime < MAX && specialTime < number; specialTime++){	//������ �ð� (0�� 1�� 2��)
			if (specialTime == 0)
				table[number][specialTime] = number;
			else{
				int divide = number / (specialTime+1);//�ð� + 1�� ������ ��� ���� (specialTime+1)
				int bonus = number % (specialTime+1);
				if (bonus == 0){
					table[number][specialTime] = divide;
				}
				else{
					table[number][specialTime] = table[bonus][bonus - 1] + divide;	//������ ���� ���� ��� ��
				}
			}
		}
	}
}

int main(){
	FILE* f = fopen("InfiniteHouseofPancakesLarge.txt", "r");
	FILE* output = fopen("output.txt", "w");

	initSpecialTimeTable(table);

	int testcase;
	fscanf(f, "%d", &testcase);
	for (int k = 0; k < testcase; k++){
		priority_queue<CakeNode, vector<CakeNode>,	greater<CakeNode> > max_heap;	//
		int peopleCount;
		fscanf(f,"%d", &peopleCount);
		for (int i = 0; i < peopleCount; i++)
		{
			int cakeCount;
			fscanf(f, "%d", &cakeCount);
			CakeNode node;
			node.initCakeCount = cakeCount;
			node.specialTime = 0;
			node.nodeValue = table[cakeCount][0];
			max_heap.push(node);
		}
		int minTime = getMinTime(max_heap);
		fprintf(output, "Case #%d: %d\n", k + 1, minTime);
	}
	fclose(output);
	fclose(f);
	

	return 0;
}
