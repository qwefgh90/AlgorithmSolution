#include <iostream>
#include <list>
#include <stdio.h>
using namespace std;
/*
https://algospot.com/judge/problem/read/ENDIANS
*/
int main(){
	int cnt = 0;
	cin >> cnt;
	list<unsigned int> sourceNums;
	for( int i=0; i<cnt; i++){
		unsigned int temp=0;
		cin >> temp;
		sourceNums.push_back(temp);
	}
	for( list<unsigned int>::iterator iterFirst = sourceNums.begin()
			; iterFirst != sourceNums.end(); iterFirst++){
		unsigned int temp = *iterFirst;
//		cout << temp << endl;
//		������ ����
		//������ �켱����  '+'  >  '>>'   >   '&' ��ȣ�� �� �ľ��Ѵ�!
		unsigned int dest_num = 0;
		dest_num = ((temp & 0xff)<<24) + ((temp>>8 & 0xff)<<16) + ((temp>>16 & 0xff)<<8) + (temp>>24 & 0xff);
		unsigned int dd=(temp&0xff) << 24;
		cout <<dest_num<<endl;	
	}
	return 0;
}