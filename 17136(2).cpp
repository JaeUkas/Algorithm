#include <iostream>

using namespace std;

int map[10][10], paperCnt[5] = { 5, 5, 5, 5, 5 }, answer = 999999;

bool inRange(int x, int y, int len)
{
	if (x + len > 10 || y + len > 10) return false;
	for (int i = y; i < y + len; i++)
		for (int j = x; j < x + len; j++)
			if (i >= 10 || j >= 10 || !map[i][j])
				return false;

	return true;
}

void set(int x, int y, int len, int idx)
{
	for (int i = y; i < y + len; i++)
		for (int j = x; j < x + len; j++)
			map[i][j] = idx;
}

void dfs(int x, int y, int cnt)
{
	if (cnt >= answer) return;
	if (y == 10) { answer = cnt; return; }
	if (x == 10) { dfs(0, y + 1, cnt); return; }
	if (!map[y][x]) { dfs(x + 1, y, cnt); return; }

	for (int i = 0; i < 5; i++)
	{
		if (paperCnt[i] == 0 || !inRange(x, y, i + 1)) continue;

		paperCnt[i]--;
		set(x, y, i + 1, 0);
		dfs(x + 1, y, cnt + 1);
		set(x, y, i + 1, 1);
		paperCnt[i]++;
	}
}

int main(void)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];

	dfs(0, 0, 0);
	
	cout << ((answer == 999999) ? -1 : answer);
	return 0;
}