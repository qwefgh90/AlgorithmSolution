//���� ���� �����鼭 �ڿ� �ִ� ���� ã�ƶ�
//���� 0�̰ų� ���� 1 �������� 0 �̸�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
int main(){
	int numCount=0;
	scanf("%d",&numCount);
	for(int i=0; i<numCount;i++){
		int min=0;
		int minindex = 0;
		int stunumber = 0;
		int giftnumber = 0;
		int wantCount = 0;
		int up=0;
		int bonus=0;
		scanf("%d %d",&stunumber,&giftnumber);
		int stuIndex=1;
		for(int i =0; i<stunumber; i++){
			scanf("%d" ,&wantCount);
			up = (wantCount/giftnumber);
			bonus = wantCount%giftnumber;
			if(bonus==0){
				up += -1;
			}
			if(min<=up){
				min = up;
				minindex = stuIndex;
			}
			stuIndex++;
		}
		printf("%d\n",minindex);
	}
	return 0;
}