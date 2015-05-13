#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <iostream>


int main(){
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int n;
		int k;
		scanf("%d %d", &n, &k);
		int cnt = 0;
		int flag = 0;
		int n2 = n / 2;
		int sqrtv = sqrtl(n);

		char m[100] = { 0, };

		
		for (int i = 1; i <= sqrtv; i++){
			if (n%i == 0){
				cnt++;
				if (cnt == k){
					printf("%d\n", i);
					flag = 1;
					break;
				}
			}
		}
		
		if (cnt == 1 && flag == 0){
			printf("0\n");
			continue;
		}

		for (int i = sqrtv+1; i <= n2; i++){
			if (n%i == 0){
				cnt++;
				if (cnt == k){
					printf("%d\n", i);
					flag = 1;
					break;
				}
			}
			if (i == n2){
				cnt++;
				if (cnt == k){
					flag = 1;
					printf("%d\n", n);
					break;
				}
			}
		}
		if (flag == 0){
			printf("0\n");
		}

	}
	return 0;
}