//Full Binary Tree
//�׷��� Ʈ�� ��ȯ ����
//Small Input ����

//1)�� ��带 Root�� �����ϰ� �ڽ��� 0���� ��� Full Binary Tree �̰�
//�ڽ��� 1�� �� ��� �ڽ��� �����߸� Full Binary Tree
//�ڽ��� 2�� �̻��� ��� �ڽ��� 2���� �����ؼ� �������� ����� ������� Full Binary Tree�� �����.
//��) �� ��忡 (Full Binary Tree�� ���� ������, ��ü ���� ��� ����) ���� ������ ���´�.
//2)(�κ� ����)(��� ��)�ٽ� �ڽ� ��带 Root�� �����ϰ� ���� ī��Ʈ�� ����� �� ������ Table�� �����Ѵ�.

//3)�ڽ� ��尡 0���� ��� (0, 1) ���� ī��Ʈ(�ڱⰡ root�� ���������� Full Binary�� �Ǳ�����) = 0, ����� �� ����(�ڽ��� ������) 1
//4)�ڽ� ����� ������ 1�� �� ��� (�ڽ� ��� �� ����, �ڽĳ�� �� ���� + 1) 
//5)�ڽĳ�尡 2�� �̻��� ��� (min(�ڽ� ��� �� 2���� ���� ���� + ������ �� ��� ����), ��� �ڽĳ�� �� ���� + 1);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1100

class Edge{
public:
	int from;
	int to;
	Edge* next;
	Edge(){
		next = NULL;
	}
};
class Vert{
public:
	int index;
	int edgeCount;
	Edge* edge;
	Vert(){
		index = -1;
		edgeCount = 0;
		edge = NULL;
	}
	void addEdge(Edge* e){
		if (edge == NULL)
			edge = e;
		else{
			e->next = edge;
			edge = e;
		}
		edgeCount++;
	}
};
class Graph{
public:
	Vert v[MAX];
};

//parent�� ��� ���� ���� �� ����
//���̺� 
class TableItem{
	public:
	//int parent;
	//int rootIndex;
	int needDeleteVertCount;
	int totalVertCount;
	bool use;
	TableItem(){
		use = false;
		needDeleteVertCount = 0;
		totalVertCount = 0;
	}
};

void memorize(Vert* vert, int rootIndex, int parent, TableItem(*table)[MAX]);

TableItem getMemorize(Vert* vert, int rootIndex, int parent, TableItem(*table)[MAX]){
	TableItem item = table[rootIndex][parent];
	if (item.use == false){
		memorize(vert, rootIndex, parent, table);	//���̺� ������ ã�´�.
		item = table[rootIndex][parent];
	}
	return item;
}

int minimize(TableItem* item, int itemCount){
	//���� ���� ^ 3�� �ð� ���⵵�� �ּ� Ž��
	int min = 9999999;
	for (int i = 0; i < itemCount - 1; i++){

		for (int j = 1; j < itemCount; j++){
			int temp = 0;
			temp += item[i].needDeleteVertCount;
			temp += item[j].needDeleteVertCount;
			for (int k = 0; k < itemCount; k++){
				if (k != i && k != j){
					temp += item[k].totalVertCount;
				}
			}
			if (min > temp){
				min = temp;
			}
		}
	}
	return min;
}

void memorize(Vert* vert, int rootIndex, int parent, TableItem(*table)[MAX]){
	int exceptVertCount = vert[rootIndex].edgeCount - 1;
	int needDeleteVertCount = 0;
	int totalVertCount = 0;
	if (exceptVertCount == 0){
		needDeleteVertCount = 0;
		totalVertCount = 1;
	}
	else if (exceptVertCount == 1){
		Edge* e = vert[rootIndex].edge;
		while (e != NULL){
			int to = e->to;
			if (to != parent){
				TableItem item = getMemorize(vert, e->to, rootIndex, table);
				needDeleteVertCount = item.totalVertCount;
				totalVertCount = item.totalVertCount + 1;
			}
			e = e->next;
		}
	}
	else if (exceptVertCount >= 2){
		TableItem usedForMinimize[MAX];
		int usedCount = 0;
		Edge* e = vert[rootIndex].edge;
		while (e != NULL){
			int to = e->to;
			if (to != parent){
				TableItem item = getMemorize(vert, to, rootIndex, table);
				usedForMinimize[usedCount++] = item;

				totalVertCount += item.totalVertCount;	//���� ������ ����
			}
			e = e->next;
		}
		int min = minimize(usedForMinimize, exceptVertCount);
		needDeleteVertCount = min;	//�ּ� ���� ����
		totalVertCount += 1;	//�ڱ��ڽ� ����
	}
	//���̺� ��� ����
	TableItem newItem;
	//newItem.parent = parent;
	//newItem.rootIndex = rootIndex;
	newItem.needDeleteVertCount = needDeleteVertCount;
	newItem.totalVertCount = totalVertCount;

	//���̺� ��� ����
	table[rootIndex][parent] = newItem;
}

