#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
/*
�ڵ����ͺ� �����м�
1.5
���� ���ڰ� �������� �ݺ��� ��� �����ض�
aabccccccccaaa
�̸� a2b1c8a3�� �����ض�. �� ª������ ������ �״�� ��ȯ�ض�
*/

//�迭�� ����� Ǯ��, ms949�� ��� ó���� �� �ֵ���
int main(){
	int testcase;
	ifstream is("cracking_���ڿ�����.txt");
	//is.imbue(locale("korean"));	//�˾Ƽ� multibyte�� unicode�� �ٲ���

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

			//������ ������ ���� ó��
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
�������� ������ ��
1) ?
*/

