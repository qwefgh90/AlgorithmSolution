#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
/*
코딩인터뷰 완전분석
문자열에 포함된 문자들이 전부 유일한지를 검사하는 알고리즘을 구현하라.
다른 자료구조를 사용할 수 없을때는?
*/

//배열을 사용한 풀이, ms949를 모두 처리할 수 있도록

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
	ifstream is("cracking_키몸무게탑쌓기.txt");

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
		
		//키의 가장 작은 무게기준으로 높이를 찾을것 
		for (int k = 0; k < num; k++){
			cout << p[k].height << ", " << p[k].weight << endl;
		}

	}
	return 0;
}

/*
면접관과 상의할 것
1) 다른자료구조라면 배열도 포함하는 것 입니까?
2) 다른 출력 없이 참 / 거짓중 하나만 반환해도 되겠습니까?
3) 아스키 문자만 가지고 있습니까?
*/

