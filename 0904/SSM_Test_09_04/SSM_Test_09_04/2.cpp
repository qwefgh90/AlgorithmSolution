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

//�Է� ������ ���°������ ����
//�� ���� �迭 �ε��� ���
int getIndex(int width, int charCount, int startOffset){
	//�ʺ� 7�̰� ������ ������ 3���϶� offset�� 0�϶� (7-(3*2-1))/2 + 0;
	return (width - (charCount*2-1))/2 + startOffset*2;
}

int main(){
	//���̽� ũ�� 1~20
	//1~255 ����ǥ
	//1~30 �ʺ� (��� int �迭)
	int testCase=0;
	char tempStr[1000]={0,};
		//hash_map<char,int> table;
	scanf("%d",&testCase);
	while(testCase--){
		//table.clear();
		int tablesize=0;
		int width=0;
		scanf("%d %d",&tablesize,&width);	//���� �� �ʺ� �Է¹���
		//printf("meta %d %d",tablesize,width);
		int result[100000]={0,};//����迭

		//memset(result,-2^31,30);
		List list;
		list.count=-1;
		
		/*if(width>5){	//
			printf("1\n");
			continue;
		}*/
		//���̺� ����
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

		//�ʺ�
		//rewind(stdin);
		
		//getchar();
		while(inputCount--){
			scanf("%[^\n]s",tempStr);
			
		//	rewind(stdin);
			getchar();
			/*
			if(width>5){	//��
				continue;
			}
			*/

			char tempArray[255]={0,};
			int tempCount = 0;
			char* ptr = NULL;
			int charCount = 0;	//���� ����
			if(ptr = strtok(tempStr," ")){//������
				charCount++;
				tempArray[tempCount++] = ptr[0];
				while(ptr = strtok(NULL," ")){
					charCount++;
					tempArray[tempCount++] = ptr[0];
				}
			}else{
				charCount = 1;	//1���� ���� �� ����.
				tempArray[tempCount++] = tempStr[0]; //�� 1��
			}
			int value = 0;
			int resultIndex  = 0;
			//���� ��� �迭�� �����ϴ� �۾�
			for (int j =0; j< charCount; j ++){
				int value = getValue(list,tempArray[j]);
				//value = table.find(tempArray[j])->second;
				resultIndex = getIndex(inputCount_ab,charCount,j);
				//printf("resultIndex : %d key :%c resultValue : %d",resultIndex,tempArray[j],value);
				result[resultIndex] += value;
			}
		}/*
		if(width>5){	//��
			printf("1\n");
				continue;
			}*/
		printf("%d\n",getMaxFromResult(result,inputCount_ab));
	}
	return 0;
}