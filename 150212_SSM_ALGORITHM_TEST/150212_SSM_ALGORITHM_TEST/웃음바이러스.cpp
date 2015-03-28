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

//테이블 가로/ 세로, 테이블, 방문 테이블, 폭탄 투하(감염)지점, 흐른시간
void updateValue(int width, int height, int(*table)[101], bool(*visit)[101], int x, int y, int time){
	//너비를 초과할 경우


	//너비 우선 탐색 필요
	//큐에 넣어도 되는 값인지 체크 (0인지 유효한지)
	int tempx = x + 1;//
	int tempy = y;
	if (!(width < tempx || tempx == 0 || tempy == 0 || height < tempy || table[tempy][tempx] == 0))
		push(tempx, tempy, time);	//이전 아이의 값
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

		//이미 방문했으면 안 방문	
		if (visit[y][x] == true)
			continue;
		else
			visit[y][x] = true;

		//시간 최대값 교체
		int tempt = node.time + 1;
		if (maxValue < tempt){
			maxValue = tempt;
		}

		//큐에 추가
		int tempx = x + 1;//
		int tempy = y;
		if (!(width < tempx || tempx == 0 || tempy == 0 || height < tempy || table[tempy][tempx] == 0))
			push(tempx, tempy, tempt);	//이전 아이의 값
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
		int table[101][101] = { 0, };	//실제 좌표를 사용한다.(1 부터 시작)
		bool visit[101][101] = { false, };	//방문 여부
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
		int x, y; // 1부터 시작
		scanf("%d %d", &x, &y);

		updateValue(width, height, table, visit, x, y, 0);//0초 부터 시작

		printf("%d\n", maxValue+1);//최대값

	}
}

/*

어느 도서관에서 게릴라들이 웃음 폭탄을 떨어뜨렸습니다. 이 폭탄 내 바이러스에 노출되면 평생 웃어야 하는 무서운 바이러스입니다. 이 폭탄은 폭탄 주위에 있는 네 사람(상,하,좌,우)을 1초동안에 바이러스에 감염시키며, 다시 1초가 지나면 감염된 사람 주위에 있는 네 사람을 다시 바이러스에 감염시킵니다. 그러나 인접해있는 네 방향이 아니면 웃음 바이러스에 감염되지 않습니다. 아래 [그림1]은 폭탄이 떨어진 위치와 사람들의 위치를 나타낸 것이고, [그림2]는 바이러스가 퍼져나가는 모습을 1초 단위로 나타낸 것으로서 도서관 전체 학생이 감염되는데 8초가 걸립니다.

O	O
O	O	O	O		O
O		O	O	O
O	O	O	O		O
●		O	O
O	O	O	O
O		O	O	O
O
[그림 1]

위의 그림을 보면 7 X 8 크기의 맵에 ( 3 , 5 )지점에 폭탄이 떨어졌습니다.
아래 그림은 폭탄으로 인한 바이러스 확산을 보여줍니다.

5	6
6	5	4	5		7
3		5	6	7
3	2	3	4		8
1		5	6
3	2	3	4
3		5	6	7
6
[그림2]

문제는 빠르게 퍼져나가는 웃음 바이러스 감염을 막기 위해 도서관이 마지막으로 감염되는 시간이 얼마인지 계산하는 것 입니다.

[입력]
입력에는 여러 테스트 케이스가 포함될 수 있다. 입력의 첫째 줄에는 테스트 케이스의 수 T가 주어지고, 이후 차례로 T개의 테스트 케이스가 주어진다 (T ≤ 30)
각 테스트 케이스의 첫 줄에 도시의 가로와 세로 N, M이 공백으로 분리되어 주어진다. (1 ≤ N, M ≤ 100)
두 번째 줄부터 N개의 줄에 걸쳐 도서관 안의 상황이 공백으로 분리되어 주어진다. 1은 사람이 있다는 것이고, 0은 사람이 없다는 것이다.
마지막 줄에는 생화학 웃음 폭탄이 떨어지는 곳의 가로와 세로 좌표가 공백으로 분리되어 주어진다.

[출력]
각 테스트 케이스의 첫 줄에 감염될 수 있는 사람이 모두 감염될 때까지 몇 초가 걸리는지를 출력한다. (중요! 테스트 케이스 개수마다 #testcase번호를 출력 후 정답 출력)

[STL사용 불가]

[입출력 예]

입력
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

출력
#testcase1
8
#testcase2
21
*/