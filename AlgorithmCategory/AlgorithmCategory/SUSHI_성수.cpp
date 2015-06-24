
/*
https://algospot.com/judge/problem/read/SUSHI
���� Ǯ�� ���⿡�� ���� ������ ���� �׿��� �˰��� ������� ȸ���� �Ϸ� ȸ���ʹ����� �����ϴ�. ȸ���ʹ����� �� ������� �ʹ��� ���� �ʰ� ���� ȸ�Ǹ� �����߽��ϴ�. ȸ���ʹ������� n������ �޴��� �ִµ�, ������� �� �޴��� ���� ��ȣ���� �Ű���ϴ�.

�ʹ�	���	����	���	����	������ũ	�Ķ��̵� ġŲ
����	2500	3000	4000	5000	10000	15000
��ȣ��	7	9	10	12	20	1
������� �־��� ���� �ȿ��� ��ȣ���� ���� �ִ������� �ϵ��� �ʹ��� �԰� �ͽ��ϴ�. �� ������ �ʹ��� ���������� ���޵ȴٰ� �����սô�. �� �� ���� �� �ִ� �ִ����� ��ȣ���� ���ϱ��?

�Է�

�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� c(1 <= c <= 50)�� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� �ʹ��� ���� n(1 <= n <= 20)�� ������� ���� m (1 <= m <= 2,147,483,647)�� �־����ϴ�. �� �� n �ٿ� �� �ʹ��� ���ݰ� ��ȣ���� ������� �־����ϴ�. ������ 20,000 ������ �ڿ�����, �׻� 100 �� ����Դϴ�. ��ȣ���� 20 ������ �ڿ����Դϴ�.
*/
//struct 

#include <iostream>
#include <string>
//#include <fstream>
#include <algorithm>
using namespace std;
int n, m;
int food[21][2];   //0�� ����, 1�� ��ȣ��

int cache[201];      //�ְ� ��ȣ��

//int max(int v1, int v2){
//	if (v1 > v2)
//		return v1;
//	return v2; 
//}


int sushi()
{
	int res = 0;

	for (int money = 1; money <= m; money++)
	{
		int need = 0;
		for (int index = 0; index < n; index++)
		{
			if (money >= food[index][0])
				need = max(need, cache[(money - food[index][0]) % 201] + food[index][1]);
		}
		cache[money % 201] = need;
		res = max(res, need);
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 201; i++){
			cache[i] = 0;
		}
		cin >> n >> m;
		m /= 100;
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			food[i][0] = (tmp / 100);
			cin >> tmp;
			food[i][1] = tmp;
		}

		cout << sushi() << endl;
	}
	return 0;
}

/*
�������� ������ ��
*/

