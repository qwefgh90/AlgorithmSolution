#include <stdio.h>

int maxValue = 0;

struct Node{
	int x;
	int y;
	int time;
	Node(){
		x = 0;
		y = 0;
		time = 0;
	}

};
int startoff = 0;
int qsize = 0;
Node queue[10000];

void push(int x, int y, int time){
	Node node;
	node.x = x;
	node.y = y;
	node.time = time;

	queue[qsize++] = node;
}
bool pop(Node& node){
	if (startoff == qsize){
		return false;
	}
	node = queue[startoff++];
	return true;
}

//���̺� ����/ ����, ���̺�, �湮 ���̺�, ��ź ����(����)����, �帥�ð�
void updateValue(int width, int height, int(*table)[101], bool(*visit)[101], int x, int y, int time){
	//�ʺ� �ʰ��� ���


	//�ʺ� �켱 Ž�� �ʿ�
	//ť�� �־ �Ǵ� ������ üũ (0���� ��ȿ����)
	int tempx = x + 1;//
	int tempy = y;
	if (!(width < tempx || tempx == 0 || tempy == 0 || height < tempy || table[tempy][tempx] == 0))
		push(tempx, tempy, time);	//���� ������ ��
	tempx = x - 1;//
	tempy = y;
	if (!(width < tempx || tempx == 0 || tempy == 0 || height < tempy || table[tempy][tempx] == 0))
		push(tempx, tempy, time);
	tempx = x;
	tempy = y + 1;//
	if (!(width < tempx || tempx == 0 || tempy == 0 || height < tempy || table[tempy][tempx] == 0))
		push(tempx, tempy, time);
	tempx = x;
	tempy = y - 1;//
	if (!(width < tempx || tempx == 0 || tempy == 0 || height < tempy || table[tempy][tempx] == 0))
		push(tempx, tempy, time);

	Node node;
	while (pop(node) == true){
		int x = node.x;
		int y = node.y;

		//�̹� �湮������ �� �湮	
		if (visit[y][x] == true)
			continue;
		else
			visit[y][x] = true;

		//�ð� �ִ밪 ��ü
		int tempt = node.time + 1;
		if (maxValue < tempt){
			maxValue = tempt;
		}

		//ť�� �߰�
		int tempx = x + 1;//
		int tempy = y;
		if (!(width < tempx || tempx == 0 || tempy == 0 || height < tempy || table[tempy][tempx] == 0))
			push(tempx, tempy, tempt);	//���� ������ ��
		tempx = x - 1;//
		tempy = y;
		if (!(width < tempx || tempx == 0 || tempy == 0 || height < tempy || table[tempy][tempx] == 0))
			push(tempx, tempy, tempt);
		tempx = x;
		tempy = y + 1;//
		if (!(width < tempx || tempx == 0 || tempy == 0 || height < tempy || table[tempy][tempx] == 0))
			push(tempx, tempy, tempt);
		tempx = x;
		tempy = y - 1;//
		if (!(width < tempx || tempx == 0 || tempy == 0 || height < tempy || table[tempy][tempx] == 0))
			push(tempx, tempy, tempt);
	}
	//updateValue(width, height, table, visit, x + 1, y, time);
	//updateValue(width, height, table, visit, x - 1, y, time);
	//updateValue(width, height, table, visit, x, y + 1, time);
	//updateValue(width, height, table, visit, x, y - 1, time);

}

int main(){
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++){
		int table[101][101] = { 0, };	//���� ��ǥ�� ����Ѵ�.(1 ���� ����)
		bool visit[101][101] = { false, };	//�湮 ����
		maxValue = 0;
		printf("#testcase%d\n", i + 1);
		int width;
		int height;
		scanf("%d %d", &width, &height);
		int startY = 1;
		int startX = 1;
		for (startY = 1; startY <= height; startY++){
			for (startX = 1; startX <= width; startX++){
				scanf("%d", &table[startY][startX]);
			}
		}
		int x, y; // 1���� ����
		scanf("%d %d", &x, &y);

		updateValue(width, height, table, visit, x, y, 0);//0�� ���� ����

		printf("%d\n", maxValue+1);//�ִ밪

	}
}

