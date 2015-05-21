#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
/*
코딩인터뷰 완전분석
10.1
정렬된 배열 A와 B가 주어진다. A의 끝에는 B를 수용하기 충분한 여유 공간이 있다. B와 A를 정렬된 상태로 병합하는 메서드를 작성하라
*/

//추가 버퍼를 사용하고 안하고에 따라 시간복잡도 차이가 있다.
//추가 버퍼 없이 개발
int main(){
	int testcase;
	ifstream is("cracking_정렬된배열병합.txt");

	is >> testcase;

	for (int i = 0; i < testcase; i++){
		int sizeA;
		int sizeB;
		is >> sizeA >> sizeB;
		int a[1000] = { 0, };
		int b[1000] = { 0, };
		for (int i = 0; i < sizeA; i++){
			is >> a[i];
		}
		for (int i = 0; i < sizeB; i++){
			is >> b[i];
		}

		int j = 0;	//a 인덱스
		int sizeAoffset = 0;	//A의 길이의 증가 오프셋

		//B를 A에 삽입하는 알고리즘 (mn 알고리즘)
		for (int i = 0; i < sizeB; i++){
			
			//삽입할 위치를 찾는 알고리즘
			for (; j < sizeA + sizeAoffset; j++){
				if (b[i] < a[j]){
					memmove(a + j + 1, a + j, sizeof(int)*((sizeB + sizeAoffset) - (j)));
					a[j] = b[i];
					sizeAoffset++;
					j++;//인덱스 하나 증가
					break;
				}
			}

			//나머지 데이터는 뒤에 삽입
			if (j >= sizeA + sizeAoffset){
				a[j++] = b[i++];
			}
		}



		for (int i = 0; i < sizeA + sizeB; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
면접관과 상의할 것
1) 추가 버퍼를 사용해도 되겠습니까?
2) 정렬된 데이터의 종류는 무엇입니까?

*/

