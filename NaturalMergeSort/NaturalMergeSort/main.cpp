#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


struct runArray{
	int offset;
	int arrsize;
	int* array;
	runArray(){
		offset = 0;
		arrsize = 0;
		array = NULL;
	}
};

void naturalMerge(int* data, int startoff, int endoff);
void mergeSort(int* data, int startoff, int middleoff, int endoff);
void makeRunarr(runArray &runarr, int* data, int size);
int main(){

	int data[1000] = {3,4,11,8,9,10,1,2};
	
	naturalMerge(data, 0, 7);
	
	return 0;
}

void naturalMerge(int* data, int startoff, int endoff){
	runArray runarr;
	runarr.array = (int*)malloc((endoff - startoff + 1)* sizeof(int));
	makeRunarr(runarr, data, endoff - startoff +1);
	
	runArray temprunarr;
	temprunarr.array = (int*)malloc((endoff - startoff + 1)* sizeof(int));
	////////////////////RUN 배열 병합/////////////////
	int arrsize = runarr.arrsize / 2;

	////////////실제로 for문 arrsize 와 i 를 강제로 바꾸는 코드가 삽입되있음. 
	////////////다시 구현할 필요가 있음
	for (int i = 0; i < arrsize; i++){
		if (i + 1 == arrsize && runarr.arrsize % 2 != 1){
			mergeSort(data, runarr.array[i * 2], runarr.array[i * 2 + 1], endoff);	//endoffset 이 run 배열에 없을 경우 (개수가 홀수 일 경우)
		}
		else{
			mergeSort(data, runarr.array[i * 2], runarr.array[i * 2 + 1], runarr.array[i * 2 + 2] - 1);
		}

		temprunarr.array[temprunarr.offset++] = runarr.array[i*2]; //새로운 run 생성

		if (i + 1 == arrsize){

			if (runarr.arrsize % 2 == 1){
				temprunarr.array[temprunarr.offset++] = runarr.array[(i+1)*2];
			}

			temprunarr.arrsize = temprunarr.offset;

			memcpy(runarr.array, temprunarr.array, temprunarr.arrsize*sizeof(int));
			runarr.arrsize = temprunarr.arrsize;

			temprunarr.arrsize = 0;//초기화
			temprunarr.offset = 0;// 초기화

			arrsize = runarr.arrsize / 2; i = -1;// 새로운 반복문 크기
		}
	}
}

void makeRunarr(runArray &runarr, int* data, int  size){
	//작으면 넣고 다시 돌림
	//startoff를 저장하는 변수 필요
	int runstartoff = 0;
	runarr.array[runarr.offset] = 0;
	runarr.offset++;

	for (int i = 0; i < size - 1; i++){
		if (data[i] > data[i + 1]){
			runarr.array[runarr.offset] = i+1;
			runarr.offset++;
		}
	}
	runarr.arrsize = runarr.offset;
}

//data, 0, 1, 2
void mergeSort(int* data, int startoff, int middleoff, int endoff){
	int* tempbuffer = (int*)malloc((endoff - startoff + 1)*sizeof(int));//임시 버퍼
	int tempbufferindex = 0;
	int localstartoff = startoff;
	int localmiddleoff = middleoff;

	while ((localstartoff <= middleoff - 1) && (localmiddleoff <= endoff)){
		if (data[localstartoff] > data[localmiddleoff]){
			tempbuffer[tempbufferindex] = data[localmiddleoff];
			localmiddleoff++;
		}
		else{
			tempbuffer[tempbufferindex] = data[localstartoff];
			localstartoff++;
		}
		tempbufferindex++;
	}

	while (localstartoff <= middleoff-1){
		tempbuffer[tempbufferindex] = data[localstartoff];
		localstartoff++; tempbufferindex++;
	}
	while (localmiddleoff <= endoff){
		tempbuffer[tempbufferindex] = data[localmiddleoff];
		localmiddleoff++; tempbufferindex++;
	}
	
	memcpy(data + startoff, tempbuffer,( endoff - startoff + 1)*sizeof(int));

	return;
}