int getDeleteCount(Vert* vert, TableItem(*table)[MAX], int rootIndex){
	Edge* temp = vert[rootIndex].edge;
	TableItem usedForMinimize[MAX];
	int usedCount = 0;
	while (temp != NULL){
		TableItem item = getMemorize(vert, temp->to, rootIndex, table);
		usedForMinimize[usedCount++] = item;
		temp = temp->next;
	}
	if (usedCount == 1)
		return usedForMinimize[0].totalVertCount;
	int min = minimize(usedForMinimize, vert[rootIndex].edgeCount);
	return min;
}

TableItem table[MAX][MAX];
int main(){
	FILE* input = fopen("FullBinaryTreeSmallInput.txt", "r");
	FILE* output = fopen("output.txt", "w");
	int testcase;
	fscanf(input,"%d", &testcase);
	for (int i = 0; i <testcase; i++){
		memset(table, 0, MAX*MAX*sizeof(TableItem));
		
		int vertCount;
		fscanf(input,"%d", &vertCount);
		Edge edgePool[MAX * 3];
		int poolCount = 0;

		Graph g;
		int from;
		int to;
		for (int j = 0; j < vertCount - 1; j++){
			fscanf(input,"%d %d", &from, &to);
			Edge* e1 = &edgePool[poolCount++];
			e1->from = from;
			e1->to = to;
			Edge* e2 = &edgePool[poolCount++];
			e2->from = to;
			e2->to = from;
			g.v[from].addEdge(e1);
			g.v[to].addEdge(e2);	//Edge �߰�
			/*if (j == 500)
				printf("500");*/
		}
		int min = 999999999;
		for (int j = 1; j <= vertCount; j++){
			int result = getDeleteCount(g.v, table, j);
			if (min > result)
				min = result;
		}
		fprintf(output,"Case #%d: %d\n", i + 1, min);

	}
	return 0;
}
/*
roblem B. Full Binary Tree
This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
Small input
9 points
Solve B-small
Large input
21 points
Solve B-large
Problem

A tree is a connected graph with no cycles.

A rooted tree is a tree in which one special vertex is called the root. If there is an edge between X and Y in a rooted tree, we say that Y is a child of X if X is closer to the root than Y (in other words, the shortest path from the root to X is shorter than the shortest path from the root to Y).

A full binary tree is a rooted tree where every node has either exactly 2 children or 0 children.

You are given a tree G with N nodes (numbered from 1 to N). You are allowed to delete some of the nodes. When a node is deleted, the edges connected to the deleted node are also deleted. Your task is to delete as few nodes as possible so that the remaining nodes form a full binary tree for some choice of the root from the remaining nodes.

Input

The first line of the input gives the number of test cases, T. T test cases follow. The first line of each test case contains a single integer N, the number of nodes in the tree. The following N-1 lines each one will contain two space-separated integers: Xi Yi, indicating that G contains an undirected edge between Xi and Yi.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the minimum number of nodes to delete from G to make a full binary tree.

Limits

1 �� T �� 100.
1 �� Xi, Yi �� N
Each test case will form a valid connected tree.

Small dataset

2 �� N �� 15.
Large dataset

2 �� N �� 1000.
Sample


Input

Output

3
3
2 1
1 3
7
4 5
4 2
1 2
3 1
6 4
3 7
4
1 2
2 3
3 4

Case #1: 0
Case #2: 2
Case #3: 1

In the first case, G is already a full binary tree (if we consider node 1 as the root), so we don't need to do anything.

In the second case, we may delete nodes 3 and 7; then 2 can be the root of a full binary tree.

In the third case, we may delete node 1; then 3 will become the root of a full binary tree (we could also have deleted node 4; then we could have made 2 the root).
*/