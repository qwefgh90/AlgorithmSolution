#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <vector>
using namespace std;
//https://code.google.com/codejam/contest/dashboard?c=6224486#s=p2
//간단한 수학 법칙 


struct Node{
	bool i;
	bool k;
	bool reverse_i;
	bool reverse_k;
};

enum table{
	one,i,j,k,minus_i,minus_one,minus_j,minus_k
};

table operate(table param1, table param2);

bool isJ(char* str, int startIndex, int endIndex){
	table sum;
	if (str[startIndex] == 'i'){
		sum = i;
	}
	if (str[startIndex] == 'j'){
		sum = j;
	}
	if (str[startIndex] == 'k'){
		sum = k;
	}
	int offset = startIndex + 1;
	while (offset <= endIndex){

		if (str[offset] == 'i'){
			sum = operate(sum, i);
		}
		if (str[offset] == 'j'){
			sum = operate(sum, j);
		}
		if (str[offset] == 'k'){
			sum = operate(sum, k);
		}
		
		offset++;
	}
	if (sum == j){
		return true;
	}
	return false;	
}

//정방향 및 역방향 탐색을 통한 후보 선출
//선출된 후보가 옳바른지 검사
bool findijk(char* str, Node* check){
	vector<int> iIndex;
	vector<int> kIndex;

	bool find = false;
	bool rfind = false;
	bool result = false;
	int len = strlen(str);
	table sum;

	for (int i = 0; i < len; i++){

		char ch = str[i];
		if (i == 0){
			if (ch == 'i'){
				check[i].i = true;
				sum = table::i;
			}
			if (ch == 'j'){
				sum = table::j;
			}
			if (ch == 'k'){
				sum = table::k;
			}
		} else {
			if (ch == 'i'){
				sum = operate(sum, table::i);
			}
			if (ch == 'j'){
				sum = operate(sum, table::j);
			}
			if (ch == 'k'){
				sum = operate(sum, table::k);
			}

			if (sum == table::i){
				check[i].i = true;
			}
			if (sum == table::k){
				check[i].k = true;
			}

			if (i == len - 1 && sum != table::minus_one){
				return false;
			}
		}
		
	}

	for (int i = len - 1; i >= 0; i--){

		char ch = str[i];
		if (i == len-1){
			if (ch == 'i'){
				sum = table::i;
			}
			if (ch == 'j'){
				sum = table::j;
			}
			if (ch == 'k'){
				check[i].reverse_k = true;
				sum = table::k;
				if (i - 1 >= 0 && check[i - 1].k == true && check[i].reverse_k == true){
					//possible
					kIndex.push_back(i - 1);
				}
			}
		}
		else {
			if (ch == 'i'){
				sum = operate(sum, table::i);
			}
			if (ch == 'j'){
				sum = operate(sum, table::j);
			}
			if (ch == 'k'){
				sum = operate(sum, table::k);
			}

			if (sum == table::k || sum == table::minus_k){
				check[i].reverse_k = true;
				if (i - 1 >= 0 && check[i - 1].k == true && check[i].reverse_k == true){
					//possible
					kIndex.push_back(i - 1);
				}
			}
			if (sum == table::i || sum == table::minus_i){
				check[i].reverse_i = true;
				if (i - 1 >= 0 && check[i - 1].i == true && check[i].reverse_i == true){
					//possible
					iIndex.push_back(i);
				}
			}
		}
	}

	//가운데 j reduce 비교
	int iVectorSize = iIndex.size();
	int kVectorSize = kIndex.size();
	
	for (int i = 0; i < iVectorSize; i++){
		for (int k = 0; k < kVectorSize; k++){
			if (true == isJ(str, iIndex[i], kIndex[k])){
				return true;
			}

		}
	}

	//존재하면 true 반환
	return result;
}

int main(){
	FILE* f = fopen("DijkstraSmall.txt", "r");
	FILE* w = fopen("output.txt", "w");
	int testcase;
	fscanf(f, "%d", &testcase);

	for (int j = 0; j < testcase; j++){
		

		int len;
		int repeat;
		fscanf(f, "%d %d", &len, &repeat);
		

		char* str = (char*)calloc(repeat*len+1, sizeof(char));
		Node* check = (Node*)calloc(repeat*len+1, sizeof(Node));

		fscanf(f, "%s", str);
		char temp[10001];
		strcpy(temp, str);
		for (int i = 0; i < repeat - 1; i++){
			strcat(str, temp);
		}
		
		bool result = findijk(str, check);
		if (result)
			fprintf(w,"Case #%d: YES\n", j+1);
		else
			fprintf(w,"Case #%d: NO\n", j + 1);
		

		free(str);
		free(check);
	}

	fclose(f);
	fclose(w);

	return 0;
}



table operate(table param1, table param2){
	bool minus = false;
	if (param1 == minus_one){
		minus = !minus;
		param1 = one;
	}
	if (param1 == minus_i){
		minus = !minus;
		param1 = i;
	}
	if (param1 == minus_j){
		minus = !minus;
		param1 = j;
	}
	if (param1 == minus_k){
		minus = !minus;
		param1 = k;
	}
	if (param2 == minus_one){
		minus = !minus;
		param2 = one;
	}
	if (param2 == minus_i){
		minus = !minus;
		param2 = i;
	}
	if (param2 == minus_j){
		minus = !minus;
		param2 = j;
	}
	if (param2 == minus_k){
		minus = !minus;
		param2 = k;
	}

	table result;


	if (param1 == one && param2 == one){
		result = one;
	}
	else if (param1 == one && param2 == i){
		result = i;
	}
	else if (param1 == one && param2 == j){
		result = j;
	}
	else if (param1 == one && param2 == k){
		result = k;
	}

	if (param1 == i && param2 == one){
		result = i;
	}
	else if (param1 == i && param2 == i){
		result = one;
		minus = !minus;
	}
	else if (param1 == i && param2 == j){
		result = k;
	}
	else if (param1 == i && param2 == k){
		result = j;
		minus = !minus;
	}

	if (param1 == j && param2 == one){
		result = j;
	}
	else if (param1 == j && param2 == i){
		minus = !minus;
		result = k;
	}
	else if (param1 == j && param2 == j){
		minus = !minus;
		result = one;
	}
	else if (param1 == j && param2 == k){
		result = i;
	}

	if (param1 == k && param2 == one){
		result = k;
	}
	else if (param1 == k && param2 == i){
		result = j;
	}
	else if (param1 == k && param2 == j){
		result = i;
		minus = !minus;
	}
	else if (param1 == k && param2 == k){
		result = one;
		minus = !minus;
	}

	if (minus == true){
		switch (result){
		case one:
			result = minus_one;
			break;
		case i:
			result = minus_i;
			break;
		case j:
			result = minus_j;
			break;
		case k:
			result = minus_k;
			break;
		}
	}
	return result;
}