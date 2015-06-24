#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//Prim 알고리즘 (간선의 BFS기반 및 힙 기반)
//1) 임의의 정점과 연결된 간선을 우선순위 큐에 추가한다.
//2) 우선순위 큐에서 한개의 간선을 뽑은 뒤 "목적지"를 아직 방문하지 않았다면 최소 신장 트리에 추가한다. 이때 간선에 의해 가르켜지는 정점은 방문 체크를한다.
//3) 가르켜지는 정점과 연결된 간선을 우선순위 큐에 추가하고 2)로 돌아간다.
//4) 큐가 비워지면 끝

//시간 복잡도
//V * logV (별모양 그래프인 경우, 방문한 점이라고 하더라도 비교로 확인해봐야 알기때문에 )
//(E + V) * logV (별모양 그래프면서 각 간선에 가중치에 의존적)
//E * logV (최종적인 시간복잡도)

class Edge{
public:
	int from;
	int to;
	int weight;
	Edge* next;
	Edge(){
		next = NULL;
	}
	Edge(Edge& e){
		this->from = e.from;
		this->to = e.to;
		this->weight = e.weight;
		this->next = NULL;
	}
	Edge getReverse(){
		Edge e;
		e.from = this->to;
		e.to = this->from;
		e.weight = this->weight;
		e.next = NULL;
		return e;
	}
};

class Vert{
public:
	Edge* adjList;
	int eCount;
	int index;
	bool visit;
	Vert(){
		visit = false;
		index = -1;
		eCount = 0;
		adjList = NULL;
	}
};

struct comparator{
	bool operator()(Edge* &e1, Edge* &e2){
		return e1->weight > e2->weight ? true : false;
	}
};

class Graph{
public:
	Vert* v;
	int vCount;
public:
	Graph prim(){
		Graph g = *this;
		Graph result(g.vCount);//최소 신장 트리 (그래프의 모든 정점을 최소의 비용으로 연결하는 트리)
		
		priority_queue<Edge*, vector<Edge*>, comparator> queue;
		
		// 기존 그래프의 간선 리스트 추가
		for (Edge* e = g.v[0].adjList; e != NULL; e = e->next){//큐에 삽입
			queue.push(e);
		}
		
		int count = 0;
		while (queue.empty() == false){
			count++;
			Edge* e = queue.top();
			queue.pop();
			result.v[e->from].visit = true;	//방문 체크

			//신장트리에 간선 삽입
			//새로운 간선 사용
			if (result.v[e->to].visit == false){//아직 목표 정점에 방문하지 않았을때

				Edge* newEdge = new Edge(*e);
				Edge* reverse = new Edge(newEdge->getReverse());

				//정 방향 간선 추가
				if (NULL == result.v[newEdge->from].adjList){
					result.v[newEdge->from].adjList = newEdge;
				}
				else{
					Edge* temp = result.v[newEdge->from].adjList;
					result.v[newEdge->from].adjList = newEdge;
					newEdge->next = temp;
				}

				//역 방향 간선 추가
				if (NULL == result.v[reverse->from].adjList){
					result.v[reverse->from].adjList = reverse;
				}
				else{
					Edge* temp = result.v[reverse->from].adjList;
					result.v[reverse->from].adjList = reverse;
					reverse->next = temp;
				}
				
				result.v[e->to].visit = true;	//방문

				//우선순위 큐에 "to"의 간선 리스트 추가
				Edge* ePointer = NULL;
				for (ePointer = g.v[e->to].adjList; ePointer != NULL; ePointer = ePointer->next){//큐에 삽입
					if (result.v[ePointer->to].visit == false)
						queue.push(ePointer);
				}
			}
		}
		return result;
	}
	Graph(){}
	Graph(int vCount){
		v = new Vert[vCount];
		this->vCount = vCount;
		for (int i = 0; i < vCount; i++){
			v[i].index = i;
		}
	}
};

int main(){
	fstream f("prim.txt");
	int count;
	f >> count;
	for (int i = 0; i < count; i++){
		int vCount, eCount;
		f >> vCount >> eCount;
		//그래프 초기화
		//정점 초기화
		Graph g(vCount);
		//간선 추가
		for (int j = 0; j < eCount; j++){
			int from, to, w;
			f >> from >> to >> w;
			Edge *e = new Edge;
			e->from = from;
			e->to = to;
			e->weight = w;

			if (g.v[from].adjList == NULL){
				g.v[from].adjList = e;
				g.v[from].eCount++;
			}
			else{
				Edge* prev = g.v[from].adjList;
				g.v[from].adjList = e;
				g.v[from].eCount++;
				e->next = prev;//간선추가
			}

			e = new Edge;
			e->from = to;
			e->to = from;
			e->weight = w;

			if (g.v[to].adjList == NULL){
				g.v[to].adjList = e;
				g.v[to].eCount++;
			}
			else{
				Edge* prev = g.v[to].adjList;
				g.v[to].adjList = e;
				g.v[to].eCount++;
				e->next = prev;//간선추가
			}

		}

		Graph result = g.prim();
		for (int i = 0; i < result.vCount; i++){
			cout << "[정점]" << result.v[i].index << endl;
			Edge* e = result.v[i].adjList;
			while (e != NULL){
				cout << "[간선]" << e->to << endl;
				e = e->next;
			}
		}
		cout << endl << endl;
	}


	return 0;
}