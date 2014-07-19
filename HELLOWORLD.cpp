#include <iostream>
#include <list>
#include <string>
using namespace std;
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
