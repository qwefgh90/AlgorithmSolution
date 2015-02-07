#include <stdio.h>
#include <stdlib.h>
#include <memory>

//세자리 자연수가 있다.이 수의 각 자리의 세제곱의 합이 같은 수를 암스트롱 수라고 한다.
//예를 들어 153 은 1 + 125 + 27 과 같으므로 153은 암스트롱 수이다.
//암스트롱 수를 모두 출력하는 프로그램을 작성하여라.
//
//<보충설명>
//위 문제는 입력 받는 테스트케이스가 없으므로
//주어진 템플릿에서 다음과 같이 출력하고 결과물을 개행으로 구분하여 출력한다.
//cout << "#testcase1" << endl;
#define MAXNUM 10

int getNumber(int x1, int x2, int x3)
{
	return x1 * 100 + x2 * 10 + x3;
}

int main()
{
	int resultCount = 0;
	int result[1000] = { 0, };
	int arr[10] = { 0, };
	for (int i = 0; i < 10; i++){
		arr[i] = i * i * i;
	}

	printf("#testcase1\n");
	for (int x = 1; x < MAXNUM; x++){
		for (int y = 0; y < MAXNUM; y++){
			for (int z = 0; z < MAXNUM; z++){
				int result = getNumber(x, y, z);
				//printf("%d\n", result);
				if (result == arr[x] + arr[y] + arr[z]){
					/*result[resultCount] = result;
					resu*/

					printf("%d\n", result);
					resultCount++;
				}
			}
		}
	}
	
	return 0;
}
