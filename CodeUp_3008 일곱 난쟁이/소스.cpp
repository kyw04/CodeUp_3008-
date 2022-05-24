#include <iostream>
#include <algorithm>
#include <stack>
#define N 9
using namespace std;

stack<int> s;
int t[7];
void f(int h[], int n, int cnt, int sum)
{
	if (sum == 100 && cnt == 7)
	{
		while (s.size())
		{
			t[s.size() - 1] = s.top();
			s.pop();
		}
	}
	else
	{
		for (int i = n; i < N; i++)
		{
			s.push(h[i]);
			f(h, n + 1, cnt + 1, sum + h[i]);
			if (!s.size())
				break;
			s.pop();
		}
	}
}
int main()
{
	int h[N];
	for (int i = 0; i < N; i++)
		cin >> h[i];
	
	f(h, 0, 0, 0);

	sort(t, t + 7);

	for (int i = 0; i < 7; i++)
		cout << t[i] << endl;

	return 0;
}