#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct Memory{
	bool flag;
	int fullDelete;
	int fullBtreeDelete;
	Memory(){
		init();
	}
	void init(){
		flag = false;
		fullDelete = 0;
		fullBtreeDelete = 0;
	}
};
struct Edge{
	int to;
	int from;
	Edge(){
		from = 0;
		to = 0;
	}
};

struct Node{
	int index;
	vector<Edge> edge;
};

struct Graph{
	Node* node;
	int size = 0;
	Graph(int size){
		node = new Node[size + 1];
		for (int i = 1; i < size + 1; i++){
			node[i].index = i;
		}
	}
};

Memory DFS(Graph& g, Node& node, int parent = -1);

#define MAX 1000

Memory memory[MAX][MAX];
//메모리 초기화
void init(){
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++){
			memory[i][j].init();
		}
	}
}
int main(){
	FILE* f = fopen("FullBinaryTreeLargeInput.txt", "r");
	FILE* w = fopen("output.txt", "w");

	int testcase;
	fscanf(f, "%d", &testcase);
	for (int i = 0; i < testcase; i++){
		init();//memory init
		int size;
		fscanf(f, "%d", &size);
		Graph graph(size);
		for (int j = 0; j < size - 1; j++){
			int from;
			int to;
			fscanf(f, "%d %d", &from, &to);
			Edge edge;
			edge.from = from;
			edge.to = to;
			graph.node[from].edge.push_back(edge);

			edge.from = to;
			edge.to = from;
			graph.node[to].edge.push_back(edge);
		}
		int min = INT_MAX;
		for (int j = 1; j <= size; j++){
			Memory m = DFS(graph, graph.node[j]);
			if (graph.node[j].edge.size() == 1){
				if (min > m.fullDelete - 1){
					min = m.fullDelete - 1;
				}
			}
			else{
				if (min > m.fullBtreeDelete){
					min = m.fullBtreeDelete;
				}
			}
		}
		fprintf(stdout, "Case #%d: %d\n", i + 1, min);
	}
	fclose(f);
	fclose(w);
}


//깊이 우선 탐색
Memory DFS(Graph& g, Node& node, int parent){
	Memory item;
	if (node.edge.size() == 1 && parent != -1){//부모가 아니고 리프 노드 일때만
		item.flag = true;
		item.fullBtreeDelete = 0;
		item.fullDelete = 1;
		memory[node.index][parent] = item;
		return item;
	}

	vector<Memory*> calculator;// 자식 노드 계산용 벡터
	//priority_queue<int,vector<int>,less<int>> queue;// 우선순위
	int min = INT_MAX;

	int childSize = node.edge.size();	//간선 리스트 사이즈
	vector<Edge>& edgeVector = node.edge;	//간선 리스트

	//깊이 우선 탐색
	for (int i = 0; i < childSize; i++){
		int childIndex = edgeVector[i].to;
		int myIndex = node.index;

		if (childIndex == parent){
			continue;//부모쪽은 계산안함.
		}

		if (memory[childIndex][myIndex].flag == false)	//테이블에 없을 경우만
			DFS(g, g.node[childIndex], myIndex);//깊이 우선 탐색

		calculator.push_back(&memory[childIndex][myIndex]);
	}

	int remainBranchCount = 0;
	int fullDeleteCount = 0;

	int calculateSize = calculator.size();



	//3중 for (다이나믹 적용) 
	//최소를 찾기 위해 
	for (int i = 0; i < calculateSize; i++){
		for (int j = i + 1; j < calculateSize; j++){
			int remainBranchCount1 = calculator[i]->fullBtreeDelete;
			int remainBranchCount2 = calculator[j]->fullBtreeDelete;
			int fullDeleteCount = 0;
			for (int k = 0; k < calculateSize; k++){
				if (k != i && k != j){
					fullDeleteCount += calculator[k]->fullDelete;
				}
			}
			//queue.push(remainBranchCount1 + remainBranchCount2 + fullDeleteCount);
			if (min > remainBranchCount1 + remainBranchCount2 + fullDeleteCount){
				min = remainBranchCount1 + remainBranchCount2 + fullDeleteCount;
			}
		}
		fullDeleteCount += calculator[i]->fullDelete;
		if (calculateSize == 1){
			min = fullDeleteCount;
		}
	}

	fullDeleteCount++; //자신 포함
	remainBranchCount = min;	//지웠을 때

	item.flag = true;
	item.fullBtreeDelete = remainBranchCount;
	item.fullDelete = fullDeleteCount;

	if (parent != -1)
		memory[node.index][parent] = item;

	return item;

}