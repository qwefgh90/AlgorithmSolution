#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

struct Edge{
	int from;
	int to;
	int weight;
	bool visit;

	Edge* next;
	Edge(){
		next = NULL;
		from = NULL;
		to = NULL;
		weight = -1;
		visit = false;
	}
};
struct Vertex{
	Edge* edge;//연결된 간선
	
	bool exist;
	Vertex(){
		exist = false;
		edge = NULL;
	}
};

void insertEdge(Vertex* v, Edge* edge){
	Vertex* temp = v;
	Edge* tempEdge = NULL;
	if (temp->edge == NULL){
		temp->edge = edge;	//간선 삽입
	}
	else{
		tempEdge = temp->edge;
		while (tempEdge->next != NULL){
			tempEdge = tempEdge->next;//다음 간선은 뭘까?
		}
		tempEdge->next = edge; //마지막 간선에 삽입
	}
}



//연결 리스트
//연결된 그래프임여..ㅎㅎ]
//너비 우선 방문 할거임

int main(){
	int testcase;
	
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int vertexCnt;
		unsigned int total = 0;
		scanf("%d", &vertexCnt);//정점의 개수

		//정점 리스트 초기화
		Vertex vlist[100000];
		//memset(vlist, 0, vertexCnt * sizeof(Vertex));
		
		//간선 및 정점 구성
		for (int i = 0; i < vertexCnt - 1; i++){
			int fromIndex;
			int toIndex;
			int weight;
			scanf("%d %d %d", &fromIndex, &toIndex, &weight);
			Edge *edge = new Edge;
			Edge *edgeto = new Edge;
			if (vlist[fromIndex].exist == false){
				vlist[fromIndex] = Vertex();
				vlist[fromIndex].exist = true;
				insertEdge(&vlist[fromIndex], edge);
			}
			else
				insertEdge(&vlist[fromIndex], edge);
			
			if (vlist[toIndex].exist == false){
				vlist[toIndex] = Vertex();
				vlist[toIndex].exist = true;
				insertEdge(&vlist[toIndex], edgeto);
			}
			else
				insertEdge(&vlist[toIndex], edgeto);
			
			//인덱스로 저장 // 간선 생성
			edge->from = fromIndex;
			edge->to = toIndex;
			edge->weight = weight;


			edgeto->from = toIndex;
			edgeto->to = fromIndex;
			edgeto->weight = weight;
		}
		
		//BFS로 순회
		printf("\n");;
		//break;
	}


	return 0;
}





/*

트리란 N개의 정점과 N-1개의 간선을 가진 연결된 그래프입니다. 또한, 모든 두 정점 사이에는 경로가 하나만 존재합니다. 이때 트리의 간선에는 모두 각각의 가중치가 있습니다.
트리에서 어떤 두 정점을 잇는 ‘경로의 가중치’는 그 경로상에 있는 모든 가중치의 곱으로 정의됩니다. 그리고, ‘트리의 가중치는 모든 경로의 가중치의 합으로 정의됩니다.
트리의 형태는 이진트리가 아닐 수도 있으며, N개의 모든 정점이 모두 연결된 것이 아닐 수 도 있습니다. 또한, 가중치 계산 시 부모 노드에서 자식 노드로 이동하는 경로의 가중치만 계산하는 것이 아닌 모든 노드에서의 경로의 가중치를 구하는 문제입니다.

예를 들어 아래와 같은 트리가 있습니다.



예시의 트리 경로의 가중치는 아래와 같습니다.
[1->2] = 100
[2->3] = 100
[1->3] = [1->2] x [2->3] = 100 x 100 = 10000

트리의 가중치 = 100 + 100 + 10000 = 10200

예시를 하나 더 보겠습니다.

예시의 트리 경로의 가중치는 아래와 같습니다.
[1->2] = 5
[1->3] = 2
[1->4] = [1->3 의 가중치] x [3->4 의 가중치] = 2 x 9 = 18
[3->4] = 9
[2->3]=[2->1의 가중치] x [1->3의 가중치] = 5 x 2 = 10
.
.
[4->6] = [4->3의 가중치]x[3->5의 가중치]x[5->6의 가중치] = 9x7x11 = 693
.
.

그럼 이 트리의 가중치는 모든 경로의 가중치의 합으로 정의되므로,

트리의 가중치 = [1->2의 가중치] + [1->3의 가중치]+ [1->4의 가중치] + [3->4의 가중치]+
[2->3의 가중치]+[2->4의 가중치]+[2->5의 가중치]+….+[4->6의 가중치]+….

가 됩니다.


트리가 주어질 때, 트리의 가중치를 구해보세요.

[입력]
입력에는 여러 테스트 케이스가 포함될 수 있다. 입력의 첫째 줄에는 테스트 케이스의 수 T가 주어지고, 이후 차례로 T개의 테스트 케이스가 주어진다 (T ≤ 10)
각 테스트 케이스의 첫 번째 줄에 트리의 정점 개수 N이 주어진다. (1 ≤ N ≤ 100000)
두 번째 줄부터 N-1개의 줄에 걸쳐 간선의 정보 a, b, c가 주어진다. 이는 정점 a와 정점 b 사이에 간선이 있고, 그 간선의 가중치는 c라는 의미이다.
입력은 루트 노드부터 깊이 순으로 입력되지 않을 수 있으며, N개의 노드가 존재하나 간선 하나도 연결되지 않은 트리가 존재할 수 있습니다.
[출력]
첫 번째 줄에 트리의 가중치를 1,000,000,007로 나눈 나머지를 출력한다.
(중요! 테스트 케이스 개수마다 #testcase번호를 출력 후 정답 출력)

[STL사용 불가 / 동적할당 사용 가능]
[입력 예]
2
3
3 2 100
2 1 100
14
6 1 5
10 12 3
6 11 3
14 10 4
13 6 5
4 6 2
6 8 5
3 2 4
6 3 2
6 9 2
3 7 4
14 5 5
5 2 4
출력
#testcase1
10200
#testcase2
71280

*/