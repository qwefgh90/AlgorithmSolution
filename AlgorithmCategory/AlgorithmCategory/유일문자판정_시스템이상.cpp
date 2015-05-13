#include <stdio.h>
#include <string.h>
int main(){
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		char input[10000] = { 0, };
		char assci_table[1000] = { 0, };
		memset(assci_table, 0, 1000);
		
		scanf("%s", input);
		int length = strlen(input);
		int duplicateFlag = 0;
		for (int j = 0; j < length; j++){
			if (assci_table[input[j]] == 1){
				duplicateFlag = 1;
				break;
			}
			else{
				assci_table[input[j]] = 1;
			}
		}

		if (duplicateFlag)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}

/*
������
����	���� ���� ����	�����ڵ�	4-L-01
����	���ڿ��� ���Ե� ���ڵ��� ���� ���������� �˻��ϴ� �˰����� �����϶�.
�迭 �� �ٸ� �ڷᱸ���� ��� �� �� ���� ��Ȳ�̶�� ��� �ϰڴ°�?
�Է� ����	ù° ���� �׽�Ʈ���̽� T�� �Է� �޾ƾ� �Ѵ�.
���� �Է� ���ڿ� S�� �־�����. (ASCII�� ���)
��� ����	ù° �ٿ� #testcaseN�� ���¿� ���� ��ȣ�� ����Ѵ�
������ ���ڷ� ������ ���ڿ��̶�� Yes �ƴ϶�� No ���
����	�Է�	���
2
ZxcvaSsd1234
CatdogsoftwareSamsung
#testcase1
Yes
#testcase2
No

*/