#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
//#include <hash_map>
//using namespace std;
struct Node{
	char key;
	int value;
};
struct List{
	int count;
	Node node[255];
};


//key-value
int getValue(List& list,char key){
	for(int i =0; i<=list.count;i++){
		if(list.node[i].key == key){
			return list.node[i].value;
		}
	}
}

int getMaxFromResult(int* result,int width){
	int max=(-2147483647 - 1);//INT_MIN
	for (int i=0; i < width; i++){
		if(max<result[i]){
			max = result[i];	
		}
	}
	return max;
}

//입력 개수와 몇번째인지에 따라
//에 따른 배열 인덱스 출력
int getIndex(int width, int charCount, int startOffset){
	//너비가 7이고 문자의 개수가 3개일때 offset이 0일때 (7-(3*2-1))/2 + 0;
	return (width - (charCount*2-1))/2 + startOffset*2;
}

int main(){
	//케이스 크기 1~20
	//1~255 원소표
	//1~30 너비 (결과 int 배열)
	int testCase=0;
	char tempStr[1000]={0,};
		//hash_map<char,int> table;
	scanf("%d",&testCase);
	while(testCase--){
		//table.clear();
		int tablesize=0;
		int width=0;
		scanf("%d %d",&tablesize,&width);	//가장 긴 너비를 입력받음
		//printf("meta %d %d",tablesize,width);
		int result[100000]={0,};//결과배열

		//memset(result,-2^31,30);
		List list;
		list.count=-1;
		
		/*if(width>5){	//
			printf("1\n");
			continue;
		}*/
		//테이블 구성
		//rewind(stdin);
			getchar();
		while(tablesize--){
			Node node;
			scanf("%c %d",&(node.key),&(node.value));
			list.node[++(list.count)] = node;
			//pair<char,int> d(node.key,node.value);
			//table.insert(d);
			//int f = table.find(node.key)->second;
			//rewind(stdin);
		getchar();
		}
		int inputCount = width*2 -1;
		int inputCount_ab  = inputCount;

		//너비
		//rewind(stdin);
		
		//getchar();
		while(inputCount--){
			scanf("%[^\n]s",tempStr);
			
		//	rewind(stdin);
			getchar();
			/*
			if(width>5){	//혜
				continue;
			}
			*/

			char tempArray[255]={0,};
			int tempCount = 0;
			char* ptr = NULL;
			int charCount = 0;	//문자 개수
			if(ptr = strtok(tempStr," ")){//여러개
				charCount++;
				tempArray[tempCount++] = ptr[0];
				while(ptr = strtok(NULL," ")){
					charCount++;
					tempArray[tempCount++] = ptr[0];
				}
			}else{
				charCount = 1;	//1개만 들어올 수 있음.
				tempArray[tempCount++] = tempStr[0]; //단 1개
			}
			int value = 0;
			int resultIndex  = 0;
			//실제 결과 배열에 저장하는 작업
			for (int j =0; j< charCount; j ++){
				int value = getValue(list,tempArray[j]);
				//value = table.find(tempArray[j])->second;
				resultIndex = getIndex(inputCount_ab,charCount,j);
				//printf("resultIndex : %d key :%c resultValue : %d",resultIndex,tempArray[j],value);
				result[resultIndex] += value;
			}
		}/*
		if(width>5){	//혜
			printf("1\n");
				continue;
			}*/
		printf("%d\n",getMaxFromResult(result,inputCount_ab));
	}
	return 0;
}