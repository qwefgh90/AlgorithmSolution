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
int main(){
	int testcase;
	wifstream is("cracking_���ϼ��˻�.txt");
	is.imbue(locale("korean"));	//�˾Ƽ� multibyte�� unicode�� �ٲ���
	
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
				cout << "�ߺ�����" << endl;
				break;
			}
			if (i == str1.size() - 1)
				cout << "���Ϲ���" << endl;
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

