#include <iostream>

using namespace std;

int map[9][9];
int tMap[9][9];
int N, M;
int dir[4][2] = { {0,-1}, {1,0}, {0, 1}, {-1,0} };
int sum, ans = -9999;

void copyMap()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tMap[i][j] = map[i][j];
}

void spread(int x, int y)
{

	for (int i = 0; i < 4; i++)
	{
		int dy = y + dir[i][1];
		int dx = x + dir[i][0];
		if (dy >= 0 && dy < N && dx >= 0 && dx < M)
			if (tMap[dy][dx] == 0) {
				tMap[dy][dx] = 2;
				spread(dx, dy);
			}
	}
}

void cntZero()
{
	sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (tMap[i][j] == 0) sum++;
}

void wall(int cnt, int y) {
	if (cnt == 3) {
		copyMap();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
			{
				if (tMap[i][j] == 2) spread(j, i);
			}
		}
		cntZero();
		if (ans < sum) ans = sum;
		return;
	}
	for (int i = y; i < N*M; i++) {
		
			if (map[i/M][i%M] == 0) {
				map[i/M][i%M] = 1;
				wall(cnt + 1, i);
				map[i/M][i%M] = 0;
			
		}
	}

}



int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	wall(0, 0);
	cout << ans;
	return 0;
}