#include <iostream>
#include <queue>

using namespace std;

int N, K, L, time = 0;
char dir[10001];
int map[101][101];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int d = 3; // 0 : ╩С, 1: аб, 2:го, 3: ©Л
queue<int> qx;
queue<int> qy;

void input()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		map[r - 1][c - 1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		dir[x] = c;
	}
}

void decrease()
{
	int x, y;
	x = qx.front();
	y = qy.front();
	map[y][x] = 0;
	qx.pop();
	qy.pop();
}

void game(int y, int x)
{
	time++;
	if (y < 0 || y >= N || x < 0 || x >= N || map[y][x] == 2) return;

	qy.push(y);
	qx.push(x);

	if (map[y][x] == 1)
	{
		map[y][x] = 2;
	}
	else if (map[y][x] == 0)
	{
		map[y][x] = 2;
		decrease();
	}
	if (dir[time] == 'D')
	{
		d++;
		if (d == 4) d = 0;
	}
	else if (dir[time] == 'L')
	{
		d--;
		if (d == -1) d = 3;
	}

	game((y + dy[d]), (x + dx[d]));
}


int main()
{
	input();
	qy.push(0);
	qx.push(0);
	game(0, 1);
	cout << time;
	return 0;
}