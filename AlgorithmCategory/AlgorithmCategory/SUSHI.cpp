#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Menu{
public:
	int price;
	int value;
	Menu(){
		price = 0;
		value = 0;
	}
};
int getMaxMenu(Menu m[20], int menuCount, int budget){
	int result = 0;
	for (int i = 0; i < menuCount; i++){
		if (m[i].price <= budget){
			result = max(result, m[i].price);
		}
	}
	return result;
}

int getMaxValue(Menu m[20], int menuCount, int budget){
	int result = 0;
	int maxPrice = getMaxMenu(m, menuCount, budget);
	if (maxPrice == 0)
		return 0;
	int* table = new int[maxPrice + 1];
	for (int k = 0; k < maxPrice + 1; k++)
		table[k] = 0;

	for (int i = 0; i <= budget; i++){
		int cIndex = i % maxPrice;
		int maxval = 0;
		for (int k = 0; k < menuCount; k++){
			if (m[k].price <= i){///예산이 더클때
				int prevPrice = i - m[k].price;
				int prevIndex = prevPrice % maxPrice;
				if (table[prevIndex] + m[k].value > table[cIndex]){
					maxval = max(maxval, table[prevIndex] + m[k].value);
					
				}
			}
		}
		table[cIndex] = maxval;
		result = max(result, maxval);
	}

	delete table;
	return result;
}

int main(){
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++){
		int cnt, budget;
		cin >> cnt >> budget;
		budget /= 100;
		Menu menu[20];
		for (int k = 0; k < cnt; k++){
			cin >> menu[k].price >> menu[k].value;
			menu[k].price /= 100;
		}
		int result = getMaxValue(menu, cnt, budget);
		cout << result << endl;
	}

	return 0;
}
