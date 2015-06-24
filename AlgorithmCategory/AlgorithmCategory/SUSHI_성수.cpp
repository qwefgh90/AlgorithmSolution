
/*
https://algospot.com/judge/problem/read/SUSHI
문제 풀이 내기에서 모인 벌금이 많이 쌓여서 알고스팟 운영진들은 회식을 하러 회전초밥집에 갔습니다. 회전초밥집에 들어선 운영진들은 초밥은 먹지 않고 전략 회의를 시작했습니다. 회전초밥집에는 n종류의 메뉴가 있는데, 운영진들은 각 메뉴에 대해 선호도를 매겼습니다.

초밥	계란	연어	장어	대뱃살	스테이크	후라이드 치킨
가격	2500	3000	4000	5000	10000	15000
선호도	7	9	10	12	20	1
운영진들은 주어진 예산 안에서 선호도의 합을 최대한으로 하도록 초밥을 먹고 싶습니다. 각 종류의 초밥은 무한정으로 공급된다고 가정합시다. 이 때 얻을 수 있는 최대한의 선호도는 얼마일까요?

입력

입력의 첫 줄에는 테스트 케이스의 수 c(1 <= c <= 50)가 주어집니다. 각 테스트 케이스의 첫 줄에는 초밥의 종류 n(1 <= n <= 20)과 운영진들의 예산 m (1 <= m <= 2,147,483,647)이 주어집니다. 그 후 n 줄에 각 초밥의 가격과 선호도가 순서대로 주어집니다. 가격은 20,000 이하의 자연수로, 항상 100 의 배수입니다. 선호도는 20 이하의 자연수입니다.
*/
//struct 

#include <iostream>
#include <string>
//#include <fstream>
#include <algorithm>
using namespace std;
int n, m;
int food[21][2];   //0은 가격, 1은 선호도

int cache[201];      //최고 선호도

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
면접관과 상의할 것
*/

