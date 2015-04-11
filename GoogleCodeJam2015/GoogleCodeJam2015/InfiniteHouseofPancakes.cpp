#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <queue>
#include <functional>
using namespace std;


//https://code.google.com/codejam/contest/dashboard?c=6224486#s=p1
//동적 프로그래밍 및 자료구조 문제
//케이스개수 X special 시간 테이블 구성 후
//1)max 힙으로 값을 가져온다.
//2)현재 상태에 따른 케이스 X special 테이블에서 값을 가져온다.
//3)최소 시간인지 검사한다.

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
	}	//오름차순
};

//시간 복잡도
//O(nlogn) + O(p*logn) (팬케이스 힙 삽입 횟수 + 팬케이스 최대 개수 * 삭제 및 삽입 횟수)

int getMinTime(priority_queue<CakeNode, vector<CakeNode>, greater<CakeNode> >& max_heap){
	int bonusTime = 0;	//special 마다 추가되는 시간
	CakeNode topNode = max_heap.top();	//팬캐이크 1개 = 1초
	int minTime = topNode.nodeValue;
	while (bonusTime < minTime){	//최소 시간은 넘어설때까지
		topNode = max_heap.top();
		max_heap.pop();
		topNode.specialTime++;
		topNode.nodeValue = table[topNode.initCakeCount][topNode.specialTime];
		if (topNode.initCakeCount - 1 < topNode.specialTime){
			//더이상 나눌 수 없음
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
//팬케잌 X 나누는 시간(0초 1초...) 가장 큰 팬케이크 덩어리 테이블
//시간에 따라 나눈 최적의 팬케이크 개수를 저장
void initSpecialTimeTable(int (*table)[MAX]){
	int number = 1;
	for (int number = 1; number < MAX; number++){	//팬케잌 초기 숫자
		for (int specialTime = 0; specialTime < MAX && specialTime < number; specialTime++){	//나누는 시간 (0초 1초 2초)
			if (specialTime == 0)
				table[number][specialTime] = number;
			else{
				int divide = number / (specialTime+1);//시간 + 1이 나누는 덩어리 개수 (specialTime+1)
				int bonus = number % (specialTime+1);
				if (bonus == 0){
					table[number][specialTime] = divide;
				}
				else{
					table[number][specialTime] = table[bonus][bonus - 1] + divide;	//나머지 값의 나눈 덩어리 수
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
