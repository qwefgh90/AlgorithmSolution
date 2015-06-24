#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

//���ͽ�Ʈ�� �˰��� with ����Ŭ (Dijkstra Algorithm) 
//1) �� ������ ����� �ּ� ���� �� ���� ���� ���� 
//�˰��� (������ BFS ���)
//1) �������� ������ �� ������ ť�� �ִ´�.
//2) ť���� ������ ������ �� Ÿ�� ������ �ּұ��̿� ���� ����ġ + ���� ���� �ּұ��̸� ���Ѵ�.
//3) Ŭ ��� �ƹ��͵� ���� ť�� Ž���Ѵ�. (�̹� �ּ� ��ΰ� ����)
//4) ���� ��� �ּҰ�� ���̷� �����ѵ� �ش� ������ �������� ť�� ��� 2)�� ���ư���.
//5) ť�� empty�� �Ǹ� �����Ѵ�.

//���ͽ�Ʈ���� ���� 
//���� ����Ŭ�� �ִ� �׷��������� �ذ��� �� ����.
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
			Edge* e = q.front();	//back()�� ������ front�� push�� ���� ����
			q.pop();
			Vert* target = &v[e->to];
			Vert* fromV = &v[e->from];
			if (target->pathSize > (fromV->pathSize + e->weight)){
				target->prevV = e->from;
				target->pathSize = fromV->pathSize + e->weight;
				//��ǥ ������ �������� ť�� ����
				Edge* adjE = target->adjList;
				while (adjE != NULL){
					if (adjE->to != e->from)
						q.push(adjE);
					adjE = adjE->next;
				}
			}
			else{
				//�ش� ��δ� ���̻� �������� ����
			}
		}
		//���� ������ ��ȸ�ϸ鼭 �ִܰ�θ� ã��
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
	fstream f("���ͽ�Ʈ��.txt");
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
		cout << "[����] " << start << "  [����] " << end << endl;
		for (; iter < v.rend(); iter++){

			cout << *iter << " -> ";

		}
		cout << "[����ġ] " << g.v[v.front()].pathSize ;
		cout << endl;
	}
	return 0;
}