#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct Memory{
	bool flag;
	int maxNodeCount;
	Memory(){
		init();
	}
	void init(){
		flag = false;
		maxNodeCount = 0;
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

#define MAX 1001

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
			Memory m = DFS(graph, graph.node[j], -1);
			int deleteSize = size - m.maxNodeCount;
			if (min > deleteSize)
				min = deleteSize;
		}
		fprintf(w, "Case #%d: %d\n", i + 1, min);
	}
	fclose(f);
	fclose(w);
}
void swap(int &v1, int &v2){
	int temp = v1;
	v1 = v2;
	v2 = temp;
}

Memory DFS(Graph& g, Node& node, int parent){
	int childSize = -1;
	if (parent != -1)
		childSize = node.edge.size() - 1;	//부모 제외
	else
		childSize = node.edge.size();

	Memory m;
	int firstMaxValue = INT_MIN;
	int secMaxValue = INT_MIN;

	if (childSize == 0 || childSize == 1){
		m.flag = true;
		m.maxNodeCount = 1;//자기자신
	}
	else if(childSize >= 2){
		int edgeSize = node.edge.size();

		if (secMaxValue > firstMaxValue){
			swap(firstMaxValue, secMaxValue);
		}

		for (int i =0; i < edgeSize; i++){
			if (node.edge[i].to != parent){//부모 제외
				Memory childM;
				if (memory[node.edge[i].to][node.index].flag){	//메모라이즈
					childM = memory[node.edge[i].to][node.index];
				}
				else{
					childM = DFS(g, g.node[node.edge[i].to], node.index);//메모라이즈
					memory[node.edge[i].to][node.index] = childM;
				}
				
				if (childM.maxNodeCount > secMaxValue){
					secMaxValue = childM.maxNodeCount;//새로운 노드

					if (secMaxValue > firstMaxValue){
						swap(firstMaxValue, secMaxValue);
					}
				}
			}
		}

		m.flag = true;
		m.maxNodeCount = 1 + firstMaxValue + secMaxValue;
	}
	return m;
}