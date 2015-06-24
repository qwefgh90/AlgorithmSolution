#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
/*
�ڵ����ͺ� �����м�
���ڿ��� ���Ե� ���ڵ��� ���� ���������� �˻��ϴ� �˰����� �����϶�.
�ٸ� �ڷᱸ���� ����� �� ��������?
*/

//�迭�� ����� Ǯ��, ms949�� ��� ó���� �� �ֵ���

class People{
public:
	int height;
	int weight;
};
int comparator_height(const void* p1_, const void* p2_){
	People* p1 = (People*)p1_;
	People* p2 = (People*)p2_;
	if (p1->height > p2->height)
		return 1;
	else if (p1->height == p2->height)
		return 0;
	return -1;
}

void insertionSort(People* p, int size){

	for (int i = 1; i < size; i++){
		bool flag = false;
		for (int k = i-1; k >= 0; k--){
			if (p[k].weight > p[i].weight){
				flag = true;
			}
			if (k == 0 && (p[k].weight > p[i].weight)){
				k = -1;
			}

			if (k == -1 || ((p[k].weight < p[i].weight) && flag == true)){
				People temp;
				temp.height = p[i].height;
				temp.weight = p[i].weight;
				memmove(p + k + 2, p + k + 1, sizeof(People) * (i - k - 1));
				p[k + 1] = temp;
				break;
			}


		}
	}
}

int main(){
	int testcase;
	ifstream is("cracking_Ű������ž�ױ�.txt");

	is >> testcase;

	for (int i = 0; i < testcase; i++){
		int num;
		is >> num;
		People p[100];
		for (int k = 0; k < num; k++){
			is >> p[k].height >> p[k].weight;
		}
		qsort(p, num, sizeof(People), comparator_height);
		insertionSort(p, num);
		
		//Ű�� ���� ���� ���Ա������� ���̸� ã���� 
		for (int k = 0; k < num; k++){
			cout << p[k].height << ", " << p[k].weight << endl;
		}

	}
	return 0;
}

/*
�������� ������ ��
1) �ٸ��ڷᱸ����� �迭�� �����ϴ� �� �Դϱ�?
2) �ٸ� ��� ���� �� / ������ �ϳ��� ��ȯ�ص� �ǰڽ��ϱ�?
3) �ƽ�Ű ���ڸ� ������ �ֽ��ϱ�?
*/

