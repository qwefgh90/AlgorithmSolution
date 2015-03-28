#include <stdio.h>

/*
*/

void swap(long long int & a, long long int & b){
	int t = a;
	a = b;
	b = t;
}

//��
int hoffset = 1;	//�����ڸ�
//���� -1����� ������ ����
long long int heap[100000] = { 0, };

void insert(int value){
	int index = hoffset;
	hoffset++;

	heap[index] = value;
	
	if (index == 1){
		return;
	}
	else{	//��ġ ����
		while (1){
			int parent = index / 2;//�θ� �ε���
			if (heap[parent] > heap[index]){
				int t = heap[parent];
				heap[parent] = heap[index];
				heap[index] = t;//����
				index = parent;	//���� �ε��� ����
				if (index == 1){
					break;
				}
			}
			else{
				break;
			}
		}
	}
}

long long int pop(){
	if (hoffset == 1){
		return -1;
	}
	if (hoffset == 2){
		hoffset--;
		return heap[1];
	}
	else{
		int lastindex = hoffset - 1;

		long long int result = heap[1];
		heap[1] = heap[lastindex];
		
		hoffset--;//��ũ�� ����
		
		int top = 1;

		//�� ����
		while (1){
			lastindex = hoffset - 1;
			int leftidx = top * 2;
			int rightidx = top * 2 + 1;
			if ((leftidx <= lastindex) && (rightidx <= lastindex)){	//��ȿ�� �˻�
				//���� �������̶� ����
				if (heap[leftidx] < heap[rightidx] && heap[leftidx] < heap[top]){
					swap(heap[leftidx], heap[top]);
					top = leftidx;
				}
				else if (heap[leftidx] >= heap[rightidx] && heap[rightidx] < heap[top]){
					swap(heap[rightidx], heap[top]);
					top = rightidx;
				}
				else{
					break; //�ٲ� ����� ����
				}
			}
			else if (leftidx <= lastindex && heap[leftidx] < heap[top]){//��ȿ�� �˻�
				//������
				swap(heap[leftidx], heap[top]);
				break;
			}
			/*else if (rightidx <= lastindex){	//�Ұ���
				swap(heap[rightidx], heap[top]);
				top = rightidx;
				break;
			}*/
			else{
				break;	//�ڽ��� �������� ����
			}
		}
		return result;
	}

}

int main(){
	int testcase;

	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int count;		//1<=N<=10000
		int rooms[100000];	
		hoffset = 1;
		long long int roomsize[10000] = { 0, };
		long long int result = 0;
		scanf("%d", &count);
		for (int j = 0; j < count; j++){	//
			scanf("%d", &rooms[j]);	//10 <= s <= 5000
			insert(rooms[j]);
		}
		//sort(rooms, count);
		
		if (hoffset == 2){
			result = heap[hoffset - 1];
		}
		else{
			while (hoffset != 2){
				long long int  a = pop();
				long long int  b = pop();
				long long int  sum = a + b;
				result += sum;
				insert(sum);
			}
		}
		printf("%lld\n", result);
	}
}