/*

��� ���������� �Ը������ ���� ��ź�� ����߷Ƚ��ϴ�. �� ��ź �� ���̷����� ����Ǹ� ��� ����� �ϴ� ������ ���̷����Դϴ�. �� ��ź�� ��ź ������ �ִ� �� ���(��,��,��,��)�� 1�ʵ��ȿ� ���̷����� ������Ű��, �ٽ� 1�ʰ� ������ ������ ��� ������ �ִ� �� ����� �ٽ� ���̷����� ������ŵ�ϴ�. �׷��� �������ִ� �� ������ �ƴϸ� ���� ���̷����� �������� �ʽ��ϴ�. �Ʒ� [�׸�1]�� ��ź�� ������ ��ġ�� ������� ��ġ�� ��Ÿ�� ���̰�, [�׸�2]�� ���̷����� ���������� ����� 1�� ������ ��Ÿ�� �����μ� ������ ��ü �л��� �����Ǵµ� 8�ʰ� �ɸ��ϴ�.

O	O
O	O	O	O		O
O		O	O	O
O	O	O	O		O
��		O	O
O	O	O	O
O		O	O	O
O
[�׸� 1]

���� �׸��� ���� 7 X 8 ũ���� �ʿ� ( 3 , 5 )������ ��ź�� ���������ϴ�.
�Ʒ� �׸��� ��ź���� ���� ���̷��� Ȯ���� �����ݴϴ�.

5	6
6	5	4	5		7
3		5	6	7
3	2	3	4		8
1		5	6
3	2	3	4
3		5	6	7
6
[�׸�2]

������ ������ ���������� ���� ���̷��� ������ ���� ���� �������� ���������� �����Ǵ� �ð��� ������ ����ϴ� �� �Դϴ�.

[�Է�]
�Է¿��� ���� �׽�Ʈ ���̽��� ���Ե� �� �ִ�. �Է��� ù° �ٿ��� �׽�Ʈ ���̽��� �� T�� �־�����, ���� ���ʷ� T���� �׽�Ʈ ���̽��� �־����� (T �� 30)
�� �׽�Ʈ ���̽��� ù �ٿ� ������ ���ο� ���� N, M�� �������� �и��Ǿ� �־�����. (1 �� N, M �� 100)
�� ��° �ٺ��� N���� �ٿ� ���� ������ ���� ��Ȳ�� �������� �и��Ǿ� �־�����. 1�� ����� �ִٴ� ���̰�, 0�� ����� ���ٴ� ���̴�.
������ �ٿ��� ��ȭ�� ���� ��ź�� �������� ���� ���ο� ���� ��ǥ�� �������� �и��Ǿ� �־�����.

[���]
�� �׽�Ʈ ���̽��� ù �ٿ� ������ �� �ִ� ����� ��� ������ ������ �� �ʰ� �ɸ������� ����Ѵ�. (�߿�! �׽�Ʈ ���̽� �������� #testcase��ȣ�� ��� �� ���� ���)

[STL��� �Ұ�]

[����� ��]

�Է�
2
7 8
0 0 1 1 0 0 0
1 1 1 1 0 1 0
0 0 1 0 1 1 1
0 1 1 1 1 0 1
0 0 1 0 1 1 0
0 1 1 1 1 0 0
0 0 1 0 1 1 1
0 0 0 0 1 0 0
3 5
10 10
1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 1 0 1 1 0
0 0 1 1 0 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 1 0 1 0 1 1 1 1 0
0 0 0 0 0 1 1 0 0 0
1 0 1 0 1 0 1 1 0 0
0 0 1 1 1 1 1 1 1 1
1 0 1 0 0 1 0 1 1 0
1 1 1 0 0 0 0 1 1 1
2 2

���
#testcase1
8
#testcase2
21
*/