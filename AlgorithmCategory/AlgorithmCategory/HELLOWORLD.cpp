#include <iostream>
#include <list>
#include <string>
using namespace std;
/*
https://algospot.com/wiki/read/%EC%95%8C%EA%B3%A0%EC%8A%A4%ED%8C%9F_%EC%98%A8%EB%9D%BC%EC%9D%B8_%EC%A0%80%EC%A7%80/%EC%B2%AB_%EB%B2%88%EC%A7%B8_%EB%AC%B8%EC%A0%9C_%ED%92%80%EA%B8%B0
*/
int main(int argc, char* argv[]){
	int name_count = 0;
	cin >> name_count;
	//cout << "Hello, " << argv[1] <<endl;
	list<string> name_list;

	int loop_cnt = 2+name_count;
	for (int i=2 ; i<loop_cnt ; i++)
	{
		string name;
		cin >> name;
		name_list.push_back(name);
	}
	list<string>::iterator iterPos = name_list.begin();
	for (int i=2 ; i<loop_cnt ; i++)
	{
		cout << "Hello, "<< *iterPos << "!" << endl;
		iterPos++;
	}
	return 0;
}
