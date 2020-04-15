#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int dir[4][2] = {
	{0,-1},{1,0},{0,1},{-1,0}
};
char map[12][6];
bool check[12][6];
queue<int> qx, qy;
deque<int> qx1, qy1;
int cnt, cnt1, ans;

void BFS(int x, int y)
{
	cnt = 1;
	check[y][x] = true;
	qx.push(x);
	qy.push(y);
	
	qx1.push_back(x);
	qy1.push_back(y);
	while (!qx.empty())
	{
		int x = qx.front();
		int y = qy.front();
		qx.pop();
		qy.pop();
		for (int i = 0; i < 4; i++)
		{
			int dx = x + dir[i][0];
			int dy = y + dir[i][1];

			if ((dy >= 0 && dy < 12) && (dx >= 0 && dx < 6) && map[dy][dx] ==map[y][x] && check[dy][dx] != true)
			{
				check[dy][dx] = true;
				cnt++;
				qx.push(dx);
				qy.push(dy);
				qx1.push_back(dx);
				qy1.push_back(dy);
			}

		}
	}
	if (cnt < 4)
	{
		for (int i = 0; i < cnt; i++)
		{
			qx1.pop_back();
			qy1.pop_back();
		}
	}
	else cnt1 += cnt;
}

void initCheck()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			check[i][j] = false;
}

void pull(int x, int y)
{
	for (int i = y; i > 0; i--)
	{
		if (map[i][x] == '.') return;
		map[i][x] = map[i - 1][x];
	}
}

void find()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			if (map[i][j] != '.' && check[i][j] != true) BFS(j, i);

	if (cnt1 != 0) {
		for (int i = 0; i < cnt1; i++)
		{
			pull(qx1.front(), qy1.front());
			qx1.pop_front();
			qy1.pop_front();
		}
		cnt1 = 0;
		ans++;
		initCheck();
		find();
	}
}

void input()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> map[i][j];
}

int main()
{
	input();
	find();
	cout << ans;
	return 0;
}