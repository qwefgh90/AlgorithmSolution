#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//Prim �˰��� (������ BFS��� �� �� ���)
//1) ������ ������ ����� ������ �켱���� ť�� �߰��Ѵ�.
//2) �켱���� ť���� �Ѱ��� ������ ���� �� "������"�� ���� �湮���� �ʾҴٸ� �ּ� ���� Ʈ���� �߰��Ѵ�. �̶� ������ ���� ���������� ������ �湮 üũ���Ѵ�.
//3) ���������� ������ ����� ������ �켱���� ť�� �߰��ϰ� 2)�� ���ư���.
//4) ť�� ������� ��

//�ð� ���⵵
//V * logV (����� �׷����� ���, �湮�� ���̶�� �ϴ��� �񱳷� Ȯ���غ��� �˱⶧���� )
//(E + V) * logV (����� �׷����鼭 �� ������ ����ġ�� ������)
//E * logV (�������� �ð����⵵)

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
		Graph result(g.vCount);//�ּ� ���� Ʈ�� (�׷����� ��� ������ �ּ��� ������� �����ϴ� Ʈ��)
		
		priority_queue<Edge*, vector<Edge*>, comparator> queue;
		
		// ���� �׷����� ���� ����Ʈ �߰�
		for (Edge* e = g.v[0].adjList; e != NULL; e = e->next){//ť�� ����
			queue.push(e);
		}
		
		int count = 0;
		while (queue.empty() == false){
			count++;
			Edge* e = queue.top();
			queue.pop();
			result.v[e->from].visit = true;	//�湮 üũ

			//����Ʈ���� ���� ����
			//���ο� ���� ���
			if (result.v[e->to].visit == false){//���� ��ǥ ������ �湮���� �ʾ�����

				Edge* newEdge = new Edge(*e);
				Edge* reverse = new Edge(newEdge->getReverse());

				//�� ���� ���� �߰�
				if (NULL == result.v[newEdge->from].adjList){
					result.v[newEdge->from].adjList = newEdge;
				}
				else{
					Edge* temp = result.v[newEdge->from].adjList;
					result.v[newEdge->from].adjList = newEdge;
					newEdge->next = temp;
				}

				//�� ���� ���� �߰�
				if (NULL == result.v[reverse->from].adjList){
					result.v[reverse->from].adjList = reverse;
				}
				else{
					Edge* temp = result.v[reverse->from].adjList;
					result.v[reverse->from].adjList = reverse;
					reverse->next = temp;
				}
				
				result.v[e->to].visit = true;	//�湮

				//�켱���� ť�� "to"�� ���� ����Ʈ �߰�
				Edge* ePointer = NULL;
				for (ePointer = g.v[e->to].adjList; ePointer != NULL; ePointer = ePointer->next){//ť�� ����
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
		//�׷��� �ʱ�ȭ
		//���� �ʱ�ȭ
		Graph g(vCount);
		//���� �߰�
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
				e->next = prev;//�����߰�
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
				e->next = prev;//�����߰�
			}

		}

		Graph result = g.prim();
		for (int i = 0; i < result.vCount; i++){
			cout << "[����]" << result.v[i].index << endl;
			Edge* e = result.v[i].adjList;
			while (e != NULL){
				cout << "[����]" << e->to << endl;
				e = e->next;
			}
		}
		cout << endl << endl;
	}


	return 0;
}