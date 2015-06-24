#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

//다익스트라 알고리즘 with 사이클 (Dijkstra Algorithm) 
//1) 각 정점에 경로의 최소 길이 및 이전 정점 저장 
//알고리즘 (간선의 BFS 기반)
//1) 시작점을 선택한 뒤 간선을 큐에 넣는다.
//2) 큐에서 간선을 꺼내온 뒤 타겟 정점의 최소길이와 간선 가중치 + 이전 정점 최소길이를 비교한다.
//3) 클 경우 아무것도 다음 큐를 탐색한다. (이미 최소 경로가 존재)
//4) 작을 경우 최소경로 길이로 갱신한뒤 해당 정점의 간선들을 큐에 담고 2)로 돌아간다.
//5) 큐가 empty가 되면 종료한다.

//다익스트라의 단점 
//음수 사이클이 있는 그래프에서는 해결할 수 없다.
//this can't be used in cycle graph with minus value


class Edge{
public:
	int from;
	int to;
	int weight;
	Edge* next;
	Edge(){
		next = NULL;
		from = -1;
		to = 1;
		weight = -1;
	}
};
class Vert{
public:
	int index;
	Edge* adjList;
	int adjSize;
	int pathSize;
	int prevV;
	Vert(){
		index = -1;
		adjList = NULL;
		adjSize = 0;
		pathSize = ~(1 << 31);
		prevV = -1;
	}
};
class Graph{
public:
	int vSize;
	Vert *v;
	Graph(int vSize){
		v = new Vert[vSize];
		for (int i = 0; i < vSize; i++){
			v[i].index = i;
		}
	}
	vector<int> getMinimumIndex(int start, int end){
		vector<int> result;
		queue<Edge*> q;
		
		Vert* startv = &v[start];
		startv->pathSize = 0;
		
		Edge* e = startv->adjList;
		while (e != NULL){
			q.push(e);
			e = e->next;
		}
		int count = 0;
		while (q.empty() == false){
			count++;
			Edge* e = q.front();	//back()도 있으나 front가 push와 같이 사용됨
			q.pop();
			Vert* target = &v[e->to];
			Vert* fromV = &v[e->from];
			if (target->pathSize > (fromV->pathSize + e->weight)){
				target->prevV = e->from;
				target->pathSize = fromV->pathSize + e->weight;
				//목표 정점의 간선들을 큐에 담음
				Edge* adjE = target->adjList;
				while (adjE != NULL){
					if (adjE->to != e->from)
						q.push(adjE);
					adjE = adjE->next;
				}
			}
			else{
				//해당 경로는 더이상 진행하지 않음
			}
		}
		//이전 정점을 순회하면서 최단경로를 찾음
		int prev = v[end].prevV;
		if (prev != -1)
			result.push_back(end);
		while (prev != -1){
			result.push_back(prev);
			prev = v[prev].prevV;
		}
		cout << count << endl;
		return result;
	}
};
int main(){
	fstream f("다익스트라.txt");
	int testcase;
	f >> testcase;
	for (int i = 0; i < testcase; i++){
		int vSize, eSize;
		int start, end;
		f >> start >> end;
		f >> vSize >> eSize;
		Graph g(vSize);
		for (int j = 0; j < eSize; j++){
			Edge* e1 = new Edge();
			Edge* e2 = new Edge();
			int from, to, weight;
			f >> from >> to >> weight;
			e1->from = from;
			e1->to = to;
			e1->weight = weight;

			e2->from = to;
			e2->to = from;
			e2->weight = weight;
			if (g.v[from].adjList == NULL){
				g.v[from].adjList = e1;
			}
			else{
				Edge* t = g.v[from].adjList ;
				g.v[from].adjList = e1;
				e1->next = t;
			}
			g.v[from].adjSize++;
			if (g.v[to].adjList == NULL){
				g.v[to].adjList = e2;
			}
			else{
				Edge* t = g.v[to].adjList;
				g.v[to].adjList = e2;
				e2->next = t;
			}
			g.v[to].adjSize++;
		}
		vector<int> v = g.getMinimumIndex(start, end);
		vector<int>::reverse_iterator iter = v.rbegin();
		cout << "[시작] " << start << "  [종료] " << end << endl;
		for (; iter < v.rend(); iter++){

			cout << *iter << " -> ";

		}
		cout << "[가중치] " << g.v[v.front()].pathSize ;
		cout << endl;
	}
	return 0;
}