#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
/*
�ڵ����ͺ� �����м�
10.1
���ĵ� �迭 A�� B�� �־�����. A�� ������ B�� �����ϱ� ����� ���� ������ �ִ�. B�� A�� ���ĵ� ���·� �����ϴ� �޼��带 �ۼ��϶�
*/

//�߰� ���۸� ����ϰ� ���ϰ� ���� �ð����⵵ ���̰� �ִ�.
//�߰� ���� ���� ����
int main(){
	int testcase;
	ifstream is("cracking_���ĵȹ迭����.txt");

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

		int j = 0;	//a �ε���
		int sizeAoffset = 0;	//A�� ������ ���� ������

		//B�� A�� �����ϴ� �˰��� (mn �˰���)
		for (int i = 0; i < sizeB; i++){
			
			//������ ��ġ�� ã�� �˰���
			for (; j < sizeA + sizeAoffset; j++){
				if (b[i] < a[j]){
					memmove(a + j + 1, a + j, sizeof(int)*((sizeB + sizeAoffset) - (j)));
					a[j] = b[i];
					sizeAoffset++;
					j++;//�ε��� �ϳ� ����
					break;
				}
			}

			//������ �����ʹ� �ڿ� ����
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
�������� ������ ��
1) �߰� ���۸� ����ص� �ǰڽ��ϱ�?
2) ���ĵ� �������� ������ �����Դϱ�?

*/

