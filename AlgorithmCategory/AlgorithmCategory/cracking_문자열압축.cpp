#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
/*
코딩인터뷰 완전분석
1.5
같은 문자가 연속으로 반복될 경우 압축해라
aabccccccccaaa
이면 a2b1c8a3로 압축해라. 단 짧아지지 않으면 그대로 반환해라
*/

//배열을 사용한 풀이, ms949를 모두 처리할 수 있도록
int main(){
	int testcase;
	ifstream is("cracking_문자열압축.txt");
	//is.imbue(locale("korean"));	//알아서 multibyte를 unicode로 바꿔줌

	is >> testcase;
	is.get();

	for (int i = 0; i < testcase; i++){
		string str1;
		string str2;
		getline(is, str1);
		int originalSize = str1.size();
		int newSize = 0;
		char currentChar = str1[0];
		int count = 1;
		for (int i = 1; i < originalSize; i++){
			if (currentChar == str1[i])
				count++;
			else{
				str2 += currentChar;
				str2 += to_string(count);
				newSize += 2;
				if (newSize > originalSize){
					break;
				}
				currentChar = str1[i];
				count = 1;
			}

			//끝날때 마지막 문자 처리
			if (i == originalSize - 1){
				str2 += currentChar;
				str2 += to_string(count);
				newSize += 2;
			}
		}
		if (newSize > originalSize){
			cout << str1 << endl;
		}
		else{
			cout << str2 << endl;
		}
		

	}
	return 0;
}

/*
면접관과 상의할 것
1) ?
*/

