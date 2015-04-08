#include <iostream>
#include <map>
#include <limits>
#define Bound numeric_limits<long long>::min();
using namespace std;
long long out[150];
long long flipping[150];
int N, L;
map<long long, long long> D;
map<long long, long long> key;
unsigned long long convertTodec(long long num)
{
	if (num <= 0)
		return 0;
	if (D[num] != 0) return D[num];
	D[num] = convertTodec(num / 2) + num % 2;
	return D[num];
}
long long charging(int dig, int cnt)
{
	if (dig >= L)
		return 1099511627776;
	bool flag = true;
	for (int i = 0; i < N; i++)
	if (key[out[i]] == 0)
	{
		key.erase(out[i]);
		flag = false;
		break;
	}
	if (flag)
		return cnt;
	long long res = 0;
	for (int i = 0; i < N; i++) out[i] ^= (1 << dig);
	res = charging(dig + 1, cnt + 1);
	for (int i = 0; i < N; i++) out[i] ^= (1 << dig);
	res = min(res, charging(dig + 1, cnt));
	return res;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		key.clear();
		cin >> N >> L;
		for (int i = 0; i < N; i++) { cin >> out[i]; out[i] = convertTodec(out[i]); }
		for (int i = 0; i < N; i++) cin >> flipping[i];
		for (int i = 0; i < N; i++) key[convertTodec(flipping[i])] = 1;
		long long res = charging(0, 0);
		if (res >= 1099511627776)
			cout << "Case #" << (t + 1) << ": NOT POSSIBLE" << endl;
		else
			cout << "Case #" << (t + 1) << ": " << res << endl;
	}
	return 0;
}