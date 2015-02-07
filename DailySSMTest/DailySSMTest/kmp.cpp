#include <stdio.h>
#include <string.h>

char s[1000] = { 0 }, p[100] = { 0 };
int n, m, pi[100] = { 0 };
void find_pi()
{
	int i = 0, j = -1;
	pi[0] = -1;
	while (i < m)
	{
		if (j == -1 || p[i] == p[j])
		{
			i++, j++;
			pi[i] = j;
		}
		else j = pi[j];
	}
}
void kmp()
{
	int i = 0, j = 0;
	while (i < n)
	{
		if (j == -1 || s[i] == p[j]) i++, j++;
		else j = pi[j];
		if (j == m)
		{
			printf("Match : %d to %d\n", i - m + 1, i);
			j = pi[j];
		}
	}
}
int main()
{
	scanf("%s", s);
	scanf("%s", p);
	n = strlen(s), m = strlen(p);
	find_pi();
	kmp();
	return 0;
}