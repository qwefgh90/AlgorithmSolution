#include <stdio.h>
#include <string.h>
int main(){
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		char input[10000] = { 0, };
		char assci_table[1000] = { 0, };
		memset(assci_table, 0, 1000);
		
		scanf("%s", input);
		int length = strlen(input);
		int duplicateFlag = 0;
		for (int j = 0; j < length; j++){
			if (assci_table[input[j]] == 1){
				duplicateFlag = 1;
				break;
			}
			else{
				assci_table[input[j]] = 1;
			}
		}

		if (duplicateFlag)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}

/*
문제지
문제	유일 문자 판정	문제코드	4-L-01
내용	문자열에 포함된 문자들이 전부 유일한지를 검사하는 알고리즘을 구현하라.
배열 외 다른 자료구조는 사용 할 수 없는 상황이라면 어떻게 하겠는가?
입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
이후 입력 문자열 S가 주어진다. (ASCII만 사용)
출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
유일한 문자로 구성된 문자열이라면 Yes 아니라면 No 출력
예시	입력	출력
2
ZxcvaSsd1234
CatdogsoftwareSamsung
#testcase1
Yes
#testcase2
No

*/