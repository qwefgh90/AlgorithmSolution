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
int main(){
	int testcase;
	wifstream is("cracking_유일성검사.txt");
	is.imbue(locale("korean"));	//알아서 multibyte를 unicode로 바꿔줌
	
	is >> testcase;
	is.get();
	
	for(int i = 0; i < testcase; i++){
		wstring str1;
		
		bool input[1 << 16] = { false, };
		getline(is, str1);

		for (int i = 0; i < str1.size(); i++){
			wchar_t target = str1[i];
			if (input[target] == false){
				input[target] = true;
			}
			else{
				cout << "중복존재" << endl;
				break;
			}
			if (i == str1.size() - 1)
				cout << "유일문자" << endl;
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

