#include <iostream>
#include <stack>
#include <map>
#include <string.h>
#include <string>
using namespace std;
struct stu{
	int id;
	char name[50];
	string name2;
};
int main(){
	string s("æ»≥Á«œº¿");
	string s3("æ»≥Á«œº¿2");

	stu s1;
	s1.id=10;
	strcpy(s1.name,"Chang");
	s1.name2 = s;
	stack<stu> st;
	st.push(s1);
	
	s1.id=20;
	strcpy(s1.name,"Won");
	s1.name2 = s3;

	st.push(s1);

	cout<<st.top().name2<<endl;
	st.pop();
	cout<<st.top().name2<<endl;
	return 0;
}