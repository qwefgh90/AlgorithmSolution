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
	Edge* edge;//����� ����
	
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
		temp->edge = edge;	//���� ����
	}
	else{
		tempEdge = temp->edge;
		while (tempEdge->next != NULL){
			tempEdge = tempEdge->next;//���� ������ ����?
		}
		tempEdge->next = edge; //������ ������ ����
	}
}



//���� ����Ʈ
//����� �׷����ӿ�..����]
//�ʺ� �켱 �湮 �Ұ���

int main(){
	int testcase;
	
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int vertexCnt;
		unsigned int total = 0;
		scanf("%d", &vertexCnt);//������ ����

		//���� ����Ʈ �ʱ�ȭ
		Vertex vlist[100000];
		//memset(vlist, 0, vertexCnt * sizeof(Vertex));
		
		//���� �� ���� ����
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
			
			//�ε����� ���� // ���� ����
			edge->from = fromIndex;
			edge->to = toIndex;
			edge->weight = weight;


			edgeto->from = toIndex;
			edgeto->to = fromIndex;
			edgeto->weight = weight;
		}
		
		//BFS�� ��ȸ
		printf("\n");;
		//break;
	}


	return 0;
}





/*

Ʈ���� N���� ������ N-1���� ������ ���� ����� �׷����Դϴ�. ����, ��� �� ���� ���̿��� ��ΰ� �ϳ��� �����մϴ�. �̶� Ʈ���� �������� ��� ������ ����ġ�� �ֽ��ϴ�.
Ʈ������ � �� ������ �մ� ������� ����ġ���� �� ��λ� �ִ� ��� ����ġ�� ������ ���ǵ˴ϴ�. �׸���, ��Ʈ���� ����ġ�� ��� ����� ����ġ�� ������ ���ǵ˴ϴ�.
Ʈ���� ���´� ����Ʈ���� �ƴ� ���� ������, N���� ��� ������ ��� ����� ���� �ƴ� �� �� �ֽ��ϴ�. ����, ����ġ ��� �� �θ� ��忡�� �ڽ� ���� �̵��ϴ� ����� ����ġ�� ����ϴ� ���� �ƴ� ��� ��忡���� ����� ����ġ�� ���ϴ� �����Դϴ�.

���� ��� �Ʒ��� ���� Ʈ���� �ֽ��ϴ�.



������ Ʈ�� ����� ����ġ�� �Ʒ��� �����ϴ�.
[1->2] = 100
[2->3] = 100
[1->3] = [1->2] x [2->3] = 100 x 100 = 10000

Ʈ���� ����ġ = 100 + 100 + 10000 = 10200

���ø� �ϳ� �� ���ڽ��ϴ�.

������ Ʈ�� ����� ����ġ�� �Ʒ��� �����ϴ�.
[1->2] = 5
[1->3] = 2
[1->4] = [1->3 �� ����ġ] x [3->4 �� ����ġ] = 2 x 9 = 18
[3->4] = 9
[2->3]=[2->1�� ����ġ] x [1->3�� ����ġ] = 5 x 2 = 10
.
.
[4->6] = [4->3�� ����ġ]x[3->5�� ����ġ]x[5->6�� ����ġ] = 9x7x11 = 693
.
.

�׷� �� Ʈ���� ����ġ�� ��� ����� ����ġ�� ������ ���ǵǹǷ�,

Ʈ���� ����ġ = [1->2�� ����ġ] + [1->3�� ����ġ]+ [1->4�� ����ġ] + [3->4�� ����ġ]+
[2->3�� ����ġ]+[2->4�� ����ġ]+[2->5�� ����ġ]+��.+[4->6�� ����ġ]+��.

�� �˴ϴ�.


Ʈ���� �־��� ��, Ʈ���� ����ġ�� ���غ�����.

[�Է�]
�Է¿��� ���� �׽�Ʈ ���̽��� ���Ե� �� �ִ�. �Է��� ù° �ٿ��� �׽�Ʈ ���̽��� �� T�� �־�����, ���� ���ʷ� T���� �׽�Ʈ ���̽��� �־����� (T �� 10)
�� �׽�Ʈ ���̽��� ù ��° �ٿ� Ʈ���� ���� ���� N�� �־�����. (1 �� N �� 100000)
�� ��° �ٺ��� N-1���� �ٿ� ���� ������ ���� a, b, c�� �־�����. �̴� ���� a�� ���� b ���̿� ������ �ְ�, �� ������ ����ġ�� c��� �ǹ��̴�.
�Է��� ��Ʈ ������ ���� ������ �Էµ��� ���� �� ������, N���� ��尡 �����ϳ� ���� �ϳ��� ������� ���� Ʈ���� ������ �� �ֽ��ϴ�.
[���]
ù ��° �ٿ� Ʈ���� ����ġ�� 1,000,000,007�� ���� �������� ����Ѵ�.
(�߿�! �׽�Ʈ ���̽� �������� #testcase��ȣ�� ��� �� ���� ���)

[STL��� �Ұ� / �����Ҵ� ��� ����]
[�Է� ��]
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
���
#testcase1
10200
#testcase2
71280

*/