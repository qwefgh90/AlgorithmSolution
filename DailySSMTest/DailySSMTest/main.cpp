#include <stdio.h>
#include <stdlib.h>
#define MAX 9
int main(){
	
	int testCount = 0;
	int dan = 0;
	scanf("%d", &testCount);
	for (int i = 0; i < testCount; i++){
		printf("#testcase%d\n", i + 1);
		scanf("%d", &dan);
		for (int i = 0; i < MAX; i++){
			printf("%d * %d = %d\n", dan, i + 1, dan*(i + 1));
		}
	}

	return 0;
}